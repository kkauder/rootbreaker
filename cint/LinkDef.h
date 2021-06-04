#ifdef __CINT__

// General preamble

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

// namespaces
#pragma link C++ namespace dicttest;

// Functions
#pragma link C++ function BuildTree;

// Base event class
#pragma link C++ class dicttest::EventMC+;

// Event classes for individual generators
#pragma link C++ class dicttest::EventPythia+;

#endif
