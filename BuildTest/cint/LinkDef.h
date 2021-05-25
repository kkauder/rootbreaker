#ifdef __CINT__

// General preamble

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

// namespaces
#pragma link C++ namespace dicttest;

// #pragma link C++ class TLorentzVector+;

// Functions
#pragma link C++ function BuildTree;

// Base event classes
#pragma link C++ class dicttest::EventMC+;
#pragma link C++ class dicttest::EventStupid+;
#pragma link C++ class dicttest::VirtualEvent+;
#pragma link C++ class dicttest::EventDis+;

// Event classes for individual generators
#pragma link C++ class dicttest::EventPythia+;

#endif
