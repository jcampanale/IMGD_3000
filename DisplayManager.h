#ifndef __DISPLAY_MANAGER_H__
#define __DISPLAY_MANAGER_H__

#include <SFML/Graphics.hpp>
#include <string>
#include "Color.h"
#include "Manager.h"
#include "Vector.h"

#define DM df::DisplayManager::getInstance()

namespace df {
		
	const int WINDOW_HORIZONTAL_PIXELS_DEFAULT = 1024;
	const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
	const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
	const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
	const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar|sf::Style::Close;
	const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
	const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
	const std::string FONT_FILE_DEFAULT = "df-font.ttf";

	float charHeight(void);

	float charWidth(void);

	Vector spacesToPixels(Vector spaces);

	Vector pixelsToSpaces(Vector pixels);

	enum Justification {
		LEFT_JUSTIFIED,
		CENTER_JUSTIFIED,
		RIGHT_JUSTIFIED,
	};

	class DisplayManager : public Manager{
	private:
		DisplayManager();
		DisplayManager(DisplayManager const&);
		void operator=(DisplayManager const&);
		sf::Font m_font;
		sf::RenderWindow* m_p_window;
		sf::Color m_window_background_color;
		int m_window_horizontal_pixels;
		int m_window_vertical_pixels;
		int m_window_horizontal_chars;
		int m_window_vertical_chars;

	public:
		static DisplayManager& getInstance();

		int startUp();

		void shutDown();

		bool setBackgroundColor(sf::Color new_color);

		int drawCh(Vector world_pos, char ch, Color color) const;

		int getHorizontal() const;

		int getVertical() const;

		int getHorizontalPixels() const;

		int getVerticalPixels() const;

		int swapBuffers();

		sf::RenderWindow* getWindow() const;

		int drawString(Vector pos, std::string str, Justification just, Color color) const;
	};
}
#endif //__DISPLAY_MANAGER_H__
