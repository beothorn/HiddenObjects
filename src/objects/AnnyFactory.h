#ifndef ANNYFACTORY_H_
#define ANNYFACTORY_H_

#include <irrlicht.h>

class AnnyFactory {
public:
	AnnyFactory(irr::scene::ISceneManager* sceneManager,irr::video::IVideoDriver* driver);
	void produce(int x,int y,int z);
private:
	irr::scene::ISceneManager* sceneManager;
	irr::video::IVideoDriver* driver;
};

#endif /* ANNYFACTORY_H_ */
