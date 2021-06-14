// Load and smear a file,
// Then create a variety of QA plots
// This implementation mirrors the "standard" work flow
// Build -> Smear -> Load and befriend -> Analyze

#include <functions.h>
#include "EventPythia.h"

#include <TSystem.h>
#include <TClass.h>
#include <TChain.h>

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
  
int main(int argc, char* argv[]){

  // Make a root tree
  TString rootname = "test.root";
  auto buildresult = BuildTree(rootname.Data());

  // Now load that tree - this should work
  TChain* c = new TChain("EICTree");
  c->Add(rootname);
  c->Show(0);

  // Now more in-depth manipulation - this breaks
  TClass branchClass(c->GetBranch("event")->GetClassName());
  if (branchClass.InheritsFrom("dicttest::EventMC")) {
    cout << "yarp" << endl;
  } else {
    cout << "norp" << endl;
  }

  // // Update, this workaround fixes the issue. 
  // TClass* branchClass = TClass::GetClass(c->GetBranch("event")->GetClassName());
  // if (branchClass->InheritsFrom("dicttest::EventMC")) {
  //   cout << "yarp" << endl;
  // } else {
  //   cout << "norp" << endl;
  // }

    
  return 0;
}
// ---------------------------------------------------------------
