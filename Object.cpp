#include "Object.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
using namespace df;

Object::Object() {
	static unsigned int idCall = 0;
	setId(idCall);
	idCall++;
	WM.insertObject(this);
	setAltitude(WM.MAX_ALTITUDE);
}

void Object::setId(int new_id){
	id = new_id;
}

int Object::getId() const {
	return id;
}

void Object::setType(std::string new_type) {
	type = new_type;
}

std::string Object::getType() const{
	return type;
}

void Object::setPos(Vector new_pos) {
	position = new_pos;
}

Vector Object::getPos() const {
	return position;
}

int Object::eventHandler(const Event* p_event) {
	char copy[20];
	strcpy(copy, p_event->getType().c_str());
	LM.writeLog("Received event of type : %s\n", copy);
	return 0;
}

int Object::draw() {
	LM.writeLog("Object draw() called\n");
	Vector pos = this->getPos();
	return m_animation.draw(pos);
}

int Object::setAltitude(int new_altitude) {
	if ((new_altitude < 0) || (new_altitude > 4)) {
		LM.writeLog("Exceeds Altitude Limits\n");
		return -1;
	}
	m_altitude = new_altitude;
	return 0;
}

int Object::getAltitude() const {
	return m_altitude;
}

void Object::setSpeed(float speed) {
	m_speed = speed;
}

float Object::getSpeed() const {
	return m_speed;
}

void Object::setDirection(Vector new_direction) {
	m_direction = new_direction;
}

Vector Object::getDirection() const {
	return m_direction;
}

void Object::setVelocity(Vector new_velocity) {
	this->setSpeed(new_velocity.getMagnitude());
	new_velocity.normalize();
	this->setDirection(new_velocity);
}

Vector Object::getXVelocity() const {
	float s = this->getSpeed();
	Vector scaleDirection = this->getDirection();
	scaleDirection.scale(this->getSpeed());
	return scaleDirection;
}

Vector Object::predictPosition() {
	Vector new_pos = position.operator+(getXVelocity());
	return new_pos;
}

bool Object::isSolid() const {
	if ((m_solidness == HARD) || (m_solidness == SOFT)) {
		return true;
	}
	else return false;
}

int Object::setSolidness(Solidness new_solid) {
	m_solidness = new_solid;
	return 0;
}

Solidness Object::getSolidness() const {
	return m_solidness;
}

void Object::setNoSoft() {
	m_no_soft = true;
}

bool Object::getNoSoft() const {
	return m_no_soft;
}

int Object::setSprite(std::string sprite_label) {
	m_sprite = RM.getSprite(sprite_label);
	Box newBox;
	newBox.setHorizontal(m_sprite->getWidth());
	newBox.setVertical((m_sprite->getHeight()));
	setBox(newBox);
	return 0;
}

void Object::setAnimation(Animation new_animation) {
	m_animation = new_animation;
}

void Object::setBox(Box new_box) {
	m_box = new_box;
}

Box Object::getBox() const {
	return m_box;
}

Object::~Object() {
	WM.removeObject(this);
	delete(this);
}