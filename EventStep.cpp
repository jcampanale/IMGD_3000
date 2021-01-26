#include "EventStep.h"
#include "LogManager.h"
using namespace df;

EventStep::EventStep() {
	setType(STEP_EVENT);
	setStepCount(0);
}
EventStep::EventStep(int init_step_count) {
	setType(STEP_EVENT);
	setStepCount(init_step_count);
	LM.writeLog("EventStep created with count : %d\n", init_step_count);
}

void EventStep::setStepCount(int new_step_count) {
	step_count = new_step_count;
}

int EventStep::getStepCount() const {
	return step_count;
}