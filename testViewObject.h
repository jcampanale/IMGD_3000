#pragma once

#include "Object.h"
#include "ViewObject.h"
#include "Event.h"

#define VIEW_OBJECT_STRING "Test"

class testViewObject : public df::ViewObject{
public:
	testViewObject();
	int eventHandler(const df::Event* p_e);

};

