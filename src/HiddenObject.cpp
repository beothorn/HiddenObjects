#include <irrlicht.h>
#include <string>

#include "MouseEventReceiver.h"
#include "objects/SydneyFactory.h"
#include "objects/AnnyFactory.h"
#include "CursorUtil.h"
#include <header.hpp>

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
gui::IGUIFont* font;
const wchar_t * converted = L"Fooo";


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

	std::string fontFile = "font.png";
	font = device->getGUIEnvironment()->getFont((constants::RESOURCES+fontFile).c_str());

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
	sydneyFactory.produce(0,0,0);
	annyFactory.produce(-40,0,0);

	mouseEventReceiver.setLabel(label);

	sceneManager->addCameraSceneNode(0, vector3df(0,5,-100), vector3df(0,5,0));


}

void drawScene() {
	if (font)
		font->draw(converted,core::rect<s32>(130,10,300,50),video::SColor(255,255,255,255));
	sceneManager->drawAll();
	guienv->drawAll();
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
