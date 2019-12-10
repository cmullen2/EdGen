{
  gSystem->Load("libEG");
  gSystem->Load("libEGGen.so");

  TEGGenerator* generator=new TEGGenerator();
  TBenchmark* bm=new TBenchmark();
  bm->Start("his100");
 

  TEGParticle* pr=new TEGParticle("",11,NULL);
  //TEGDecay* decay1=new TEGDecay();
  TEGDecay* decay1=new TEGDecTwoBody();
  TEGParticle* eprime=decay1->AddProduct(11);
  TEGParticle* gstar=decay1->AddProduct(22);
  decay1->Initialise();
  pr->AddDecayChannel(decay1);

  for(Int_t i=0;i<10;i++){
    cout<<"Mass "<<pr->GetDynamicMass()<<endl;
    pr->SetP4(TLorentzVector(0,0,10.,sqrt(10*10+pr->GetDynamicMass()*pr->GetDynamicMass())));
    pr->Decay();
    cout<<"photon "<<gstar->GetP4()->E()<<" "<<gstar->GetP4()->M2()<<" "<<gstar->GetP4()->Theta()*TMath::RadToDeg()<<endl;
  }
  //pr->Decay();
  //pr->Decay();
  bm->Stop("his100");
  cout<<"time "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
 
}
