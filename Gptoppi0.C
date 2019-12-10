{
  gSystem->Load("libEG");
  gSystem->Load("libEGGen.so");

  TEGGenerator* generator=new TEGGenerator();
  TBenchmark* bm=new TBenchmark();
  bm->Start("his100");
 

  TEGParticle* pr=new TEGParticle("",0,NULL);//Rootino
  //TEGDecay* decay1=new TEGDecay();
  TEGDecay* decay1=new TEGDecTwoBody();
  TEGParticle* pi0=decay1->AddProduct(211);
  TEGParticle* proton=decay1->AddProduct(2212);
  TEGDistDsigDOmega* dist1=new TEGDistDsigDOmega();
  //  TEGDistDsigDt* dist1=new TEGDistDsigDt();
  TF2* func=new TF2("ff","x+y+2",1.90038,1.90039,0.9,1);//need some gap between limits so an integral can be calculated
  dist1->SetDistribution(func);
  decay1->SetDistribution((TEGDistribution*)dist1);
  pr->AddDecayChannel(decay1);
  decay1->Initialise();

  TLorentzVector target(0,0,0,proton->GetP4()->M());
  Double_t Eb=1;
  TLorentzVector beam(0,0,Eb,Eb);
  //  beam.RotateX(10*TMath::DegToRad());
  //Beam distribution
  TEGDistribution* distBeam=new TEGDistribution();
  TF1* beamCosTh=new TF1("beamCosTh","gaus(0)",0.9999975,1);
  beamCosTh->SetParameters(1,1.0,0.000001);
  distBeam->SetCosThDist(beamCosTh);

  for(Int_t i=0;i<1;i++){
    //get beam direction
    distBeam->GenerateRandom();
    beam->SetTheta(distBeam->GetTheta());
    beam->SetPhi(distBeam->GetPhi());

    //Now reaction mass and pi0 CMangle
    dist1->GenerateRandom();
    Double_t Egamma=((dist1->GetM()*dist1->GetM()-target.M2())/2/target.M());
    beam->SetE(Egamma);
    beam->SetRho(Egamma);
    TLorentzVector total=beam+target;
    pr->SetP4(total);
    cout<<"Mass "<<beam.M()<<" "<<pr->GetDynamicMass()<<" "<<pr->GetP4()->E()<<" "<<pr->GetP4()->Rho()<<" "<<dist1->GetM()<<" egamma "<<Egamma<<endl;

    if(pr->Decay()==kFALSE)continue;

    cout<<"photon "<<proton->GetP4()->E()<<" "<<proton->GetP4()->M()<<" "<<proton->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    cout<<"pi0 "<<pi0->GetP4()->E()<<" "<<pi0->GetP4()->M()<<" "<<pi0->GetP4()->Theta()*TMath::RadToDeg()<<endl;
    TLorentzVector out=*(pi0->GetP4())+*(proton->GetP4());
    cout<<"out "<<out.M()<<" "<<out.E()<<" "<<out.Rho()<<" "<<out.Theta()*TMath::RadToDeg()<<endl;
  }
  //pr->Decay();
  //pr->Decay();
  bm->Stop("his100");
  cout<<"time "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
 
}
