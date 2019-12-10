#ifndef __TEGDistDsigDOmega_h__
#define __TEGDistDsigDOmega_h__

#include "TEGDistribution.h"
#include "TF2.h"
#include "TH2.h"


class TEGDistDsigDOmega : public TEGDistribution {
 

 public:
  TEGDistDsigDOmega( );
  virtual ~TEGDistDsigDOmega();

  virtual void GenerateRandom();
  virtual void GenerateRandomM();
  virtual void GenerateRandomE();
  Double_t EvalHist(Double_t *x,Double_t *p){return fH2Dist->GetBinContent(fH2Dist->FindBin(x[0],x[1]))*TMath::Sin(x[1]);}
  virtual void Set2Distribution(TF2* f2){f2Dist=f2;}
  virtual void Set2Distribution(TH2* f2){
    fH2Dist=f2;
    f2Dist=new TF2("DsDO",this,&TEGDistDsigDOmega::EvalHist,
		   fH2Dist->GetXaxis()->GetBinLowEdge(1),
		   fH2Dist->GetXaxis()->GetBinUpEdge(fH2Dist->GetNbinsX()),
		   fH2Dist->GetYaxis()->GetBinLowEdge(1),
		   fH2Dist->GetYaxis()->GetBinUpEdge(fH2Dist->GetNbinsY()),
		   1,"TEGDistDsigDOmega","EvalHist");
   }
  TF2* Get2Distribution(){return f2Dist;}

  virtual void Initialise();
  void SetIsM(Bool_t is=kTRUE){fIsM=is;}
  void SetIsE(Bool_t is=kTRUE){fIsE=is;}
 protected:
  TF2* f2Dist;          //2D distribution function
  TH2* fH2Dist;          //2D distribution histogram

  Bool_t fIsM;
  Bool_t fIsE;
  ClassDef(TEGDistDsigDOmega,1)

};

#endif
