/**
 * \file Vehicle.cpp
 *
 * \author Nikolai Tolmoff
 */

#include "pch.h"
#include "Vehicle.h"

using namespace Gdiplus;

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


/**
 * Draw the vehicle
 * \param graphics 
 */
void CVehicle::Draw(Gdiplus::Graphics* graphics)
{
    // Get the image item
    Gdiplus::Bitmap* itemImage = this->GetImage();

    // Height and Width of Image
    double wid = itemImage->GetWidth();
    double hit = itemImage->GetHeight();

    const int Width = 1024;

    if (GetX() - GetWidth() / 2 < 0)
    {
        CItem::Draw(graphics);

        SolidBrush black(Color(0, 0, 0));

        graphics->FillRectangle(&black, float(-600), float(GetY() - hit / 2),
            (float)600, (float)800);
    }
    else if (GetWidth() / 2 + GetX() > Width)
    {
        CItem::Draw(graphics);

        SolidBrush black(Color(0, 0, 0));

        graphics->FillRectangle(&black, float(Width), float(GetY() - hit / 2),
            (float)800, (float)800);
    }
    else
    {
        CItem::Draw(graphics);
    }

}
