#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__
#include <string>
#include <vector>
#include "Manager.h"
#include "Sprite.h"
#include "SpriteResourceManager.h"
#include "Sound.h"
#include "Music.h"

#define RM df::ResourceManager::getInstance()

namespace df {
	const int MAX_SOUNDS = 128;
	const int MAX_MUSICS = 128;

	class ResourceManager : public SpriteResourceManager{
	private:
		ResourceManager();
		ResourceManager(ResourceManager const&);
		void operator=(ResourceManager const&);
		Sprite* m_sprite[MAX_SPRITES];
		int m_sprite_count;
		Sound l_sound[MAX_SOUNDS];
		int sound_count;
		Music l_music[MAX_MUSICS];
		int music_count;

	public:
		static ResourceManager& getInstance();
		int startUp();
		void shutDown();

		int loadSound(std::string filename, std::string label);
		int unloadSound(std::string label);
		Sound* getSound(std::string label);

		int loadMusic(std::string filename, std::string label);
		int unloadMusic(std::string label);
		Music* getMusic(std::string label);
	};
}
#endif //__RESOURCE_MANAGER_H__ 

