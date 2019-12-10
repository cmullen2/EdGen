void LoadCrossSection(TString cfName){
  ifstream infile(cfName.Data()); 
  //first line is setup
  Double_t E0,Elow,Eup,Est,Thlow,Thup,Thst;
  Int_t nE,nTh;
  //some input file have nE and nTh incuded so need to use different read
  infile>>E0>>Elow>>Eup>>Est>>Thlow>>Thup>>Thst;
  //infile>>E0>>Elow>>Eup>>Est>>Thlow>>Thup>>Thst>>nE>>nTh;
  Elow=Elow;//incusive programme run with small offset
  cout<<nE<<" "<<nTh<<endl;
  nE=(Eup-Elow)/Est+1;
  nTh=(Thup-Thlow)/Thst+1;
  cout<<E0<<" "<<Elow<<" "<<Eup<<" "<<Est<<" "<<Thlow<<" "<<Thup<<" "<<Thst<<" "<<nE<<" "<<nTh<<" "<<endl;
  //Construct csHistograms
  Thlow=Thlow*TMath::DegToRad();
  Thup=Thup*TMath::DegToRad();
  Thst=Thst*TMath::DegToRad();
  TH2F* hin=new TH2F("hin","hin",nE,Elow-Est/2,Eup+Est/2,nTh,Thlow-Thst/2,Thup+Thst/2);
  TH2F* htot=new TH2F("htot","htot",nE,Elow-Est/2,Eup+Est/2,nTh,Thlow-Thst/2,Thup+Thst/2);
  TH2F* hinrad=new TH2F("hinrad","hinrad",nE,Elow-Est/2,Eup+Est/2,nTh,Thlow-Thst/2,Thup+Thst/2);
  TH2F* hrad=new TH2F("hrad","hrad",nE,Elow-Est/2,Eup+Est/2,nTh,Thlow-Thst/2,Thup+Thst/2);
  //The next are the diffrential cross sections
  Double_t E,Th,sig_in,sig_tot,sig_inrad;
 
   while(!infile.eof())
    {
      infile >> Th>>E>>sig_in>>sig_tot>>sig_inrad;            
      //cout<<" "<< Th<<" "<<E<<" "<<sig_in<<" "<<sig_tot<<" "<<sig_inrad<<endl ;
      if(sig_tot>10*htot->GetBinContent(htot->FindBin(E-Est,Th*TMath::DegToRad()))&&E>0.101)E=(htot->FindBin(E-Est,Th*TMath::DegToRad()));//cout<<" "<< Th<<" "<<E<<" "<<sig_in<<" "<<sig_tot<<" "<<sig_inrad<<endl ;
      if(infile.eof())break;
      hin->Fill(E,Th*TMath::DegToRad(),sig_in);
      htot->Fill(E,Th*TMath::DegToRad(),sig_tot);
      hinrad->Fill(E,Th*TMath::DegToRad(),sig_inrad);
      hrad->Fill(E,Th*TMath::DegToRad(),sig_tot-sig_inrad);
      //break;
     }
  infile.close();

  TFile* fout=new TFile(cfName+TString(".root"),"recreate");

  hin->Write();
  htot->Write();
  hinrad->Write();
  hrad->Write();
  fout->Close();
}
