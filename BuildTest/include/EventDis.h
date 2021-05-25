#ifndef INCLUDE_EICSMEAR_DICTTEST_EVENTDIS_H_
#define INCLUDE_EICSMEAR_DICTTEST_EVENTDIS_H_

#include <cmath>  // For pow
#include <Rtypes.h>  // For ClassDef
#include "VirtualEvent.h"

namespace dicttest {
class EventDis : public VirtualEvent {
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
