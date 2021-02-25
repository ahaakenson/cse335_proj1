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
 * \param filename file where the image is.
 */
CRoad::CRoad(CGame* game, const std::wstring& filename) :
	CDecor(game, filename)
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