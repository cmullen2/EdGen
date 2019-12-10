//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 18 22:10:57 2015 by ROOT version 5.34/28
// from TTree Reaction_Kinematics/TEGOutAll
// found on file: ../Eptopipp_low.root
//////////////////////////////////////////////////////////

#ifndef Plotter_h
#define Plotter_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include "THSOutput.h"

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TVector3.h>
#include <TLorentzVector.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxP4 = 4;
   const Int_t kMaxVertex = 4;

class Plotter : public TSelector, public THSOutput {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           P4_;
   UInt_t          P4_fUniqueID[kMaxP4];   //[P4_]
   UInt_t          P4_fBits[kMaxP4];   //[P4_]
   UInt_t          P4_fP_fUniqueID[kMaxP4];   //[P4_]
   UInt_t          P4_fP_fBits[kMaxP4];   //[P4_]
   Double_t        P4_fP_fX[kMaxP4];   //[P4_]
   Double_t        P4_fP_fY[kMaxP4];   //[P4_]
   Double_t        P4_fP_fZ[kMaxP4];   //[P4_]
   Double_t        P4_fE[kMaxP4];   //[P4_]
   Int_t           Np;
   Int_t           pdg[4];   //[fNp]
   Int_t           Vertex_;
   UInt_t          Vertex_fUniqueID[kMaxVertex];   //[Vertex_]
   UInt_t          Vertex_fBits[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_fX[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_fY[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_fZ[kMaxVertex];   //[Vertex_]
   TLorentzVector pi;
   TLorentzVector prot;
   TLorentzVector es;
   TLorentzVector vp;
   TVector3 pidir;
   TVector3 protdir;

   // List of branches
   TBranch        *b_P4_;   //!
   TBranch        *b_P4_fUniqueID;   //!
   TBranch        *b_P4_fBits;   //!
   TBranch        *b_P4_fP_fUniqueID;   //!
   TBranch        *b_P4_fP_fBits;   //!
   TBranch        *b_P4_fP_fX;   //!
   TBranch        *b_P4_fP_fY;   //!
   TBranch        *b_P4_fP_fZ;   //!
   TBranch        *b_P4_fE;   //!
   TBranch        *b_fNp;   //!
   TBranch        *b_pdg;   //!
   TBranch        *b_Vertex_;   //!
   TBranch        *b_Vertex_fUniqueID;   //!
   TBranch        *b_Vertex_fBits;   //!
   TBranch        *b_Vertex_fX;   //!
   TBranch        *b_Vertex_fY;   //!
   TBranch        *b_Vertex_fZ;   //!

   Plotter(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~Plotter() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
//Add THSHisto functions
   virtual void HistogramList(TString sLabel);
   virtual void FillHistograms(TString sCut,Int_t bin);
   TVector3 ScatteredVector(TVector3 v_inc,TVector3 v_sc);
   ClassDef(Plotter,0);
};

#endif

#ifdef Plotter_cxx
void Plotter::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("P4", &P4_, &b_P4_);
   fChain->SetBranchAddress("P4.fUniqueID", P4_fUniqueID, &b_P4_fUniqueID);
   fChain->SetBranchAddress("P4.fBits", P4_fBits, &b_P4_fBits);
   fChain->SetBranchAddress("P4.fP.fUniqueID", P4_fP_fUniqueID, &b_P4_fP_fUniqueID);
   fChain->SetBranchAddress("P4.fP.fBits", P4_fP_fBits, &b_P4_fP_fBits);
   fChain->SetBranchAddress("P4.fP.fX", P4_fP_fX, &b_P4_fP_fX);
   fChain->SetBranchAddress("P4.fP.fY", P4_fP_fY, &b_P4_fP_fY);
   fChain->SetBranchAddress("P4.fP.fZ", P4_fP_fZ, &b_P4_fP_fZ);
   fChain->SetBranchAddress("P4.fE", P4_fE, &b_P4_fE);
   fChain->SetBranchAddress("Np", &Np, &b_fNp);
   fChain->SetBranchAddress("pdg", pdg, &b_pdg);
   fChain->SetBranchAddress("Vertex", &Vertex_, &b_Vertex_);
   fChain->SetBranchAddress("Vertex.fUniqueID", Vertex_fUniqueID, &b_Vertex_fUniqueID);
   fChain->SetBranchAddress("Vertex.fBits", Vertex_fBits, &b_Vertex_fBits);
   fChain->SetBranchAddress("Vertex.fX", Vertex_fX, &b_Vertex_fX);
   fChain->SetBranchAddress("Vertex.fY", Vertex_fY, &b_Vertex_fY);
   fChain->SetBranchAddress("Vertex.fZ", Vertex_fZ, &b_Vertex_fZ);
}

Bool_t Plotter::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   THSOutput::HSNotify(fChain);

   return kTRUE;
}

#endif // #ifdef Plotter_cxx
