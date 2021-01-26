#ifndef __FRAME_H__
#define __FRAME_H__

#include <string>
#include "Vector.h"
#include"Color.h"

namespace df {
	class Frame {
	private:
		int m_width;
		int m_height;
		std::string m_frame_str;

	public:
		Frame();

		Frame(int new_width, int new_height, std::string frame_str);

		void setWidth(int new_width);

		int getWidth() const;

		void setHeight(int new_height);

		int getHeight() const;
		
		void setString(std::string new_string);

		std::string getString() const;

		int draw(Vector position, Color color) const;

	};
}

#endif //__FRAME_H__