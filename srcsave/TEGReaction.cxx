#include "TEGReaction.h"
#include "TEGParticle.h"
#include "TEGGenerator.h"
#include "TEGDistribution.h"

ClassImp(TEGReaction)

//-----------------------------------------------------------------------------
TEGReaction::TEGReaction():TEGParticle()
{
  fInitial1=NULL;
  fInitial2=NULL;
  fP4I1=NULL;
  fP4I2=NULL;
  fW=0;
  fBeamSpotSize=0;
  fTargetLength=0;
}
TEGReaction::TEGReaction(const Char_t* name ):TEGParticle(name)
{
  fInitial1=NULL;
  fInitial2=NULL;
  fP4I1=NULL;
  fP4I2=NULL;
  fW=0;
  fBeamSpotSize=0;
  fTargetLength=0;
}
TEGReaction::~TEGReaction( ){
  //note :deleting fDist here will delete it
  //for other objects that use it too
}
void TEGReaction::Initialise(){
  TEGParticle::Initialise();
  cout<<"TEGReaction::Initialise() "<<fInitial1<<" "<<fInitial2<<endl;
  fInitial1->Initialise();
  fInitial2->Initialise();
}
// Bool_t TEGReaction::Decay( ){
//   //Assuming in the rest frame of particle 2.
//   ChooseDecay(); //choose from possible decay channels
//   fCurrDecay->FindDaughterMasses(); //get final state masses
  
//   //choose reaction mass in allowed beam limits
//   TEGDistribution* Dist1=NULL;
//   if((Dist1=fInitial1->GetDistribution())){
//     //now we know masses can calc max,min W
//     Double_t Emin,Emax;
//     Dist1->GetERange(Emin,Emax);
//     if(Emin!=0&&Emax!=0){;
//       Double_t Mmin=sqrt(fCurrDecay->GetProductP4(0)->M2()+\
// 			 fCurrDecay->GetProductP4(1)->M2()+\
// 			 +2*Emin*fCurrDecay->GetProductP4(1)->M());
//       Double_t Mmax=sqrt(fCurrDecay->GetProductP4(0)->M2()+\
// 			 fCurrDecay->GetProductP4(1)->M2()+\
// 			 +2*Emax*fCurrDecay->GetProductP4(1)->M());

//       if(fCurrDecay->GetDistribution()->GetMDist())
// 	fCurrDecay->GetDistribution()->GetMDist()->GetRange(Emin,Emax);
//       else {Emin=Mmin;Emax=Mmax;}
//       //reset limits if inside the TF1 range
//       fCurrDecay->GetDistribution()->SetMRange(TMath::Min(Mmin,Emin),TMath::Max(Mmax,Emax));
//       cout<<"TEGReaction::Decay( ) limits "<<Emin<<" "<<Emax<<" "<<Mmin<<" "<<Mmax<<endl;
//     }
//   }
//   //Get the event invariant mass
//   GenerateReactionMass();
//   if(fInitial1->IsDecay()){
//     fInitial1->ChooseDecay();
//     fInitial1->GetCurrDecay()->FindDaughterMasses();
//     fInitial1->GenerateInitialP4();
//     fInitial1->GetCurrDecay()->GenerateRandom();
//     Double_t dec1theta=fInitial1->GetCurrDecay()->GetDistribution()->GetTheta();
//     Double_t dec1E=(fW*fW-fP4I2->M2()-2*fInitial1->GetP4()->E()*fP4I2->M())/2/(fP4I2->M()-2*fInitial1->GetP4()->E()*TMath::Sin(dec1theta/2));
//     //overwrite energy using one calc from w and theta
//     fInitial1->GetCurrDecay()->GetDistribution()->SetE(dec1E);
//     fInitial1->GetCurrDecay()->GenDecay();
//     fP4I1=fInitial1->GetCurrDecay()->GetProductByClass("Unknown")->GetP4();
//   }
//   else fP4I1=fInitial1->GenerateInitialP4();//from beam dist
//   //as much as allowed get intial 4-vectors
  
//   fP4I2=fInitial2->GenerateInitialP4();//stationary target
//   //at moment lab is defined as E2=M2
//   Double_t E1=(fW*fW-fP4I1->M2()-fP4I2->M2())/2/fP4I2->M();
//   Double_t E2=fP4I2->M();
//   fP4I1->SetRho(sqrt(E1*E1-fP4I1->M2()));
//   //fP4I2->SetRho(0);//taken 0
//   fP4I1->SetE(E1);
//   fP4I2->SetE(E2); 
//   cout<<"TEGReaction::Decay( ) 1"<<" "<<fP4I1->M()<<" "<<fP4I1->E()<<" "<<" "<<fP4I1->Theta()<<endl;
//   cout<<"TEGReaction::Decay( ) 2"<<" "<<fP4I2->M()<<" "<<fP4I2->E()<<" "<<" "<<fP4I2->Theta()<<endl;
  
//   //TLorentzVector lv(*fP4I1+*fP4I2);
//   //fP4->SetVectM(lv.Vect(),lv.M());
//   *fP4=*fP4I1+*fP4I2;
//   cout<<"TEGReaction::Decay( ) CM"<<" "<<fP4->M()<<" "<<fP4->E()<<" "<<" "<<fP4->Theta()<<endl;
  
//   return fCurrDecay->GenDecay();
// }
void TEGReaction::GenerateReactionMass(){
  fCurrDecay->GenerateRandom();
  fW=fCurrDecay->GetDistribution()->GetM();
}
// Bool_t TEGReaction::GenWCosThDecay( )
// {
//   cout<<"TEGReaction::GenWCosThDecay( )"<<" "<<endl;
//   FindDaughterMasses();

//   Double_t md,md02,md12,ed,pd; // mass, energy, momentum decay particle
//   md02 = fMd[0]*fMd[0];
//   md12 = fMd[1]*fMd[1];
//   ed = (fW*fW + md02 - md12)/(2.0*fW); // E decay product 1
//   cout<<"Daughter "<<md02<<" "<<md12<<" "<<fW<<" "<<ed<<" "<<ed*ed - md02<<endl;
//   if( ed < 0.0 ) return kFALSE;
//   if( (pd = ed*ed - md02) < 0.0 ) return kFALSE;
//   pd = TMath::Sqrt( pd );             //|p| decay product 1
//   fP4d[0]->SetXYZT(0,0,pd,ed);//just need e and p at moment
//   cout<<"Daughter done"<<endl;
//   if(fDist){  
//     fCosTheta =fDist->GetCosTh();
//     fPhi     =fDist->GetPhi();
//   }
//   else{
//     fCosTheta =gEGRandom->Uniform(-1,1);
//     fPhi      =gEGRandom->Uniform(-TMath::Pi(),TMath::Pi());
//   }
//   // Set components of 4-momenta in CM
//   Double_t sinth = TMath::Sqrt(1.0 - fCosTheta*fCosTheta);
//   Double_t x = pd * sinth * TMath::Cos( fPhi );
//   Double_t y = pd * sinth * TMath::Sin( fPhi );
//   Double_t z = pd * fCosTheta;
//   fP4d[0]->SetXYZT(x,y,z,ed);
//   fP4d[1]->SetXYZT( -x,-y,-z, TMath::Sqrt( pd*pd + md12 ));

//   // Boost CM -> Lab. Boost vector from 4-momentum of parent particle
//   BoostLab( );
//   cout<<"TEGDecay::Gen2Decay( ) "<<fP4d[0]->E()<<" "<<fP4d[1]->E()<<" "<<acos(fCosTheta)*TMath::RadToDeg()<<endl;
//   return kTRUE;
// }
