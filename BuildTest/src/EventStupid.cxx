#include "EventStupid.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include <TCollection.h>
#include <TDatabasePDG.h>
#include <TDirectory.h>
#include <TParticlePDG.h>
#include <TTree.h>

namespace dicttest {

// We use these vectors/iterators a lot, so define
// some typedefs for convenience.
typedef std::vector<const TLorentzVector*> TrackVector;

EventStupid::EventStupid()
: nTracks(-1)
, track()
{
}

EventStupid::~EventStupid() {
  // No memory to clear. The TClonesArray takes care of the
  // particles when it is destroyed.
}

void EventStupid::AddLast(TLorentzVector* newtrack) {
  track = *newtrack;
}


}  // namespace dicttest
