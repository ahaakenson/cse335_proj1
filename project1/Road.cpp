/**
 * \file Road.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Road.h"

/**
 * Constructor for CRoad.
 * 
 * \param game Pointer to game where this will belong.
 * \param bitmap Bitmap of image
 */
CRoad::CRoad(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap) :
	CDecor(game, bitmap)
{
}

/**
 * Loads road specific attributes from xml node.
 * 
 * \param node The Xml node we are loading the road from
 */
void CRoad::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	// Set speed equal to value from xml node
	mSpeed = node->GetAttributeIntValue(L"speed", 0);
}