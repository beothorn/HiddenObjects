/*
 * NodeOverMouse.h
 *
 *  Created on: 26/12/2012
 *      Author: lucas
 */

#ifndef NODEOVERMOUSE_H_
#define NODEOVERMOUSE_H_

#include <irrlicht.h>

using namespace irr;

class CursorUtil {
public:
	scene::ISceneCollisionManager* sceneCollisionManager;
	IrrlichtDevice *device;
	CursorUtil(scene::ISceneCollisionManager* sceneCollisionManager, IrrlichtDevice *device);
	irr::scene::ISceneNode* getNodeOverCursor();
};

#endif /* NODEOVERMOUSE_H_ */
