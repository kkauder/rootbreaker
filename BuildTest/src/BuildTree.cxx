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
BuildTree(const std::string& inputFileName,
          const std::string& outputDirName,
          const Long64_t maxEvent,
          const std::string& logFileName) {

  // Set the maximum size of the tree on disk.
  // Once this size is reached a new file is opened for continued writing.
  // Set 10 Gb. Us LL to force long integer.
  TTree::SetMaxTreeSize(10LL * 1024LL * 1024LL * 1024LL);

  // Get the input file name, stripping any leading directory path via
  // use of the BaseName() method from TSystem.
  TString outName = gSystem->BaseName(inputFileName.c_str());
  outName.Append(".root");

  TString outDir(outputDirName);
  if (!outDir.EndsWith("/")) outDir.Append('/');
  outName.Prepend(outDir);

  // Open the ROOT file and check it opened OK
  auto mRootFile = new TFile(outName, "RECREATE");
  if (!mRootFile->IsOpen()) {
    std::string message("Unable to open file ");
    throw std::runtime_error(message.append(outName));
  }  // if
  // Create the tree and check for errors
  auto mTree = new TTree("EICTree", "my EIC tree");
  if (!mTree) {
    std::string message("Error allocating TTree ");
    throw std::runtime_error(message.append("EICTree"));
  }  // if
  
  // Allocate memory for the branch buffer and
  // add the branch to the tree
  dicttest::EventMC* mEvent = new dicttest::EventPythia();
  mTree->Branch("event", mEvent->ClassName(),
		&mEvent, 32000, 99);
  // Auto-save every 500 MB
  mTree->SetAutoSave(500LL * 1024LL * 1024LL);

  mEvent->AddLast(new TLorentzVector());
  mEvent->AddLast(new TLorentzVector()); mTree->Fill();
  mEvent->AddLast(new TLorentzVector()); mTree->Fill();
  mTree->Write();
  mRootFile->Close();
  delete mRootFile;
  Long64_t result=0;
  if (result != 0) {
    std::cerr << "Tree building failed" << std::endl;
    return result;
  }  // if

  cout << "Building done" << endl;
  return result;
}
