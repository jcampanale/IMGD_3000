#include "Animation.h"
#include "Box.h"
using namespace df;

Animation::Animation() {
	m_index = 1;
}

void Animation::setSprite(Sprite* p_new_sprite) {
	m_p_sprite = p_new_sprite;
}

Sprite* Animation::getSprite() const {
	return m_p_sprite;
}

void Animation::setName(std::string new_name) {
	m_name = new_name;
}

std::string Animation::getName() const {
	return m_name;
}

void Animation::setIndex(int new_index) {
	m_index = new_index;
}

int Animation::getIndex() const {
	return m_index;
}

void Animation::setSlowdownCount(int new_slowdown_count) {
	m_slowdown_count = new_slowdown_count;
}

int Animation::getSlowdownCount() const {
	return m_slowdown_count;
}

int Animation::draw(Vector position) {
	if (m_p_sprite == NULL) {
		return -1;
	}

	int index = m_index;
	this->getSprite()->draw(index, position);

	if (m_slowdown_count == -1) {
		return -1;
	}

	int count = this->getSlowdownCount();
	count++;

	if (count >= this->getSlowdownCount()) {
		count = 0;

		index++;

		if (index >= this->getSprite()->getFrameCount()) {
			index = 0;
		}

		this->setIndex(index);
	}

	this->setSlowdownCount(count);
	return 0;
}
