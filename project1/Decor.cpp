/**
 * \file Decor.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Decor.h"
#include "Game.h"

CDecor::CDecor(CGame* game, const std::wstring& filename) : 
	CItem(game, filename)
{
}

/**
 * Load the attributes for a decor node.
 * 
 * \param node The Xml node we are loading the decor from
 */
void CDecor::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	CItem::XmlLoad(node);
	// TODO: once we have level class, have that actually load decor and have it repeat like xml file specifies
}