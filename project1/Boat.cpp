/**
 * \file Boat.cpp
 *
 * \author Michael Dittman
 */

#include "pch.h"
#include "Boat.h"


/**
 * Constructor
 * \param game Game that boat is in
 * \param bitmap Image of boat
 */
CBoat::CBoat(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap) : CVehicle(game, bitmap)
{
}

void CBoat::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{

    CVehicle::XmlLoad(node);

}
