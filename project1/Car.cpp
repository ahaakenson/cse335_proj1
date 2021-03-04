/**
 * \file Car.cpp
 *
 * \author Michael Dittman
 */

#include "pch.h"
#include "Car.h"

 /**
 * Constructor
 * \param game Game that car is in
 * \param bitmap Image of car
 */
CCar::CCar(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap, double speed, int yPos, int xPos) : CVehicle(game, bitmap, speed, yPos, xPos)
{
}

void CCar::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	CVehicle::XmlLoad(node);
}
