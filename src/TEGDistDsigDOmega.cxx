#include "TEGDistDsigDOmega.h"
#include "TEGGenerator.h"
#include "TAxis.h"

ClassImp(TEGDistDsigDOmega)

TEGDistDsigDOmega::TEGDistDsigDOmega():TEGDistribution(){
  f2Dist=NULL;
  fH2Dist=NULL;
  fIsM=kFALSE;
  fIsE=kFALSE;
}
TEGDistDsigDOmega::~TEGDistDsigDOmega(){
  if(fH2Dist) delete f2Dist; //TH2 used to create TF2
 
}
void TEGDistDsigDOmega::Initialise(){
  if(fMMin!=fMMax)fIsM=kTRUE;
  if(fEMin!=fEMax)fIsE=kTRUE;
  if(fIsM&&fIsE){cerr<<"TEGDistDsigDOmega::Initialise() is both E and M, meed to switch of SetRange for either"<<endl;exit(0);}
  if(!f2Dist&&!fH2Dist){cerr<<"TEGDistDsigDOmega::Initialise no distribution supplied"<<endl;exit(0);}
  //Set ranges
  if(fThetaMin==0&&fThetaMax==TMath::Pi()){//default so take function range
    if(f2Dist){
      SetThetaRange(f2Dist->GetYmin(),f2Dist->GetYmax());
    }
    // if(fH2Dist){
    //   SetThetaRange(fH2Dist->GetYaxis()->GetBinLowEdge(1),fH2Dist->GetYaxis()->GetBinUpEdge(fH2Dist->GetNbinsY()));
    // }
  }
  else {//make sure in range of function
    if(f2Dist){
      if(fThetaMin<f2Dist->GetYmin())fThetaMin=f2Dist->GetYmin();
      if(fThetaMax>f2Dist->GetYmax())fThetaMax=f2Dist->GetYmax(); 
    }
    // if(fH2Dist){
    //   if(fThetaMin<fH2Dist->GetYaxis()->GetBinLowEdge(1))fThetaMin=fH2Dist->GetYaxis()->GetBinLowEdge(1);
    //   if(fThetaMax>fH2Dist->GetYaxis()->GetBinUpEdge(fH2Dist->GetNbinsY()))fThetaMax=fH2Dist->GetYaxis()->GetBinUpEdge(fH2Dist->GetNbinsY());
    // }
    SetThetaRange(fThetaMin,fThetaMax);//recalc cos limits
  }
  if(f2Dist&&fIsE)f2Dist->SetRange(fEMin,fThetaMin,fEMax,fThetaMax);
  if(f2Dist&&fIsM)f2Dist->SetRange(fMMin,fThetaMin,fMMax,fThetaMax);
  // if(fH2Dist&&fIsE){
  //   fH2Dist->GetXaxis()->SetRangeUser(fEMin,fEMax);
  //   fH2Dist->GetYaxis()->SetRangeUser(fThetaMin,fThetaMax);
  // }
  // if(fH2Dist&&fIsM){
  //   fH2Dist->GetXaxis()->SetRangeUser(fMMin,fMMax);
  //   fH2Dist->GetYaxis()->SetRangeUser(fThetaMin,fThetaMax);
  // }
  if(fIsM) cout<<"TEGDistDsigDOmega::Initialise() mass dist "<<
	    "Mass range "<<fMMin<<"-"<<fMMax<<
	    "Theta range "<<fThetaMin*TMath::RadToDeg()<<"-"<<fThetaMax*TMath::RadToDeg()<<endl;
  if(fIsE) cout<<"TEGDistDsigDOmega::Initialise() energy dist "<<
	    "Energy range "<<fEMin<<"-"<<fEMax<<
	    "Theta range "<<fThetaMin*TMath::RadToDeg()<<"-"<<fThetaMax*TMath::RadToDeg()<<endl;
}
void TEGDistDsigDOmega::GenerateRandom(){
  if(fIsM)GenerateRandomM();
  if(fIsE)GenerateRandomE();
}
void TEGDistDsigDOmega::GenerateRandomM(){
  //invariant mass and cos theta from distribution
  if(f2Dist)f2Dist->GetRandom2(fM,fCosTh);
  else if(fH2Dist)fH2Dist->GetRandom2(fM,fCosTh);
  //default random phi
  fPhi=TEGDistribution::GeneratePhi();
  // cout<<"TEGDistDsigDOmega::GenerateRandomM() "<<fM<<" "<<fCosTh<<" "<<fPhi<<endl;
}
void TEGDistDsigDOmega::GenerateRandomE(){
  //invariant mass and cos theta from distribution
  if(f2Dist)f2Dist->GetRandom2(fE,fTheta);
  else if(fH2Dist)fH2Dist->GetRandom2(fE,fTheta);
  //default random phi
  fPhi=TEGDistribution::GeneratePhi();
  // cout<<"TEGDistDsigDOmega::GenerateRandomE() "<<fE<<" "<<fTheta*TMath::RadToDeg()<<" "<<fPhi*TMath::RadToDeg()<<endl; 
}
