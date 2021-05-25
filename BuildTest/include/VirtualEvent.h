#ifndef INCLUDE_EICSMEAR_DICTTEST_VIRTUALEVENT_H_
#define INCLUDE_EICSMEAR_DICTTEST_VIRTUALEVENT_H_

#include <TObject.h>
#include <vector>

namespace dicttest {

class VirtualEvent : public TObject {
 public:
  /**
   Destructor
   */
  virtual ~VirtualEvent() { }

  /**
   Returns the number of tracks in the event.
   */
  virtual UInt_t GetNTracks() const = 0;

  ClassDef(dicttest::VirtualEvent, 1)
};

}  // namespace dicttest

#endif  // INCLUDE_EICSMEAR_DICTTEST_VIRTUALEVENT_H_
