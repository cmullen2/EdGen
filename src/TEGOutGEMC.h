
#ifndef __TEGOutGEMC_h__
#define __TEGOutGEMC_h__

#include "TEGOutput.h"
#include "TEGElectroReaction.h"
#include <iostream>
#include <fstream>
using namespace std;

class TEGOutGEMC : public TEGOutput{
 protected:
  // TEGGenerator * fGenerator;
 public:
  TEGOutGEMC(  );
  virtual ~TEGOutGEMC();

  //Virtual classes that required to be defined to make the clas concrete
  virtual Int_t Init();  //intialisation, create file, ouput object etc
  virtual Int_t SaveEvent(); //write event data
  virtual Int_t Close(); //close output

  //TEGOutGEMC specific data members
  ofstream fOutFile;
  TEGElectroReaction* fReaction; //required for event header info
 ClassDef(TEGOutGEMC,1)
};

#endif
