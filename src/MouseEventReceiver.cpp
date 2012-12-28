#include "MouseEventReceiver.h"
#include "CursorUtil.h"

#include <iostream>
using namespace irr;
using namespace std;

void MouseEventReceiver::setCursorUtil(CursorUtil *pcursorUtil) {
	cursorUtil = pcursorUtil;
}

void MouseEventReceiver::setLabel(irr::gui::IGUIStaticText* plabel){
	label = plabel;
}

bool MouseEventReceiver::OnEvent(const SEvent& event) {
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
		switch (event.MouseInput.Event) {
			case EMIE_LMOUSE_PRESSED_DOWN:{
				irr::scene::ISceneNode* nodeToDelete = cursorUtil->getNodeOverCursor();
				if(nodeToDelete){
					irr::core::stringw tempryw = nodeToDelete->getName();
					const wchar_t * converted = tempryw.c_str();
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

