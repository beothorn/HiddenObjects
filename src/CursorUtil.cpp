/*
 * NodeOverMouse.cpp
 *
 *  Created on: 26/12/2012
 *      Author: lucas
 */

#include "CursorUtil.h"

CursorUtil::CursorUtil(scene::ISceneCollisionManager* psceneCollisionManager, IrrlichtDevice *pdevice) {
	sceneCollisionManager = psceneCollisionManager;
	device = pdevice;
}

irr::scene::ISceneNode* CursorUtil::getNodeOverCursor(){
	return sceneCollisionManager->getSceneNodeFromScreenCoordinatesBB(device->getCursorControl()->getPosition());
}

