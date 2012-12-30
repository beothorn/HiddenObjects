#include "AnnyFactory.h"
#include <string>

using namespace irr;
using namespace scene;
using namespace video;

AnnyFactory::AnnyFactory(ISceneManager* psceneManager, IVideoDriver* pdriver) {
	sceneManager = psceneManager;
	driver = pdriver;
}

void AnnyFactory::produce(int x,int y,int z){
	std::string resources = "./resources/";
	std::string sydneyMesh = "sydney.md2";
	std::string sydneyMaterial = "anny.bmp";
	IAnimatedMesh* mesh = sceneManager->getMesh((resources+sydneyMesh).c_str());
	if (!mesh)
	{
		exit(1);
	}
	IAnimatedMeshSceneNode* node = sceneManager->addAnimatedMeshSceneNode( mesh );
	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_RUN);
		node->setMaterialTexture( 0, driver->getTexture((resources+sydneyMaterial).c_str()) );
		node->setName(L"Anny");
		node->setPosition(core::vector3df(x,0,0));
	}
}
