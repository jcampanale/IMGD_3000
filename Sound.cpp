#include "Sound.h"
#include "LogManager.h"
using namespace df;

Sound::Sound() {

}

int Sound::loadSound(std::string filename) {
	if (m_sound_buffer.loadFromFile(filename) == false) {
		LM.writeLog("Sound could not be loaded");
		return -1;
	}
	m_sound.setBuffer(m_sound_buffer);
	return 0;
}

void Sound::setLabel(std::string new_label) {
	m_label = new_label;
}

std::string Sound::getLabel() const {
	return m_label;
}

void Sound::play(bool loop) {
	m_sound.play();
}

void Sound::stop() {
	m_sound.stop();
}

void Sound::pause() {
	m_sound.pause();
}

sf::Sound Sound::getSound() const {
	return m_sound;
}

Sound::~Sound() {
	m_sound.resetBuffer();
}