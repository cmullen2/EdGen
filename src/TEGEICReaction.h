#ifndef __TEGEICReaction_h__
#define __TEGEICReaction_h__

#include "TEGReaction.h"
#include "TEGDecay.h"

class TEGEICReaction : public TEGReaction {

 protected:

 public:
  TEGEICReaction();
  TEGEICReaction(const Char_t* );
  virtual ~TEGEICReaction();

  //overwrite TEGReaction functions
  virtual Bool_t Decay( );
  virtual void GenerateReactionMass();
  virtual void  AddToEvent(TObjArray* );//Add to list to be saved
  void Initialise() override;
 public:
  TEGParticle* GetGammaStar(){return fGammaStar;}
 protected:
  TEGParticle* fGammaStar;  //the virtual photon 4 vector

  ClassDefOverride(TEGEICReaction,1)
};

#endif


