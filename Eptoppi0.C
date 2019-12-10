{

  //Construct generator
  TEGGenerator* generator=new TEGGenerator();
  
  //make benchmark to monitor timing
  TBenchmark* bm=new TBenchmark();
  bm->Start("Epto3pi");

  // //construct output
  // // TEGOutAll* outg=new TEGOutAll();
  // // outg->SetFileName("Eptopipp_low3.root");
  // // generator->SetOutput((TEGOutput*)outg);
  // TEGOutGEMC* outg=new TEGOutGEMC();
  // // outg->SetFileName("Eptonpip100k_11GeVPhi1.ld");//Output file name
  // outg->SetFileName("dummy.ld");//Output file name
  // generator->SetOutput(dynamic_cast<TEGOutput*>(outg));

  //construct dummy reaction particle
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");
  pr->SetIsTrack(kFALSE);//don't track this);
  generator->SetReaction(pr);

  //make phase space reaction decay direct to 3 pi+ p
  TEGDecTwoBody* decay1=new TEGDecTwoBody();
  decay1->SetIsWCosTh();
  TEGDistDsigDt* dist1=new TEGDistDsigDt(3.0);  //What is this number? What is the tslope e(-b*t). Can relate to reg traj.https://journals.aps.org/prd/pdf/10.1103/PhysRevD.92.074013
  decay1->SetDistribution((TEGDistribution*)dist1);
//  dist1->SetPhiDist(new TF1("PhotAsym","1-[0]*0.9*cos(2*x)",-TMath::Pi(),TMath::Pi())); //Apply some photon beam asym that can be extracted
  //  dist1->SetPhiDist(new TF1("PhotAsym","1+[0]*0.8*cos(2*x)",1-0.0001,1.0001));
 
  dist1->SetReaction(pr);
  //dist1->SettMin(1);
  //dist1->SettMax(1.5);
  //set decay channel to reaction
  pr->AddDecayChannel(decay1,1);//(decay,branchingratio)
  // add particles to decay
  TEGParticle* pi=decay1->AddProduct(111,"pi0");//a pi+
  pi->SetIsTrack(kTRUE);//don't track this
  TEGParticle* proton=decay1->AddProduct(2212,"proton");
  pr->FixCurrDecay(0);
  
  //decay pi0o
  TEGDecay* decayPi0o=new TEGDecay();
  pi->AddDecayChannel(decayPi0o,1);
  TEGParticle* gamma1o=decayPi0o->AddProduct(22,"gamma1o");
  TEGParticle* gamma2o=decayPi0o->AddProduct(22,"gamma1o");

  //make a target
  TEGParticle *target=new TEGParticle("target",2212,pr);
  //make the beam
  TEGParticle* beam=new TEGParticle("beam",11,NULL);
  beam->SetIsTrack(kFALSE);//don't store beam
  TEGDistribution* distBeam=new TEGDistribution();
  //can create realistic beam characteristics
  //at moment have fixed energy as varying would mean recalculating the 
  //VPhoton distribution each time, can perhaps use foam to make 3D dist 
  distBeam->SetERange(10.6,10.6); // IS this the e beam energy so should give it 10.7?
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
  //if(dynamic_cast<TEGOutGEMC*>(outg))
    gstar->SetIsTrack(kFALSE);//don't track this for GEMC
  //create virtual photon distribution
  TEGDistEScat* vPhot=new TEGDistEScat();
  vPhot->SetE0(10.6); //Should this be the same as e beam energy?
  //vPhot->SetE0(4.000510999);
  vPhot->SetIsScatETh();
  //set ranges
  Double_t Eemin=0.2;//min scattered electron energy  // What is the electron energy detected in the forward tagger?
  Double_t Eemax=6.5;//max scattered electron energy
  vPhot->SetERange(Eemin,Eemax);  //set eprime E range
  Double_t thmin=2.5*TMath::DegToRad(); //min scatter angle convert to rad
  Double_t thmax=10*TMath::DegToRad(); //max scatter angle convert to rad  //just use 10deg for now really it is 4.5 Need to look at ft angle range:https://www.ge.infn.it/~batta/jlab/ft-tdr.2.0.pdf
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
  Double_t Lumin=50./75*1E35; //Copying Adam for current and target size??
  //Double_t Lumin=1E35;
  Double_t rate=cross_sec*f2->Integral(Eemin,Eemax,thmin,thmax)*Lumin*1E-30*2*TMath::Pi();
  //60s*60minute*24hours*24 days.
  Double_t TIME=24*60*60*2*1/32; //seconds  multiplying by 24 gives ~1million
  
  cout<<rate <<" "<<TIME<<" "<<rate*TIME<<endl;
   Int_t NFiles=100;
   // exit(0);

 //Comment out file creation until I have rates and lums. working correctly
  for(Int_t j=0;j<NFiles;j++){
    TEGOutGEMC* outg=new TEGOutGEMC();
    outg->SetFileName(Form("data/Epto_ppi0106GeV_t3_50nA_%d.ld",j));//Output file name
    generator->SetOutput(dynamic_cast<TEGOutput*>(outg));

    for(Int_t i=0;i<rate*TIME/NFiles;i++){
  //for(Int_t i=0;i<100000;i++){
      if(i%1000==0)cout<<"event "<<i<<endl;
      generator->GenerateEvent();
    }
  outg->Close();
  }
  bm->Stop("Epto3pi");
  //   outg->Close();


  cout<<"time "<<bm->GetCpuTime("Epto3pi")<<" real "<<bm->GetRealTime("Epto3pi")
<<endl;
 
}
