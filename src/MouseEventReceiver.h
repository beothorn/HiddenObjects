/*
 * MouseEventReceiver.h
 *
 *  Created on: 25/12/2012
 *      Author: carol
 */

#ifndef MOUSEEVENTRECEIVER_H_
#define MOUSEEVENTRECEIVER_H_

#include <IEventReceiver.h>
#include <irrlicht.h>
#include "CursorUtil.h"

class MouseEventReceiver: public irr::IEventReceiver {
public:
	void setCursorUtil(CursorUtil *cursorUtil);
	void setSceneManager(irr::scene::ISceneManager *sceneManager);
	void setLabel(irr::gui::IGUIStaticText* label);
	virtual bool OnEvent(const SEvent& event);
private:
	CursorUtil *cursorUtil;
	irr::gui::IGUIStaticText* label;
	irr::scene::ISceneManager *sceneManager;
};

#endif /* MOUSEEVENTRECEIVER_H_ */
