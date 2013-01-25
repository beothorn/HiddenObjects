#ifndef SYDNEY_H_
#define SYDNEY_H_

#include <irrlicht.h>
#include <ObjectsList.h>

class SydneyFactory {
public:
	SydneyFactory(irr::scene::ISceneManager* sceneManager,irr::video::IVideoDriver* driver,ObjectsList *objectList);
	void produce(int x,int y,int z);
private:
	irr::scene::ISceneManager* sceneManager;
	irr::video::IVideoDriver* driver;
	ObjectsList *objectList;
};

#endif /* SYDNEY_H_ */
