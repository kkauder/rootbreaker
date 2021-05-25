// Load and smear a file,
// Then create a variety of QA plots
// This implementation mirrors the "standard" work flow
// Build -> Smear -> Load and befriend -> Analyze

#include <functions.h>
#include <smear/functions.h>

#include "EventPythia.h"
#include "EventStupid.h"

// Note: The remaining includes are not necessary for eic-smear usage
#include <TSystem.h>
#include <TFile.h>
#include <TChain.h>
#include <TCanvas.h>

#include <string>
#include <iostream>
#include <exception>
#include <vector>

// Convenience only
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
  
int main(int argc, char* argv[]){
  // Set up output name
  TString basename = "test";
  TString inname=basename+".txt";

  auto buildresult = BuildTree(inname.Data(), ".", -1);

  // Now load that tree - this should work
  TChain* c = new TChain("EICTree");
  c->Add(inname+".root");
  c->Show(0);

  // Now more in-depth manipulation - this breaks?
  TClass branchClass(c->GetBranch("event")->GetClassName());
  if (branchClass.InheritsFrom("dicttest::EventDis")) {
    cout << "yarp" << endl;
  } else {
    cout << "norp" << endl;
  } 
  
  
  // Smear::Detector detector;
  // detector = BuildByName("matrix02b3");
  
  // // Convert input file to tree
  // // --------------------------
  // string txtfilename="ep_hiQ2.20x250.small.txt.gz";
  // auto buildresult = BuildTree(txtfilename.c_str(), ".", -1);
  // if ( buildresult !=0 ){
  //   cerr << "Failed to build a tree from " << txtfilename << endl;
  //   return buildresult;
  // }

  // TChain* c = new TChain("EICTree");
  // c->Add(rootname);
  // c->Show(0);

  // dicttest::EventPythia* evp;
  // dicttest::EventPythia ev;
  
  // TFile inFile(rootname, "READ");
  // TTree* mcTree(NULL);
  // inFile.GetObject("EICTree", mcTree);
  // TClass branchClass(mcTree->GetBranch("event")->GetClassName());
  // if (branchClass.InheritsFrom("dicttest::EventDis")) {
  //   cout << "yarp" << endl;
  // } else {
  //   cout << "norp" << endl;
  // } 

  

  // DoNonsense( rootname);
  
  // // Smear the tree
  // // --------------
  // TString smearedname = rootname;
  // smearedname.ReplaceAll (".root",".smeared.root" );
  // // Can disable warnings here.
  // // Many warnings are harmless ( x or y can be smeared to values >1)
  // // But it is recommended to leave it on and follow up on "inf", "nan" etc. if you test a new detector
  // // dicttest::DisKinematics::BoundaryWarning=false;
  // SmearTree( detector, rootname.Data(), smearedname.Data());

  return 0;
}
// ---------------------------------------------------------------
