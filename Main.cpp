#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Object.h"
#include "Vector.h"
#include "testObject.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "SpriteResourceManager.h"
#include "Color.h"
#include "ViewObject.h"
#include "testViewObject.h"
#include <string>
#include <Windows.h>
using namespace df;

int main(int argc, char* argv[]) {
	GM.startUp();
	if (RM.loadSprite("sprites/good-spr.txt", "good") != 0) {
		LM.writeLog("Error loading good sprite\n");
	}
	else LM.writeLog("Good sprite loaded\n");
	if (RM.loadSprite("sprites/bad-spr.txt", "bad") == 0) {
		LM.writeLog("Loaded bad sprite, oopsies\n");
	}
	else LM.writeLog("Did not load bad sprite\n");
	if (RM.loadSound("sounds/oof.wav", "oof") == 0) {
		LM.writeLog("Loaded sound\n");
	}
	else LM.writeLog("Could not load sound\n");
	if (RM.loadMusic("sounds/kokomo.wav", "kokomo") != 0) {
		LM.writeLog("Error loading music\n");
	}
	else LM.writeLog("Loaded music\n");
	Sprite* goodSprite = RM.getSprite("good");
	Object* spriteObject = new Object;
	Object* spriteObject2 = new Object;
	spriteObject->setPos(Vector(20, 7));
	spriteObject2->setPos(Vector(5, 7));
	//WM.setViewFollowing(spriteObject);
	spriteObject->setSprite("good");
	spriteObject2->setSprite("good");
	Animation goodAnimation;
	goodAnimation.setSprite(goodSprite);
	spriteObject->setAnimation(goodAnimation);
	spriteObject2->setAnimation(goodAnimation);
	//testing that objects move and collide properly
	spriteObject->setVelocity(Vector(-0.1, 0));
	spriteObject2->setVelocity(Vector(0.1, 0));
	int width = goodSprite->getWidth();
	int height = goodSprite->getHeight();
	spriteObject->getBox().setCorner(Vector(-2.75, -0.75));
	Vector corner = spriteObject->getBox().getCorner();
	LM.writeLog("Sprite width : %d\n", width);
	LM.writeLog("Sprite height : %d\n", height);
	LM.writeLog("Corner X : %d\n", corner.getX());
	LM.writeLog("Corner Y : %d\n", corner.getY());
	//testing view objects
	testViewObject testVO;
	//Object* cameraObject = new Object;
	//cameraObject->setPos(Vector(15, 8));
	//WM.setViewFollowing(cameraObject);
	GM.run();
	
	
	/*
	LM.startUp();
	LM.writeLog("test\n");

	DM.startUp();
	IM.startUp();
	Object* test = new Object();
	test->setVelocity(Vector(1.5, 1));
	test->setPos(Vector(2, 5));
	Vector predict = test->predictPosition();
	Vector get = test->getXVelocity();
	//test object velocity
	LM.writeLog("Object velocity X : %f Y : %f\n", get.getX(), get.getY());
	//test predict position
	LM.writeLog("Object predictPosition X : %f Y : %f\n", predict.getX(), predict.getY());
	Object* test2 = new Object();
	test2->setPos(Vector(2, 5));
	Object* test3 = new Object();
	test3->setPos(Vector(4, 20));
	test->setSolidness(HARD);
	test2->setSolidness(HARD);
	test3->setSolidness(HARD);
	//testing collisions
	std::vector<Object*> collisionList = WM.getCollisions(test2, test2->getPos());
	int move = WM.moveObject(test2, Vector(2, 5));
	int move2 = WM.moveObject(test3, Vector(5, 19));
	LM.writeLog("Collided object moveable : %d\n", move);
	LM.writeLog("Non collided object moveable : %d\n", move2);
	for (int i = 0; i < collisionList.size(); i++) {
		LM.writeLog("Collision found with object of ID : %d\n", collisionList[i]->getId());
	}
	//testing drawing 
	DM.drawCh(Vector(15, 7), '*', WHITE);
	LM.writeLog("drawing string\n");
	DM.drawString(Vector(10, 5), ":)(:", LEFT_JUSTIFIED, YELLOW);

	testObject newTest1;
	newTest1.setAltitude(1);
	testObject newTest2;

	//testing drawing object classes
	newTest1.draw(Vector (17, 6));
	newTest2.draw(Vector(18, 6));

	DM.swapBuffers();
	
	for (int i = 0; i < 1000000; i++) {
		IM.getInput();
	}

	Sleep(2000);
	test->setAltitude(5);
	test->setAltitude(-1);
	test->setAltitude(1);
	DM.shutDown();
	IM.shutDown();
	LM.shutDown();
	*/
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

}