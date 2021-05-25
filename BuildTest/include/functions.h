#ifndef INCLUDE_EICSMEAR_FUNCTIONS_H_
#define INCLUDE_EICSMEAR_FUNCTIONS_H_

#include <string>

#include <Rtypes.h>
#include <TString.h>

class TLorentzVector;

Long64_t BuildTree(const std::string& inputFileName,
                   const std::string& outputDirName = ".",
                   const Long64_t maxEvent = 0,
                   const std::string& logFileName = "");


#endif  // INCLUDE_EICSMEAR_FUNCTIONS_H_
