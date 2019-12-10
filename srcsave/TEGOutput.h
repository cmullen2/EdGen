#ifndef __TEGOutput_h__
#define __TEGOutput_h__

#include "TString.h"
#include "TEGGenerator.h"
#include "Riostream.h"

class TEGGenerator;

class TEGOutput {
 protected:
  TString fFileName;         //Name of output file for saved events
  TEGGenerator *fGenerator;// Used to get data for writing
 public:
  TEGOutput(  );
  virtual ~TEGOutput();

  virtual Int_t Init() = 0;      //intialisation, create file, ouput object etc
  virtual Int_t SaveEvent() = 0; //write event data
  virtual Int_t Close() = 0;     //close output

  TString GetFileName(){return fFileName;}
  void SetFileName(TString name){fFileName=name;}
  void SetGenerator(TEGGenerator* gen){fGenerator=gen;}

  ClassDef(TEGOutput,1)
};


#endif


