{
  gSystem->Load("libTree");
  gSystem->Load("libPhysics");
  gSystem->Load("libEG");
  gSystem->Load("libEGGen.so");

  //TDatabasePDG::Instance()->AddParticle("vphoton","vphoton",-(TDatabasePDG::Instance()->GetParticle(11)->Mass()),true,0,0,"GaugeBoson",-22);
  TEGGenerator* generator=new TEGGenerator();
  TBenchmark* bm=new TBenchmark();
  bm->Start("his100");
  // TEGOutLorentz* outg=new TEGOutLorentz();
  // outg->SetFileName("Lorentz.root");
  // generator->SetOutput((TEGOutput*)outg);
  /////////  // outg->SetGenerator(generator);
  TEGOutAll* outg=new TEGOutAll();
  outg->SetFileName("OutAll.root");
  generator->SetOutput((TEGOutput*)outg);
  // // TEGOutGEMC* outg=new TEGOutGEMC();
  // // outg->SetFileName("InElastic_elonly.ld");
  // // generator->SetOutput(dynamic_cast<TEGOutput*>(outg));
  // // outg->SetGenerator(generator);
  //TEGElectroReaction* pr=new TEGElectroReaction("Reaction");//Rootino
  TEGParticle* pr=new TEGParticle("Reaction");//Rootino
  pr->SetIsTrack(kFALSE);
  generator->SetReaction(pr);
  //TEGDecay* decay1=new TEGDecay();
  TEGDecay* decay1=new TEGDecay();
  TEGParticle* pi0=decay1->AddProduct(111);
  TEGParticle* pip=decay1->AddProduct(211);
  TEGParticle* pim=decay1->AddProduct(-211);
  TEGParticle* proton=decay1->AddProduct(2212);
  //proton->SetIsTrack(kFALSE);
  proton->SetName("proton");
  //TEGDistribution* d1=new TEGDistribution();
  //decay1->SetDistribution(d1);
  pi0->SetName("pi0");
  pi0->SetPDGDecays();
  pi0->SetForceDecay(0);
  pip->SetName("pip");
  pim->SetName("pim");
  pi0->Initialise();
  proton->Initialise();
  pim->Initialise();
  pip->Initialise();
  pr->AddDecayChannel(decay1);
  pr->FixCurrDecay(0);

  TEGParticle *target=new TEGParticle("target",2212,pr);

  // pr->SetInitial1(beam);
  // pr->SetInitial2(target);
  // dist1->SetReaction(pr);// t dist needs intial1 to get pointer to gamma
   

  //open adams file
  ifstream infile("events.db"); 
  Double_t lvec[4];
  Double_t gammapol[2];
  TLorentzVector tlvec(0,0,1,1);
  // while(!infile.eof())
  for(Int_t i=0;i<100;i++){
    infile>>gammapol[0]>>gammapol[1];
    infile>>lvec[0]>>lvec[1]>>lvec[2]>>lvec[3];//gamma
    infile>>lvec[0]>>lvec[1]>>lvec[2]>>lvec[3];//proton;
    tlvec->SetXYZT(lvec[0],lvec[1],lvec[2],lvec[3]);
    cout<<"Proton "<<tlvec.X()<<" "<<tlvec.Y()<<" "<<tlvec.Z()<<" "<<tlvec.T()<<" "<<endl;
    proton->SetP4(tlvec);
    infile>>lvec[0]>>lvec[1]>>lvec[2]>>lvec[3];//pi-;
    tlvec->SetXYZT(lvec[0],lvec[1],lvec[2],lvec[3]);
    pim->SetP4(tlvec);
    infile>>lvec[0]>>lvec[1]>>lvec[2]>>lvec[3];//pip;
    tlvec->SetXYZT(lvec[0],lvec[1],lvec[2],lvec[3]);
    pip->SetP4(tlvec);
    infile>>lvec[0]>>lvec[1]>>lvec[2]>>lvec[3];//pi0;
    tlvec->SetXYZT(lvec[0],lvec[1],lvec[2],lvec[3]);
    cout<<"Pi0 "<<tlvec.X()<<" "<<tlvec.Y()<<" "<<tlvec.Z()<<" "<<tlvec.T()<<" "<<endl;
    pi0->SetP4(tlvec);
    pi0->Decay();
    generator->FillEvent();
    generator->SaveEvent();

  }
  infile.close();
  //pr->Decay();
  //pr->Decay();
  bm->Stop("his100");
  outg->Close();
  cout<<"time "<<bm->GetCpuTime("his100")<<" real "<<bm->GetRealTime("his100")
<<endl;
 
}
