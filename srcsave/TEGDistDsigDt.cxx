#include "TEGDistDsigDt.h"
#include "TEGGenerator.h"
#include "TLorentzVector.h"
#include "TEGElectroReaction.h"

ClassImp(TEGDistDsigDt)

TEGDistDsigDt::TEGDistDsigDt(Double_t b,Double_t min,Double_t max):TEGDistDsigDOmega(){
  //note range must be large enough for full t range or will hang
  ftDist=new TF1("DistDsigDt","1000*TMath::Exp(-[0]*x)",0,10);
  ftDist->SetParameter(0,b);
  ftDist->SetNpx(10000);
  fReaction=NULL;
  fRP4=NULL;
  fMP4=NULL;
  fGP4=NULL;
  ftMin=min;
  ftMax=max;

}
TEGDistDsigDt::~TEGDistDsigDt(){
  if(ftDist)delete ftDist;

}
void TEGDistDsigDt::Initialise(){
  TEGDistribution::Initialise();
}
void TEGDistDsigDt::GenerateRandom(){
  //need to do this first to allow beam and CM 
  //kinematics to be determined
  if(fMDist)fM=fMDist->GetRandom(fMMin,fMMax);
  else fM=gEGRandom->Uniform(fMMin,fMMax);

  //make sure costh doesn't work
  //done later when initial kinematics known
  fCosTh=-2;
  fPhi=TEGDistribution::GeneratePhi();
}
//actually could just use this function to make a 2D distribution
//in W and cos(theta)!!!!!!!!!!!!probably has to be W and t or would
//have to worry about Jacobian
//i.e theta is chosen at the same time as W
Double_t TEGDistDsigDt::GetCosTh(){
  //once beam and CM kinematics done can calculate t and CosTh
  //calculate tmax and tmin from CM energy/momentum
  //  cout<<"TEGDistDsigDt::GetCosTh() "<<fReaction<<endl;
  //Get the current channel meson
  //will slow it down a little, if only one decay uses
  //this distribution could do this in intialise.
  fMP4=fReaction->GetCurrDecay()->GetProductByClass("Meson")->GetP4(); 
  fGP4=((TEGElectroReaction*)fReaction)->GetGammaStar()->GetP4();

  // cout<<"gamma 1m "<<fGP4->M()<<" "<<fGP4->E()<<" "<<fGP4->Rho()<<" "<<fGP4->Theta()<<endl;
  //photon in the lab, boost to CM
  fGP4->Boost(-fRP4->BoostVector());
  //cout<<"TEGDistDsigDt::GetCosTh() booseted"<<fGP4<<endl;

  //The CM e and p for meson should have been calculated before
  //GetCosTh, see for example TEGDecTwoBody::GenWCosThDecay( )
  Double_t tmax=-(fMP4->M2()+fGP4->M2()-2*(fGP4->E()*fMP4->E()+fGP4->Rho()*fMP4->Rho()));
  Double_t tmin=-(fMP4->M2()+fGP4->M2()-2*(fGP4->E()*fMP4->E()-fGP4->Rho()*fMP4->Rho()));

  //  cout<<"meson "<<fMP4->M()<<" "<<fMP4->E()<<" "<<fMP4->Rho()<<" "<<fMP4->Theta()<<endl;
  //cout<<"gamma "<<fGP4->M()<<" "<<fGP4->E()<<" "<<fGP4->Rho()<<" "<<fGP4->Theta()<<endl;
  //cout<<"TEGDistDsigDt::GetCosTh() tdisted "<<tmin<<" "<<tmax<<" "<< ftDist<<endl;
  //cout<<ft<<" "<<tmin<<" "<<tmax<<endl;
  if(tmax>ftMax&&ftMax!=-1)tmax=ftMax;
  if(tmin<ftMin&&ftMin!=-1)tmin=ftMin;
  if(tmin>tmax){fGP4->Boost(fRP4->BoostVector());return 2;} //no valid t for these kinematics
 //Get t from defined distribution
  //  ft=ftDist->GetRandom(tmin,tmax);//garuntee a t
  ft=ftDist->GetRandom(0,tmax);
  if(ft<tmin){fGP4->Boost(fRP4->BoostVector());return 2;}
  //ft=0.4;
  // cout<<ft<<" "<<tmin<<" "<<tmax<<endl;
  if(TMath::IsNaN(ft)){//if tmin is high the integral can be too low to calc a random number so need to reset the range
    ftDist->SetRange(tmin,tmax);//slow to do this every event
    ft=ftDist->GetRandom();
    ftDist->SetRange(0,30);
  }

  //calculate CosTh
   Double_t costh1=(0.5*(fMP4->M2()+fGP4->M2()-(-ft))-fGP4->E()*fMP4->E())/fMP4->Rho()/fGP4->Rho();
   //Double_t costh1=(0.5*(-fMP4->M2()+fGP4->M2()-(-ft))+fGP4->E()*fMP4->E())/fMP4->Rho()/fGP4->Rho();
  //cout<<"TEGDistDsigDt::GetCosTh() tdisted "<<ft<<" "<<costh1<<endl;
  fCosTh=cos(TMath::Pi()-acos(costh1));
  // fCosTh=cos(costh1);

  //boost photon back to lab
  fGP4->Boost(fRP4->BoostVector());
  //cout<<"TEGDistDsigDt::GetCosTh() and return "<<fCosTh<<endl;

  return fCosTh;
  //default random phi
  //fPhi=TEGDistribution::GetPhi();
}
