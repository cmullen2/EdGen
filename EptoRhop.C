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
  // TEGOutGEMC* outg=new TEGOutGEMC();
  // // outg->SetFileName("Eptonpip100k_11GeVPhi1.ld");//Output file name
  // outg->SetFileName("data/EptoRhop.ld");//Output file name
  // generator->SetOutput(dynamic_cast<TEGOutput*>(outg));

  //construct dummy reaction particle
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");
  pr->SetIsTrack(kFALSE);//don't track this);
  generator->SetReaction(pr);

  //make phase space reaction decay direct to 3 pi+ p
  TEGDecTwoBody* decay1=new TEGDecTwoBody();
  decay1->SetIsWCosTh();
  TEGDistDsigDt* dist1=new TEGDistDsigDt(6.0);
  decay1->SetDistribution((TEGDistribution*)dist1);
  // dist1->SetPhiDist(new TF1("PhotAsym","1+[0]*0.8*cos(2*x)",-TMath::Pi(),TMath::Pi()));
   //dist1->SetPhiDist(new TF1("PhotAsym","1+[0]*0.8*cos(2*x)",1-0.0001,1.0001));
 
  dist1->SetReaction(pr);
  //dist1->SettMin(1);
  //dist1->SettMax(1.5);
  //set decay channel to reaction
  pr->AddDecayChannel(decay1,1);//(decay,branchingratio)
  // add particles to decay
  //  TEGParticle* pi=decay1->AddProduct(211,"pip");//a pi+
  //pi->SetIsTrack(kTRUE);//don't track this
  TEGParticle* rho=decay1->AddProduct(113,"rho");
  rho->SetIsTrack(kFALSE);//don't track this

  TEGParticle* proton=decay1->AddProduct(2212,"proton");
  pr->FixCurrDecay(0);
  //decay phi
  TEGDecay* decay2=new TEGDecay();
  rho->AddDecayChannel(decay2,1);
  TEGParticle* Pip=decay2->AddProduct(211,"Pip");
  TEGParticle* Pim=decay2->AddProduct(-211,"Pim");

  //make a target
  TEGParticle *target=new TEGParticle("target",2212,pr);
  //make the beam
  TEGParticle* beam=new TEGParticle("beam",11,NULL);
  beam->SetIsTrack(kFALSE);//don't store beam
  TEGDistribution* distBeam=new TEGDistribution();
  //can create realistic beam characteristics
  //at moment have fixed energy as varying would mean recalculating the 
  //VPhoton distribution each time, can perhaps use foam to make 3D dist 
  distBeam->SetERange(10.6,10.6);
  distBeam->SetE(10.6);
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
  gstar->SetIsTrack(kFALSE);//don't track this for GEMC
  //create virtual photon distribution
  TEGDistEScat* vPhot=new TEGDistEScat();
  vPhot->SetE0(10.6);
  //vPhot->SetE0(4.000510999);
  vPhot->SetIsScatETh();
  //set ranges
  Double_t Eemin=0.5;//min scattered electron energy
  Double_t Eemax=10.5;//max scattered electron energy
  vPhot->SetERange(Eemin,Eemax);  //set eprime E range
  Double_t thmin=2.*TMath::DegToRad(); //min scatter angle convert to rad
  Double_t thmax=5.*TMath::DegToRad(); //max scatter angle convert to rad
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
  Double_t cross_sec=15;//photoproduction cross section microbarns
  //Double_t Lumin=5E33;
  Double_t Lumin=1E35*50/75;
  //  Double_t rate=f2->Integral(Eemin,Eemax,thmin,thmax)*1E35*1E-30*2*TMath::Pi();
  Double_t rate=cross_sec*f2->Integral(Eemin,Eemax,thmin,thmax)*Lumin*1E-30*2*TMath::Pi();
  //60s*60minute*24hours*24 days.
  Double_t TIME=0.1*60*60*2*1; //seconds
  
  cout<<rate <<" "<<TIME<<" "<<rate*TIME<<" "<< f2->Integral(Eemin,Eemax,thmin,thmax)<<endl;
  //  exit(0);
  Int_t NFiles=1;
  for(Int_t j=0;j<NFiles;j++){
    TEGOutGEMC* outg=new TEGOutGEMC();
    outg->SetFileName(Form("EptoRhop_%d.ld",j));//Output file name
    generator->SetOutput(dynamic_cast<TEGOutput*>(outg));

    for(Int_t i=0;i<rate*TIME/NFiles;i++){
  //for(Int_t i=0;i<100000;i++){
      if(i%1000==0)cout<<"event "<<i<<endl;
      generator->GenerateEvent();
    }

  bm->Stop("Epto3pi");
  outg->Close();
  delete outg;
  }
  // for(Int_t i=0;i<rate*TIME;i++){
  // //for(Int_t i=0;i<100000;i++){
  //   if(i%1==0)cout<<"event "<<i<<endl;
  //   generator->GenerateEvent();
  // }

  bm->Stop("Epto3pi");
  outg->Close();

  cout<<"time "<<bm->GetCpuTime("Epto3pi")<<" real "<<bm->GetRealTime("Epto3pi")
<<endl;
 
}
