#include "testObject.h"
#include "EventStep.h"
#include "LogManager.h"
#include "DisplayManager.h"
using namespace df;
testObject::testObject() {
	setAltitude(0);
}

int testObject::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::STEP_EVENT) {
		LM.writeLog("Step Event received\n");
		return 1;
	}
	return 0;
}

int testObject::draw(Vector where) {
	DM.drawString(where, "test", LEFT_JUSTIFIED, GREEN);
	return 0;
}
