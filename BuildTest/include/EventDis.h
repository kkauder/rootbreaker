#ifndef INCLUDE_EICSMEAR_DICTTEST_EVENTDIS_H_
#define INCLUDE_EICSMEAR_DICTTEST_EVENTDIS_H_

#include <cmath> // for nan
#include <TObject.h>
#include <Rtypes.h>  // For ClassDef

namespace dicttest {
class EventDis : public TObject {
 public:
  /**
   Destructor.
   */
  virtual ~EventDis();

  /**
   Default constructor.
   */
  EventDis();

  /**
   Returns the number of tracks in the event.
   */
  virtual UInt_t GetNTracks() const = 0;

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


  ClassDef(dicttest::EventDis, 1)
};

inline void EventDis::SetX( const Double_t newx){
  x = newx;
 }

inline Double_t EventDis::GetX() const {
  return x;
}

   
}  // namespace dicttest

#endif  // INCLUDE_EICSMEAR_DICTTEST_EVENTDIS_H_
