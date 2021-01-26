#ifndef __EVENT_STEP_H__
#define __EVENT_STEP_H__

#include "Event.h"
#include <string>
namespace df {

	const std::string STEP_EVENT = "df::step";

	class EventStep : public Event{
	private:
		int step_count;

	public:
		EventStep();

		EventStep(int init_step_count);
	
		void setStepCount(int new_step_count);

		int getStepCount() const;
	};
}

#endif // __EVENT_STEP_H__

