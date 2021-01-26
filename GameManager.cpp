#pragma comment(lib, "winmm.lib")

#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "Clock.h"
#include "Event.h"
#include "EventStep.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include <Windows.h>
using namespace df;

GameManager::GameManager(){
    Manager::setType("GameManager");
}

int GameManager::startUp(){
    int started = Manager::StartUp();
    timeBeginPeriod(1);
    //logmanager startup
    LM.startUp();
    LM.writeLog("GM started with value of : %d\n", started);
    LM.writeLog("LM started\n");
    DM.startUp();
    IM.startUp();
    WM.startUp();
    LM.writeLog("WM started\n");
    Box viewBox;
    viewBox.setHorizontal(DM.getHorizontal());
    viewBox.setVertical(DM.getVertical());
    WM.setBoundary(viewBox);
    WM.setView(viewBox);
    RM.startUp();

    return started;
}

GameManager &GameManager::getInstance(){
    static GameManager single;
    return single;
}

void GameManager::run(){
    Music* music = RM.getMusic("kokomo");
    music->play();
    int count = 0;
    Clock newClock;
    frame_time = FRAME_TIME_DEFAULT;
    while(game_over == false){
        long int delta = newClock.delta();
        LM.writeLog("Clock delta : %d\n", delta);
        //game loop
        
        IM.getInput();
        WM.update();
        WM.draw();
        DM.swapBuffers();
       
        EventStep step(count);
        std::vector<Object*> allObjects = WM.getAllObjects();
        for (int i = 0; i < allObjects.size(); i++) {
            allObjects[i]->eventHandler(&step);
        }
        
        long int loop_time = newClock.split() / 1000;
        long int sleep_time = frame_time - loop_time;
        if (sleep_time < 0) {
            sleep_time = 0;
        }
        Sleep(sleep_time);
        count++;
        LM.writeLog("Loop time : %d\n", loop_time);

        if (count == 1000)
            shutDown();
    }
}

void GameManager::setGameOver(){
    game_over = true;
}

void GameManager::shutDown(){
    setGameOver();
    //test setGameOver
    LM.writeLog("GameOver : %d\n", game_over);
    DM.shutDown();
    IM.shutDown();
    WM.shutDown();
    //RM.shutDown();
    timeEndPeriod(1);
    Manager::ShutDown();
    LM.writeLog("GM shutDown\n");
    LM.shutDown();
}
