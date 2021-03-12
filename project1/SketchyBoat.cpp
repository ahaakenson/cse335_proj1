/**
 * \file SketchyBoat.cpp
 *
 * \author Ethan Strain
 */


#include "pch.h"
#include "SketchyBoat.h"


/**
 * Constructor
 * \param game 
 * \param bitmap 
 * \param speed 
 * \param yPos 
 * \param xPos 
 * \param width 
 */
CSketchyBoat::CSketchyBoat(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap, double speed, int yPos, int xPos, int width) :
    CBoat(game, bitmap, speed, yPos, xPos, width)
{
}

/**
 * Copy constructor
 * \param boat 
 */
CSketchyBoat::CSketchyBoat(const CSketchyBoat& boat) : CBoat(boat)
{
    mIsRidden = boat.mIsRidden;
}

/** Accept a visitor
 * \param visitor The visitor we accept */
void CSketchyBoat::Accept(CItemVisitor* visitor)
{
    visitor->VisitBoat(this);
    visitor->VisitVehicle(this);
}
