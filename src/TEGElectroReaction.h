#ifndef __TEGElectroReaction_h__
#define __TEGElectroReaction_h__

#include "TEGReaction.h"
#include "TEGDecay.h"

class TEGElectroReaction : public TEGReaction {

 protected:

 public:
  TEGElectroReaction();
  TEGElectroReaction(const Char_t* );
  virtual ~TEGElectroReaction();

  //overwrite TEGReaction functions
  virtual Bool_t Decay( );
  virtual void GenerateReactionMass();
  virtual void  AddToEvent(TObjArray* );//Add to list to be saved

 public:
  TEGParticle* GetGammaStar(){return fGammaStar;}
 protected:
  TEGParticle* fGammaStar;  //the virtual photon 4 vector

  ClassDef(TEGElectroReaction,1)
};

#endif


