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
private:
	irr::gui::IGUIFont* font;
};

#endif /* OBJECTSLIST_H_ */
