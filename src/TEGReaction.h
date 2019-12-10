#ifndef __TEGReaction_h__
#define __TEGReaction_h__

#include "TEGParticle.h"
#include "TEGDecay.h"

class TEGReaction : public TEGParticle {

 protected:
  //2 intial state particles
  TEGParticle* fInitial1;
  TEGParticle* fInitial2;
  TLorentzVector* fP4I1;
  TLorentzVector* fP4I2;

  Double_t fW;//invariant mass of the reaction

  Double_t fBeamSpotSize;
  Double_t fTargetLength;
  TVector3 fTargetPos;
 public:
  TEGReaction( );
  TEGReaction(const Char_t* );
  virtual ~TEGReaction();

  virtual Bool_t Decay( )=0;//this is an abstract class
  //  virtual Bool_t GenWCosThDecay( ); //calculates final state from W and cos(thetaCM)
  virtual void Initialise();
  Double_t GetReactionMass(){return fW;}
  virtual void GenerateReactionMass();

  void SetBeamSpotSize(Double_t siz){fBeamSpotSize=siz;}
  void SetTargetLength(Double_t len){fTargetLength=len;}
  void SetTargetPos(TVector3 pos){fTargetPos=pos;}
  virtual TVector3* CalcVertex(){
    Double_t perp=gEGRandom->Uniform(0,fBeamSpotSize*fBeamSpotSize);
    fVertex->SetXYZ(sqrt(perp),0,gEGRandom->Uniform(-fTargetLength/2,fTargetLength/2));
    fVertex->SetPhi(gEGRandom->Uniform(-TMath::Pi(),TMath::Pi()));
    *fVertex+=fTargetPos;
    return fVertex;
  };

  TLorentzVector* GetP4I1(){return fP4I1;}
  TLorentzVector* GetP4I2(){return fP4I2;}

  virtual void SetInitial1(TEGParticle* i1){fInitial1=i1;}
  virtual void SetInitial2(TEGParticle* i2){fInitial2=i2;}
  TEGParticle* GetInitial1(){return fInitial1;}
  TEGParticle* GetInitial2(){return fInitial2;}
  ClassDef(TEGReaction,1)
};

#endif


