#ifndef __TEGGenerator_h__
#define __TEGGenerator_h__


#include "TDatabasePDG.h"
#include "TPDGCode.h"
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "TObjArray.h" 
#include "TEGOutput.h"
#include "TEGParticle.h"
#include "Riostream.h"

R__EXTERN class TRandom3*   gEGRandom;     // global ptr random numbers

class TEGParticle;
class TEGOutput;

class TEGGenerator : public TObject {
 public:
  TEGGenerator( );
  virtual ~TEGGenerator();


 protected:
  Int_t    fSeed;            // initial random seed
  Int_t    fNrun;            // # of runs
  TDatabasePDG* fdbPDG;      // PDG data base
  TLorentzVector* fP4Target; // target 4-momentum (usually at rest
  TLorentzVector* fP4Beam;   // 4-momentum of beam
  TLorentzVector* fP4R;      // 4-momentum beam + target particle
  TEGParticle*    fBeam;     // beam particle
  TEGParticle*    fTarget;   // quasi-free "particle" in target
  TEGParticle*    fReaction; // reaction "particle"
  TObjArray*   fParticles;// Array of particles for saving
  TObjArray*   fProducts;// Array of particles for saving
  TEGOutput* fOutput;        //class to manage persistant output
  Int_t    fNEvents;         // total # of events to be thrown
  Int_t    fNEventi;         // event # counter
  Int_t    fNParticle;       // # particles in final state

  static TEGGenerator* fgInstance;
  
 public:
  static TEGGenerator* Generator(){
    //if(!fgInstance) fgInstance=new TEGGenerator();
    return fgInstance;//only return if exists
  }
  virtual void SaveEvent();               // write event to TTree
  virtual void GenerateEvent();                  // generate single event
 
  Int_t GetSeed(){ return fSeed; }
  TDatabasePDG* GetPDGdb(){ return fdbPDG; }
  TLorentzVector* GetP4Target(){ return fP4Target; }
  TLorentzVector* GetP4Beam(){ return fP4Beam; }
  TLorentzVector* GetP4R(){ return fP4R; }
  TEGParticle* GetBeam(){ return fBeam; }
  TEGParticle* GetTarget(){ return fTarget; }
  TEGParticle* GetReaction(){ return fReaction; }
  TObjArray* GetProducts(){ return fProducts; }
  Int_t GetNEvents(){ return fNEvents; }
  Int_t GetNEvent(){ return fNEventi; }
  Int_t GetNParticle(){ return fNParticle; }
  void AddParticleToEvent(TObject* p){fProducts->Add(p);}

  void SetOutput(TEGOutput* out){fOutput=out;};
  void SetReaction(TEGParticle* rp){fReaction=rp;};
 void FillEvent();

  ClassDef(TEGGenerator,1)
};

//-----------------------------------------------------------------------------

#endif
