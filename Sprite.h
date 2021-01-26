#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <string>
#include "Frame.h"
#include "Color.h"

namespace df {
	class Sprite {
	private:
		int m_width;
		int m_height;
		int m_max_frame_count;
		int m_frame_count;
		Color m_color;
		int m_slowdown;
		Frame* m_frame;
		std::string m_label;
		Sprite();

	public:
		~Sprite();

		Sprite(int max_frames);

		void setWidth(int new_width);

		int getWidth() const;

		void setHeight(int new_height);

		int getHeight() const;

		void setColor(Color new_color);

		Color getColor() const;

		int getFrameCount() const;

		int addFrame(Frame new_frame);

		Frame getFrame(int frame_number) const;

		void setLabel(std::string new_label);

		std::string getLabel() const;

		void setSlowdown(int new_sprite_slowdown);

		int getSlowdown() const;

		int draw(int frame_number, Vector position) const;

	};
}
#endif //__SPRITE_H__	
