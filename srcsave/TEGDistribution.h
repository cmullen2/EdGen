#ifndef __TEGDistribution_h__
#define __TEGDistribution_h__
//used by TEGDecay classes to produce random numbers
//This top level class uses 1D distributions for energy and angles.

#include "Riostream.h"
#include "TRandom3.h"
#include "TF1.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TEGGenerator.h"

class TEGDistribution  {
 
 protected:
 
  Double_t fTheta; //return an angle
  Double_t fThetaMax;
  Double_t fThetaMin;
  Double_t fCosTh; //return an angle
  Double_t fCosThMin;
  Double_t fCosThMax;
  Double_t fPhi;   //return an azimuthal angle
  Double_t fPhiMax;   
  Double_t fPhiMin;   
  Double_t fE;     //return an energy (or p)
  Double_t fEMax; 
  Double_t fEMin; 
  Double_t fM;     //return a mass
  Double_t fMMax; 
  Double_t fMMin; 

  TF1* fThetaDist; //1D(uncorrelated) theta dist
  TF1* fCosThDist; //1D(uncorrelated) cos(theta) dist
  TF1* fPhiDist;//1D(uncorrelated) phi dist
  TF1* fEDist;//1D(uncorrelated) E dist
  TF1* fMDist;//1D(uncorrelated) M dist

  TLorentzVector* fP4; //possible random 4 vector
 public:
  TEGDistribution( );
  virtual ~TEGDistribution();

  virtual void GenerateRandom();
  virtual void Initialise(){};

  virtual Double_t GenerateTheta(){
    // if(fThetaDist||fCosThDist)return fTheta;
    if(fThetaDist){fTheta=fThetaDist->GetRandom(fThetaMin,fThetaMax);fCosTh=TMath::Cos(fTheta);}
    else if(fCosThDist){fCosTh=fCosThDist->GetRandom(fCosThMin,fCosThMax);fTheta=TMath::ACos(fCosTh);}
    else {fCosTh=gEGRandom->Uniform(fCosThMin,fCosThMax);fTheta=TMath::ACos(fCosTh);}
    
    return fTheta;
  }
 virtual Double_t GeneratePhi(){
    if(fPhiDist)fPhi=fPhiDist->GetRandom(fPhiMin,fPhiMax);
    else fPhi=gEGRandom->Uniform(fPhiMin,fPhiMax);
    return fPhi;
  }
  virtual Double_t GenerateE(){
    if(fEDist)fE=fEDist->GetRandom(fEMin,fEMax);
    else  fE=gEGRandom->Uniform(fEMin,fEMax);
    return fE;
  }
  virtual Double_t GenerateM(){
    if(fMDist)fM=fMDist->GetRandom(fMMin,fMMax);
    else  fM=gEGRandom->Uniform(fMMin,fMMax);
    return fM;
  }


  void SetThetaDist(TF1* dist){fThetaDist=dist;fThetaDist->GetRange(fThetaMin,fThetaMax);}
  void SetCosThDist(TF1* dist){fCosThDist=dist;fCosThDist->GetRange(fCosThMin,fCosThMax);}
  void SetPhiDist(TF1* dist){fPhiDist=dist;fPhiDist->GetRange(fPhiMin,fPhiMax);}
  void SetEDist(TF1* dist){fEDist=dist;fEDist->GetRange(fEMin,fEMax);}
  void SetMDist(TF1* dist){fMDist=dist;fMDist->GetRange(fMMin,fMMax);}
  TF1* GetThetaDist(){return fThetaDist;}
  TF1* GetCosThDist(){return fCosThDist;}
  TF1* GetPhiDist(){return fPhiDist;}
  TF1* GetEDist(){return fEDist;}
  TF1* GetMDist(){return fMDist;}

  Bool_t InERange(Double_t d){
    if(d>fEMin&&d<fEMax) return kTRUE;
    else return kFALSE;}
  Bool_t InThRange(Double_t d){
    if(d>fThetaMin&&d<fThetaMax) return kTRUE;
    else return kFALSE;}
   Bool_t InPhiRange(Double_t d){
    if(d>fPhiMin&&d<fPhiMax) return kTRUE;
    else return kFALSE;}
 Bool_t InMRange(Double_t d){
    if(d>fMMin&&d<fMMax) return kTRUE;
    else return kFALSE;}

  void SetThetaRange(Double_t min,Double_t max){
    //min=min*TMath::DegToRad();
    //max=max*TMath::DegToRad();
    fThetaMin=min;
    fThetaMax=max;
    fCosThMin=TMath::Cos(max);
    fCosThMax=TMath::Cos(min);

  }
  void SetCosThRange(Double_t min,Double_t max){
    fCosThMin=min;
    fCosThMax=max;
    fThetaMin=TMath::ACos(max);
    fThetaMax=TMath::ACos(min);
   }
  void SetPhiRange(Double_t min,Double_t max){
    fPhiMin=min;
    fPhiMax=max;
  }
  void SetERange(Double_t min,Double_t max){
    fEMin=min;
    fEMax=max;
  }
  void SetMRange(Double_t min,Double_t max){
    fMMin=min;
    fMMax=max;
  }

  void GetThRange(Double_t &min,Double_t &max){
    min=fThetaMin;
    max=fThetaMax;
  }
  void GetCosThRange(Double_t &min,Double_t &max){
    min=fCosThMin;
    max=fCosThMax;
  }
  void GetPhiRange(Double_t &min,Double_t &max){
    min=fPhiMin;
    max=fPhiMax;
  }
  void GetERange(Double_t &min,Double_t &max){
    min=fEMin;
    max=fEMax;
  }
  void GetMRange(Double_t &min,Double_t &max){
    min=fMMin;
    max=fMMax;
  }

  virtual Double_t GetTheta(){return fTheta;}
  virtual Double_t GetCosTh(){return fCosTh;}
  virtual Double_t GetPhi(){return fPhi;}
  virtual Double_t GetE(){return fE;}
  virtual Double_t GetM(){return fM;}

  void SetTheta(Double_t d){fTheta=d;fCosTh=TMath::Cos(fTheta);}
  void SetCosTh(Double_t d){fCosTh=d;fTheta=TMath::ACos(fCosTh);}
  void SetE(Double_t d){fE=d;}
  void SetM(Double_t d){fM=d;}
  void SetPhi(Double_t d){fPhi=d;}

  TLorentzVector* GetP4(){return fP4;}//return preexisting p4
  TLorentzVector* GenerateP4(Double_t M);//return random 4 vector from this distribution using this Mass M
  
  ClassDef(TEGDistribution,1)
};
inline TLorentzVector* TEGDistribution::GenerateP4(Double_t M){
  //Note fE is taken as kinetic energy
  GenerateRandom();//careful this has not been called already
  fM=M;//mass
  Double_t p=sqrt((fE+fM)*(fE+fM)-fM*fM);
  fP4->SetXYZT(0,0,p,fE+fM);
  fP4->SetTheta(fTheta);
  fP4->SetPhi(fPhi);
  //cout<<"TEGDistribution::GetP4 "<<fP4->M()<<" "<<fP4->E()<<" "<<fP4->Theta()*TMath::RadToDeg()<<" "<<fP4->Phi()*TMath::RadToDeg()<<" "<<fP4->Rho()<<" done"<<endl;
  return fP4;
}
#endif


