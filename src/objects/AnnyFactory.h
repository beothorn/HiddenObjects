#ifndef ANNYFACTORY_H_
#define ANNYFACTORY_H_

#include <irrlicht.h>
#include <ObjectsList.h>

class AnnyFactory {
public:
	AnnyFactory(irr::scene::ISceneManager* sceneManager,irr::video::IVideoDriver* driver,ObjectsList *objectList);
	void produce(int x,int y,int z);
private:
	irr::scene::ISceneManager* sceneManager;
	irr::video::IVideoDriver* driver;
	ObjectsList *objectList;
};

#endif /* ANNYFACTORY_H_ */
