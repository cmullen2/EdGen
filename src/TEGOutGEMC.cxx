#include "TEGOutGEMC.h"
#include "TLorentzVector.h"

ClassImp(TEGOutGEMC)

//-----------------------------------------------------------------------------
TEGOutGEMC::TEGOutGEMC( ):TEGOutput()
{
  fGenerator=TEGGenerator::Generator();
  fReaction=NULL;
}

//---------------------------------------------------------------------------
TEGOutGEMC::~TEGOutGEMC()
{

}
//---------------------------------------------------------------------------
Int_t TEGOutGEMC::Init(){
  if(fReaction)return 0; //already initilaised
  //call this after first event is created
  //at the moment is can only 1 use fixed
  //decay mode 
  if(fFileName.Length()) fOutFile.open(fFileName.Data());

  else {
    cout<<"TEGOutGEMC::Init() No out file given will save to MCOutGEMC.root"<<endl;
    fFileName="MCOutGEMC.lund";
    fOutFile.open(fFileName.Data());
  }

  //get reaction for event header info
  fReaction=static_cast<TEGElectroReaction*>(fGenerator->GetReaction());
  if(!fReaction)cerr<<"TEGOutGEMC::Init() no reaction defined"<<endl;
  return 0;
}
//---------------------------------------------------------------------------
Int_t TEGOutGEMC::SaveEvent(){
// LUND format:
// Header (Event Info):
// # of Particles, # of Target Nucleons, # of Target Protons, Pol. of Target, Pol. of Electron, x, y, W2, Q2, nu
// Body (Particle Info):
// index, charge, type, particle id, parent, daughter, p_x, p_y, p_z, E, mass, x vertex, y vertex, z vertex
// type is 1 for particles in the detector

  TIter next( fGenerator->GetProducts() );//iterator for output particles
  TEGParticle* particle=NULL;
  TLorentzVector* p4=NULL;
  TLorentzVector* gamma=fReaction->GetGammaStar()->GetP4();
  TVector3* ver=NULL;
  TParticlePDG* pdg=NULL;
  Int_t index=1;
  //first event header
  Double_t bx=-gamma->M2()/2/fReaction->GetInitial2()->GetP4()->M()/gamma->E();
  Double_t y=gamma->E()/fReaction->GetP4I1()->E();
  Double_t entries=fGenerator->GetProducts()->GetEntriesFast();
  fOutFile<<"\t"<<entries<<" "<<1<<" "<<1<<" "			\
	  <<fReaction->GetInitial2()->GetPol()->Z()<<" "		\
	  <<fReaction->GetInitial1()->GetPol()->Z()<<" "		\
	  <<" "<<bx<<" "<<y<<" "<<fReaction->GetP4()->M2()<<" "		\
	  <<" "<<-gamma->M2()<<" "<<gamma->E()<<endl;

 //now all particles
  while( (particle = (TEGParticle*)next()) ){
      //match the tree branches to the ouput particle lorentz vectors
    if(!(particle->IsTrack()))continue;
    p4=particle->GetP4();
    pdg=particle->GetPDG();
    ver=particle->GetVertex();
    fOutFile<<index<<" "<<((Float_t)pdg->Charge())/3<<" "<<particle->IsTrack() \
	    <<" "<<pdg->PdgCode()<<" "<<0<<" "<<0<<" "\
	    <<p4->X()<<" "<<p4->Y()<<" "<<p4->Z()<<" "<<p4->T()<<" "\
	    <<p4->M()<<" "<<ver->X()<<" "<<ver->Y()<<" "<<ver->Z()<<endl;
    index++;
  }
  if((index-1)!=entries) cerr<<"TEGOutGEMC::SaveEvent() mismatch in event header info, wrong number of particles "<<entries<<" compared to "<<index-1<<" written "<<endl;
  return 0;
}
//---------------------------------------------------------------------------
Int_t TEGOutGEMC::Close(){
  if(fOutFile){
    fOutFile.close();
    return 1;
  }
  else return 0;
}