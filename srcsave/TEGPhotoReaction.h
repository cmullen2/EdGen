#ifndef __TEGPhotoReaction_h__
#define __TEGPhotoReaction_h__

#include "TEGReaction.h"
#include "TEGDecay.h"

class TEGPhotoReaction : public TEGReaction {

 protected:

 public:
  TEGPhotoReaction();
  TEGPhotoReaction(const Char_t* );
  virtual ~TEGPhotoReaction();

  //overwrite TEGReaction functions
  virtual Bool_t Decay( );
  virtual void GenerateReactionMass();

  //Functions from this class
  virtual void SetWLimits();

  ClassDef(TEGPhotoReaction,1)
};

#endif


