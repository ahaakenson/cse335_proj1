/**
 * \file Road.h
 *
 * \author Matthew Norris
 *
 * Class representing grass tiles.
 */

#pragma once
#include "Decor.h"
#include "XmlNode.h"
 /**
  * Class representing grass tiles
  */
class CGrass : public CDecor
{
public:
	/// Default contructor (disabled)
	CGrass() = delete;

	/// Copy constructor (disabled)
	CGrass(const CGrass&) = delete;

	~CGrass();

	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);


};

