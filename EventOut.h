#ifndef __EVENT_OUT_H__
#define __EVENT_OUT_H__

#include "Event.h"
#include <string>

namespace df {
	const std::string OUT_EVENT = "df::out";

	class EventOut : public Event {
	public:
		EventOut();
	};

}
#endif //__EVENT_OUT_H__

