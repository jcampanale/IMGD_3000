#include "Utility.h"
#include "WorldManager.h"
using namespace df;

bool Utility::positionsIntersect(Vector p1, Vector p2) {
	if ((abs(p1.getX() - p2.getX()) <= 1) && (abs(p1.getY() - p2.getY()) <= 1)) {
		return true;
	}
	else return false;
}

bool Utility::boxIntersectsBox(Box A, Box B) {
	bool x_overlap = (((B.getCorner().getX() <= A.getCorner().getX()) && (A.getCorner().getX() <= (B.getCorner().getX() + B.getHorizontal())))
		|| ((A.getCorner().getX() <= B.getCorner().getX()) && (B.getCorner().getX() <= (A.getCorner().getX() + A.getHorizontal()))));
	bool y_overlap = (((B.getCorner().getY() <= A.getCorner().getY()) && (A.getCorner().getY() <= (B.getCorner().getY() + B.getVertical())))
		|| ((A.getCorner().getY() <= B.getCorner().getY()) && (B.getCorner().getY() <= (A.getCorner().getY() + A.getVertical()))));

	if (x_overlap && y_overlap)
		return true;
	else return false;
}

Box Utility::getWorldBox(const Object* p_o) {
	Box temp_box = p_o->getBox();
	Vector corner = temp_box.getCorner();
	corner.setX(corner.getX() + p_o->getPos().getX());
	corner.setY(corner.getY() + p_o->getPos().getY());
	temp_box.setCorner(corner);

	return temp_box;
}
Box Utility::getWorldBox(const Object* p_o, Vector where) {
	Box temp_box = p_o->getBox();
	Vector corner = temp_box.getCorner();
	corner.setX(corner.getX() + where.getX());
	corner.setY(corner.getY() + where.getY());
	temp_box.setCorner(corner);

	return temp_box;
}

Vector Utility::worldToView(Vector world_pos) {
	Vector view_origin = WM.getView().getCorner();
	float view_x = view_origin.getX();
	float view_y = view_origin.getY();
	Vector view_pos(world_pos.getX() - view_x, world_pos.getY() - view_y);
	return view_pos;
}

Vector Utility::viewToWorld(Vector view_pos) {
	Vector view_origin = WM.getView().getCorner();
	float view_x = view_origin.getX();
	float view_y = view_origin.getY();
	Vector world_pos(view_pos.getX() + view_x, view_pos.getY() + view_y);
	return world_pos;
}