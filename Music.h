#ifndef __MUSIC_H__
#define __MUSIC_H__

#include <string>
#include <SFML/Audio.hpp>

namespace df {
	class Music {
	private:
		Music(Music const&);
		void operator=(Music const&);
		sf::Music m_music;
		std::string m_label;

	public:
		Music();

		int loadMusic(std::string filename);

		void setLabel(std::string new_label);

		std::string getLabel() const;

		void play(bool loop = true);

		void stop();

		void pause();

		sf::Music* getMusic();
	};
}

#endif //__MUSIC_H__
