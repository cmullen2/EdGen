{
 
  TEGGenerator* generator=new TEGGenerator();
  TBenchmark* bm=new TBenchmark();
  bm->Start("his100");
  // TEGOutLorentz* outg=new TEGOutLorentz();
  // outg->SetFileName("Wthe.root");
  // generator->SetOutput((TEGOutput*)outg);
  // outg->SetGenerator(generator);
  TEGElectroReaction* pr=new TEGElectroReaction("Reaction");//Rootino
  generator->SetReaction(pr);
  TEGDecay* decay1=new TEGDecay();
  TEGParticle* proton=decay1->AddProduct(2212);
  pr->AddDecayChannel(decay1,1);//(decay,branchingratio)

  TEGParticle* beam=new TEGParticle("beam",11,NULL);
  TEGDistribution* distBeam=new TEGDistribution();
  distBeam->SetERange(2.2,2.2);
  distBeam->SetE(2.2);
  distBeam->SetThetaRange(0,0.000);
  beam->SetDistribution(distBeam);

  TEGDecay* beamDec=new TEGDecay();
  TEGParticle* eprime=beamDec->AddProduct(11);
  TEGParticle* gstar=beamDec->AddProduct(0);
  eprime->SetName("eprime");
  gstar->SetName("gstar");
  TEGDistEScat* eScat=new TEGDistEScat();
  // eScat->SetIsWThe();
  // eScat->SetE(11);
  // eScat->SetMRange(1,6);
  // eScat->SetThetaRange(2,7);
  eScat->SetIsScatETh();
  eScat->SetE(2.2);
  eScat->SetE0(2.2);
  eScat->SetERange(0.05,2);
  eScat->SetThetaRange(2*TMath::DegToRad(),5*TMath::DegToRad());
  beamDec->SetDistribution(eScat);
  beam->AddDecayChannel(beamDec);
  beamDec->Initialise();
  eScat->Initialise();

  TEGParticle *target=new TEGParticle("target",2212,pr);

  pr->SetInitial1(beam);
  pr->SetInitial2(target);
  //dist1->SetReaction(pr);// t dist needs intial1 to get pointer to gamma

  TF2* f2=eScat->Get2Distribution();
  //cout<<"Rate "<<f2->Integral(0.05,4,2*TMath::DegToRad(),5*TMath::DegToRad())*2*TMath::Pi<<endl;

  for(Int_t i=0;i<10000;i++){
    generator->GenerateEvent();
    cout<<"beam "<<beam->GetP4()->E()<<" "<<beam->GetP4()->M()<<" "<<beam->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    cout<<"target "<<target->GetP4()->E()<<" "<<target->GetP4()->M()<<" "<<target->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    cout<<"eprime "<<eprime->GetP4()->E()<<" "<<eprime->GetP4()->M()<<" "<<eprime->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    cout<<"gstar "<<gstar->GetP4()->E()<<" "<<gstar->GetP4()->M()<<" "<<gstar->GetP4()->Theta()*TMath::RadToDeg()<<endl;
     cout<<"proton "<<proton->GetP4()->E()<<" "<<proton->GetP4()->Rho()<<" "<<proton->GetP4()->M()<<" "<<proton->GetP4()->Theta()*TMath::RadToDeg()<<endl;
     // cout<<"pi0 "<<pi0->GetP4()->E()<<" "<<pi0->GetP4()->Rho()<<" "<<pi0->GetP4()->M()<<" "<<pi0->GetP4()->Theta()*TMath::RadToDeg()<<endl;
     TLorentzVector in=*(beam->GetP4())+*(target->GetP4());
     TLorentzVector out=*(eprime->GetP4())+*(proton->GetP4());
     cout<<"in "<<out.M()<<" "<<out.E()<<" "<<out.Rho()<<" "<<out.Theta()*TMath::RadToDeg()<<endl;
    //cout<<"out "<<out.M()<<" "<<out.E()<<" "<<out.Rho()<<" "<<out.Theta()*TMath::RadToDeg()<<endl;
  }
  //pr->Decay();
  //pr->Decay();
  bm->Stop("his100");
  outg->Close();
  cout<<"time "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
 
}
