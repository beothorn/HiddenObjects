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
#include <map>

class MouseEventReceiver: public irr::IEventReceiver {
public:
	CursorUtil *cursorUtil;
	irr::gui::IGUIStaticText* label;
	std::map< scene::ISceneNode*, const wchar_t*> objects;
	MouseEventReceiver();
	void setCursorUtil(CursorUtil *cursorUtil);
	void setLabel(irr::gui::IGUIStaticText* label, std::map< scene::ISceneNode*, const wchar_t*> objects);
	virtual bool OnEvent(const SEvent& event);
};

#endif /* MOUSEEVENTRECEIVER_H_ */
