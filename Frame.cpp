#include "Frame.h"
#include "DisplayManager.h"
using namespace df;

Frame::Frame() {
	m_width = 0;
	m_height = 0;
}

Frame::Frame(int new_width, int new_height, std::string frame_str) {
	m_width = new_width;
	m_height = new_height;
	m_frame_str = frame_str;
}

void Frame::setWidth(int new_width) {
	m_width = new_width;
}

int Frame::getWidth() const {
	return m_width;
}

void Frame::setHeight(int new_height) {
	m_height = new_height;
}

int Frame::getHeight() const {
	return m_height;
}

void Frame::setString(std::string new_string) {
	m_frame_str = new_string;
}

std::string Frame::getString() const {
	return m_frame_str;
}

int Frame::draw(Vector position, Color color) const {
	if (m_frame_str.empty()) {
		return -1;
	}

	float x_offset = m_width / 2;
	float y_offset = m_height / 2;

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			Vector temp_pos((position.getX() + j - x_offset), (position.getY() + i - y_offset));
			DM.drawCh(temp_pos, m_frame_str[i * m_width + j], color);
		}
	}
}

