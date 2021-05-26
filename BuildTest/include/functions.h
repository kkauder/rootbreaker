#ifndef INCLUDE_EICSMEAR_FUNCTIONS_H_
#define INCLUDE_EICSMEAR_FUNCTIONS_H_

#include <string>

#include <Rtypes.h>
#include <TString.h>

class TLorentzVector;

Long64_t BuildTree(const std::string& inputFileName,
                   const std::string& outputDirName = ".");

#endif  // INCLUDE_EICSMEAR_FUNCTIONS_H_
