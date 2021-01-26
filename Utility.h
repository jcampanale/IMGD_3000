#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "Vector.h"
#include "Box.h"
#include "Object.h"

namespace df {
	class Utility{
	public:
		bool positionsIntersect(Vector p1, Vector p2);

		bool boxIntersectsBox(Box A, Box B);

		Box getWorldBox(const Object* p_o);
	
		Box getWorldBox(const Object* p_o, Vector where);

		Vector worldToView(Vector world_pos);

		Vector viewToWorld(Vector view_pos);
	};
}

#endif //__UTILITY_H__

