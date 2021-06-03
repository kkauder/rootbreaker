
#ifndef INCLUDE_EICSMEAR_DICTTEST_EVENTMC_H_
#define INCLUDE_EICSMEAR_DICTTEST_EVENTMC_H_

#include <string>
#include <vector>
#include <cmath> // for nan

#include <TObject.h>
#include <Rtypes.h>  // For ClassDef
#include <TClonesArray.h>
#include <TLorentzVector.h>

namespace dicttest {

/**
 Abstract base class for DIS Monte Carlo events.
 Implements common event properties and methods.
 */
class EventMC : public TObject {
 public:
  /**
   Constructor.
   */
  EventMC();

  /**
   Destructor.
   */
  virtual ~EventMC();

  /**
   Returns the number of tracks in the event.
   */
  virtual UInt_t GetNTracks() const;

  /**
   Add a copy of a track argument to the end of the track list.
   @param [in] Pointer to the track to add.
   */
  virtual void AddLast(TLorentzVector* track);

  /**
   Returns the nth track.
   Returns NULL if the track number is out of the range [0, GetNTracks()).
   @param [in] The track index, in the range [0, GetNTracks()).
   */
  virtual TLorentzVector* GetTrack(UInt_t) const;

  /**
   Sets the track count for this event.
   @param [in] n The track count, an integer
   */
  virtual void SetNTracks(int n);

  /**
     Sets Bjorken-x of the event.
  */
  virtual void SetX( const Double_t newx);
  
  /**
   Returns Bjorken-x of the event.
  */
  virtual Double_t GetX() const;

 protected:
  Double32_t x;  ///< Bjorken scaling variable
  Int_t nTracks;  ///< Number of Particles in the event (intermediate + final)
  TClonesArray particles;  ///< Particle list

  ClassDef(dicttest::EventMC, 2)
};

inline UInt_t EventMC::GetNTracks() const {
  return particles.GetEntries();
}

inline TLorentzVector* EventMC::GetTrack(UInt_t u) const {
  if (u < (UInt_t)particles.GetEntries()) {
    return static_cast<TLorentzVector*>(particles.At(u));
  } else {
    return NULL;
  }  // if
}

inline void EventMC::SetNTracks(int n) {
  nTracks = n;
}

inline void EventMC::SetX( const Double_t newx){
  x = newx;
 }

inline Double_t EventMC::GetX() const {
  return x;
}


}  // namespace dicttest

#endif  // INCLUDE_EICSMEAR_DICTTEST_EVENTMC_H_
