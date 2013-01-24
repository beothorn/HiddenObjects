#include "AnnyFactory.h"
#include <string>
#include <header.hpp>

using namespace irr;
using namespace scene;
using namespace video;
using namespace constants;

AnnyFactory::AnnyFactory(ISceneManager* psceneManager, IVideoDriver* pdriver) {
	sceneManager = psceneManager;
	driver = pdriver;
}

void AnnyFactory::produce(int x,int y,int z){
	std::string sydneyMesh = "monkey.obj";
	std::string sydneyMaterial = "unwrappedPainted.png";//"monkey.bmp";
	IAnimatedMesh* mesh = sceneManager->getMesh((RESOURCES+sydneyMesh).c_str());
	if (!mesh)
	{
		exit(1);
	}
	IAnimatedMeshSceneNode* node = sceneManager->addAnimatedMeshSceneNode( mesh );

	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_RUN);
		node->setMaterialTexture( 0, driver->getTexture((RESOURCES+sydneyMaterial).c_str()) );
		node->setName(L"Monkey head");
		node->setPosition(core::vector3df(x,y,z));
		node->setScale(core::vector3df(10,10,10));
		node->setRotation(core::vector3df(0,200,0));
	}
}
