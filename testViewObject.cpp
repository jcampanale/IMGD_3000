#include "testViewObject.h"
#include "EventStep.h"

testViewObject::testViewObject() {
	setLocation(df::ViewObjectLocation::TOP_RIGHT);
	setViewString(VIEW_OBJECT_STRING);
	setColor(df::BLUE);
}

int testViewObject::eventHandler(const df::Event* p_e) {
    if (df::ViewObject::eventHandler(p_e)) {
        return 1;
    }
    // If step, increment score every second (30 steps).
    if (p_e->getType() == df::STEP_EVENT) {
        if (dynamic_cast <const df::EventStep*> (p_e)
            ->getStepCount() % 30 == 0) {
            setValue(getValue() + 1);
        }
        return 1;
    }
}