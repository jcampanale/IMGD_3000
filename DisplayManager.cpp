#include <iostream>
#include "DisplayManager.h"
#include "LogManager.h"
#include "Utility.h"
using namespace df;

DisplayManager::DisplayManager() {
	m_p_window = NULL;
}

DisplayManager& DisplayManager::getInstance() {
	static DisplayManager single;
	return single;
}

int DisplayManager::startUp() {
	LM.writeLog("DM started\n");
	if (m_p_window != NULL) {
		return 0;
	}

	m_p_window = new sf::RenderWindow(sf::VideoMode(900, 600), "SFML - Hello, world!");
	
	m_p_window->setMouseCursorVisible(false);
	m_p_window->setVerticalSyncEnabled(true);

	if (m_font.loadFromFile("df-font.ttf") == false) {
		std::cout << "Error! Unable to load font df-font.ttf" << std::endl;
		return -1;
	}
	
	int started = Manager::StartUp();
	return started;
}

sf::RenderWindow* DisplayManager::getWindow() const{
	return m_p_window;
}

int DisplayManager::drawCh(Vector world_pos, char ch, Color color) const{
	Utility ut;
	Vector view_pos = ut.worldToView(world_pos);
	
	if (m_p_window == NULL) {
		return -1;
	}

	Vector pixel_pos = spacesToPixels(world_pos);
	
	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(df::charWidth(), df::charHeight()));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	rectangle.setPosition(pixel_pos.getX() - charWidth() / 10,
		pixel_pos.getY() + charHeight() / 5);
	m_p_window->draw(rectangle);

	static sf::Text text("", m_font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold);

	if (charWidth() < charHeight()) {
		text.setCharacterSize(charWidth() * 2);
	}
	else {
		text.setCharacterSize(charHeight() * 2);
	}

	switch (color) {
	case YELLOW:
		text.setFillColor(sf::Color::Yellow);
		break;
	case RED:
		text.setFillColor(sf::Color::Red);
		break;
	case BLACK:
		text.setFillColor(sf::Color::Black);
		break;
	case GREEN:
		text.setFillColor(sf::Color::Green);
		break;
	case BLUE:
		text.setFillColor(sf::Color::Blue);
		break;
	case MAGENTA:
		text.setFillColor(sf::Color::Magenta);
		break;
	case CYAN:
		text.setFillColor(sf::Color::Cyan);
		break;
	case WHITE:
		text.setFillColor(sf::Color::White);
		break;
	}

	text.setPosition(pixel_pos.getX(), pixel_pos.getY());
	m_p_window->draw(text);
	return 0;
}

float df::charHeight() {
	int vertPixels = DM.getVerticalPixels();
	int vert = DM.getVertical();
	
	float height = vertPixels / vert;
	return height;
}

float df::charWidth() {
	int horizPixels = DM.getHorizontalPixels();
	int horiz = DM.getHorizontal();

	float width = horizPixels / horiz;
	return width;
}

Vector df::spacesToPixels(Vector spaces) {
	Vector returnVector;
	float x = spaces.getX();
	float stpX = x * charWidth();
	returnVector.setX(stpX);
	float y = spaces.getY();
	float stpY = y * charHeight();
	returnVector.setY(stpY);
	return returnVector;
}

int DisplayManager::getVerticalPixels() const{
	return WINDOW_VERTICAL_PIXELS_DEFAULT;
}

int DisplayManager::getHorizontalPixels() const {
	return WINDOW_HORIZONTAL_PIXELS_DEFAULT;
}

int DisplayManager::getHorizontal() const {
	return WINDOW_HORIZONTAL_CHARS_DEFAULT;
}

int DisplayManager::getVertical() const {
	return WINDOW_VERTICAL_CHARS_DEFAULT;
}

int DisplayManager::swapBuffers() {
	LM.writeLog("swapBuffers called\n");
	if (m_p_window == NULL) {
		return -1;
	}

	m_p_window->display();

	m_p_window->clear();

	return 0;
}

int DisplayManager::drawString(Vector pos, std::string str, Justification just, Color color) const {
	Vector startingPos = pos;
	switch (just) {
	case CENTER_JUSTIFIED:
		startingPos.setX(pos.getX() - str.size() / 2);
		break;
	case RIGHT_JUSTIFIED:
		startingPos.setX(pos.getX() - str.size());
		break;
	case LEFT_JUSTIFIED:
	default:
		break;
	}

	for (int i = 0; i < str.size(); i++) {
		Vector tempPos(startingPos.getX() + i, startingPos.getY());
		drawCh(tempPos, str[i], color);
	}

	return 0;
}

bool DisplayManager::setBackgroundColor(sf::Color new_color) {
	m_window_background_color = new_color;
	return true;
}

void DisplayManager::shutDown() {
	m_p_window->close();
	LM.writeLog("DM shut down\n");
	Manager::ShutDown();
}