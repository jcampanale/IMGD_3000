#include <vector>
#include "WorldManager.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include "Utility.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "ViewObject.h"
#include "ResourceManager.h"
#include <string>
using namespace df;

Utility ut2;

WorldManager::WorldManager() {
	setType("WorldManager");
}

WorldManager& WorldManager::getInstance() {
	static WorldManager single;
	return single;
}

int WorldManager::startUp() {
	int started = Manager::StartUp();
	//initialize everything to empty
	return started;
}

void WorldManager::shutDown() {
	LM.writeLog("WM shutDown\n");
	Manager::ShutDown();
	m_updates.clear();
}

int WorldManager::insertObject(Object* p_o) {
	m_updates.push_back(p_o);
	return 0;
}

int WorldManager::removeObject(Object* p_o) {
	int index = p_o->getId();
	m_updates.erase(m_updates.begin() + index);
	return 0;
}

std::vector<Object*> WorldManager::getAllObjects() const {
	return m_updates;
}

std::vector<Object*> WorldManager::objectsOfType(std::string type) const {
	std::vector<Object*> returnList;
	for (int i = 0; i < m_updates.size(); i++) {
		if (m_updates[i]->getType() == type)
			returnList.push_back(m_updates[i]);
	}
	return returnList;
}

void WorldManager::update() {
	for (int i = 0; i < m_updates.size(); i++) {
		Vector new_pos = m_updates[i]->predictPosition();
		Vector current_pos = m_updates[i]->getPos();
		if ((new_pos.getX() != current_pos.getX()) || (new_pos.getY() != current_pos.getY())){
			moveObject(m_updates[i], new_pos);
		}
	}
	//update world
	m_deletions.clear();
	LM.writeLog("m_deletions cleared : update() called\n");
}

int WorldManager::markForDelete(Object *p_o) {
	WM.removeObject(p_o);
	m_deletions.push_back(p_o);
	return 0;
}

void WorldManager::draw() {
	for (int alt = 0; alt < MAX_ALTITUDE; alt++) {
		for (int i = 0; i < m_updates.size(); i++) {
			Box temp_box = ut2.getWorldBox(m_updates[i]);
			if ((ut2.boxIntersectsBox(temp_box, view)) || (dynamic_cast<ViewObject *> (m_updates[i]))) {
				m_updates[i]->draw();
			}
		}
	}
}

int WorldManager::moveObject(Object* p_o, Vector where) {
	LM.writeLog("moveObject started\n");
	if (p_o->isSolid() == true) {
		std::vector<Object*> objectCollisions = getCollisions(p_o, where);
	
		if (!objectCollisions.empty()) {
			
			bool do_move = true;
			for (int i = 0; i < objectCollisions.size(); i++) {
				EventCollision c(p_o, m_updates[i], where);
				p_o->eventHandler(&c);
				m_updates[i]->eventHandler(&c);

				if ((p_o->getSolidness() == HARD) && (m_updates[i]->getSolidness() == HARD)) {
					do_move = false;
				}

				if ((p_o->getNoSoft()) && (m_updates[i]->getSolidness() == SOFT)) {
					do_move = false;
				}
			}
			if (do_move == false) {
				return -1;
			}
		}
	}
	Box orig_box = ut2.getWorldBox(p_o);
	p_o->setPos(where);
	Box new_box = ut2.getWorldBox(p_o);

	if (p_view_following == p_o) {
		setViewPosition(p_o->getPos());
	}

	if ((ut2.boxIntersectsBox(orig_box, boundary)) && !(ut2.boxIntersectsBox(new_box, boundary))) {
		EventOut ov;
		p_o->eventHandler(&ov);
	}
	return 0;
}

std::vector<Object*> WorldManager::getCollisions(Object* p_o, Vector where) const {
	std::vector<Object*> collisionList;

	for (int i = 0; i < m_updates.size(); i++) {
		if (m_updates[i] != p_o) {
			Vector position = m_updates[i]->getPos();
			Box b = ut2.getWorldBox(p_o, where);
			Box b_temp = ut2.getWorldBox(m_updates[i]);
			if ((ut2.boxIntersectsBox(b, b_temp)) && (m_updates[i]->isSolid())) {
				collisionList.push_back(m_updates[i]);
			}
		}
	}
	return collisionList;
}

void WorldManager::setBoundary(Box new_boundary) {
	boundary = new_boundary;
}

Box WorldManager::getBoundary() const {
	return boundary;
}

void WorldManager::setView(Box new_view) {
	view = new_view;
}

Box WorldManager::getView() const {
	return view;
}

void WorldManager::setViewPosition(Vector view_pos) {
	float x = view_pos.getX() - (view.getHorizontal() / 2);
	
	if (x + view.getHorizontal() > boundary.getHorizontal()) {
		x = boundary.getHorizontal() - view.getHorizontal();
	}
	if (x < 0) {
		x = 0;
	}

	float y = view_pos.getY() - (view.getVertical() / 2);

	if (y + view.getVertical() > boundary.getVertical()) {
		y = boundary.getVertical() - view.getVertical();
	}
	if (y < 0) {
		y = 0;
	}

	Vector new_corner(x, y);
	view.setCorner(new_corner);
}

int WorldManager::setViewFollowing(Object* p_new_view_following) {
	
	if (p_new_view_following == NULL) {
		p_view_following = NULL;
		return 0;
	}

	bool found = false;
	for (int i = 0; i < m_updates.size(); i++) {
		if (m_updates[i] == p_new_view_following)
			found = true;
	}

	if (found) {
		p_view_following = p_new_view_following;
		setViewPosition(p_view_following->getPos());
		return 0;
	}

	return -1;
}