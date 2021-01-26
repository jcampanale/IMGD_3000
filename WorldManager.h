#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include "Manager.h"
#include "Object.h"
#include "Box.h"
#include <vector>

#define WM df::WorldManager::getInstance()

namespace df {

	class WorldManager : public Manager{
	private:
		WorldManager();
		WorldManager(WorldManager const&);
		void operator=(WorldManager const&);

		std::vector<Object*> m_updates;
		std::vector<Object*> m_deletions;

		Box boundary;
		Box view;

		Object* p_view_following;

	public:
		const int MAX_ALTITUDE = 4;

		static WorldManager& getInstance();
		
		int startUp();

		void shutDown();

		int insertObject(Object* p_o);

		int removeObject(Object* p_o);

		std::vector<Object*> getAllObjects() const;

		std::vector<Object*> objectsOfType(std::string type) const;

		void update();

		int markForDelete(Object* p_o);

		void draw();

		int moveObject(Object* p_o, Vector where);

		std::vector<Object*> getCollisions(Object* p_o, Vector where) const;
	
		void setBoundary(Box new_boundary);

		Box getBoundary() const;

		void setView(Box new_view);

		Box getView() const;

		void setViewPosition(Vector view_pos);

		int setViewFollowing(Object* p_new_view_following);
	};

}
#endif // __WORLD_MANAGER_H__
