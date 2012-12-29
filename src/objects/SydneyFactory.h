#ifndef SYDNEY_H_
#define SYDNEY_H_

#include <irrlicht.h>

class SydneyFactory {
public:
	SydneyFactory(irr::scene::ISceneManager* sceneManager,irr::video::IVideoDriver* driver);
	void produce(int x);
private:
	irr::scene::ISceneManager* sceneManager;
	irr::video::IVideoDriver* driver;
};

#endif /* SYDNEY_H_ */
