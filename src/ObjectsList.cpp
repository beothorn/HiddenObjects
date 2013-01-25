/*
 * ObjectsList.cpp
 *
 *  Created on: 24/01/2013
 *      Author: lucas
 */

#include "ObjectsList.h"
#include <irrlicht.h>
#include <string>
#include <header.hpp>
#include <list>

using namespace irr;
using namespace std;

list<wstring>* objects;

ObjectsList::ObjectsList(IrrlichtDevice *device) {
	string fontFile = "font/myfont.xml";
	font = device->getGUIEnvironment()->getFont((constants::RESOURCES+fontFile).c_str());

	objects = new list<wstring>();
}

void ObjectsList::addObject(const wchar_t* newObject){
	objects->insert(objects->end(), newObject);
}

void ObjectsList::removeObject(const wchar_t* removeObject){
	objects->remove(removeObject);
}


void ObjectsList::drawAll(){
	list<wstring>::const_iterator cii;
	int cursorX = 130;
	int y = 10;
	int spacing = 10;
	for(cii=objects->begin(); cii!=objects->end(); ++cii){
		const wchar_t* cStr = cii->c_str();
		irr::core::dimension2d<unsigned int> stringSize = font->getDimension(cStr);
		font->draw(cStr, core::rect<s32>(cursorX, y, cursorX+stringSize.Width, y+stringSize.Height),video::SColor(255, 255, 255, 255));
		cursorX += stringSize.Width + spacing;
	}
}

