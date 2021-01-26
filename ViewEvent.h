#ifndef __VIEW_EVENT_H__
#define __VIEW_EVENT_H__

#include "Event.h"
#include <string>

namespace df {
	const std::string VIEW_EVENT = "df::view";

	class ViewEvent : public Event{
	private:
		std::string m_tag;
		int m_value;
		bool m_delta;
	public:
		ViewEvent();

		ViewEvent(std::string new_tag, int new_value, bool new_delta);

		void setTag(std::string new_tag);

		std::string getTag() const;

		void setValue(int new_value);

		int getValue() const;

		void setDelta(bool new_delta);

		bool getDelta() const;
	};
}

#endif //__VIEW_EVENT_H__

