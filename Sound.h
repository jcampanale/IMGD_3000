#ifndef __SOUND_H__
#define __SOUND_H__

#include <string>
#include <SFML/Audio.hpp>

namespace df {
	class Sound {
	private:
		sf::Sound m_sound;
		sf::SoundBuffer m_sound_buffer;

		std::string m_label;
	public:
		Sound();
		~Sound();

		int loadSound(std::string filename);

		void setLabel(std::string new_label);

		std::string getLabel() const;

		void play(bool loop = false);

		void stop();

		void pause();

		sf::Sound getSound() const;
	};
}

#endif //__SOUND_H__
