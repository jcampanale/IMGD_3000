#include "ViewEvent.h"
using namespace df;

ViewEvent::ViewEvent() {
	setType(VIEW_EVENT);
}

ViewEvent::ViewEvent(std::string new_tag, int new_value, bool new_delta) {
	setType(VIEW_EVENT);
	m_tag = new_tag;
	m_value = new_value;
	m_delta = new_delta;
}

void ViewEvent::setTag(std::string new_tag) {
	m_tag = new_tag;
}

std::string ViewEvent::getTag() const {
	return m_tag;
}

void ViewEvent::setValue(int new_value) {
	m_value = new_value;
}

int ViewEvent::getValue() const {
	return m_value;
}

void ViewEvent::setDelta(bool new_delta) {
	m_delta = new_delta;
}

bool ViewEvent::getDelta() const {
	return m_delta;
}