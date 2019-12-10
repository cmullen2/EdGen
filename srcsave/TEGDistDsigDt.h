#ifndef __TEGDistDsigDt_h__
#define __TEGDistDsigDt_h__

#include "TEGDistDsigDOmega.h"
#include "TEGReaction.h"


class TEGDistDsigDt : public TEGDistDsigDOmega {
 

 public:
  TEGDistDsigDt(Double_t b=5,Double_t min=-1,Double_t max=-1);
  virtual ~TEGDistDsigDt();

  virtual void GenerateRandom();
  virtual void Initialise();
  virtual Double_t GetCosTh();//now depends on R,M,G

 protected:
  TEGReaction* fReaction;
  TLorentzVector *fRP4;  //reaction 4 vector 
  TLorentzVector *fMP4;//meson 4 vector 
  TLorentzVector *fGP4; //beam 4 vector

  TF1* ftDist;
  Double_t ft;
  Double_t ftMin;
  Double_t ftMax;
 public:
  void SetReaction(TEGReaction* r){
    fReaction=r;
    if(fReaction){
      fRP4=fReaction->GetP4();
    }
  }
  void SettDist(TF1* dist){ftDist=dist;}
  TF1* GettDist(){return ftDist;}
  Double_t Gett(){return ft;}

  Double_t GettMax(){return ftMax;}
  void SettMax(Double_t max){ftMax=max;}
  Double_t GettMin(){return ftMin;}
  void SettMin(Double_t min){ftMin=min;}
  ClassDef(TEGDistDsigDt,1)

};

#endif
