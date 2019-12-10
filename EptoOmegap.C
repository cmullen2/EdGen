{
  gSystem->Load("libTree");
  gSystem->Load("libPhysics");
  gSystem->Load("libEG");
  gSystem->Load("libEGGen.so");

  //Construct generator
  TEGGenerator* generator=new TEGGenerator();
  
  //make benchmark to monitor timing
  TBenchmark* bm=new TBenchmark();
  bm->Start("Epto3pi");

  //construct output
  // TEGOutAll* outg=new TEGOutAll();
  // outg->SetFileName("Eptopipp_low3.root");
  // generator->SetOutput((TEGOutput*)outg);
  TEGOutGEMC* outg=new TEGOutGEMC();
  outg->SetFileName("Eptopipp_low3.ld");//Output file name
  generator->SetOutput(dynamic_cast<TEGOutput*>(outg));

  //construct dummy reaction particle
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");
  pr->SetIsTrack(kFALSE);//don't track this
  generator->SetReaction(pr);

  //make phase space reaction decay direct to 3 pi+ p
  TEGDecTwoBody* decay1=new TEGDecTwoBody();
  decay1->SetIsWCosTh();
  TEGDistDsigDt* dist1=new TEGDistDsigDt(3.0);
  decay1->SetDistribution((TEGDistribution*)dist1);
  // dist1->SetPhiDist(new TF1("PhotAsym","1+[0]*0.8*cos(2*x)",-TMath::Pi(),TMath::Pi()));
  dist1->SetReaction(pr);
  //dist1->SettMin(1);
  //dist1->SettMax(1.5);
  //set decay channel to reaction
  pr->AddDecayChannel(decay1,1);//(decay,branchingratio)
  // add particles to decay
  TEGParticle* pi=decay1->AddProduct(223,"omega");//a pi+
  pi->SetIsTrack(kTRUE);//don't track this
  TEGParticle* proton=decay1->AddProduct(2212,"proton");
  pr->FixCurrDecay(0);

  //make a target
  TEGParticle *target=new TEGParticle("target",2212,pr);
  //make the beam
  TEGParticle* beam=new TEGParticle("beam",11,NULL);
  beam->SetIsTrack(kFALSE);//don't store beam
  TEGDistribution* distBeam=new TEGDistribution();
  //can create realistic beam characteristics
  //at moment have fixed energy as varying would mean recalculating the 
  //VPhoton distribution each time, can perhaps use foam to make 3D dist 
  distBeam->SetERange(11,11);
  distBeam->SetE(11);
  distBeam->SetThetaRange(0,0.000);
  beam->SetDistribution(distBeam);

  //create beam decay (really e- scattering)
  TEGDecay* eScat=new TEGDecay();
  //give e- scatter to e- beam
  beam->AddDecayChannel(eScat);
  TEGParticle* eprime=eScat->AddProduct(11,"eprime");
  TEGParticle* gstar=eScat->AddProduct(-22,"gstar");//-22 defined as virtual photon in TEGGenerator()
  if(dynamic_cast<TEGOutGEMC*>(outg))gstar->SetIsTrack(kFALSE);//don't track this for GEMC
  //create virtual photon distribution
  TEGDistEScat* vPhot=new TEGDistEScat();
  vPhot->SetE0(11.000510999);
  vPhot->SetIsScatETh();
  //set ranges
  Double_t Eemin=0.5;//min scattered electron energy
  Double_t Eemax=4.5;//max scattered electron energy
  vPhot->SetERange(Eemin,Eemax);  //set eprime E range
  Double_t thmin=2.5*TMath::DegToRad(); //min scatter angle convert to rad
  Double_t thmax=4.5*TMath::DegToRad(); //max scatter angle convert to rad
  vPhot->SetThetaRange(thmin,thmax);//set eprime theta range

  //give distribution to e- scatter
  eScat->SetDistribution(vPhot);
  
  pr->SetInitial1(beam);
  pr->SetInitial2(target);

  pr->Initialise();


  //Get the eprime distribution
  TF2* f2=vPhot->Get2Distribution();
  //increase Npoints, default is 30, this decreases binning artifacts
  //actually should be Ok if not defining dist from histogram
  f2->SetNpx(100);
  f2->SetNpy(50);
  //calculate number of events per second
  //integrated cross section*Luminosity*microbarns*2pi
  Double_t cross_sec=0.5;//photoproduction cross section microbarns
  //Double_t Lumin=5E33;
  Double_t Lumin=1E35;
  Double_t rate=cross_sec*f2->Integral(Eemin,Eemax,thmin,thmax)*Lumin*1E-30*2*TMath::Pi();
  //60s*60minute*24hours*24 days.
  Double_t time=1*60*60*24*24; //seconds
  
  cout<<rate <<" "<<time<<" "<<rate*time<<endl;
  //   return;
  for(Int_t i=0;i<rate*time/10;i++){
  //for(Int_t i=0;i<11000;i++){
    if(i%10000==0)cout<<"event "<<i<<endl;
    generator->GenerateEvent();
  }

  bm->Stop("Epto3pi");
  outg->Close();

  cout<<"time "<<bm->GetCpuTime("Epto3pi")<<" real "<<bm->GetRealTime("Epto3pi")
<<endl;
 
}
