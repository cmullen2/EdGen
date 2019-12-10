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
  TEGOutAll* outg=new TEGOutAll();
  outg->SetFileName("../EdGenOut/EptoKpLambda1405_11GeV.root");
  generator->SetOutput((TEGOutput*)outg);

  //construct dummy reaction particle
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");
  pr->SetIsTrack(kFALSE);//don't track this
  generator->SetReaction(pr);

  //make phase space reaction decay direct to 3 pi+ p
  TEGDecTwoBody* decay1=new TEGDecTwoBody();
  decay1->SetIsWCosTh();
  TEGDistDsigDt* dist1=new TEGDistDsigDt();
  decay1->SetDistribution((TEGDistribution*)dist1);
  dist1->SetReaction(pr);
  //dist1->SettMin(1);
  //dist1->SettMax(1.5);
  //set decay channel to reaction
  pr->AddDecayChannel(decay1,1);//(decay,branchingratio)
  // add particles to decay
  TEGParticle* Kp=decay1->AddProduct(321,"Kp");
  // Pi->SetIsTrack(kTRUE);//don't track this
  TEGParticle* L1405=decay1->AddProduct(3214,"L1405");
  L1405->SetIsTrack(kFALSE);//don't track this
 
  //pr->FixCurrDecay(0);
  //TF1* Xmass=new TF1("Xmass","pol0(0)",1,4);
  //Xmass->SetParameter(0,1);
  //nstar->SetMassDist(Xmass);
  //intialise all particles in the decay and their daughters
  //decay1->Initialise();

  //decay X
  TEGDecay* decay2=new TEGDecay();
  L1405->AddDecayChannel(decay2,1);
  TEGParticle* pi0=decay2->AddProduct(111,"Pi0");
  TEGParticle* Sigma=decay2->AddProduct(3212,"Sigma");
  //TEGParticle* pim=decay2->AddProduct(-211,"pim");
  L1405->FixCurrDecay(0);
  Sigma->SetIsTrack(kFALSE);
  pi0->SetIsTrack(kFALSE);

  TEGDecay* decay3=new TEGDecay();
  Sigma->AddDecayChannel(decay3,1);
  TEGParticle* gammaS=decay3->AddProduct(22,"GammaS");
  TEGParticle* Lambda=decay3->AddProduct(3122,"Lambda");
  Sigma->FixCurrDecay(0);
  Lambda->SetIsTrack(kFALSE);

  TEGDecay* decay4=new TEGDecay();
  Lambda->AddDecayChannel(decay4,1);
  TEGParticle* pim=decay4->AddProduct(-211,"pim");
  TEGParticle* proton=decay4->AddProduct(2212,"proton");
  Lambda->FixCurrDecay(0);

  TEGDecay* decay5=new TEGDecay();
  pi0->AddDecayChannel(decay5,1);
  TEGParticle* gamma1=decay5->AddProduct(22,"gamma1");
  TEGParticle* gamma2=decay5->AddProduct(22,"gamma2");
  Lambda->FixCurrDecay(0);

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
  //create virtual photon distribution
  TEGDistEScat* vPhot=new TEGDistEScat();
  vPhot->SetE0(11.000510999);
  // vPhot->SetE0(6.600510999);
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
  f2->SetNpx(60);
  f2->SetNpy(30);
  //calculate number of events per second
  //integrated cross section*Luminosity*microbarns*2pi
  Double_t cross_sec=0.1;//photoproduction cross section microbarns
  Double_t rate=cross_sec*f2->Integral(Eemin,Eemax,thmin,thmax)*1E35*1E-30*2*TMath::Pi();
  //60s*60minute*24hours*1month*30days/10luminosity.
  Double_t time=1*60*60*24*80/100; //seconds
  
  cout<<rate <<" "<<time<<" "<<rate*time<<endl;
  // return;
  for(Int_t i=0;i<rate*time;i++){
  //for(Int_t i=0;i<1;i++){
    if(i%1000000==0)cout<<"event "<<i<<endl;
    generator->GenerateEvent();
  }

  bm->Stop("Epto3pi");
  outg->Close();

  cout<<"time "<<bm->GetCpuTime("Epto3pi")<<" real "<<bm->GetRealTime("Epto3pi")
<<endl;
 
}
