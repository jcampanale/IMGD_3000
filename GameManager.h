#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "Manager.h"

#define GM df::GameManager::getInstance()

namespace df{
    const std::string CONFIG_FILENAME = "df-config.txt";

    const int FRAME_TIME_DEFAULT = 33;

    class GameManager : public Manager {
        private:
            GameManager();
            GameManager(GameManager const&);
            void operator=(GameManager const&);
            bool game_over;
            int frame_time;
            int step_count;

        public:
            static GameManager &getInstance();

            int startUp();

            void shutDown();

            void run();

            void setGameOver();
    };

}

#endif // __GAME_MANAGER_H__
