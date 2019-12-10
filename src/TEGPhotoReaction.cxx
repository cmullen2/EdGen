#include "TEGPhotoReaction.h"
#include "TEGParticle.h"
#include "TEGGenerator.h"
#include "TEGDistribution.h"

ClassImp(TEGPhotoReaction)

//-----------------------------------------------------------------------------
TEGPhotoReaction::TEGPhotoReaction( ):TEGReaction()
{
}
TEGPhotoReaction::TEGPhotoReaction(const Char_t* name ):TEGReaction(name)
{
}
TEGPhotoReaction::~TEGPhotoReaction( ){
  //note :deleting fDist here will delete it
  //for other objects that use it too
}
Bool_t TEGPhotoReaction::Decay( ){
  //Assuming in the rest frame of particle 2.
  ChooseDecay(); //choose from possible decay channels
  fCurrDecay->FindDaughterMasses(); //get final state masses
  
 //Get the event invariant mass, having calculated limits
  SetWLimits();
  GenerateReactionMass();

  //as much as allowed get intial 4-vectors
  fP4I1=fInitial1->GenerateInitialP4();//from beam dist
  fP4I2=fInitial2->GenerateInitialP4();//stationary target

  //at moment lab is defined as E2=M2
  Double_t E1=(fW*fW-fP4I1->M2()-fP4I2->M2())/2/fP4I2->M();
  Double_t E2=fP4I2->M();
  fP4I1->SetRho(sqrt(E1*E1-fP4I1->M2()));
  //fP4I2->SetRho(0);//taken 0
  fP4I1->SetE(E1);
  fP4I2->SetE(E2); 
  //  cout<<"TEGPhotoReaction::Decay( ) 1"<<" "<<fP4I1->M()<<" "<<fP4I1->E()<<" "<<" "<<fP4I1->Theta()<<endl;
  //cout<<"TEGPhotoReaction::Decay( ) 2"<<" "<<fP4I2->M()<<" "<<fP4I2->E()<<" "<<" "<<fP4I2->Theta()<<endl;
  
  //TLorentzVector lv(*fP4I1+*fP4I2);
  //fP4->SetVectM(lv.Vect(),lv.M());
  *fP4=*fP4I1+*fP4I2;
  //cout<<"TEGPhotoReaction::Decay( ) CM"<<" "<<fP4->M()<<" "<<fP4->E()<<" "<<" "<<fP4->Theta()<<endl;
  
  return fCurrDecay->GenDecay();
}
void TEGPhotoReaction::GenerateReactionMass(){
  fCurrDecay->GenerateRandom();
  fW=fCurrDecay->GetDistribution()->GetM();
  fP4->SetVectM(fP4->Vect(),fW);
}
void TEGPhotoReaction::SetWLimits(){
  //choose reaction mass in allowed beam limits
  TEGDistribution* Dist1=NULL;
  if((Dist1=fInitial1->GetDistribution())){
    //now we know masses can calc max,min W range
    Double_t Emin,Emax;
    Dist1->GetERange(Emin,Emax);
    if(Emin!=0&&Emax!=0){;
      Double_t Mmin=sqrt(fCurrDecay->GetProductP4(0)->M2()+\
			 fCurrDecay->GetProductP4(1)->M2()+\
			 +2*Emin*fCurrDecay->GetProductP4(1)->M());
      Double_t Mmax=sqrt(fCurrDecay->GetProductP4(0)->M2()+\
			 fCurrDecay->GetProductP4(1)->M2()+\
			 +2*Emax*fCurrDecay->GetProductP4(1)->M());

      if(fCurrDecay->GetDistribution()->GetMDist())
	fCurrDecay->GetDistribution()->GetMDist()->GetRange(Emin,Emax);
      else {Emin=Mmin;Emax=Mmax;}
      //reset limits if inside the TF1 range
      fCurrDecay->GetDistribution()->SetMRange(TMath::Min(Mmin,Emin),TMath::Max(Mmax,Emax));
      cout<<"TEGPhotoReaction::SetWLimits( ) limits "<<Emin<<" "<<Emax<<" "<<Mmin<<" "<<Mmax<<endl;
    }
  }
 
}
