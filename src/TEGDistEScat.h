#ifndef __TEGDistEScat_h__
#define __TEGDistEScat_h__

#include "TEGDistribution.h"
#include "TF2.h"

//electron scattering class should return the 4 vector
//of the scattered electron
//Can use photon flux or given 2D dist in Ee' and thetae'

class TEGDistEScat : public TEGDistribution {
 

 public:
  TEGDistEScat( );
  virtual ~TEGDistEScat();

  virtual void GenerateRandom();
  virtual void Set2Distribution(TF2* f2){f2Dist=f2;}
  virtual void Initialise();

  TF2* Get2Distribution(){return f2Dist;}

 protected:
  TF2* f2Dist;   //2D distribution function

  //photon flux and polarisation 
  Double_t fFlux;
  Double_t fGPol;
  //kinematics required for calculation
  Double_t fMTar; //target mass
  Double_t fW; //invariant mass
  Double_t fEscat;//scattered electron energy
  Double_t fThscat;//scattered electron angle
  Double_t fomega;//virtual photon energy
  Double_t fQ2;//negative mass of virtual photon
  Double_t fThg;//virtual photon angle
  Double_t fE0;//e- beam energy
  Double_t fMe;//electron mass

  //What kinematics doyou want to generate?
  Bool_t fIsWThe; //use invariant mass W, and Thscat'
  Bool_t fIsScatETh;//use Escat and Thscat
  Bool_t fIsElastic;//use Elastic scattering decay
 public:
  void SetE0(Double_t e0){fE0=e0;}
  void SetIsWThe(Bool_t is=kTRUE){fIsWThe=is;}
  void SetIsScatETh(Bool_t is=kTRUE){fIsScatETh=is;}
  void SetIsElastic(Bool_t is=kTRUE){fIsElastic=is;}
 //functions to calc photon flux
  Double_t Flux_W_The(Double_t*,Double_t*);//using reaction invariant mass and scat electron theta
  Double_t Flux_ScatETh(Double_t*,Double_t*);//using scat electron energy and theta
  //Function to calc gamma polarisation
  Double_t GPol(){ return fGPol=1./(1+2*(1+fomega*fomega/fQ2)*TMath::Tan(fThscat/2)*TMath::Tan(fThscat/2));}
  Double_t CalcKinematics();

  ClassDef(TEGDistEScat,1)

};

#endif
