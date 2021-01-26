#include "Manager.h"
#include "WorldManager.h"
#include <string>
#include <vector>
using namespace df;

Manager::Manager() {
//code
    started = true;
}

void Manager::setType(std::string new_type) {
    type = new_type;
}

std::string Manager::getType() {
    return type;
}

int Manager::StartUp() {
//return 0 if good
    if (started == true)
        return 0;
    else return -1;
//return -1 otherwise
}

void Manager::ShutDown() {
    started = false;
}

bool Manager::isStarted() const{
    return started;
}

int Manager::onEvent(const Event* p_event) const {
    int count = 0;

    std::vector<Object*> all_objects = WM.getAllObjects();
    for (int i = 0; i < all_objects.size(); i++) {
        all_objects[i]->eventHandler(p_event);
        count++;
    }

    return count;
}
