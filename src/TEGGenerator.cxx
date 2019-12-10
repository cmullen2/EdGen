#include "TEGGenerator.h"


ClassImp(TEGGenerator)

TEGGenerator* TEGGenerator::fgInstance=0;
TRandom3* gEGRandom=NULL;

TEGGenerator::TEGGenerator( ):TObject(){
  gEGRandom=new TRandom3();
  fSeed=0;
  gEGRandom->SetSeed(0);
  fNrun=1;
  fdbPDG=new TDatabasePDG();
  FILE* file = fopen("eg_pdg_table.txt","r");
  if (file == 0) {
    Error("TEGGenerator","Could not open PDG particle file %s","eg_pdg_table.txt");
    Error("TEGGenerator","will just use $ROOTSYS/etc/pdg_table.txt default");
  }
  else {fclose(file);fdbPDG->ReadPDGTable("eg_pdg_table.txt");}
  fP4Target=NULL;
  fP4Beam=NULL;
  fP4R=NULL;
  fBeam=NULL;
  fTarget=NULL;
  fReaction=NULL;
  fParticles=NULL;
  fProducts=NULL;
  fOutput=NULL;
  fNEvents=0;
  fNEventi=0;
  fNParticle=0;
  fProducts=new TObjArray();
  fgInstance=this;
  //Add virtual photon
  TDatabasePDG::Instance()->AddParticle("vphoton","vphoton",-(TDatabasePDG::Instance()->GetParticle(11)->Mass()),true,0,0,"GaugeBoson",-22);
  //Add dummy meson
  //note width 1 so recongnised as a resonance and findDaughterMass computed
  TDatabasePDG::Instance()->AddParticle("EGMeson","EGMeson",1,false,1,0,"Meson",10);
  TDatabasePDG::Instance()->AddParticle("EGBaryon","EGBaryon",1,false,1,0,"Baryon",100);

}
TEGGenerator::~TEGGenerator( ){

  delete fdbPDG;
  if(fP4Target)delete fP4Target;
  if(fP4Beam)delete fP4Beam;
  if(fP4R)delete fP4R;
  if(fTarget)delete fTarget;
  if(fBeam)delete fBeam;
  if(fReaction)delete fReaction;
  if(fProducts)delete fProducts;
}
void TEGGenerator::GenerateEvent(){
  // cout<<"TEGGenerator::GenerateEvent() an event "<<fNEventi<<" "<<fReaction<<endl;
  Int_t Ntries=0;
  while(! fReaction->Decay()){cout<<"TEGGenerator::GenerateEvent() Did not pass kinematics try again "<<Ntries++<<endl;};//generate decay above threshold
  FillEvent();
  if(fOutput)SaveEvent();
  fNEventi++;
}
void TEGGenerator::SaveEvent(){
  // if(fNEventi==0)fOutput->Init();
  fOutput->Init();
  fOutput->SaveEvent();
  //  cout<<"save an event "<<fNEventi<<endl;
}
void TEGGenerator::FillEvent(){
  //clear previous event
  fProducts->Clear();
  //interate through the decays for this event
  fReaction->AddToEvent(fProducts);
}
