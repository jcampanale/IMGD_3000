#include "InputManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "Object.h"
#include <vector>

using namespace df;

InputManager::InputManager() {
	setType("InputManager");
}

InputManager &InputManager::getInstance() {
	static InputManager single;
	return single;
}

int InputManager::startUp() {
	if (DM.isStarted() == false) {
		return -1;
	}

	sf::RenderWindow* window = DM.getWindow();

	window->setKeyRepeatEnabled(false);

	Manager::StartUp();
	LM.writeLog("IM started\n");
}

void InputManager::getInput() {
	sf::Event event;
	std::vector<Object*> allObjects = WM.getAllObjects();
	while (DM.getWindow()->pollEvent(event)) {
		EventKeyboard* keyboard = new EventKeyboard();
		keyboard::Key new_key;

		switch (event.key.code) {
		case sf::Keyboard::Space:
			new_key = keyboard::SPACE;
			break;
		case sf::Keyboard::Return:
			new_key = keyboard::RETURN;
			break;
		case sf::Keyboard::Escape:
			new_key = keyboard::ESCAPE;
			break;
		case sf::Keyboard::Tab:
			new_key = keyboard::TAB;
			break;
		case sf::Keyboard::Left:
			new_key = keyboard::LEFTARROW;
			break;
		case sf::Keyboard::Right:
			new_key = keyboard::RIGHTARROW;
			break;
		case sf::Keyboard::Up:
			new_key = keyboard::UPARROW;
			break;
		case sf::Keyboard::Down:
			new_key = keyboard::DOWNARROW;
			break;
		case sf::Keyboard::Pause:
			new_key = keyboard::PAUSE;
			break;
		case sf::Keyboard::Dash:
			new_key = keyboard::MINUS;
			break;
		case sf::Keyboard::Add:
			new_key = keyboard::PLUS;
			break;
		case sf::Keyboard::Tilde:
			new_key = keyboard::TILDE;
			break;
		case sf::Keyboard::Period:
			new_key = keyboard::PERIOD;
			break;
		case sf::Keyboard::Comma:
			new_key = keyboard::COMMA;
			break;
		case sf::Keyboard::Slash:
			new_key = keyboard::SLASH;
			break;
		case sf::Keyboard::Equal:
			new_key = keyboard::EQUAL;
			break;
		case sf::Keyboard::BackSlash:
			new_key = keyboard::BACKSLASH;
			break;
		case sf::Keyboard::Multiply:
			new_key = keyboard::MULTIPLY;
			break;
		case sf::Keyboard::Quote:
			new_key = keyboard::QUOTE;
			break;
		case sf::Keyboard::SemiColon:
			new_key = keyboard::SEMICOLON;
			break;
		case sf::Keyboard::LControl:
			new_key = keyboard::LEFTCONTROL;
			break;
		case sf::Keyboard::RControl:
			new_key = keyboard::RIGHTCONTROL;
			break;
		case sf::Keyboard::LShift:
			new_key = keyboard::LEFTSHIFT;
			break;
		case sf::Keyboard::RShift:
			new_key = keyboard::RIGHTSHIFT;
			break;
		case sf::Keyboard::F1:
			new_key = keyboard::F1;
			break;
		case sf::Keyboard::F2:
			new_key = keyboard::F2;
			break;
		case sf::Keyboard::F3:
			new_key = keyboard::F3;
			break;
		case sf::Keyboard::F4:
			new_key = keyboard::F4;
			break;
		case sf::Keyboard::F5:
			new_key = keyboard::F5;
			break;
		case sf::Keyboard::F6:
			new_key = keyboard::F6;
			break;
		case sf::Keyboard::F7:
			new_key = keyboard::F7;
			break;
		case sf::Keyboard::F8:
			new_key = keyboard::F8;
			break;
		case sf::Keyboard::F9:
			new_key = keyboard::F9;
			break;
		case sf::Keyboard::F10:
			new_key = keyboard::F10;
			break;
		case sf::Keyboard::F11:
			new_key = keyboard::F11;
			break;
		case sf::Keyboard::F12:
			new_key = keyboard::F12;
			break;
		case sf::Keyboard::A:
			new_key = keyboard::A;
			break;
		case sf::Keyboard::B:
			new_key = keyboard::B;
			break;
		case sf::Keyboard::C:
			new_key = keyboard::C;
			break;
		case sf::Keyboard::D:
			new_key = keyboard::D;
			break;
		case sf::Keyboard::E:
			new_key = keyboard::E;
			break;
		case sf::Keyboard::F:
			new_key = keyboard::F;
			break;
		case sf::Keyboard::G:
			new_key = keyboard::G;
			break;
		case sf::Keyboard::H:
			new_key = keyboard::H;
			break;
		case sf::Keyboard::I:
			new_key = keyboard::I;
			break;
		case sf::Keyboard::J:
			new_key = keyboard::J;
			break;
		case sf::Keyboard::K:
			new_key = keyboard::K;
			break;
		case sf::Keyboard::L:
			new_key = keyboard::L;
			break;
		case sf::Keyboard::M:
			new_key = keyboard::M;
			break;
		case sf::Keyboard::N:
			new_key = keyboard::N;
			break;
		case sf::Keyboard::O:
			new_key = keyboard::O;
			break;
		case sf::Keyboard::P:
			new_key = keyboard::P;
			break;
		case sf::Keyboard::Q:
			new_key = keyboard::Q;
			break;
		case sf::Keyboard::R:
			new_key = keyboard::R;
			break;
		case sf::Keyboard::S:
			new_key = keyboard::S;
			break;
		case sf::Keyboard::T:
			new_key = keyboard::T;
			break;
		case sf::Keyboard::U:
			new_key = keyboard::U;
			break;
		case sf::Keyboard::V:
			new_key = keyboard::V;
			break;
		case sf::Keyboard::W:
			new_key = keyboard::W;
			break;
		case sf::Keyboard::X:
			new_key = keyboard::X;
			break;
		case sf::Keyboard::Y:
			new_key = keyboard::Y;
			break;
		case sf::Keyboard::Z:
			new_key = keyboard::Z;
			break;
		case sf::Keyboard::Num1:
			new_key = keyboard::NUM1;
			break;
		case sf::Keyboard::Num2:
			new_key = keyboard::NUM2;
			break;
		case sf::Keyboard::Num3:
			new_key = keyboard::NUM3;
			break;
		case sf::Keyboard::Num4:
			new_key = keyboard::NUM4;
			break;
		case sf::Keyboard::Num5:
			new_key = keyboard::NUM5;
			break;
		case sf::Keyboard::Num6:
			new_key = keyboard::NUM6;
			break;
		case sf::Keyboard::Num7:
			new_key = keyboard::NUM7;
			break;
		case sf::Keyboard::Num8:
			new_key = keyboard::NUM8;
			break;
		case sf::Keyboard::Num9:
			new_key = keyboard::NUM9;
			break;
		case sf::Keyboard::Num0:
			new_key = keyboard::NUM0;
			break;
		case sf::Keyboard::Backspace:
			new_key = keyboard::BACKSPACE;
			break;
		}

		EventMouse* mouse = new EventMouse();
		Mouse::Button new_button;

		switch (event.key.code) {
		case sf::Mouse::Left:
			new_button = Mouse::LEFT;
			break;
		case sf::Mouse::Right:
			new_button = Mouse::RIGHT;
			break;
		case sf::Mouse::Middle:
			new_button = Mouse::MIDDLE;
			break;
		}

		if (event.type == sf::Event::KeyPressed) {
			LM.writeLog("KeyPressed : %d\n", (int)new_key);
			keyboard->setKey(new_key);
			for (int i = 0; i < allObjects.size(); i++) {
				allObjects[i]->eventHandler(keyboard);
			}
		}
		else if (event.type == sf::Event::KeyReleased) {
			LM.writeLog("KeyReleased\n");
			keyboard->setKey(new_key);
			for (int i = 0; i < allObjects.size(); i++) {
				allObjects[i]->eventHandler(keyboard);
			}
		}
		else if (event.type == sf::Event::MouseMoved) {	
			LM.writeLog("MouseMoved\n");
			Vector mouseMovement;
			sf::Vector2i getSFPosition = sf::Mouse::getPosition();
			mouseMovement.setX(getSFPosition.x);
			mouseMovement.setY(getSFPosition.y);
			mouse->setMousePosition(mouseMovement);
			for (int i = 0; i < allObjects.size(); i++) {
				allObjects[i]->eventHandler(mouse);
			}
		}
		else if (event.type == sf::Event::MouseButtonPressed) {
			LM.writeLog("MouseButtonPressed : %d\n", (int)new_button);
			mouse->setMouseButton(new_button);
			for (int i = 0; i < allObjects.size(); i++) {
				allObjects[i]->eventHandler(mouse);
			}
		}
	}
}

void InputManager::shutDown() {
	LM.writeLog("IM shutting down\n");
	sf::RenderWindow* window = DM.getWindow();
	window->setKeyRepeatEnabled(true);
}