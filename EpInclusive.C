{
  // gSystem->Load("libTree");
  // gSystem->Load("libPhysics");
  // gSystem->Load("libEG");
  // gSystem->Load("libEGGen.so");

  TEGGenerator* generator=new TEGGenerator();
  //Time the generator
  TBenchmark* bm=new TBenchmark();
  bm->Start("his100");
  //Set the random seed
  gEGRandom->SetSeed(111111);
  //Construct the output
  // TEGOutGEMC* outg=new TEGOutGEMC();
  // outg->SetFileName("Inclusive.ld");//Output file name
  // generator->SetOutput(dynamic_cast<TEGOutput*>(outg));
  // outg->SetGenerator(generator);
  // TEGOutLorentz* outg=new TEGOutLorentz();
  // outg->SetFileName("Inclusive.root");
  // generator->SetOutput((TEGOutput*)outg);
  // outg->SetGenerator(generator);
  //construct output
  TEGOutAll* outg=new TEGOutAll();
  outg->SetFileName("Incoherent.root");
  outg->SetOnlyTrackFinal();//only track particles which don't decay
  generator->SetOutput((TEGOutput*)outg);

  //Create an electroproduction reaction
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");
  pr->SetIsTrack(kFALSE);//don't write the combined CM particle to output
  generator->SetReaction(pr);

  //Construct beam   
  TEGParticle* beam=new TEGParticle("beam",11,NULL);
  beam->SetIsTrack(kFALSE); //don't write the initial electron
  //make a distribution for the electron beam
  TEGDistribution* distBeam=new TEGDistribution();
  distBeam->SetThetaRange(0,0);
  distBeam->SetERange(11,11);
  distBeam->SetE(11);
  //smear beam angle
  //TF1* fbtheta=new TF1("btheta","gaus(0)",0,TMath::DegToRad()*100);//range in radians
  //fbtheta->SetParameters(1,0,TMath::DegToRad()*0.1);//height,mean,width
  //distBeam->SetThetaDist(fbtheta);
  beam->SetDistribution(distBeam);
  //for vertex position 
  pr->SetTargetPos(TVector3(0,0,0));
  pr->SetTargetLength(5);//should be in same units as GEMC LUND input
  pr->SetBeamSpotSize(0.01); //100um in cm

  //create beam "decay" to eprime,radiated gamma, virtual photon
  TEGDecTwoBody* beamDec=new TEGDecTwoBody();
  beamDec->SetIsE1Theta1();
  TEGParticle* eprime=beamDec->AddProduct(11);
  TEGParticle* inc=beamDec->AddProduct(-22);
  eprime->SetName("eprime");
  inc->SetName("inclusive");
  //inc->SetIsTrack(kFALSE); //virtual photon in non radiative case
  //create distribution from inclusive.f cross section file
  TEGDistDsigDOmega* eScat=new TEGDistDsigDOmega();
  eScat->SetIsE();
  TFile* csf=new TFile("EScat/inclE0.1_10.9_Th0.5_9.db.root"); //the root file
  //TH2F* hin=(TH2F*)csf->Get("htot"); //get total cross section
  TH2F* hin=(TH2F*)csf->Get("hin"); //get inelastic cross section
   eScat->Set2Distribution(hin);
  Double_t Eemin=0.5;//min scattered electron energy
  Double_t Eemax=4.;//max scattered electron energy
  eScat->SetERange(Eemin,Eemax);  //set eprime E range
  Double_t thmin=2.*TMath::DegToRad(); //min scatter angle convert to rad
  Double_t thmax=5.*TMath::DegToRad(); //min scatter angle convert to rad
  eScat->SetThetaRange(thmin,thmax);//set eprime theta range
  beamDec->SetDistribution(eScat);//give distribtution to decay
  beam->AddDecayChannel(beamDec); //give decay to beam
  ///beam->Initialise();

  //proton target PDG #=2212
  TEGParticle *target=new TEGParticle("target",2212,pr);

  //set reaction intitial and final particles
  pr->SetInitial1(beam);
  pr->SetInitial2(target);
  pr->Initialise();

  //Get the eprime distribution
  TF2* f2=eScat->Get2Distribution();
  //increase Npoints, default is 30, this decreases binning artifacts
  f2->SetNpx(108);
  f2->SetNpy(30);

  //calculate number of events per second
  //integrated cross section*Luminosity*microbarns*2pi
  Double_t rate=f2->Integral(Eemin,Eemax,thmin,thmax)*1E35*1E-30*2*TMath::Pi();
  Double_t TIME=10; //run for 1 second
 cout<<rate <<" "<<TIME<<" "<<rate*TIME<<endl;
 return;
  for(Int_t i=0;i<rate*TIME;i++){
    generator->GenerateEvent();
    cout<<eprime->GetP4()->Theta()*TMath::RadToDeg()<<endl;
  }
  bm->Stop("his100");
  outg->Close();
  cout<<"time "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
 
}
