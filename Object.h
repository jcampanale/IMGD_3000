#ifndef __OBJECT_H__
#define __OBJECT_H__


#include <string>
#include "Vector.h"
#include "Event.h"
#include "Animation.h"
#include "Box.h"

namespace df {

	const int MAX_ALTITUDE = 4;

	enum Solidness {
		HARD,
		SOFT,
		SPECTRAL,
	};

	class Object {
		
	private:
		int id;
		Solidness m_solidness;
		std::string type;
		Vector position;
		int m_altitude;
		Vector m_direction;
		float m_speed;
		bool m_no_soft;
		Sprite* m_sprite;
		Animation m_animation;
		Box m_box;

	public:
		Object();

		virtual ~Object();

		int setAltitude(int new_altitude);

		int getAltitude() const;

		void setSpeed(float speed);

		float getSpeed() const;

		void setDirection(Vector new_direction);

		Vector getDirection() const;

		void setVelocity(Vector new_velocity);

		Vector getXVelocity() const;

		Vector predictPosition();

		void setId(int new_id);

		int getId() const;

		void setType(std::string new_type);

		std::string getType() const;

		void setPos(Vector new_pos);

		Vector getPos() const;

		virtual int eventHandler(const Event* p_event);

		virtual int draw();

		bool isSolid() const;

		int setSolidness(Solidness new_solid);

		Solidness getSolidness() const;

		void setNoSoft();

		bool getNoSoft() const;

		int setSprite(std::string sprite_label);

		void setAnimation(Animation new_animation);

		Animation getAnimation() const;

		void setBox(Box new_box);

		Box getBox() const;
	};
}

#endif //__OBJECT_H__