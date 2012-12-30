#include "SydneyFactory.h"
#include <string>

using namespace irr;
using namespace scene;
using namespace video;

SydneyFactory::SydneyFactory(ISceneManager* psceneManager, IVideoDriver* pdriver) {
	sceneManager = psceneManager;
	driver = pdriver;
}

void SydneyFactory::produce(int x,int y,int z){
	std::string resources = "./resources/";
	std::string sydneyMesh = "sydney.md2";
	std::string sydneyMaterial = "sydney.bmp";
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
		node->setName(L"Sydney");
		node->setPosition(core::vector3df(x,y,z));
	}
}
