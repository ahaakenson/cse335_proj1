/**
 * \file Vehicle.cpp
 *
 * \author Nikolai Tolmoff
 */

#include "pch.h"
#include "Vehicle.h"



/**
 * Constructor
 * \param game Pointer to the game this decor is a part of
 * \param bitmap Bitmap of this item's image
 * \param speed Speed of the boat
 * \param yPos Y position
 * \param xPos X position
 */
CVehicle::CVehicle(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap, double speed, int yPos, int xPos) : mSpeed(speed),
	CItem(game, bitmap, yPos, xPos)
{


}

/**
 * Constructor for CVehicle.
 *
 * \param game Pointer to the game this decor is a part of
 */
CVehicle::CVehicle(CGame* game) : CItem(game)
{
}



/**
 * Constructor
 * \param game Pointer to the game this decor is a part of
 * \param bitmap Bitmap of this item's image
 */
CVehicle::CVehicle(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap) : CItem(game, bitmap)
{
}


/**
 * Update function for vehicle
 * \param elapsed Time elapsed
 */
void CVehicle::Update(double elapsed)
{
	SetLocation(GetX() + mSpeed* elapsed, GetY());
}

/**
 * Load the attributes for a vehicle node.
 *
 * This is the  base class version that loads the attributes
 * common to all vehicles. Override this to load custom attributes
 * for specific vehicle.
 *
 * \param node The Xml node we are loading the vehicle from
 */
void CVehicle::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	//this->SetLocation(node->GetAttributeDoubleValue(L"x", 0), GetY());

	//mSpeed = node->GetAttributeDoubleValue(L"speed", 0);

    //CItem::XmlLoad(node);

}