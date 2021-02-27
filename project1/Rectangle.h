/**
 * \file Rectangle.h
 *
 * \author Andrew Haakenson
 *
 * Class representing a rectangle like a stripe on the road.
 */

#pragma once
#include "Decor.h"
#include "Game.h"
#include <vector>

 /** 
  *Class representing a rectangle like a stripe on the road.
  */
class CRectangle : public CDecor
{
public:
	/// Default contructor (disabled)
	CRectangle() = delete;

	/// Copy constructor (disabled)
	CRectangle(const CRectangle&) = delete;

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	CRectangle(CGame* game);

	virtual void Draw(Gdiplus::Graphics* graphics);

private:
	/// Vector representing RGB colors of rectangle
	std::vector<int> mColor{0, 0, 0};
	/// Height of rectangle
	double mHeight = 0;
	/// Width of rectangle
	double mWidth = 0;
};

