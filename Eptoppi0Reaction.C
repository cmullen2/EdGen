{
  gSystem->Load("libTree");
  gSystem->Load("libPhysics");
  gSystem->Load("libEG");
  gSystem->Load("libEGGen.so");

  TDatabasePDG::Instance()->AddParticle("vphoton","vphoton",-(TDatabasePDG::Instance()->GetParticle(11)->Mass()),true,0,0,"GaugeBoson",-22);
  TEGGenerator* generator=new TEGGenerator();
  TBenchmark* bm=new TBenchmark();
  bm->Start("his100");
  TEGOutLorentz* outg=new TEGOutLorentz();
  outg->SetFileName("AllDecayKinRestart.root");
  generator->SetOutput((TEGOutput*)outg);
  outg->SetGenerator(generator);
  // // TEGOutGEMC* outg=new TEGOutGEMC();
  // // outg->SetFileName("InElastic_elonly.ld");
  // // generator->SetOutput(dynamic_cast<TEGOutput*>(outg));
  // // outg->SetGenerator(generator);
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");//Rootino
  pr->SetIsTrack(kFALSE);
  generator->SetReaction(pr);
  //TEGDecay* decay1=new TEGDecay();
  TEGDecTwoBody* decay1=new TEGDecTwoBody();
  TEGParticle* pi0=decay1->AddProduct(113);
  //pi0->SetIsTrack(kFALSE);
  TEGParticle* proton=decay1->AddProduct(2212);
  //proton->SetIsTrack(kFALSE);
  proton->SetName("proton");
  //TEGDistribution* d1=new TEGDistribution();
  //decay1->SetDistribution(d1);
  pi0->SetName("rho");
  pi0->SetPDGDecays();
  pi0->SetForceDecay(0);
  pi0->Initialise();
  // TEGDistDsigDOmega* dist1=new TEGDistDsigDOmega();
  //TF2* func=new TF2("ff","x+y+2",1.90038,1.90039,0.9,1);//need some gap between limits so an integral can be calculated
  //dist1->Set2Distribution(func);
  TEGDistDsigDt* dist1=new TEGDistDsigDt();
  ////dist1->SetMRange(3,4);
  decay1->SetDistribution((TEGDistribution*)dist1);
  pr->AddDecayChannel(decay1);
  decay1->SetIsWCosTh();
  decay1->Initialise();

  TEGParticle* beam=new TEGParticle("beam",11,NULL);
  beam->SetIsTrack(kFALSE);
  TEGDistribution* distBeam=new TEGDistribution();
  distBeam->SetERange(11,11);
  distBeam->SetE(11);
  distBeam->SetThetaRange(0,0.000);
  beam->SetDistribution(distBeam);

  TEGDecTwoBody* beamDec=new TEGDecTwoBody();
  beamDec->SetIsE1Theta1();
  TEGParticle* eprime=beamDec->AddProduct(11);
  TEGParticle* gstar=beamDec->AddProduct(-22);
  eprime->SetName("eprime");
  gstar->SetName("gstar");
  gstar->SetIsTrack(kFALSE);
  TEGDistDsigDOmega* eScat=new TEGDistDsigDOmega();
  //TFile* csf=new TFile("EScat/EscatSigma.root");
  TFile* csf=new TFile("EScat/inclE0.1_10.9_Th0.5_9.db.root");
  TH2F* hin=(TH2F*)csf->Get("hin");
  eScat->Set2Distribution(hin);
  eScat->SetERange(0.5,4);
  eScat->SetThetaRange(2*TMath::DegToRad(),5*TMath::DegToRad());
  beamDec->SetDistribution(eScat);

  // TEGDecay* beamDec=new TEGDecay();
  // TEGParticle* eprime=beamDec->AddProduct(11);
  // TEGParticle* gstar=beamDec->AddProduct(0);
  // eprime->SetName("eprime");
  // gstar->SetName("gstar");
  // TEGDistEScat* eScat=new TEGDistEScat();
  //eScat->SetE0(11.000510999);
  // eScat->SetIsWThe();
  // eScat->SetE0(11.000510999);
  // eScat->SetMRange(1,6);
  // eScat->SetThetaRange(2,7);
  // eScat->SetIsScatETh();
  // eScat->SetE0(11.000510999);
  // eScat->SetERange(0.0,10.5);
  // eScat->SetThetaRange(2,7);
  // eScat->SetIsElastic();
  // eScat->SetE(11.000510999);
  // //eScat->SetERange(0.0,10.5);
  // eScat->SetThetaRange(2,70);
  beamDec->SetDistribution(eScat);
  beam->AddDecayChannel(beamDec);
  beamDec->Initialise();
  //eScat->Initialise();

  TEGParticle *target=new TEGParticle("target",2212,pr);

  pr->SetInitial1(beam);
  pr->SetInitial2(target);
  dist1->SetReaction(pr);// t dist needs intial1 to get pointer to gamma
   
  TF2* f2=eScat->Get2Distribution();
  f2->SetNpx(1000);
  // cout<<"Rate "<<f2->Integral(0.3,10.8,2*TMath::DegToRad(),5*TMath::DegToRad())*1E35*1E-30*2*TMath::Pi()<<endl;
  //return;
  Double_t Nevents=f2->Integral(0.5,4,2*TMath::DegToRad(),5*TMath::DegToRad())*1E35*1E-30*2*TMath::Pi();
  for(Int_t i=0;i<Nevents;i++){
    //for(Int_t i=0;i<200000;i++){
    generator->GenerateEvent();
    // cout<<"beam "<<beam->GetP4()->E()<<" "<<beam->GetP4()->M()<<" "<<beam->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    // cout<<"target "<<target->GetP4()->E()<<" "<<target->GetP4()->M()<<" "<<target->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    // cout<<"eprime "<<eprime->GetP4()->E()<<" "<<eprime->GetP4()->M()<<" "<<eprime->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    // cout<<"gstar "<<gstar->GetP4()->E()<<" "<<gstar->GetP4()->M()<<" "<<gstar->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    //  cout<<"proton "<<proton->GetP4()->E()<<" "<<proton->GetP4()->Rho()<<" "<<proton->GetP4()->M()<<" "<<proton->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    //  cout<<"pi0 "<<pi0->GetP4()->E()<<" "<<pi0->GetP4()->Rho()<<" "<<pi0->GetP4()->M()<<" "<<pi0->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    TLorentzVector in=*(beam->GetP4())+*(target->GetP4());
    //    TLorentzVector out=*(pi0->GetP4())+*(proton->GetP4());
    TLorentzVector out=*(eprime->GetP4())+*(pi0->GetP4())+*(proton->GetP4());
    // cout<<"in "<<out.M()<<" "<<out.E()<<" "<<out.Rho()<<" "<<out.Theta()*TMath::RadToDeg()<<endl;
    // cout<<"out "<<out.M()<<" "<<out.E()<<" "<<out.Rho()<<" "<<out.Theta()*TMath::RadToDeg()<<endl;
  }
  //pr->Decay();
  //pr->Decay();
  bm->Stop("his100");
  outg->Close();
  cout<<"time "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
 
}
