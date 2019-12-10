
#ifndef __TEGOutAll_h__
#define __TEGOutAll_h__

#include "TEGOutput.h"
#include "TEGElectroReaction.h"
#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"
#include <iostream>

class TEGOutAll : public TEGOutput{
 protected:
  // TEGGenerator * fGenerator;
 public:
  TEGOutAll(  );
  virtual ~TEGOutAll();

  //Virtual classes that required to be defined to make the clas concrete
  virtual Int_t Init();  //intialisation, create file, ouput object etc
  virtual Int_t SaveEvent(); //write event data
  virtual Int_t Close(); //close output

  void SetOnlyTrackFinal(Bool_t on=kTRUE){fOnlyTrackFinal=on;};
 private:
  //TEGOutAll specific data members
  TFile* fOutFile;
  TTree* fOutTree;  //root output tree
  TClonesArray* fP4s;
  TClonesArray* fVertices;
  Int_t fPDGs[100];
  Int_t fNp;   //number of particles in event
  Bool_t fOnlyTrackFinal;
  TEGElectroReaction* fReaction; //required for event header info


  ClassDef(TEGOutAll,1)
};

#endif
