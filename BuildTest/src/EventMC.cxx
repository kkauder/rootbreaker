#include "EventMC.h"

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

EventMC::EventMC()
: nTracks(-1)
, particles("TLorentzVector", 100)
{
}

EventMC::~EventMC() {
  // No memory to clear. The TClonesArray takes care of the
  // particles when it is destroyed.
}

void EventMC::AddLast(TLorentzVector* track) {
  new(particles[particles.GetEntries()]) TLorentzVector(*track);
  nTracks = particles.GetEntries();
}


  // TrackVector EventMC::GetTracks() const {
//   TrackVector tracks;
//   TObject* object(NULL);
//   TIter next(&particles);
//   while ((object = next())) {
//     tracks.push_back(static_cast<ParticleMC*>(object));
//   }  // while
//   return tracks;
// }


}  // namespace dicttest
