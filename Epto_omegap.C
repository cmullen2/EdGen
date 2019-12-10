{

  //Construct generator
  TEGGenerator* generator=new TEGGenerator();
  
  //make benchmark to monitor timing
  TBenchmark* bm=new TBenchmark();
  bm->Start("Epto3pi");

  //construct output
  // TEGOutAll* outg=new TEGOutAll();
  // outg->SetFileName("Eptopipp_low3.root");
  // generator->SetOutput((TEGOutput*)outg);

  //construct dummy reaction particle
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");
  pr->SetIsTrack(kFALSE);//don't track this);
  generator->SetReaction(pr);

  //make t-dist reaction decay direct to omega p
  TEGDecTwoBody* decay1=new TEGDecTwoBody();
  decay1->SetIsWCosTh();
  TEGDistDsigDt* dist1=new TEGDistDsigDt(3.0);
  decay1->SetDistribution((TEGDistribution*)dist1);
  dist1->SetPhiDist(new TF1("PhotAsym","1+[0]*0.8*cos(2*x)",-TMath::Pi(),TMath::Pi()));
 
  dist1->SetReaction(pr);
  //set decay channel to reaction
  pr->AddDecayChannel(decay1,1);//(decay,branchingratio)
  // add particles to decay
  TEGParticle* omega=decay1->AddProduct(223,"omega");
  omega->SetIsTrack(kFALSE);//don't track this

  TEGParticle* proton=decay1->AddProduct(2212,"proton");
  pr->FixCurrDecay(0);
  //decay omega
  TEGDecay* decay2=new TEGDecay();
  omega->AddDecayChannel(decay2,1);
  TEGParticle* pip=decay2->AddProduct(211,"pip");
  TEGParticle* pim=decay2->AddProduct(-211,"pim");
  TEGParticle* pi0=decay2->AddProduct(111,"pi0");
  // pi0->SetIsDecay(kFALSE);
   //decay pi0
  TEGDecay* decayPi0=new TEGDecay();
  pi0->AddDecayChannel(decayPi0,1);
  TEGParticle* gamma1=decayPi0->AddProduct(22,"gamma1");
  TEGParticle* gamma2=decayPi0->AddProduct(22,"gamma1");


  //make a target
  TEGParticle *target=new TEGParticle("target",2212,pr);
  //make the beam
  TEGParticle* beam=new TEGParticle("beam",11,NULL);
  beam->SetIsTrack(kFALSE);//don't store beam
  TEGDistribution* distBeam=new TEGDistribution();
  //can create realistic beam characteristics
  //at moment have fixed energy as varying would mean recalculating the 
  //VPhoton distribution each time, can perhaps use foam to make 3D dist 
  distBeam->SetERange(10.6005,10.6005);
  distBeam->SetE(10.6005);
  //distBeam->SetERange(4,4);
  //distBeam->SetE(4);
  distBeam->SetThetaRange(0,0.000);
  beam->SetDistribution(distBeam);

  //create beam decay (really e- scattering)
  TEGDecay* eScat=new TEGDecay();
  //give e- scatter to e- beam
  beam->AddDecayChannel(eScat);
  TEGParticle* eprime=eScat->AddProduct(11,"eprime");
  TEGParticle* gstar=eScat->AddProduct(-22,"gstar");//-22 defined as virtual photon in TEGGenerator()
  // if(dynamic_cast<TEGOutGEMC*>(outg))gstar->SetIsTrack(kFALSE);//don't track this for GEMC
 gstar->SetIsTrack(kFALSE);//don't track this for GEMC
  //create virtual photon distribution
  TEGDistEScat* vPhot=new TEGDistEScat();
  vPhot->SetE0(10.600510999);
  //vPhot->SetE0(4.000510999);
  vPhot->SetIsScatETh();
  //set ranges
  //Double_t Eemin=0.5;//min scattered electron energy
  //Double_t Eemax=10;//max scattered electron energy
  Double_t Eemin=0.5;//min scattered electron energy
  Double_t Eemax=5.5;//max scattered electron energy
  vPhot->SetERange(Eemin,Eemax);  //set eprime E range
  Double_t thmin=2.5*TMath::DegToRad(); //min scatter angle convert to rad
  Double_t thmax=4.5*TMath::DegToRad(); //max scatter angle convert to rad
  // Double_t thmin=8*TMath::DegToRad(); //min scatter angle convert to rad
  //Double_t thmax=35*TMath::DegToRad(); //max scatter angle convert to rad
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
  Double_t cross_sec=2;//photoproduction cross section microbarns
  Double_t Lumin=1E35;
  //Double_t Lumin=1E35;
  Double_t rate=cross_sec*f2->Integral(Eemin,Eemax,thmin,thmax)*Lumin*1E-30*2*TMath::Pi();
  //60s*60minute*24hours*24 days.
  Double_t TIME=1*60*60*24; //seconds
  
  cout<<rate <<" "<<TIME<<" "<<rate*TIME<<" "<<f2->Integral(Eemin,Eemax,thmin,thmax)<<endl;
  exit(0);
  Int_t NFiles=10;
  for(Int_t j=0;j<NFiles;j++){
    TEGOutGEMC* outg=new TEGOutGEMC();
    outg->SetFileName(Form("data/AsymPhiEpto_omega_%d.ld",j));//Output file name
    generator->SetOutput(dynamic_cast<TEGOutput*>(outg));

    for(Int_t i=0;i<rate*TIME/NFiles/10;i++){
  //for(Int_t i=0;i<100000;i++){
      if(i%1000==0)cout<<"event "<<i<<endl;
      generator->GenerateEvent();
    }

  // bm->Stop("Epto3pi");
  // outg->Close();
  // delete outg;
  }
  cout<<"time "<<bm->GetCpuTime("Epto3pi")<<" real "<<bm->GetRealTime("Epto3pi")
<<endl;
 
}
