#include "TEGElectroReaction.h"
#include "TEGParticle.h"
#include "TEGGenerator.h"
#include "TEGDistribution.h"

ClassImp(TEGElectroReaction)

//-----------------------------------------------------------------------------
TEGElectroReaction::TEGElectroReaction( ):TEGReaction()
{
  fGammaStar=NULL;
}
TEGElectroReaction::TEGElectroReaction(const Char_t* name ):TEGReaction(name)
{
  fGammaStar=NULL;
}
TEGElectroReaction::~TEGElectroReaction( ){
  //note :deleting fDist here will delete it
  //for other objects that use it too
}
Bool_t TEGElectroReaction::Decay( ){
  //Assuming in the rest frame of particle 2.
  fP4I1=fInitial1->GenerateInitialP4();//from ebeam dist
  CalcVertex(); //get reaction vertex
  fInitial1->SetVertex(fVertex);
  if(!fInitial1->Decay()) return kFALSE; //scatter e produce gstar
  //Get the vertex Postion
  //get gstar 4 vector, escat is product 0
  //cout<<"TEGElectroReaction::Decay "<<fInitial1->GetCurrDecay()->GetProductP4(1)<<endl;
  fGammaStar=fInitial1->GetCurrDecay()->GetProduct(1);
  //fP4I1=fGammaStar->GetP4();
  fP4I2=fInitial2->GenerateInitialP4();//stationary target
  //calculate reaction 4 vector
  *fP4=*(fGammaStar->GetP4())+*fP4I2;
  //cout<<"TEGElectroReaction::Decay( ) tot "<<fP4->E()<<" "<<fP4->M()<<" "<<fP4->Theta()<<endl;
  GenerateReactionMass();//already done!

  //find hadronic decay mode
 if(fIsDecay){//if not elastic
   // ChooseDecay(); //choose from possible decay channels
   // fCurrDecay->FindDaughterMasses(); //get final state masses
   // cout<<"TEGElectroReaction::Decay( ) going to generate"<<endl;
   // fCurrDecay->GenerateRandom();
   // cout<<"TEGElectroReaction::Decay( ) done generate"<<endl;
   //  return fCurrDecay->GenDecay();
   return TEGParticle::Decay();
  }
 else return kTRUE;
}
void TEGElectroReaction::GenerateReactionMass(){
  fW=fP4->M();
  //cout<<"W "<<fW<<endl;
}
void  TEGElectroReaction::AddToEvent(TObjArray* event){
  TEGParticle::AddToEvent(event);
 //also add particles from beam
  fInitial1->AddToEvent(event);  
}
