#pragma once
#include "Object.h"
#include "Event.h"
#include "Vector.h"
#include <string>

namespace df {
	class testObject : public Object {
	private:
		std::string type;
	
	public:
		testObject();
		int eventHandler(const df::Event* p_e);
		int draw(Vector where);
	};

}