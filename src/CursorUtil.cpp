#include "CursorUtil.h"

using namespace std;
#include <iostream>

CursorUtil::CursorUtil(scene::ISceneCollisionManager* psceneCollisionManager, IrrlichtDevice *pdevice) {
	sceneCollisionManager = psceneCollisionManager;
	device = pdevice;
}

irr::scene::ISceneNode* CursorUtil::getNodeOverCursor(){
	cout << "getNodeOverCursor start";
	irr::gui::ICursorControl* cursorControl = device->getCursorControl();
	const irr::core::vector2d<signed int> position = cursorControl->getPosition();
	irr::scene::ISceneNode* nodeOverCursor = sceneCollisionManager->getSceneNodeFromScreenCoordinatesBB(position);
	cout << "getNodeOverCursor end";
	return nodeOverCursor;
}

