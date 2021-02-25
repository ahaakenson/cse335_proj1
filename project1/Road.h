/**
 * \file Road.h
 *
 * \author Andrew Haakenson
 * 
 * Class representing a road.
 */

#pragma once
#include "Decor.h"
#include "XmlNode.h"
#include "Game.h"

/**
 * Class representing a road.
 */
class CRoad : public CDecor
{
public:
	/// Default contructor (disabled)
	CRoad() = delete;

	/// Copy constructor (disabled)
	CRoad(const CRoad&) = delete;

	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	CRoad(CGame* game, const std::wstring& filename);

private:
	/// Speed of cars on this road.
	double mSpeed = 0;
};

