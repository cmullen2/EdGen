#ifndef __TEGDecElElasticRad_h__
#define __TEGDecElElasticRad_h__

#include "TEGDecay.h"
#include "TEGDistDsigDOmega.h"


class TEGDecElElasticRad : public TEGDecay {

 protected:

 public:
  TEGDecElElasticRad( );
  virtual ~TEGDecElElasticRad();

  virtual Bool_t GenDecay( );
  virtual TEGParticle* AddProduct(Int_t pdg);
  virtual void Initialise();
 
  void SetDistParticle(TObject* dp){
    //make this particle first in list, thus gets dist costh
    fProducts->Remove(dp);
    fProducts->AddFirst(dp);
  }
  void SetTarMass(Double_t mass){fTarMass=mass;}

  protected:
  Double_t fEe;  //Energy of scattered electron
  Double_t fThe;  //Energy of scattered electron
  Double_t fTarMass;  //Mass of target
  ClassDef(TEGDecElElasticRad,1)
};

#endif


