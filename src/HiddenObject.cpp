#include <irrlicht.h>
#include <string>

#include "/home/lucas/workspaceC/HiddenObject/src/MouseEventReceiver.h"
#include "/home/lucas/workspaceC/HiddenObject/src/CursorUtil.h"
#include <map>

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


int main()
{
	irr::video::E_DRIVER_TYPE deviceType = video::EDT_SOFTWARE;
	int width = 800;
	int height = 600;
	irr::core::dimension2d<unsigned int> windowSize = dimension2d<u32>(width,height);
	int bits = 16;
	bool fullscreen = false;
	bool stencilbuffer = false;
	bool vsync = false;

	MouseEventReceiver mouseEventReceiver;
	IrrlichtDevice *device = createDevice(deviceType, windowSize, bits,fullscreen, stencilbuffer, vsync, &mouseEventReceiver);

	if (!device){
		return 1;
	}

	device->setWindowCaption(L"Find the hidden objects");

	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* sceneManager = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	scene::ISceneCollisionManager* collisionManager = sceneManager->getSceneCollisionManager();
	irr::gui::IGUIStaticText* label = guienv->addStaticText(L"Lets hope this one works", rect<s32>(10, 10, 260, 22), true);

	CursorUtil nodeOverMouse = CursorUtil(collisionManager,device);
	mouseEventReceiver.setCursorUtil(&nodeOverMouse);

	std::string resources = "/home/lucas/sdk/irrlicht-1.8/media/";
	std::string sydneyMesh = "sydney.md2";
	std::string sydneyMaterial = "sydney.bmp";
	IAnimatedMesh* mesh = sceneManager->getMesh((resources+sydneyMesh).c_str());
	if (!mesh)
	{
		device->drop();
		return 1;
	}
	IAnimatedMeshSceneNode* node = sceneManager->addAnimatedMeshSceneNode( mesh );

	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_RUN);
		node->setMaterialTexture( 0, driver->getTexture((resources+sydneyMaterial).c_str()) );
	}

	std::map< ISceneNode*, const wchar_t*> objects;

	objects[node] = L"Sydney";

	mouseEventReceiver.setLabel(label,objects);

	sceneManager->addCameraSceneNode(0, vector3df(0,5,-40), vector3df(0,5,0));

	while(device->run())
	{
		driver->beginScene(true, true, SColor(255,100,101,140));
		sceneManager->drawAll();
		guienv->drawAll();

		driver->endScene();
	}

	device->drop();
	return 0;
}
