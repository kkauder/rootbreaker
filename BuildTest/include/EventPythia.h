#ifndef INCLUDE_EICSMEAR_DICTTEST_EVENTPYTHIA_H_
#define INCLUDE_EICSMEAR_DICTTEST_EVENTPYTHIA_H_

#include <string>
#include <Rtypes.h>

#include "EventMC.h"

namespace dicttest {

class EventPythia : public EventMC {
 public:

  /**
   Constructor.
   @param [in] str A text string setting event-wise quantities.
   */
  explicit EventPythia(const std::string& str = "");

  /**
   Destructor
   */
  virtual ~EventPythia();

  /* /\** */
  /*  Parses the event information from a text string. */
  /*  See the constructor for the string format. */
  /*  Returns true in the event of a successful read operation, */
  /*  false in case of an error. */
  /*  *\/ */
  /* virtual bool Parse(const std::string&); */

  /**
   Sets the true (not reconstructed) value for Q<sup>2</sup>.
   */
  virtual void SetTrueQ2(double Q2);

  /**
   Gets the true (not reconstructed) value for Q<sup>2</sup>.
   */
  virtual double GetTrueQ2() const;

  // Let them all be public; this access method dances for POD does not make sense;
  //protected:
  // Inline comments after field names will appear in ROOT
  // when EventPythia::Dump() is called.
  Double32_t  trueQ2;           ///< Generated Q<sup>2</sup> of the event,

  ClassDef(dicttest::EventPythia, 2)
};


inline void EventPythia::SetTrueQ2(double Q2) {
  trueQ2 = Q2;
}

inline double EventPythia::GetTrueQ2() const {
  return trueQ2;
}


}  // namespace dicttest

#endif  // INCLUDE_EICSMEAR_DICTTEST_EVENTPYTHIA_H_
