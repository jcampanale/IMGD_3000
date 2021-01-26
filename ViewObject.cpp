#include "ViewObject.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "Utility.h"
#include "ViewEvent.h"
using namespace df;

Utility ut;

ViewObject::ViewObject() {
	setSolidness(SPECTRAL);
	setAltitude(MAX_ALTITUDE);
	setType("ViewObject");

	setValue(0);
	setDrawValue();
	setBorder(true);
	setLocation(TOP_CENTER);
	setColor(COLOR_DEFAULT);
}

int ViewObject::draw() {
	std::string temp_str;
	if (m_border == true) {
		temp_str = " " + getViewString() + " " + std::to_string(m_value) + " ";
	}
	else {
		temp_str = getViewString() + " " + std::to_string(m_value);
	}

	Vector pos = ut.viewToWorld(getPos());
	DM.drawString(pos, temp_str, CENTER_JUSTIFIED, getColor());
	return 0;
}

int ViewObject::eventHandler(const Event* p_e) {
	if (p_e->getType() == VIEW_EVENT) {
		const ViewEvent* p_ve = static_cast<const ViewEvent*> (p_e);
		if (p_ve->getTag() == view_string) {
			if (p_ve->getDelta()) {
				setValue(getValue() + p_ve->getValue());
			}
			else {
				setValue(p_ve->getValue());
			}
			return 1;
		}
	}
	return 0;
}

void ViewObject::setLocation(ViewObjectLocation new_location) {
	int y_delta = 0;
	Vector p;
	switch (new_location) {
	case TOP_LEFT:
		p.setX(WM.getView().getHorizontal() * (1 / 6));
		p.setY(1);
		if (this->getBorder() == false) {
			y_delta = -1;
		}
		break;
	case TOP_CENTER:
		p.setX(WM.getView().getHorizontal() * (3 / 6));
		p.setY(1);
		if (this->getBorder() == false) {
			y_delta = -1;
		}
		break;
	case TOP_RIGHT:
		p.setX(WM.getView().getHorizontal() * (5 / 6));
		p.setY(1);
		if (this->getBorder() == false) {
			y_delta = -1;
		}
		break;
	case CENTER_LEFT:
		p.setX(WM.getView().getHorizontal() * (1 / 6));
		p.setY(0);
		break;
	case CENTER_CENTER:
		p.setX(WM.getView().getHorizontal() * (3 / 6));
		p.setY(0);
		break;
	case CENTER_RIGHT:
		p.setX(WM.getView().getHorizontal() * (5 / 6));
		p.setY(0);
		break;
	case BOTTOM_LEFT:
		p.setX(WM.getView().getHorizontal() * (1 / 6));
		p.setY(-1);
		if (this->getBorder() == false) {
			y_delta = 1;
		}
		break;
	case BOTTOM_CENTER:
		p.setX(WM.getView().getHorizontal() * (3 / 6));
		p.setY(-1);
		if (this->getBorder() == false) {
			y_delta = 1;
		}
		break;
	case BOTTOM_RIGHT:
		p.setX(WM.getView().getHorizontal() * (5 / 6));
		p.setY(-1);
		if (this->getBorder() == false) {
			y_delta = 1;
		}
		break;
	}
	p.setY(p.getY() + y_delta);
	this->setPos(p);
	m_location = new_location;
}

ViewObjectLocation ViewObject::getLocation() const {
	return m_location;
}

void ViewObject::setValue(int new_value) {
	m_value = new_value;
}

int ViewObject::getValue() const {
	return m_value;
}

void ViewObject::setBorder(bool new_border) {
	if (m_border != new_border) {
		m_border = new_border;
		setLocation(getLocation());
	}
}

bool ViewObject::getBorder() const {
	return m_border;
}

void ViewObject::setColor(Color new_color) {
	m_color = new_color;
}

Color ViewObject::getColor() const {
	return m_color;
}

void ViewObject::setViewString(std::string new_view_string) {
	view_string = new_view_string;
}

std::string ViewObject::getViewString() const {
	return view_string;
}

void ViewObject::setDrawValue(bool new_draw_value) {
	m_draw_value = new_draw_value;
}

bool ViewObject::getDrawValue() const {
	return m_draw_value;
}