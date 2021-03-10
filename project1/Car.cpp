/**
 * \file Car.cpp
 *
 * \author Michael Dittman, Matthew Norris
 */

#include "pch.h"
#include "Car.h"

 /**
 * Constructor
 * \param game Game that car is in
 * \param bitmap1 Default image of car
 * \param bitmap2 Swapped image of car
 * \param speed Speed of car
 * \param yPos y position of car
 * \param xPos x position of car
 * \param width Width of road
 */
CCar::CCar(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap1, std::shared_ptr<Gdiplus::Bitmap> bitmap2, double speed, int yPos, int xPos, int width)
    : CVehicle(game, bitmap1, speed, yPos, xPos, width)
{
    mSwappedImage = bitmap2;
    mImage = bitmap1;
}

/**
 * Copy constructor
 * \param car Car being copied.
 */
CCar::CCar(const CCar& car) : CVehicle(car)
{
    mSwappedImage = car.mSwappedImage;
    mImage = car.mImage;
    mSwapTime = car.mSwapTime;
}

/**
 * 
 * \param node 
 */
void CCar::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{

    double swapTime = node->GetAttributeDoubleValue(L"swap-time", 0);
    mSwapTime = swapTime;
	CVehicle::XmlLoad(node);
}


/**
 * 
 * \param elapsed 
 */
void CCar::Update(double elapsed)
{
    // some logic to swap every time swap-time has passed

    CVehicle::Update(elapsed);

}

