{
  gSystem->Load("libEG");
  gSystem->Load("libEGGen.so");

  TEGGenerator* generator=new TEGGenerator();
  TBenchmark* bm=new TBenchmark();
  bm->Start("his100");
 

  TEGPhotoReaction* pr=new TEGPhotoReaction("Reaction");//Rootino
  //TEGDecay* decay1=new TEGDecay();
  TEGDecTwoBody* decay1=new TEGDecTwoBody();
  TEGParticle* pi0=decay1->AddProduct(211);
  TEGParticle* proton=decay1->AddProduct(2212);
  //TEGDistDsigDOmega* dist1=new TEGDistDsigDOmega();
  // TF2* func=new TF2("ff","x+y+2",1.90038,1.90039,0.9,1);//need some gap between limits so an integral can be calculated
  //dist1->Set2Distribution(func);
  TEGDistDsigDt* dist1=new TEGDistDsigDt();
  dist1->SetMRange(3,4);
  decay1->SetDistribution((TEGDistribution*)dist1);
  pr->AddDecayChannel(decay1);
  decay1->SetIsWCosTh();
  decay1->Initialise();

  TEGParticle* beam=new TEGParticle("beam",22,pr);
  TEGDistribution* distBeam=new TEGDistribution();
  TF1* beamCosTh=new TF1("beamCosTh","gaus(0)",0.9999975,1);
  beamCosTh->SetParameters(1,1.0,0.000001);
  //  distBeam->SetCosThDist(beamCosTh);
  distBeam->SetERange(7.5,7.6);
  distBeam->SetThetaRange(85,86);
  //TEGDecay* beamDec=new TEGDecay();
  //TEGParticle* gstar=decay1->AddProduct(22);
  //TEGParticle* proton=decay1->AddProduct(11);
  beam->SetDistribution(distBeam);
  //beam->AddDecayChannel(beamDec);
  //beamDec->Initialise();
  TEGParticle *target=new TEGParticle("target",2212,pr);

  pr->SetInitial1(beam);
  pr->SetInitial2(target);
  dist1->SetReaction(pr);//needs intial1 to get gamma
 
  for(Int_t i=0;i<10;i++){
    if(pr->Decay()==kFALSE)continue;
    cout<<"beam "<<beam->GetP4()->E()<<" "<<beam->GetP4()->M()<<" "<<beam->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    cout<<"target "<<target->GetP4()->E()<<" "<<target->GetP4()->M()<<" "<<target->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    cout<<"proton "<<proton->GetP4()->E()<<" "<<proton->GetP4()->M()<<" "<<proton->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    cout<<"pi0 "<<pi0->GetP4()->E()<<" "<<pi0->GetP4()->M()<<" "<<pi0->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    TLorentzVector in=*(beam->GetP4())+*(target->GetP4());
    TLorentzVector out=*(pi0->GetP4())+*(proton->GetP4());
    cout<<"in "<<out.M()<<" "<<out.E()<<" "<<out.Rho()<<" "<<out.Theta()*TMath::RadToDeg()<<endl;
    cout<<"out "<<out.M()<<" "<<out.E()<<" "<<out.Rho()<<" "<<out.Theta()*TMath::RadToDeg()<<endl;
  }
  //pr->Decay();
  //pr->Decay();
  bm->Stop("his100");
  cout<<"time "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
 
}
