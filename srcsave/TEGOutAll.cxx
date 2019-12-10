#include "TEGOutAll.h"
#include "TLorentzVector.h"

ClassImp(TEGOutAll)

//-----------------------------------------------------------------------------
TEGOutAll::TEGOutAll( ):TEGOutput()
{
  fGenerator=TEGGenerator::Generator();
  fReaction=NULL;
  fP4s=NULL;
  fVertices=NULL;
  fNp=0;
  fOnlyTrackFinal=kFALSE;
  // fPDGs=NULL;
}

//---------------------------------------------------------------------------
TEGOutAll::~TEGOutAll()
{
  if( fP4s)  fP4s->Delete();
  if(fVertices)fVertices->Delete();
  if(fOutFile) fOutFile->Delete();
  if(fOutTree)fOutTree->Delete();
}
//---------------------------------------------------------------------------
Int_t TEGOutAll::Init(){
  if(fOutFile) {cout<<"TEGOutLorentz::Init() already done returning"<<endl;return 1;}
  if(fFileName.Length()) fOutFile=new TFile(fFileName,"recreate");
  else {
    cout<<"TEGOutLorentz::Init() No out file given will save to MCOutLorentz.root"<<endl;
    fFileName="MCOutLorentz.root";
    fOutFile=new TFile(fFileName,"recreate");
  }
  cout<<"make tree" <<fGenerator<<endl;
  fOutTree=new TTree("Reaction_Kinematics", "TEGOutAll");
  fOutTree->SetAutoSave();

  //Make a branch for the lorentz vectors
  fP4s=new TClonesArray("TLorentzVector");
  fOutTree->Branch("P4",&fP4s);
  //Make a branch for the pdgs
  //fPDGs=new TClonesArray("TParticlePDG");
  fOutTree->Branch("Np",&fNp,"fNp/I");
  fOutTree->Branch("pdg",fPDGs,"fPDGs[fNp]/I");
  //Make a branch for the vertices
  fVertices=new TClonesArray("TVector3");
  fOutTree->Branch("Vertex",&fVertices);
  
  //get reaction for event header info
  // fReaction=static_cast<TEGElectroReaction*>(fGenerator->GetReaction());
  // if(!fReaction)cerr<<"TEGOutAll::Init() no reaction defined"<<endl;
  return 0;
}
//---------------------------------------------------------------------------
Int_t TEGOutAll::SaveEvent(){

  TIter next( fGenerator->GetProducts() );//iterator for output particles
  TEGParticle* particle=NULL;
  TLorentzVector* p4=NULL;
  //TLorentzVector* gamma=fReaction->GetGammaStar()->GetP4();
  TVector3* ver=NULL;
  TParticlePDG* pdg=NULL;
  Int_t index=0;

  //Clear CloneArrays
  TClonesArray &p4s=*fP4s;
  p4s.Clear();
  TClonesArray &vers=*fVertices;
  vers.Clear();
  fNp=0;
  while( (particle = (TEGParticle*)next()) ){
      //match the tree branches to the ouput particle lorentz vectors
    if(!(particle->IsTrack()))continue;
    if(particle->IsDecay()&&fOnlyTrackFinal)continue;
    if(fNp>=100){cout<<"TEGOutAll::SaveEvent(), whoops never made the pdg array big enough, yu can increase it from 100 in TEGOutAll.h fPDGs[100] "<<fNp<<endl;continue;}
    p4=particle->GetP4();
    pdg=particle->GetPDG();
    ver=particle->GetVertex();
    new(p4s[fNp])TLorentzVector(*p4);
    new(vers[fNp])TVector3(*ver);
    fPDGs[fNp]=pdg->PdgCode();
    fNp++;
  }
  Int_t res=fOutTree->Fill();
  return res;
}
//---------------------------------------------------------------------------
Int_t TEGOutAll::Close(){
    if(fOutFile){
    fOutTree->Print();
    fOutFile->Write();
    fOutTree->Delete();
    fOutFile->Close();
    fOutTree=NULL;
    fOutFile->Delete();
    fOutFile=NULL;
    return 1;
  }
  else return 0;
}
