/**
 smearLinkDef.h

 \file
 Declaration of class smearLinkDef.

 \author Thomas Burton 
 \date 5/8/12
 \copyright 2012 BNL. All rights reserved.
*/

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclasses;
#pragma link C++ nestedtypedef;

// STL classes
// Needed for the status field in ParticleMCS
// #pragma link C++ class std::bitset<64>+;

// Namespace
#pragma link C++ namespace Smear;

// Functions
#pragma link C++ function SmearTree;


#endif // __CINT__
