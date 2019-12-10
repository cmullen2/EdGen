
#include "TEGOutLorentz.h"

ClassImp(TEGOutLorentz)

//-----------------------------------------------------------------------------
TEGOutLorentz::TEGOutLorentz( ):TEGOutput()
{
  fGenerator=TEGGenerator::Generator();
  fOutTree=NULL;
  fOutFile=NULL;
  fNVect=0;
  fp4=NULL;
  fver=NULL;
}

//---------------------------------------------------------------------------
TEGOutLorentz::~TEGOutLorentz()
{
  if(fOutTree) delete fOutTree;
  if(fOutFile) delete fOutFile;
  //if(fp4) delete fp4;
}
//---------------------------------------------------------------------------
Int_t TEGOutLorentz::Init(){
  //call this after first event is created
  //at the moment is can only 1 use fixed
  //decay mode 
  if(fOutFile) {cout<<"TEGOutLorentz::Init() already done returning"<<endl;return 1;}
  if(fFileName.Length()) fOutFile=new TFile(fFileName,"recreate");
  else {
    cout<<"TEGOutLorentz::Init() No out file given will save to MCOutLorentz.root"<<endl;
    fFileName="MCOutLorentz.root";
    fOutFile=new TFile(fFileName,"recreate");
  }
 cout<<"make tree" <<fGenerator<<endl;
  fOutTree=new TTree("Reaction_Kinematics", "TEGOutLorentz");
  //Get tree info from generator
  //First the final state
  TIter next( fGenerator->GetProducts() );//iterator for output particles
  fp4=new TLorentzVector*[fGenerator->GetProducts()->GetEntries()];
  fver=new TVector3*[fGenerator->GetProducts()->GetEntries()];
  TEGParticle* particle=NULL;
  cout<<"Going to save the lorentz vectors for,"<<endl;
  while( (particle = (TEGParticle*)next()) ){
      //match the tree branches to the ouput particle lorentz vectors
    fp4[fNVect]=particle->GetP4();
    fver[fNVect]=particle->GetVertex();
    TString paname=particle->GetName();
    paname.ReplaceAll("+","p");
    paname.ReplaceAll("-","m");
    cout<<"TEGOutLorentz "<<paname<<endl;
    fOutTree->Branch(paname,&fp4[fNVect]);
    fOutTree->Branch(TString("ver_")+paname,&fver[fNVect]);
    fNVect++;
  }

  return 0;
}
//---------------------------------------------------------------------------
Int_t TEGOutLorentz::SaveEvent(){
  Int_t res=fOutTree->Fill();
  return res;
}
//---------------------------------------------------------------------------
Int_t TEGOutLorentz::Close(){
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
