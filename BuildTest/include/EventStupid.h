
#ifndef INCLUDE_EICSMEAR_DICTTEST_EVENTStupid_H_
#define INCLUDE_EICSMEAR_DICTTEST_EVENTStupid_H_

#include <string>
#include <vector>

#include <TClonesArray.h>
#include <TLorentzVector.h>

#include "EventDis.h"

class TTree;

namespace dicttest {

/**
 Abstract base class for DIS Monte Carlo events.
 Implements common event properties and methods.
 */
class EventStupid : public EventDis {
 public:
  /**
   Constructor.
   */
  EventStupid();

  /**
   Destructor.
   */
  virtual ~EventStupid();

  /**
   Add a copy of a track argument to the end of the track list.
   @param [in] Pointer to the track to add.
   */
  virtual void AddLast(TLorentzVector* track);

  virtual UInt_t GetNTracks() const;

  virtual TLorentzVector GetTrack() const;

  /**
   Sets the track count for this event.
   @param [in] n The track count, an integer
   */
  virtual void SetNTracks(int n);


 protected:
  Int_t nTracks;  ///< Number of Particles in the event (intermediate + final)
  TLorentzVector track;  ///< Particle list

  ClassDef(dicttest::EventStupid, 2)
};

inline UInt_t EventStupid::GetNTracks() const {
  return 1;
}

 inline TLorentzVector EventStupid::GetTrack() const {
   return track;
}

inline void EventStupid::SetNTracks(int n) {
  nTracks = n;
}

}  // namespace dicttest

#endif  // INCLUDE_EICSMEAR_DICTTEST_EVENTStupid_H_
