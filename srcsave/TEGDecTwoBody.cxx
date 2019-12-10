#include "TEGDecTwoBody.h"
#include "TEGParticle.h"
#include "TEGGenerator.h"

ClassImp(TEGDecTwoBody)

//-----------------------------------------------------------------------------
TEGDecTwoBody::TEGDecTwoBody( ):TEGDecay()
{
  fDist=NULL;
  fIsWCosTh=kFALSE;
  fIsE1Theta1=kFALSE;
}
TEGDecTwoBody::~TEGDecTwoBody( ){
  //note :deleting fDist here will delete it
  //for other objects that use it too
  // if(fDist) delete fDist;
}
Bool_t TEGDecTwoBody::GenDecay( ){
  //FindDaughterMasses();done in particle::Decay()
  // cout<<"TEGDecTwoBody::GenDecay "<<fIsWCosTh<<" "<<fIsE1Theta1<<endl;
  if(fIsWCosTh)return GenWCosThDecay( );
  if(fIsE1Theta1) return GenE1Theta1Decay();
  cout<<"TEGDecTwoBody::GenDecay What type of two body decay?"<<endl;
  return kFALSE;
}
Bool_t TEGDecTwoBody::GenE1Theta1Decay( )
{
  //Uses E and theta in lab system
  //calculate 4vector of first product from distribution
  Double_t E1=fDist->GetE();
  Double_t P1=sqrt(E1*E1-fMd[0]*fMd[0]);
  fP4d[0]->SetE(E1);
  fP4d[0]->SetVect(TVector3(0,0,P1));
  fP4d[0]->SetTheta(fDist->GetTheta());
  fP4d[0]->SetPhi(fDist->GetPhi());
  //rotate into mother frame
  fDirection=fP4->Vect().Unit();
  fP4d[0]->RotateUz(fDirection);
  //calculate 4vecor of other daughter
  *fP4d[1]=*fP4-*fP4d[0];
  //cout<<"TEGDecay::GenE1CosTh1Decay( ) "<<fP4d[0]->E()<<" "<<fP4d[1]->E()<<" "<<fP4d[0]->Theta()*TMath::RadToDeg()<<" "<<fP4d[1]->Theta()*TMath::RadToDeg()<<endl;
  return kTRUE;

}
Bool_t TEGDecTwoBody::GenWCosThDecay( )
{
  //uses W and cos(theta) in rest frame
  //cout<<"TEGDecTwoBody::GenWCosThDecay( )"<<fP4<<" "<<fMd<<endl;

  //Get random kinematic variables
  //from distribution
  // if(fDist){
  //   fW=fDist->GetM();
  //   if(!fW)fW=fMother->GetDynamicMass();
  // }
  // else {
    //no defined mass distribution
  //  fW=fMother->GetDynamicMass();//should have been set when fW generated
  fW=fP4->M();
  Double_t Tcm = fP4->M();
  //cout<<" TEGDecay::GenPhaseSpace( ) initial mass "<<fTcm<<" "<<fMother->GetName()<<" with daughter # "<<fNd<<endl;

  for( Int_t n=0; n<fNd; n++ ){ Tcm -= fMd[n]; }
  //cout<<fTcm<<endl;
  if( Tcm <= 0.0 ){ return kFALSE; }            // not sufficient energy

    //  }
  //need to watch the above when have angular dist defined but no mass component. In this case want fMother->GetDynamicMass
 
  Double_t md02,md12,ed,pd; // mass, energy, momentum decay particle
  md02 = fMd[0]*fMd[0];
  md12 = fMd[1]*fMd[1];
  ed = (fW*fW + md02 - md12)/(2.0*fW); // E decay product 1
  //cout<<"Daughter "<<sqrt(md02)<<" "<<sqrt(md12)<<" "<<fW<<" "<<ed<<" "<<ed*ed - md02<<endl;
  if( ed < 0.0 ) return kFALSE;
  if( (pd = ed*ed - md02) < 0.0 ) return kFALSE;
  pd = TMath::Sqrt( pd );             //|p| decay product 1
  //note at the moment must make sure meson is first particle in decay
  //could make it so it sorts the product list to force this

  fP4d[0]->SetXYZT(0,0,pd,ed);   //just need e and p at moment
  // cout<<"Daughter done"<<endl;
  if(fDist){  
    fCosTheta =fDist->GetCosTh();
    fPhi     =fDist->GetPhi();
    if(TMath::Abs(fCosTheta)>1) return kFALSE;//for ex, if t range is not allowed
  }
  else{
    fCosTheta =gEGRandom->Uniform(-1,1);
    fPhi      =gEGRandom->Uniform(-TMath::Pi(),TMath::Pi());
  }
  //cout<<"TEGDecTwoBody::GenWCosThDecay( )"<<fCosTheta<<" "<<fPhi<<endl;
  // Set components of 4-momenta in CM
  Double_t sinth = TMath::Sqrt(1.0 - fCosTheta*fCosTheta);
  Double_t x = pd * sinth * TMath::Cos( fPhi );
  Double_t y = pd * sinth * TMath::Sin( fPhi );
  Double_t z = pd * fCosTheta;
  fP4d[0]->SetXYZT(x,y,z,ed);
  fP4d[1]->SetXYZT( -x,-y,-z, TMath::Sqrt( pd*pd + md12 ));
  // cout<<"TEGDecay::Gen2Decay( ) P4"<<fP4->E()<<" "<<fP4->M()<<" "<<fP4->Theta()<<endl;
  // Boost CM -> Lab. Boost vector from 4-momentum of parent particle
  BoostLab( );
  // cout<<"TEGDecay::Gen2Decay( ) "<<fP4d[0]->E()<<" "<<fP4d[1]->E()<<" "<<fP4d[0]->M()<<" "<<fP4d[1]->M()<<" "<<acos(fCosTheta)*TMath::RadToDeg()<<endl;
  return kTRUE;
}
