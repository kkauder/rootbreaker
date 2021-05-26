#include <string>
#include <iostream>

#include <TString.h>
#include <TSystem.h>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>

#include "EventMC.h"
#include "EventPythia.h"

using std::cout;
using std::cerr;
using std::endl;

Long64_t
BuildTree(const std::string& outName ) {

  // Open the ROOT file and create tree
  auto mRootFile = new TFile(outName, "RECREATE");
  auto mTree = new TTree("EICTree", "my EIC tree");
  
  // Allocate memory for the branch buffer and
  // add the branch to the tree
  dicttest::EventMC* mEvent = new dicttest::EventPythia();
  mTree->Branch("event", mEvent->ClassName(),
		&mEvent, 32000, 99);
  // Auto-save every 500 MB
  mTree->SetAutoSave(500LL * 1024LL * 1024LL);

  // keeping it simple, just two really stupid event, not even clearing the ClonesArray
  mEvent->AddLast(new TLorentzVector());
  mEvent->AddLast(new TLorentzVector()); mTree->Fill();
  mEvent->AddLast(new TLorentzVector()); mTree->Fill();
  mTree->Write();
  mRootFile->Close();
  delete mRootFile;

  cout << "Building done" << endl;
  return 0;
}
