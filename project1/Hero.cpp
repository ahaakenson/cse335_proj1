/**
 * \file Hero.cpp
 *
 * \author Michael Dittman
 */

#include "pch.h"
#include "Hero.h"
#include <iostream>

 /// The Hero's image
const std::wstring HeroImageName = L"images/sparty.png";


/**
 * Constructor for the Hero
 * \param game The game this Hero is a part of
 */
/*
CHero::CHero(CGame* game) : CItem(game, HeroImageName)
{

}*/

/**
 * Constructor for the Hero
 * \param game The game this Hero is a part of
 * \param bitmap Bitmap of the default image of hero
 */
CHero::CHero(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap) :
    CItem(game, bitmap)
{

}


/**
 * Save the hero node
 * \param node 
 * \returns 
 */
std::shared_ptr<xmlnode::CXmlNode> CHero::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto heroNode = node->AddChild(L"hero");

    return heroNode;

}


/**
 * Function to make the Hero move forwards
 */
void CHero::moveForward()
{

    // Get the current position
    double currentY = this->GetY();
    double currentX = this->GetX();

    // Move the hero forward, this may have to be changed w/ Virtual pixels
    this->SetLocation(currentX, currentY - 64);

}


/**
 * Function to make the hero move backwards
 */
void CHero::moveBackward()
{

    // Get the current position
    double currentY = this->GetY();
    double currentX = this->GetX();

    // Move the hero forward, this may have to be changed w/ Virtual pixels
    this->SetLocation(currentX, currentY + 64);

}

/**
 * Function to make the hero move left
 */
void CHero::moveLeft()
{

    // Get the current position
    double currentY = this->GetY();
    double currentX = this->GetX();

    // Move the hero forward, this may have to be changed w/ Virtual pixels
    this->SetLocation(currentX - 64, currentY);

}

/**
 * Function to make the hero move right
 */
void CHero::moveRight()
{

    // Get the current position
    double currentY = this->GetY();
    double currentX = this->GetX();

    // Move the hero forward, this may have to be changed w/ Virtual pixels
    this->SetLocation(currentX + 64, currentY);

}
