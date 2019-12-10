#include "TEGDecElElasticRad.h"
#include "TEGParticle.h"
#include "TEGGenerator.h"

ClassImp(TEGDecElElasticRad)

//-----------------------------------------------------------------------------
TEGDecElElasticRad::TEGDecElElasticRad( ):TEGDecay()
{
  fDirection=TVector3(0,1,0);
}
TEGDecElElasticRad::~TEGDecElElasticRad( ){
  //note :deleting fDist here will delete it
  //for other objects that use it too
  // if(fDist) delete fDist;
}
TEGParticle*  TEGDecElElasticRad::AddProduct(Int_t ){
  cerr<<"TEGDecElElasticRad::AddProduct() not-valid, particles defined in TEGDecElElasticRad::Initialise"<<endl;
  return NULL;
}
void TEGDecElElasticRad::Initialise(){
  //we know the "decay" particles
  //radiative photon, gammastar and e-scat
  //use TEGDecay::AddProduct()
  TEGDecay::AddProduct(22);//first radiative photon
  TEGDecay::AddProduct(-22);//second gammastar, PDG -22 created in TEGGenerator
  TEGDecay::AddProduct(11);//third the scattered electron
  fTarMass=0.938272;//default proton target
  TEGDecay::Initialise();
  //we know these 4 vector are not stationary
  //give momentum initial mag. so SetRho works
  Double_t mass=fP4d[0]->M();
  fP4d[0]->SetVect(TVector3(0,0,1));
  fP4d[0]->SetE(sqrt(1+mass*mass));
  mass=fP4d[1]->M();
  fP4d[1]->SetVect(TVector3(0,0,1));
  fP4d[1]->SetE(sqrt(1+mass*mass));
  mass=fP4d[2]->M();
  fP4d[2]->SetVect(TVector3(0,0,1));
  fP4d[2]->SetE(sqrt(1+mass*mass));
 
}
Bool_t TEGDecElElasticRad::GenDecay( ){
  //First get scattered electron kinematics
  Double_t E2=fDist->GetE();
  Double_t P2=sqrt(E2*E2-fMd[2]*fMd[2]);
  Double_t Th2=fDist->GetTheta();
  fP4d[2]->SetE(E2);
  fP4d[2]->SetRho(P2);
  fP4d[2]->SetTheta(Th2);
  fP4d[2]->SetPhi(fDist->GetPhi());
  //now calculate intermediate e- energy
  Double_t E1=fTarMass*E2/(fTarMass-2*E2*TMath::Sin(Th2/2)*TMath::Sin(Th2/2));
  Double_t Eph=fP4->E()-E1; //beam - e-scat
  fP4d[0]->SetE(Eph);
  fP4d[0]->SetRho(Eph);
  fP4d[0]->SetTheta(0);//radiative photon almost along beamline
  fP4d[0]->SetPhi(0);

  //rotate to mother frame
  fDirection=fP4->Vect().Unit();
  fP4d[0]->RotateUz(fDirection);
  fP4d[2]->RotateUz(fDirection);
  //now gstar
  *fP4d[1]=*fP4-*fP4d[0]-*fP4d[2];//beam - photon - e-scat
  return kTRUE;
}
