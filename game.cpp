#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Object.h"
#include "Vector.h"
#include "testObject.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "Color.h"
#include <string>
#include <Windows.h>
using namespace df;

int main(int argc, char** args)
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

	LM.writeLog("test");

	//DM.startUp();
	//DM.drawCh(df::Vector(10, 5), '*', WHITE);
	//DM.swapBuffers();
	//Sleep(2000);
	//DM.shutDown();

	/*
	//test start up
	GM.startUp();
	//test set and get type
	std::string gmType = GM.getType();
	std::string lmType = LM.getType();
	std::string wmType = WM.getType();
	LM.writeLog("GM type : %s\n", gmType.c_str());
	LM.writeLog("LM type : %s\n", lmType.c_str());
	LM.writeLog("WM type : %s\n", wmType.c_str());

	for (int i = 0; i < 3; i++) {
		df::testObject* newTestObject = new df::testObject();
	}
	//test game loop
	//need to uncomment  this and comment out everything below run to test run
	//GM.run();

	//test object and WM insert Object
	df::Object* test = new df::Object();
	//test object type and ID
	test->setType("tester1");
	LM.writeLog("Object inserted of type : %s\n", test->getType().c_str());
	LM.writeLog("Object ID : %d\n", test->getId());
	df::Object* test2 = new df::Object();
	test2->setType("test2");
	LM.writeLog("Object inserted of type : %s\n", test2->getType().c_str());
	LM.writeLog("Object ID : %d\n", test2->getId());
	//test vector X and Y and object position
	float x = 3.5;
	float y = 2.1;
	df::Vector testVector(x, y);
	test->setPos(testVector);
	LM.writeLog("X pos : %f  Y pos : %f\n", testVector.getX(), testVector.getY());
	//test magnitude
	LM.writeLog("Magnitude of pos : %f\n", testVector.getMagnitude());
	//test scale
	testVector.scale(2);
	LM.writeLog("Vector after scale X : %f Y : %f\n", testVector.getX(), testVector.getY());
	//test normalize
	testVector.normalize();
	LM.writeLog("Vector after normalize X : %f Y : %f\n", testVector.getX(), testVector.getY());
	//test getAllObjects
	std::vector < df::Object* > allObjects = WM.getAllObjects();
	for (int i = 0; i < allObjects.size(); i++) {
		LM.writeLog("Object found of ID : %d\n", allObjects[i]->getId());
	}
	//test removeObject
	WM.removeObject(test2);
	std::vector < df::Object* > allObjects2 = WM.getAllObjects();
	LM.writeLog("After remove object\n");
	for (int i = 0; i < allObjects2.size(); i++) {
		LM.writeLog("Object found of ID : %d\n", allObjects2[i]->getId());
	}
	//test objectsOfType
	df::Object* test3 = new df::Object();
	test3->setType("tester1");
	df::Object* test4 = new df::Object();
	test4->setType("blah");
	std::vector<df::Object*> objectsSameType = WM.objectsOfType("tester1");
	for (int i = 0; i < objectsSameType.size(); i++) {
		LM.writeLog("Object, same type, found of ID : %d\n", objectsSameType[i]->getId());
	}
	WM.markForDelete(test3);
	//test that object marked for deletion removed from update list
	std::vector<df::Object*> objectDeleteTest = WM.getAllObjects();
	for (int i = 0; i < objectDeleteTest.size(); i++) {
		LM.writeLog("Object found for updating of ID : %d\n", objectDeleteTest[i]->getId());
	}
	//test update
	WM.update();
	//test shut down
	GM.shutDown();
	*/

    return 0;
}