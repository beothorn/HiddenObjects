#include <irrlicht.h>
#include <string>

#include "MouseEventReceiver.h"
#include "objects/SydneyFactory.h"
#include "objects/AnnyFactory.h"
#include "CursorUtil.h"
#include "ObjectsList.h"
#include <header.hpp>

#include <iostream>

using namespace std;

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;

/*
To be able to use the Irrlicht.DLL file, we need to link with the Irrlicht.lib.
We could set this option in the project settings, but to make it easy, we use a
pragma comment lib for VisualStudio. On Windows platforms, we have to get rid
of the console window, which pops up when starting a program with main(). This
is done by the second pragma. We could also use the WinMain method, though
losing platform independence then.
*/
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

IrrlichtDevice *device;
ISceneManager* sceneManager;
MouseEventReceiver mouseEventReceiver;
IVideoDriver* driver;
ObjectsList* objectsList;


void startEngine(){
	irr::video::E_DRIVER_TYPE deviceType = video::EDT_OPENGL;
	int width = 1042;
	int height = 720;
	irr::core::dimension2d<unsigned int> windowSize = dimension2d<u32>(width,height);
	int bits = 16;
	bool fullscreen = false;
	bool stencilbuffer = false;
	bool vsync = false;

	device = createDevice(deviceType, windowSize, bits,fullscreen, stencilbuffer, vsync, &mouseEventReceiver);
	if (!device) exit (1);
	sceneManager = device->getSceneManager();
	scene::ISceneCollisionManager* collisionManager = sceneManager->getSceneCollisionManager();
	CursorUtil *nodeOverMouse = new CursorUtil(collisionManager,device);
	mouseEventReceiver.setCursorUtil(nodeOverMouse);
	mouseEventReceiver.setSceneManager(sceneManager);

	driver = device->getVideoDriver();
}

void endGame(){
	device->drop();
}

void setupGame(){
	device->setWindowCaption(L"Find the hidden objects");

	objectsList = new ObjectsList(device);

	SydneyFactory sydneyFactory(sceneManager,driver,objectsList);
	AnnyFactory annyFactory(sceneManager,driver,objectsList);
	sydneyFactory.produce(0,0,0);
	annyFactory.produce(-40,0,0);

	mouseEventReceiver.setObjectList(objectsList);

	sceneManager->addCameraSceneNode(0, vector3df(0,5,-100), vector3df(0,5,0));
}

void drawScene() {
	sceneManager->drawAll();
	objectsList->drawAll();
}

void enterGameLoop(){
	while(device->run()){
		driver->beginScene(true, true, SColor(255,100,101,140));
		drawScene();
		driver->endScene();
	}
}

int main()
{
	cout << "main.startEngine()\n";
	startEngine();
	cout << "main.setupGame()\n";
	setupGame();
	cout << "main.enterGameLoop()\n";
	enterGameLoop();
	cout << "main.endGame()\n";
	endGame();
}
