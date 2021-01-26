#ifndef __EVENT_MOUSE_H__
#define __EVENT_MOUSE_H__

#include <string>
#include "Vector.h"
#include "Event.h"

namespace df {

	const std::string MSE_EVENT = "df::mouse";

	enum EventMouseAction {
		UNDEFINED_MOUSE_ACTION = -1,
		CLICKED,
		PRESSED,
		MOVED,
	};

	namespace Mouse {
		enum Button {
			UNDEFINED_MOUSE_BUTTON = -1,
			LEFT,
			RIGHT,
			MIDDLE,
		};
	}

	class EventMouse : public Event {
	private:
		EventMouseAction m_mouse_action;
		Mouse::Button m_mouse_button;
		Vector m_mouse_xy;

	public:
		EventMouse();

		void setMouseAction(EventMouseAction new_mouse_action);

		EventMouseAction getMouseAction() const;

		void setMouseButton(Mouse::Button new_mouse_button);

		Mouse::Button getMouseButton() const;

		void setMousePosition(Vector new_mouse_xy);

		Vector getMousePosition() const;
	};
}
#endif //__EVENT_MOUSE_H__