#include "MouseEventReceiver.h"
#include "CursorUtil.h"


MouseEventReceiver::MouseEventReceiver() {
}

void MouseEventReceiver::setCursorUtil(CursorUtil *pcursorUtil) {
	cursorUtil = pcursorUtil;
}

void MouseEventReceiver::setLabel(irr::gui::IGUIStaticText* plabel, std::map< scene::ISceneNode*, const wchar_t*> pobjects){
	label = plabel;
	objects = pobjects;
}

bool MouseEventReceiver::OnEvent(const SEvent& event) {
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
		switch (event.MouseInput.Event) {
		case EMIE_LMOUSE_PRESSED_DOWN:{
			irr::scene::ISceneNode* nodeToDelete = cursorUtil->getNodeOverCursor();
			if(nodeToDelete){
				label->setText(objects[nodeToDelete]);
			}
		}
			break;

			default:
			break;
		}
	}
	return false;
}

