#include "EventKeyboard.h"
using namespace df;

EventKeyboard::EventKeyboard() {
	setType(KEYBOARD_EVENT);
}

void EventKeyboard::setKey(keyboard::Key new_key) {
	m_key_val = new_key;
}

keyboard::Key EventKeyboard::getKey() const {
	return m_key_val;
}

void EventKeyboard::setKeyboardAction(EventKeyboardAction new_action) {
	m_keyboard_action = new_action;
}

EventKeyboardAction EventKeyboard::getKeyboardAction() const {
	return m_keyboard_action;
}