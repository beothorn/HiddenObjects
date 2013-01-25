/*
 * ObjectsList.h
 *
 *  Created on: 24/01/2013
 *      Author: lucas
 */

#ifndef OBJECTSLIST_H_
#define OBJECTSLIST_H_

#include <irrlicht.h>

class ObjectsList {
public:
	ObjectsList(irr::IrrlichtDevice *device);
	void drawAll();
	void addObject(const wchar_t* newObject);
	void removeObject(const wchar_t* removeObject);
private:
	irr::gui::IGUIFont* font;
};

#endif /* OBJECTSLIST_H_ */
