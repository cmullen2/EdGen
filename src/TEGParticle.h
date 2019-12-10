#ifndef __TEGParticle_h__
#define __TEGParticle_h__

#include "TParticlePDG.h"
#include "TLorentzVector.h"
//#include "TLorentzRotation.h"
#include "TObjArray.h"
#include "TArrayD.h"
#include "TObject.h"
#include "TVector3.h"
#include "TF1.h"
#include "Riostream.h"
//#include "TEGDecay.h"
#include "TEGGenerator.h"//for gEGRandom

//R__EXTERN class TRandom3*   gEGRandom;     // global ptr random numbers

class TEGDecay;
class TEGDistribution;

class TEGParticle : public TNamed {
 protected:
  TParticlePDG*   fPDG;        // PDG particle properties
  Int_t fPDGcode;              //PDG code
  Double_t fLifetime;          //TPDG does not handle this very well!!!
  TEGParticle*    fParent;     // parent particle (if decay product)
  TLorentzVector* fP4;         // 4 momentum in Lab frame
  TVector3* fPol;              //Polarisation vector
  TVector3* fVertex;              //Production vertex
  TVector3* fDecVertex;              //Decay vertex
  TObjArray*   fDecayParts; // list of decay products for current event
  TObjArray*   fDecays; // list of decays
  Int_t fNdecays;    //number of possible decay channels
  Bool_t fIsDecay;   //Does this particle decay?
  Bool_t fIsTrack;   //Should this particle be tracked?
  Int_t fForceDecay;  //Force this decay number only
  TEGDecay* fCurrDecay;
  TArrayD fBranchRatio;
  TEGDistribution* fDist; //possible initial distribution
  TF1* fMassDist; //mass distribution
  TF1* fDecVertexTime; //decay vertex distrbution
  Double_t fPDGMass;  //mass from PDG
  Double_t fDynamicMass;  //mass calculated for this event
  Double_t fMinMass;  //min mass calculated allowed by decay products
  Double_t fMinThresh;  //min decay threshold
  Double_t fMaxThresh;  //max decay threshold
  public:
  TEGParticle(); //its name and its parent
  TEGParticle( const Char_t* name, Int_t pdg, TEGParticle* parent); //its name, its pdg code and its parent
  TEGParticle(const Char_t* name);
  virtual ~TEGParticle();
  virtual void AddDecayChannel(TEGDecay* decay,Double_t bratio=1);
  virtual void Initialise();
  virtual Double_t CalcDynamicMass(Double_t Mmin=0,Double_t Mmax=0){
    fDynamicMass=fPDGMass;
    if(fMassDist){
      if(Mmin==Mmax)fDynamicMass=fMassDist->GetRandom();
      else fDynamicMass=fMassDist->GetRandom(Mmin,Mmax);
    }
    return fDynamicMass; 
  }
  virtual Double_t GetDynamicMass(){return fDynamicMass;}
  virtual Double_t CalcMinMass(){//if particle has width calc. a minimum mass
    if(!fPDG)return 0;//a Reaction particle for example
    Double_t Mmin=fPDGMass-5*fPDG->Width();
    if(Mmin<0)Mmin=0;
    if(fPDG->PdgCode()==-22)Mmin=fPDGMass;//hack for virtual photon to make sure beam "decay" is above threshold 
    return Mmin;
  }
  virtual void  CalcDecVertex();  
  virtual Double_t GetMinMass(){return fMinMass;}
  virtual  TEGDecay *ChooseDecay();
  virtual Bool_t Decay();
  void FixCurrDecay(Int_t i);
  Bool_t IsDecay(){return fIsDecay;}
  Bool_t IsTrack(){return fIsTrack;}
  TParticlePDG* GetPDG(){ return fPDG; }
  void SetParent( TEGParticle* parent ){ fParent = parent; }
  TEGParticle* GetParent(){ return fParent; }
  TLorentzVector* GetP4(){ return fP4; }
  TVector3* GetPol(){ return fPol; }
  TVector3* GetVertex(){ return fVertex; }
  TVector3* GetDecVertex(){ return fDecVertex; }
  TEGDecay* GetCurrDecay(){return fCurrDecay;}
  TEGDecay* GetDecay(Int_t i);
  TF1* GetMassDist(){return fMassDist;}
  TF1* GetDecVertexDist(){return fDecVertexTime;}

  void SetIsDecay(Bool_t is=true){fIsDecay=is;};
  void SetIsTrack(Bool_t is=true){fIsTrack=is;};
  void SetP4( TLorentzVector* p4 ){ fP4 = p4; }
  void SetP4( TLorentzVector p4 ){ fP4->SetVectM(p4.Vect(),p4.M()); }
  void SetPol( TVector3 *pol ){ fPol=pol; }
  void SetVertex( TVector3 *ver ){ fVertex->SetXYZ(ver->X(),ver->Y(),ver->Z()); }
  void SetPDGcode(Int_t pdg){fPDGcode=pdg;}
  void SetForceDecay(Int_t fd){fForceDecay=fd;}
  void SetDistribution(TEGDistribution* dist){fDist=dist;}
  void SetMassDist(TF1* md){fMassDist=md;}

  void SetPDGDecays();

  TEGDistribution* GetDistribution(){return fDist;}
  TLorentzVector* GenerateInitialP4(Int_t d=0);
  virtual void  AddToEvent(TObjArray* );//Add to list to be saved
  ClassDef(TEGParticle,1)

};

#endif
