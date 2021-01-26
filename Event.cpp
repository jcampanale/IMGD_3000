#include "Event.h"
using namespace df;

Event::Event() {
	//constructor
	setType("Event");
}

void Event::setType(std::string new_type) {
	type = new_type;
}

std::string Event::getType() const {
	return type;
}

Event::~Event() {
	//destructor
}