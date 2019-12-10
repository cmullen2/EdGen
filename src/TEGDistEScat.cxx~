#include "TEGDistEScat.h"
#include "TEGGenerator.h"
#include "TDatabasePDG.h"

ClassImp(TEGDistEScat)

TEGDistEScat::TEGDistEScat():TEGDistribution(){
  f2Dist=NULL;
  fMe=TDatabasePDG::Instance()->GetParticle("e-")->Mass();
  fMTar=TDatabasePDG::Instance()->GetParticle("proton")->Mass();
  fIsWThe=kFALSE;
  fIsScatETh=kFALSE;
  fE0=0;
}
TEGDistEScat::~TEGDistEScat(){
  if(f2Dist) delete f2Dist;
}
void TEGDistEScat::Initialise(){
  if(fIsWThe){
    if(fMMin==fMMax)cout<<"TEGDistEScat::Initialise() no invariant mass range specified"<<endl;
    //use TEGDistribution::SetMMax() SetThetaMax() etc
    //   f2Dist=new TF2("VGammaFlux",this,&TEGDistEScat::Flux_W_The,fMMin,fMMax,fThetaMin,fThetaMax,1);
    // TEGDistEScat* dummy=new TEGDistEScat();
    f2Dist=new TF2("VGammaFlux",this,&TEGDistEScat::Flux_W_The,fMMin,fMMax,fThetaMin,fThetaMax,1,"TEGDistEScat","Flux_W_The");
    // f2Dist->SetNpx(1000);//make sure resolve fast fall off
    //f2Dist->SetNpy(50);
    f2Dist->SetParName(0,"Ebeam");
    f2Dist->SetParameter(0,fE0); //use SetE0()
    cout<<"TEGDistEScat::Initialise() made VGammaFlux with WTh, includes dipole form factor weighting:1/ (1+fQ2/.7/.7)/ (1+fQ2/.7/.7)"
	<<endl<<"Theta range : "<<fThetaMin*TMath::RadToDeg()<< "-"<<fThetaMax*TMath::RadToDeg()
	<<endl<<"W range :"<<fMMin<<"-"<<fMMax
	<<endl<<"Beam Energy :"<<fE0<<endl;
  }
  else if(fIsScatETh){
    if(fEMin==fEMax)cout<<"TEGDistEScat::Initialise() no scattered electron energy range specified"<<endl;
    //use TEGDistribution::SetEMax() SetThetaMax() etc
    f2Dist=new TF2("VGammaFlux",this,&TEGDistEScat::Flux_ScatETh,fEMin,fEMax,fThetaMin,fThetaMax,1,"TEGDistEScat","Flux_ScatETh");
    //f2Dist->SetNpx(1000);//make sure resolve fast fall off
    //f2Dist->SetNpy(50);
    f2Dist->SetParName(0,"Ebeam");
    f2Dist->SetParameter(0,fE0); //use SetE0()
    cout<<"TEGDistEScat::Initialise() made VGammaFlux with ScatETh, includes dipole form factor weighting:1/ (1+fQ2/.7/.7)/ (1+fQ2/.7/.7)"
	<<endl<<"Theta range : "<<fThetaMin*TMath::RadToDeg()<< "-"<<fThetaMax*TMath::RadToDeg()
	<<endl<<"Ee' range :"<<fEMin<<"-"<<fEMax
	<<endl<<"Beam Energy :"<<fE0<<endl;
  }
  else if(fIsElastic){
  }
  else cout<<"TEGDistEScat::Initialise() no distribution specified will just be using TEGDistribution"<<endl;
  if(fE0==0){cerr<<"TEGDistEScat::Initialise() need to set E0"<<endl;exit(0);}

}
void TEGDistEScat::GenerateRandom(){
  //Get random variables from distribution and calculate rest
  Int_t calckin=0;
  if(fIsWThe){
    f2Dist->GetRandom2(fW,fThscat);
    //f2Dist->Eval(fW,fThscat);//calc other kinematics
    fEscat=-(fW*fW-fMTar*fMTar-2*fE0*fMTar)/2/(2*fE0*TMath::Sin(fThscat/2)*TMath::Sin(fThscat/2)+fMTar);
    fM=2;
    calckin=CalcKinematics();
  }
  else if(fIsScatETh){
    f2Dist->GetRandom2(fEscat,fThscat);
    //f2Dist->Eval(fEscat,fThscat);//calc other kinematics
    calckin=CalcKinematics();
  }
  else if(fIsElastic){
    fThscat=GenerateTheta();
    fEscat=fMTar*fE0/(2*fE0*TMath::Sin(fThscat/2)*TMath::Sin(fThscat/2)+fMTar);
    calckin=CalcKinematics();
  }
  //default random phi
  // cout<<"TEGDistEScat::GenerateRandom() "<<fW<<" "<<fThscat<<" "<<fPhi<<" "<<fEscat<<" "<<calckin<<endl;
  //cout<<"TEGDistEScat::CalcKinematics() "<<fEscat<<" "<<fThscat<< " "<<" "<<fQ2<<" "<<fomega<<" "<<fW<<" "<<fP4->M()<<" "<<fEscat*fEscat-fMe*fMe<<" "<<fMe<<" "<<fP4->Rho()<<endl;
}
Double_t TEGDistEScat::CalcKinematics(){
  //given fEscat and fThscat already assigned
  fomega=fE0-fEscat;
  //is it kinematically allowed
  if(fomega<0||fomega>fE0) return 0;
  fQ2=4*fE0*fEscat*sin(fThscat/2)*sin(fThscat/2);
  fW=(fMTar*fMTar+2*fMTar*fomega-fQ2);
  if(fW<0) return 0;
  fW=sqrt(fW);

  if((fEscat*fEscat-fMe*fMe)<0)return 0;
  Double_t Pscat=sqrt(fEscat*fEscat-fMe*fMe);
  fThg=TMath::ACos((fQ2+2*fE0*fomega)/(2*fE0*sqrt(fQ2+fomega*fomega)));
  //fW=sqrt(fMTar*fMTar+2*fMTar*omega-Q2);
  //set some things for TEGDistribution to return
  if(fMMax==2)cout<<Pscat<<" "<<fEscat*fEscat-fMe*fMe<<" "<<fP4->M()<<" "<<fP4->Rho()<<" "<<fP4->E()<<endl;
  fP4->SetE(fEscat);
  fP4->SetRho(Pscat);
  fP4->SetTheta(fThscat);
  fP4->SetPhi(GeneratePhi());//random phi angle
  fCosTh=TMath::ACos(fThscat);
  fTheta=fThscat;
  if(fMMax==2)cout<<fP4->Rho()<<endl;
  return 1;
}
Double_t TEGDistEScat::Flux_W_The(Double_t *x,Double_t *p){
  fE0=p[0];//only parameter is electron beam energy
  fW=x[0]; //invariant mass has to be x-axis
  fThscat=x[1]; //theta has to be y-axis
  fEscat=-(fW*fW-fMTar*fMTar-2*fE0*fMTar)/2/(2*fE0*TMath::Sin(fThscat/2)*TMath::Sin(fThscat/2)+fMTar);
  //calculate other kinematics
  if(!CalcKinematics())return 0; //not kinematically allowed

  //photon polarisation and flux
  fGPol=GPol();
  fFlux=(1./137/4/TMath::Pi()/TMath::Pi())/fE0*fEscat*((fW*fW-fMTar*fMTar)/fMTar)/fQ2/(1-fGPol);
  //include phase space factors and dipole form factor
  fFlux=fFlux*TMath::Sin(fThscat)/ (1+fQ2/.7/.7)/ (1+fQ2/.7/.7);//*TMath::Sin(fThg);
  if(fFlux<0)return 0;
  return fFlux;
}
Double_t TEGDistEScat::Flux_ScatETh(Double_t *x,Double_t *p){
  fE0=p[0];//only parameter is electron beam energy
  fEscat=x[0]; //e' energy has to be x-axis
  fThscat=x[1]; //theta has to be y-axis
  //calculate other kinematics
  if(!CalcKinematics())return 0; //not kinematically allowed
  //photon polarisation and flux
  fGPol=GPol();
  // fFlux=(1./137/2/TMath::Pi()/TMath::Pi())*(fE0/fEscat)*((fW*fW-fMTar*fMTar)/fMTar)/fQ2/(1-fGPol);
  fFlux=(1./137/4/TMath::Pi()/TMath::Pi())/fE0*fEscat*((fW*fW-fMTar*fMTar)/fMTar)/fQ2/(1-fGPol);

  //include phase space factors and dipole form factor
  fFlux=fFlux*TMath::Sin(fThscat)/ (1+fQ2/.7/.7)/ (1+fQ2/.7/.7);//*TMath::Sin(fThg);
  if(fFlux<0)return 0;
  return fFlux;
}
