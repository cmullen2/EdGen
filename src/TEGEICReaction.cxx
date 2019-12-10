#include "TEGEICReaction.h"
#include "TEGParticle.h"
#include "TEGGenerator.h"
#include "TEGDistribution.h"
#include "TEGDistEScat.h"

ClassImp(TEGEICReaction)

//-----------------------------------------------------------------------------
TEGEICReaction::TEGEICReaction( ):TEGReaction()
{
  fGammaStar=NULL;
}
TEGEICReaction::TEGEICReaction(const Char_t* name ):TEGReaction(name)
{
  fGammaStar=NULL;
}
TEGEICReaction::~TEGEICReaction( ){
  //note :deleting fDist here will delete it
  //for other objects that use it too
}
void TEGEICReaction::Initialise(){
  TEGReaction::Initialise();
  auto dist=dynamic_cast<TEGDistEScat*>(fInitial1->GetCurrDecay()->GetDistribution());
  fP4I1=fInitial1->GenerateInitialP4();//from ebeam dist
  fP4I2=fInitial2->GenerateInitialP4();// target
  cout<<"Momentum check "<<(*fP4I1+*fP4I2).P()<<" "<<endl;
  cout<<fP4I1->P()<<" "<<fP4I1->M()<<" "<<fP4I1->E()<<endl;
  cout<<fP4I2->P()<<" "<<fP4I2->M()<<" "<<fP4I2->E()<<endl;
  
  auto tarboost=fP4I2->BoostVector();
  fP4I1->Boost(-tarboost);
  Double_t E0=fP4I1->E();
  dist->SetE0(E0);
   dist->SetERange(0.1*E0,0.99*E0);
    //dist->SetERange(1E-2*E0,0.99*E0);
  dist->Initialise();
  TF2* f2=dist->Get2Distribution();
  //increase Npoints, default is 30, this decreases binning artifacts
  //actually should be Ok if not defining dist from histogram
  f2->SetNpx(500);
  f2->SetNpy(10000);
 
}
Bool_t TEGEICReaction::Decay( ){
  //Assuming in the rest frame of particle 2.
  fP4I1=fInitial1->GenerateInitialP4();//from ebeam dist
  CalcVertex(); //get reaction vertex
  fInitial1->SetVertex(fVertex);
 

  fP4I2=fInitial2->GenerateInitialP4();// target
  //now boost into rest frame of target
  auto tarboost=fP4I2->BoostVector();
  fP4I1->Boost(-tarboost);
  // fP4I1->RotateY(TMath::Pi());
  fInitial1->SetP4(fP4I1);

  //fInitial1->GetP4()->Print();
  if(!fInitial1->Decay()) return kFALSE; //scatter e produce gstar
  //get gstar 4 vector, escat is product 0

  // fInitial1->GetCurrDecay()->GetProduct(0)->GetP4()->RotateY(-TMath::Pi());
  // fInitial1->GetCurrDecay()->GetProduct(1)->GetP4()->RotateY(-TMath::Pi());
   fInitial1->GetCurrDecay()->GetProduct(0)->GetP4()->Boost(tarboost);
   fInitial1->GetCurrDecay()->GetProduct(1)->GetP4()->Boost(tarboost);
  // fP4I1->RotateY(-TMath::Pi());
  fGammaStar=fInitial1->GetCurrDecay()->GetProduct(1);

  //fP4I1=fGammaStar->GetP4();
  // cout<<"gamma "<<endl;
  //fGammaStar->GetP4()->Print();
  //fInitial1->GetCurrDecay()->GetProduct(0)->GetP4()->Print();
  //fP4I2->Print();
  //calculate reaction 4 vector
  *fP4=*(fGammaStar->GetP4())+*fP4I2;
  //set the reaction polarisation = gamma pol.
  //first check it is a decay to virtual photon
  // TEGDistEScat* vpdist=dynamic_cast<TEGDistEScat*>( fInitial1->GetCurrDecay()->GetDistribution());
  // if(vpdist){
  //   Float_t gampol=vpdist->GPol();
  //    //This will set the polarisation of the reaction particle to be decayed
  //   TVector3 rpol(gampol,0,0); //transverse/linear polarisation
  //   rpol.SetPhi(fGammaStar->GetP4()->Phi()); //linear polarisation in the scattering plane
  //   SetPol(&rpol);
  // }
  //cout<<"TEGEICReaction::Decay( ) tot "<<fP4->E()<<" "<<fP4->M()<<" "<<fP4->Theta()<<endl;
  GenerateReactionMass();//already done!
  // cout<<fW<<" "<<GetMinMass()<<endl;
  if(fW<1.2*GetMinMass()) return kFALSE;

  //find hadronic decay mode
 if(fIsDecay){//if not elastic
   // ChooseDecay(); //choose from possible decay channels
   // fCurrDecay->FindDaughterMasses(); //get final state masses
   // cout<<"TEGEICReaction::Decay( ) going to generate"<<endl;
   // fCurrDecay->GenerateRandom();
   // cout<<"TEGEICReaction::Decay( ) done generate"<<endl;
   //  return fCurrDecay->GenDecay();
   return TEGParticle::Decay();
  }
 else return kTRUE;
}
void TEGEICReaction::GenerateReactionMass(){
  fW=fP4->M();
  //cout<<"W "<<fW<<endl;
}
void  TEGEICReaction::AddToEvent(TObjArray* event){
  TEGParticle::AddToEvent(event);
 //also add particles from beam
  fInitial1->AddToEvent(event);  
}
