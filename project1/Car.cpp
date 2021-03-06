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
CCar::CCar(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap1, std::shared_ptr<Gdiplus::Bitmap> bitmap2, double speed, int yPos, int xPos, int width)
    : CVehicle(game, bitmap1, speed, yPos, xPos, width)
{
    mSwappedImage = bitmap2;
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

