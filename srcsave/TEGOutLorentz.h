
#ifndef __TEGOutLorentz_h__
#define __TEGOutLorentz_h__

#include "TEGOutput.h"
#include "TTree.h"
#include "TFile.h"
#include "TLorentzVector.h"

class TEGOutLorentz : public TEGOutput{
 protected:
  // TEGGenerator * fGenerator;
 public:
  TEGOutLorentz(  );
  virtual ~TEGOutLorentz();

  //Virtual classes that required to be defined to make the clas concrete
  virtual Int_t Init();  //intialisation, create file, ouput object etc
  virtual Int_t SaveEvent(); //write event data
  virtual Int_t Close(); //close output

  //TEGOutLorentz specific data members
  TTree* fOutTree;  //root output tree
  TFile* fOutFile;  //root output file
  Int_t fNVect;
  TLorentzVector** fp4;// vector for branches 
  TVector3** fver;// vector for vertex branches 

 ClassDef(TEGOutLorentz,1)
};

#endif
