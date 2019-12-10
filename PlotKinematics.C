// #include "TFile.h"
// #include "TTree.h"
// #include "TClonesArray.h"
gSystem->Load("/home/dglazier/clas12/root_fastmc/libFastMC.so");

TNtuple* PlotKinematics(TString filename,TString tag="_data",Int_t Nout=0){
  //Open file and get tree
  TFile* file=new TFile(filename);
  //  TTree* tree=(TTree*)file->Get("kin");
  TTree* tree=(TTree*)file->Get("Reaction_Kinematics");
  //for basic  particles
  // tree->Draw("P4[2].Theta()*TMath::RadToDeg()");//etc
  
  //for higher level reconstruction need to loop
  //make pointers to the input branches
  TClonesArray *P4s=NULL;
  TClonesArray *Vertices=NULL;
  // Int_t pdgs[]={22,2212,211,-211,211};
  Int_t *pdgs=NULL;
  Int_t Np;
  tree->SetBranchAddress("P4",&P4s);
  //tree->SetBranchAddress("Vertex",&Vertices);
  tree->SetBranchAddress("Np",&Np);
  //  tree->SetBranchAddress("nPart",&Np);
  // tree->SetBranchAddress("pdg",pdgs);


   TNtuple *outnt=new TNtuple("plotter","plotter","M3pi:Mmiss:t:phRes:thRes:thGJ:phGJ:alpha:Miso:Q2:omega:thetae");
  TLorentzVector* lv=NULL;
  Int_t pdg=0;

  TLorentzVector pia;
  TLorentzVector pib;
  TLorentzVector pim;
  TLorentzVector proton;
  TLorentzVector neutron;
  TLorentzVector target(0,0,0,0.938);
  TLorentzVector beam;
  TLorentzVector scat;
  TLorentzVector phot;
  TLorentzVector X;
  TLorentzVector isobar;
  TLorentzVector temp4;
  TVector3 Xboost;
  TVector3 GJY;
  TVector3 temp3;
  TVector3 labX;
 //loop over events in tree
  for(Int_t i=0;i<tree->GetEntries();i++){
  //for(Int_t i=0;i<10;i++){
     tree->GetEntry(i);
     lv=((TLorentzVector*)P4s->At(5));
     phot.SetXYZT(lv->X(),lv->Y(),lv->Z(),lv->T());  
     lv=((TLorentzVector*)P4s->At(3));
     proton.SetXYZT(lv->X(),lv->Y(),lv->Z(),lv->T());  
     lv=((TLorentzVector*)P4s->At(0));
     pia.SetXYZT(lv->X(),lv->Y(),lv->Z(),lv->T());  
     lv=((TLorentzVector*)P4s->At(1));
     pim.SetXYZT(lv->X(),lv->Y(),lv->Z(),lv->T());  
     lv=((TLorentzVector*)P4s->At(2));
     pib.SetXYZT(lv->X(),lv->Y(),lv->Z(),lv->T());  
     lv=((TLorentzVector*)P4s->At(4));
     scat.SetXYZT(lv->X(),lv->Y(),lv->Z(),lv->T());  
     // cout<<beam.M()<<" "<<proton.M()<<" "<<pia.M()<<" "<<pim.M()<<" "<<pib.M()<<scat.M()<<endl;
     //  phot=beam-scat;

     //now analyse
     //invariant mass
     X=pia+pib+pim;
     Double_t M3pi=X.M();
     //missing mass
    //missing mass
     neutron=target+phot-X;
     Double_t Mmiss=neutron.M();
     //t
     temp4=phot-X;
     Double_t t=-temp4.M2();
     //isobar
     isobar=pia+pim;
     Double_t Miso=isobar.M();
     //some angles
     //some angles
     Xboost=X.BoostVector();
     TLorentzRotation resBoost(-Xboost);
     TLorentzVector resBeam=resBoost*phot;//boost to X rest frame, now z-axis in GJ frame
     TLorentzVector resNeut=resBoost*neutron;//boost to X rest frame, now z-axis in GJ frame
     TLorentzVector respib=resBoost*pib;
     
     TVector3 zRes = -resNeut.Vect().Unit();
     //TVector3 zRes = resBeam.Vect().Unit();
     TVector3 yRes = resBeam.Vect().Cross(zRes).Unit();
     TVector3 xRes = yRes.Cross(zRes);
     
     TVector3 anglesRes( (respib.Vect()).Dot(xRes),
			 (respib.Vect()).Dot(yRes),
                        (respib.Vect()).Dot(zRes) );
         
     Double_t phiRes=anglesRes.Phi()*TMath::RadToDeg();
     Double_t thRes=anglesRes.Theta()*TMath::RadToDeg();
     
     TVector3 Yscat=(phot.Vect().Cross(scat.Vect())).Unit();
     X.RotateZ(Yscat.Phi());
   // Double_t Xphi=X.Phi()*TMath::RadToDeg();
     //  Double_t Xtheta=X.Theta()*TMath::RadToDeg();
     GJY=phot.Vect().Cross(X.Vect());
     //   cout<<GJY.X()<<" "<<GJY.Y()<<" "<<GJY.Z()<<" "<<endl;
     
     //temp3=X.Vect().Cross(labX);
      // TVector3 YX=(phot.Vect().Cross(X.Vect())).Unit();
     Double_t alpha=X.Phi()*TMath::RadToDeg();
     Xboost=X.BoostVector();
     beam.Boost(-Xboost);//boost to X rest frame, now z-axis in GJ frame
     pib.Boost(-Xboost);
     // GJY=beam.Vect().Cross(X.Vect());
     //cout<<GJY.X()<<" "<<GJY.Y()<<" "<<GJY.Z()<<" "<<endl;
     Double_t thGJ=phot.Vect().Angle(pib.Vect())*TMath::RadToDeg();
     Double_t phGJ=GJY.DeltaPhi(pib.Vect())*TMath::RadToDeg();
     
     
     outnt->Fill(M3pi,Mmiss,t,phiRes,thRes,thGJ,phGJ,alpha,Miso,-phot.M2(),phot.E(),scat.Theta()*TMath::RadToDeg());
  }

  return outnt;
}
