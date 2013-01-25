#include "MouseEventReceiver.h"
#include "CursorUtil.h"

#include <iostream>
using namespace irr;
using namespace std;
using namespace scene;

void MouseEventReceiver::setCursorUtil(CursorUtil *pcursorUtil) {
	cursorUtil = pcursorUtil;
}

void MouseEventReceiver::setSceneManager(ISceneManager *psceneManager) {
	sceneManager = psceneManager;
}

void MouseEventReceiver::setLabel(irr::gui::IGUIStaticText* plabel){
	label = plabel;
}

void MouseEventReceiver::setObjectList(ObjectsList *pobjectsList){
	objectsList = pobjectsList;
}

bool MouseEventReceiver::OnEvent(const SEvent& event) {
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
		switch (event.MouseInput.Event) {
			case EMIE_LMOUSE_PRESSED_DOWN:{
				irr::scene::ISceneNode* nodeClicked = cursorUtil->getNodeOverCursor();
				if(nodeClicked){
					scene::ISceneNodeAnimator* anim = sceneManager->createRotationAnimator(core::vector3df(0,5,0));
					nodeClicked->addAnimator(anim);
					irr::core::stringw tempryw = nodeClicked->getName();
					const wchar_t * converted = tempryw.c_str();
					objectsList->removeObject(converted);
					label->setText(converted);
				}
			}
			break;

			default:
			break;
		}
	}
	return false;
}

