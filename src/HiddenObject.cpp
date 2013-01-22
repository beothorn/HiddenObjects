#include <irrlicht.h>
#include <string>

#include "MouseEventReceiver.h"
#include "objects/SydneyFactory.h"
#include "objects/AnnyFactory.h"
#include "CursorUtil.h"

#include <iostream>

using namespace std;

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

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
IGUIEnvironment* guienv;

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

	driver = device->getVideoDriver();
	guienv = device->getGUIEnvironment();
}

void endGame(){
	device->drop();
}

void setupGame(){
	device->setWindowCaption(L"Find the hidden objects");
	irr::gui::IGUIStaticText* label = guienv->addStaticText(L"Lets hope this one works", rect<s32>(10, 10, 260, 22), true);

	SydneyFactory sydneyFactory(sceneManager,driver);
	AnnyFactory annyFactory(sceneManager,driver);
	for(int i = -30*5; i < 30*5;i+=30){
		if((i/30)%2==0)
			sydneyFactory.produce(i,i,i);
		else
			annyFactory.produce(i,i,i);
	}

	mouseEventReceiver.setLabel(label);

	sceneManager->addCameraSceneNode(0, vector3df(0,5,-400), vector3df(0,5,0));
}

void enterGameLoop(){
	while(device->run()){
		driver->beginScene(true, true, SColor(255,100,101,140));
		sceneManager->drawAll();
		guienv->drawAll();
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
