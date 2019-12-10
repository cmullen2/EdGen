{
  gSystem->Load("libTree");
  gSystem->Load("libPhysics");
  gSystem->Load("libEG");
  gSystem->Load("libEGGen.so");

  TEGGenerator* generator=new TEGGenerator();
  //Time the generator
  TBenchmark* bm=new TBenchmark();
  bm->Start("his100");
  //Set the random seed
  gEGRandom->SetSeed(111111);
  //Construct the output
  // TEGOutGEMC* outg=new TEGOutGEMC();
  // outg->SetFileName("RadElastic.ld");//Output file name
  // generator->SetOutput(dynamic_cast<TEGOutput*>(outg));
  // outg->SetGenerator(generator);
  TEGOutLorentz* outg=new TEGOutLorentz();
  outg->SetFileName("test.root");
  generator->SetOutput((TEGOutput*)outg);
  outg->SetGenerator(generator);

  //Create an electroproduction reaction
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");
  pr->SetIsTrack(kFALSE);//don't write the combined CM particle to output
  generator->SetReaction(pr);

  //Construct beam   
  TEGParticle* beam=new TEGParticle("beam",11,NULL);
  // beam->SetIsTrack(kFALSE); //don't write the initial electron
  //make a distribution for the electron beam
  TEGDistribution* distBeam=new TEGDistribution();
  distBeam->SetERange(11,11);
  distBeam->SetE(11);
  TF1* fbtheta=new TF1("btheta","gaus(0)",0,TMath::DegToRad()*1);//range in radians

   fbtheta->SetParameters(1,0,TMath::DegToRad()*0.5);//height,mean,width
  //fbtheta->SetParameters(1,20*TMath::DegToRad(),TMath::DegToRad()*0.5);//height,mean,width
  //distBeam->SetThetaRange(0,0.5*TMath::DegToRad());
  distBeam->SetThetaDist(fbtheta);
  beam->SetDistribution(distBeam);

  //create beam "decay" to eprime,radiated gamma, virtual photon
  TEGDecElElasticRad* beamDec=new TEGDecElElasticRad();
  //create distribution from inclusive.f cross section file
  TEGDistDsigDOmega* eScat=new TEGDistDsigDOmega();
  TFile* csf=new TFile("EScat/inclE0.1_10.9_Th0.5_9.db.root"); //the root file
  TH2F* hin=(TH2F*)csf->Get("hrad"); //get radiated cross section
  eScat->Set2Distribution(hin);
  Double_t Eemin=0.3;//min scattered electron energy
  Double_t Eemax=10.8;//max scattered electron energy
  eScat->SetERange(Eemin,Eemax);  //set eprime E range
  Double_t thmin=1*TMath::DegToRad(); //min scatter angle convert to rad
  Double_t thmax=5*TMath::DegToRad(); //min scatter angle convert to rad
  eScat->SetThetaRange(thmin,thmax);//set eprime theta range
  beamDec->SetDistribution(eScat);//give distribtution to decay
  beam->AddDecayChannel(beamDec); //give decay to beam
  beamDec->Initialise();
  //Get final state particles
  TEGParticle* eprime=beamDec->GetProduct(2);
  TEGParticle* gstar=beamDec->GetProduct(1);
  TEGParticle* radg=beamDec->GetProduct(0);
  eprime->SetName("eprime");
  gstar->SetName("gstar");
  radg->SetName("radg");

  //proton target PDG #=2212
  TEGParticle *target=new TEGParticle("target",2212,pr);

  //set reaction intitial and final particles
  pr->SetInitial1(beam);
  pr->SetInitial2(target);

  //Get the eprime distribution
  TF2* f2=eScat->Get2Distribution();
  //increase Npoints, default is 30, this decreases binning artifacts
  f2->SetNpx(100);
  f2->SetNpy(100);

  //calculate number of events per second
  //integrated cross section*Luminosity*microbarns*2pi
  Double_t rate=f2->Integral(Eemin,Eemax,thmin,thmax)*1E35*1E-30*2*TMath::Pi();
  Double_t time=1; //run for 1 second


  for(Int_t i=0;i<rate*time;i++){
    generator->GenerateEvent();
  }
  bm->Stop("his100");
  outg->Close();
  cout<<"time "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
 
}
