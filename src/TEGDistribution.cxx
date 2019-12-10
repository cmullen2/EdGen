#include "TEGDistribution.h"
#include "TMath.h"

ClassImp(TEGDistribution)

TEGDistribution::TEGDistribution( ){

  fThetaDist=NULL;
  fCosThDist=NULL;
  fPhiDist=NULL;
  fEDist=NULL;
  fMDist=NULL;
  fP4=NULL;
  fThetaMin=0;
  fThetaMax=TMath::Pi();
  fCosThMin=-1;
  fCosThMax=1;
  fPhiMin=-TMath::Pi();
  fPhiMax= TMath::Pi();
  fEMin=0;
  fEMax=0;
  fMMin=0;
  fMMax=0;

  fP4=new TLorentzVector(0,0,1,1); 
};
TEGDistribution::~TEGDistribution( ){
  if(fP4)delete fP4;
}
void TEGDistribution::GenerateRandom(){
    //Don't need to generate every one
    //need to make more efficient
  if(fThetaMin!=fThetaMax)GenerateTheta();
  else {fTheta=fThetaMin;fCosTh=TMath::ACos(fTheta);}
  if(fPhiMin!=fPhiMax) GeneratePhi();
  else fPhi=fPhiMin;
  if(fEMin!=fEMax) GenerateE();
  else fE=fEMin;
  if(fMMin!=fMMax) GenerateM();
  else fM=fMMin;
}
 
