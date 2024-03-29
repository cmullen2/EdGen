#include "TEGDecay.h"
#include "TEGParticle.h"
#include "TEGGenerator.h"
#include "TEGDistribution.h"
//#include "TEGDistDsigDOmega.h"

ClassImp(TEGDecay)

//-----------------------------------------------------------------------------
TEGDecay::TEGDecay( )
{
  //initialise all pointers to NULL
  fProducts=NULL;
  fP4=NULL;
  fP4d=NULL;
  fMd=NULL;
  fNd=0;
  fDist=NULL;
  fMother=NULL;
  fProdPDG=NULL;
  fDist=NULL;
  // fMother->AddDecayChannel(this);
  //create object array for decay products (TEGParticles)
  fProducts=new TObjArray(); 
  fProducts->SetOwner(kTRUE); //Particles will be deleted by fProducts
  fThreshold=0;
  fNRes=0;

}

//---------------------------------------------------------------------------
TEGDecay::~TEGDecay()
{
  if(fProducts) delete fProducts;
  if(fMd) delete fMd;
  if(fP4d) delete fP4d;
}
TEGParticle* TEGDecay::GetProduct(Int_t p){
  return dynamic_cast<TEGParticle*>(fProducts->At(p));
}
TEGParticle* TEGDecay::AddProduct(Int_t pdg,TString name){
  //Note Mother not assigned yet
  //Should perhaps use the initialise function for use 
  //after the mother is set.
  cout<<"void TEGDecay::AddProduct "<<pdg<<" "<<TDatabasePDG::Instance()->GetParticle(pdg)->GetName()<<endl;
  if(fMother)cout<<"For "<<fMother->GetName()<<endl;
  //Add a decay product for this decay channel
  //first get its pdg ID
  //fProdPDG[fNd]=pdg;
  //now create its TEGParticle
  TEGParticle* egp=new TEGParticle(name,pdg,fMother);
  fProducts->Add(egp);
  //link the product LorentzVector to fP4d, 
  //the TLorentzVector array used to calculate kinematics
  //fP4d[fNProd]=(static_cast<TEGParticle*>(fProducts[fNProd]))->GetP4();//need to initialise fP4d array first knowing the number of decay particles
  fNd++;
  return egp;
}
void TEGDecay::SetMother(TEGParticle* moth){
  if(!fMother){  
    fMother=moth;
    fP4=fMother->GetP4();//note because fMother calls a fn this SetMother fn
    //has to be defined here and not in the header where the incomplete type
    //declaration of TEGParticle is used
  }
  else cout<<fName<<" This decay is already linked to another particle, please create a new one "<<endl;
}
void TEGDecay::Initialise(){
  if(!fMd) fMd=new Double_t[fNd];
  if(!fP4d){
    fP4d=new TLorentzVector*[fNd];
    for(Int_t i=0;i<fNd;i++)
      fP4d[i]=NULL;
  }
  //link the duaghter 4 vector array to the product 4 vectors
 TIter nextp( fProducts );
 TEGParticle* p=NULL;
 fThreshold=0;
 for(Int_t i=0;i<fNd;i++){
   p=static_cast<TEGParticle*>(nextp());
   p->Initialise();
   fP4d[i]=p->GetP4();
   fMd[i]=p->GetPDG()->Mass();//initialise mass to PDG value
   //calculate the threshold for the decay
   //if the particle has width allow a minimum mass of 5*width
   if(p->IsDecay())fThreshold+=p->GetMinMass();//calculated from product masses
   else fThreshold+=p->CalcMinMass();
   fIsRes.Set(i+1);
   fIsRes.AddAt(Bool_t(p->GetPDG()->Width()>0.0001),i);//treat as resonace if width >0.1MeV
   fNRes+=fIsRes.At(i);
   if(fIsRes.At(i)){
   }
 }
   cout<<fMother->GetName()<<" TEGDecay::Initialise() threshold = "<<fThreshold<<endl;

 //initialise distribution
 if(fDist)fDist->Initialise();
}
TEGParticle* TEGDecay::GetProductByClass(TString type){
  //cout<<"TEGDecay::GetProductByClass "<<type<<" "<<fMother->GetName()<<" "<<fProducts<<endl;
  TIter nextp( fProducts );
  TEGParticle* p=NULL;
  TEGParticle* ptype=NULL;
  for(Int_t i=0;i<fNd;i++){
    p=static_cast<TEGParticle*>(nextp());
    // cout<<p->GetPDG()->ParticleClass()<<endl;
    if(TString(p->GetPDG()->ParticleClass()).Contains(type)){
      if(ptype) cout<<"Multiple "<<type<<" found should not use TEGDecay::GetProductByType"<<endl;
      else ptype=p;
    }
  }
    if(!ptype) cout<<"TEGDecay::GetProductByType, no "<<type <<" found"<<endl;
  return ptype;
}
void TEGDecay::FindDaughterMasses(){
  //if(!fMd) Initialise();
  if(fP4->M()<fThreshold){//note this should already be passed in TEGParticle::ChooseDecay(), this is a check
    cout<<"TEGDecay::FindDaughterMasses() reaction does not meet this decay threshold "<<fMother->GetName()<<" "<<fP4->M()<<"<"<<fThreshold<<endl;
    exit(0);
    return;
  }
  //Note reaction may still not pass threshold if a too high resonace mass is
  //selected, in this case the event is scrapped and started again
  //Could force it to choose a mass below threshold, but not sure if this is the correct thing to do...
 // for(Int_t i=0;i<fNd;i++){
 //   auto p=static_cast<TEGParticle*>(fProducts->At(i));
 //   cout<<p->GetPDG()->PdgCode()<<endl;
 // }
 if(!fNRes) return; //all masses just have PDG value
  TIter nextp( fProducts );
  TEGParticle* p=NULL;
  //First calc energy above decay threshold
  Double_t Eabove=fP4->M();
  for(Int_t i=0;i<fNd;i++){
    p=static_cast<TEGParticle*>(fProducts->At(i));
    Eabove-=p->GetMinMass();
    //cout<<p->GetName()<<" "<<p->GetMinMass()<<endl;
  }
  if(Eabove<0){cout<<"TEGDecay::FindDaughterMasses() below threshold should not have got here!"<<Eabove<<" "<<fP4->M()<<" "<<GetThreshold()<<endl;exit(0);}

  for(Int_t i=0;i<fNd;i++){
    p=static_cast<TEGParticle*>(nextp());
    //cout<<"Mass "<<fMd[i]<<" "<<p->GetName()<<" "<<fIsRes.At(i)<<" "<<Eabove<<endl;
    if(!fIsRes.At(i))continue;//not a resonance so keep PDG mass
    // p=static_cast<TEGParticle*>(nextp());
    // cout<<i<<" TEGDecay::FindDaughterMasses() "<<p->GetPDG()->GetName()<<" "<<p->GetMinMass()<<" "<<Eabove<<" "<<endl;
    fMd[i]=p->CalcDynamicMass(p->GetMinMass(),Eabove+p->GetMinMass());
    // fMd[i]=p->CalcDynamicMass();
    //now recalculate Eabove to account for this actual mass
    Eabove-=(fMd[i]-p->GetMinMass());
    //cout<<"New Mass "<<fMd[i]<<" "<<p->GetName()<<" "<<fIsRes.At(i)<<" "<<p->GetMinMass()<<" "<<Eabove<<endl;
    fP4d[i]->SetVectM(fP4d[i]->Vect(),fMd[i]);//recalcs E
    //cout<<"TEGDecay::FindDaughterMasses() "<< fMd[i]<<endl;
  }
}
inline void TEGDecay::GenerateRandom(){if(fDist)fDist->GenerateRandom();}

Bool_t TEGDecay::GenDecay( )
{
  // Decide which phase-space generator to use and call it
  // For 2-body use simple algorithm which allows non phase-space angular
  // distributions. For >2 body use general recursive algorithm which allows
  // phase space only

//fill array with daughter masses, 
//could change for each event if particles have width
  // FindDaughterMasses();//done in particle::Decay()
  switch( fNd ){
  // case 0:
  //   cout<<"Should be here"<<endl;
  //   // no decay just choose random 4 vector from distribution
  //   p4=fDist->GetP4(fMother->GetDynamicMass());
  //   fP4->SetVectM(p4->Vect(),p4->M());
  //   //Maybe need case 3 for quick 2 body
  //   return kTRUE;
  case 1:
    // no decay just choose random 4 vector from distribution
    // fP4=fP4d[0]=fDist->GenerateP4(fMother->GetDynamicMass());
    *fP4d[0]=*fP4; //daughter is the same is this
    //Maybe need case 3 for quick 2 body
    return kTRUE;
  case 2:
    // cout<<"!!!!!!!!!!!!!!!!!!!"<<endl;
    //quick two-body decay if dist returns a sensible 4 vector
    //for example TEGDistEScat
    if(fDist){
       *fP4d[0]=*(fDist->GetP4());
       *fP4d[1]=*fP4-*fP4d[0];
       //cout<<"GenDEcay 0 "<<fP4d[0]->E()<<" "<<fP4d[0]->M()<<" "<<fP4d[0]->Theta()<<endl;
       // cout<<"GenDEcay 1 "<<fP4d[1]->E()<<" "<<fP4d[1]->M()<<" "<<fP4d[1]->Theta()<<endl;
      return kTRUE;
    }//or else do default
    return GenPhaseSpace( );
  default:
    // any >=3-particle decay (based on genbod)
    return GenPhaseSpace( );
  }
}

Bool_t TEGDecay::GenPhaseSpace( ){
  //  Generate an N-Body random final state.
  //  Use Raubold Lynch method ( F.James CERN 68-15 (1968) )
  //  Borrows from ROOT Class TGenPhaseSpace
  //  Check sufficient energy available for the final state
  //  before starting kinematics


  fTcm = fP4->M();
  //cout<<" TEGDecay::GenPhaseSpace( ) initial mass "<<fTcm<<" "<<fMother->GetName()<<" with daughter # "<<fNd<<endl;

  Int_t n,m;
  for( n=0; n<fNd; n++ ){ fTcm -= fMd[n]; }
  //cout<<fTcm<<endl;
  if( fTcm <= 0.0 ){return kFALSE; }            // not sufficient energy
  Double_t emmax = fTcm + fMd[0];
  Double_t emmin = 0;
  Double_t wt = 1;
  for (n=1; n<fNd; n++) {
    emmin += fMd[n-1];
    emmax += fMd[n];
    wt *= Pdk(emmax, emmin, fMd[n]);
  }
  fWtMax = 1/wt;                               // max weight for gating events

  Double_t rnd[fNd];
  Double_t invMas[fNd];
  Double_t pd[fNd];
  Int_t irnd[fNd];
  rnd[0] = 0.0; rnd[fNd-1] = 1.0;
  do{
    switch( fNd ){
    default:
      gEGRandom->RndmArray(fNd-2, rnd+1);         // random values [0,1]
      TMath::Sort(fNd, rnd, irnd, kFALSE);      // sort random val ascending
      break;
    case 3:                                     // 3 decay particles
      rnd[1] = gEGRandom->Uniform(0.0,1.0);
      irnd[0] = 0; irnd[1] = 1; irnd[2] = 2;
      break;
    case 2:
      irnd[0] = 0; irnd[1] = 1;
      break;
    }
    wt = 0.0;
    for (n=0; n<fNd; n++) {
      wt += fMd[n];
      invMas[n] = rnd[irnd[n]]*fTcm + wt;
    }
    wt = fWtMax;
    for (n=0; n<fNd-1; n++) {
      pd[n] = Pdk(invMas[n+1],invMas[n],fMd[n+1]);
      wt *= pd[n];
    }
  }while( gEGRandom->Uniform(0.0,fWtMax) > wt );
  fWt = wt; //Above line seems to be rejection method to give correct distributions
  //
  // Specification of 4-momenta (Raubold-Lynch method)
  //
  fP4d[0]->SetPxPyPzE(0, pd[0], 0 , TMath::Sqrt(pd[0]*pd[0]+fMd[0]*fMd[0]) );
  for(n=1;;){
    fP4d[n]->SetPxPyPzE(0, -pd[n-1], 0 , 
		      TMath::Sqrt(pd[n-1]*pd[n-1]+fMd[n]*fMd[n]) );

    Double_t cosZ   = gEGRandom->Uniform(-1.,1.);
    Double_t angY = gEGRandom->Uniform(0.0, TMath::TwoPi());;
    for (m=0; m<=n; m++) {
      fP4d[m]->RotateZ( TMath::ACos(cosZ) );
      fP4d[m]->RotateY( angY );
    }
    if( n == fNd-1 ) break;
    Double_t beta = pd[n] / sqrt(pd[n]*pd[n] + invMas[n]*invMas[n]);
    for (m=0; m<=n; m++) fP4d[m]->Boost(0,beta,0);
    n++;
  }
  // Boost CM -> Lab
  BoostLab( );
  // cout<<"TEGDecay::GenPhaseSpace( ) "<<fP4d[0]->E()<<" "<<fP4d[1]->E()<<endl;
  return kTRUE;


}
