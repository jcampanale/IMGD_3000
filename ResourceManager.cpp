#include <iostream>
#include <fstream>
#include <sstream>
#include "ResourceManager.h"
#include "LogManager.h"
using namespace df;

ResourceManager::ResourceManager() {
	setType("ResourceManager");
}

ResourceManager& ResourceManager::getInstance() {
	static ResourceManager single;
	return single;
}

int ResourceManager::startUp() {
	m_sprite_count = 0;
	sound_count = 0;
	music_count = 0;
	int started = Manager::StartUp();
	LM.writeLog("RM started\n");
	return started;
}

int ResourceManager::loadSound(std::string filename, std::string label) {
	if (sound_count == MAX_SOUNDS) {
		LM.writeLog("Sound array full\n");
		return -1;
	}
	if (l_sound[sound_count].loadSound(filename) == -1) {
		return -1;
	}

	l_sound[sound_count].setLabel(label);
	sound_count++;
	return 0;
}

int ResourceManager::unloadSound(std::string label) {
	for (int i = 0; i < sound_count - 1; i++) {
		if (label == l_sound[i].getLabel()) {
			for (int j = i; j < sound_count - 2; j++) {
				l_sound[j] = l_sound[j + 1];
			}
			sound_count--;
			return 0;
		}
	}
	LM.writeLog("No sound found to unload\n");
	return -1;
}

Sound* ResourceManager::getSound(std::string label) {
	for (int i = 0; i < sound_count - 1; i++) {
		if (label == l_sound[i].getLabel()) {
			return (&l_sound[i]);
		}
	}

	return NULL;
}

int ResourceManager::loadMusic(std::string filename, std::string label) {
	if (music_count == MAX_MUSICS) {
		LM.writeLog("Music array full\n");
		return -1;
	}
	if (l_music[music_count].loadMusic(filename) == -1) {
		LM.writeLog("Filename incorrect\n");
		return -1;
	}

	l_music[music_count].setLabel(label);
	music_count++;
	return 0;

}

int ResourceManager::unloadMusic(std::string label) {
	for (int i = 0; i < music_count; i++) {
		if (label == l_music[i].getLabel()) {
			l_music[i].setLabel("");
			return 0;
		}
	}
	LM.writeLog("No music found to unload\n");
	return -1;
}

Music* ResourceManager::getMusic(std::string label) {
	for (int i = 0; i < music_count; i++) {
		LM.writeLog("Music label : %s\n", l_music[i].getLabel().c_str());
		LM.writeLog("i : %d\n", i);
		if (label == l_music[i].getLabel()) {
			return (&l_music[i]);
			LM.writeLog("Got music\n");
		}
	}
	LM.writeLog("Did not get music\n");
	return NULL;
}

void ResourceManager::shutDown() {
	free(m_sprite);
	Manager::ShutDown();
	LM.writeLog("RM shut down\n");
}
