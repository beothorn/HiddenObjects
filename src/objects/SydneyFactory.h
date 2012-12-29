#ifndef SYDNEY_H_
#define SYDNEY_H_

#include <irrlicht.h>

class SydneyFactory {
public:
	irr::scene::ISceneManager* sceneManager;
	irr::video::IVideoDriver* driver;
	SydneyFactory(irr::scene::ISceneManager* sceneManager,irr::video::IVideoDriver* driver);
	void produce(int x);
};

#endif /* SYDNEY_H_ */
