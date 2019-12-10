#define Plotter_cxx
// The class definition in Plotter.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("Plotter.C")
// Root > T->Process("Plotter.C","some options")
// Root > T->Process("Plotter.C+")
//

#include "Plotter.h"
#include <TH2.h>
#include <TStyle.h>


void Plotter::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void Plotter::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);
  //if you want kinematic bins you must define fHisbins here
   //fHisbins=new TH*()
   if(fHisbins) fOutput->Add(fHisbins);
   //fHisbins->SetXTitle();//give useful axis name
   //fHisbins->SetYTitle();//give useful axis name
   THSHisto::ChangeNames();
   THSHisto::LoadCut("Cut1");
   THSHisto::LoadHistograms();
}

Bool_t Plotter::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Plotter::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   GetEntry(entry); //lazy and slow, you can speed the code up by getting the branches you need to use instead
   //Ready to do some analysis here, before the Fill
   pi=TLorentzVector(P4_fP_fX[0],P4_fP_fY[0],P4_fP_fZ[0],P4_fE[0]);
   prot=TLorentzVector(P4_fP_fX[1],P4_fP_fY[1],P4_fP_fZ[1],P4_fE[1]);
   es=TLorentzVector(P4_fP_fX[2],P4_fP_fY[2],P4_fP_fZ[2],P4_fE[2]);
   vp=TLorentzVector(P4_fP_fX[3],P4_fP_fY[3],P4_fP_fZ[3],P4_fE[3]);
   pidir=ScatteredVector(vp.Vect(),pi.Vect());
   protdir=ScatteredVector(vp.Vect(),prot.Vect());

   //Int_t kinBin=GetKinBin();//if fHisbins is defined need to give this meaningful arguments
   //FillHistograms("Cut1",kinBin);
   FillHistograms("Cut1",0);
   //EnterKinBinList(kinBin,entry);//save evente in kinematic bins entry lists
   THSOutput::HSProcessFill(); 


   return kTRUE;
}

void Plotter::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Plotter::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
void Plotter::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  // e.g fOutput->Add(MapHist(new TH1F("Mp1"+sLabel,"M_{p1}"+sLabel,100,0,2)));
 fOutput->Add(MapHist(new TH1F("Q2"+sLabel,"-Q^{2}"+sLabel,100,0,1)));
 fOutput->Add(MapHist(new TH1F("Eg"+sLabel,"E^{#gamma}"+sLabel,100,5,11)));
 fOutput->Add(MapHist(new TH1F("vpPhi"+sLabel,"Virtual Photon #phi"+sLabel,90,-180,180)));

 fOutput->Add(MapHist(new TH1F("piMom"+sLabel,"#pi+ Momentum"+sLabel,100,4,12)));
 fOutput->Add(MapHist(new TH1F("piPhi"+sLabel,"#pi+ #phi"+sLabel,90,-180,180)));
 fOutput->Add(MapHist(new TH1F("piTheta"+sLabel,"#pi+ #theta"+sLabel,90,0,20)));

 fOutput->Add(MapHist(new TH1F("nMom"+sLabel,"neutron Momentum"+sLabel,100,0,10)));
 fOutput->Add(MapHist(new TH1F("nPhi"+sLabel,"neutron #phi"+sLabel,90,-180,180)));
 fOutput->Add(MapHist(new TH1F("nTheta"+sLabel,"neutron #theta"+sLabel,90,0,180)));
 
 fOutput->Add(MapHist(new TH1F("tDist"+sLabel,"-t distribution"+sLabel,100,0,5)));
 
 fOutput->Add(MapHist(new TH2F("pivpPhi"+sLabel,"#pi+ #phi V #gamma #phi"+sLabel,90,-180,180,90,-180,180)));

 //end of histogram list
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void Plotter::FillHistograms(TString sCut,Int_t bin){
  fCurrCut=sCut;
  fCurrBin=bin;
  //Get histogram from list
  //Fill histogram
  TString sLabel;
  sLabel=sCut+fVecBinNames[bin];

  // e.g. FindHist("Mp1"+sLabel)->Fill(fp1->M());
  FindHist("Q2"+sLabel)->Fill(-vp.M2());
  FindHist("Eg"+sLabel)->Fill(vp.E());
  FindHist("vpPhi"+sLabel)->Fill(vp.Phi()*TMath::RadToDeg());

  FindHist("piMom"+sLabel)->Fill(pi.Rho());
  FindHist("piTheta"+sLabel)->Fill(pi.Theta()*TMath::RadToDeg());//lab
  FindHist("piPhi"+sLabel)->Fill(pidir.Phi()*TMath::RadToDeg());

  FindHist("nMom"+sLabel)->Fill(prot.Rho());
  FindHist("nTheta"+sLabel)->Fill(prot.Theta()*TMath::RadToDeg());//lab
  FindHist("nPhi"+sLabel)->Fill(protdir.Phi()*TMath::RadToDeg());

  FindHist("pivpPhi"+sLabel)->Fill(vp.Phi()*TMath::RadToDeg(),pidir.Phi()*TMath::RadToDeg());

  TLorentzVector trans=vp-pi;
  FindHist("tDist"+sLabel)->Fill(-trans.M2());

}
TVector3 Plotter::ScatteredVector(TVector3 v_inc,TVector3 v_sc){
  TVector3 XLAB(1,0,0);
  TVector3 YLAB(0,1,0);
  TVector3 ZLAB(0,0,1);

  //Define primed frame
  TVector3 Zprime=v_inc.Unit();//Nucleon momentum direction
  TVector3 Yprime=ZLAB.Cross(-v_inc);//BeamXpi momentum or protonXbeam
  Yprime=Yprime.Unit();
  TVector3 Xprime=Yprime.Cross(Zprime);
  Xprime=Xprime.Unit();
  // Xprime.Print();
  // Yprime.Print();
  //Zprime.Print();
   //Make rotation matrix
  Double_t Drot[3][3];
  Drot[0][0]=XLAB.Dot(Xprime);Drot[1][0]=YLAB.Dot(Xprime);Drot[2][0]=ZLAB.Dot(Xprime);
  Drot[0][1]=XLAB.Dot(Yprime);Drot[1][1]=YLAB.Dot(Yprime);Drot[2][1]=ZLAB.Dot(Yprime);
  Drot[0][2]=XLAB.Dot(Zprime);Drot[1][2]=YLAB.Dot(Zprime);Drot[2][2]=ZLAB.Dot(Zprime);
  //Calculate new coordinates
  TVector3 v_scat; 
  v_scat.SetX(Drot[0][0]*v_sc.X()+Drot[1][0]*v_sc.Y()+Drot[2][0]*v_sc.Z());
  v_scat.SetY(Drot[0][1]*v_sc.X()+Drot[1][1]*v_sc.Y()+Drot[2][1]*v_sc.Z());
  v_scat.SetZ(Drot[0][2]*v_sc.X()+Drot[1][2]*v_sc.Y()+Drot[2][2]*v_sc.Z());
  return v_scat;

}
