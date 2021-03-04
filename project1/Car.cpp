/**
 * \file Car.cpp
 *
 * \author Michael Dittman
 */

#include "pch.h"
#include "Car.h"

CCar::CCar(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap) :
	CVehicle(game, bitmap)
{
}

void CCar::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	CVehicle::XmlLoad(node);
}
