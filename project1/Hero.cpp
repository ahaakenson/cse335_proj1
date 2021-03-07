/**
 * \file Hero.cpp
 *
 * \author Michael Dittman
 */

#include "pch.h"
#include "Hero.h"
#include <iostream>

/// The upper border of the screen
const int topBorder = 128;

const int lowerBorder = 896;

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
 * Copy constructor
 * \param hero Hero being copied
 */
CHero::CHero(const CHero& hero) : CItem(hero)
{
    mName = hero.mName;
}

/**
 * Load the attributes for a decor node.
 *
 * \param node The Xml node we are loading the decor from
 */
void CHero::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);

    // Save repeats in each direction
    std::wstring name = node->GetAttributeValue(L"name", L"Sparty");
    mName = name;

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

    // Move the hero forward, unless at top of the screen
    if (currentY > topBorder)
    {
        this->SetLocation(currentX, currentY - 64);
    }
}


/**
 * Function to make the hero move backwards
 */
void CHero::moveBackward()
{

    // Get the current position
    double currentY = this->GetY();
    double currentX = this->GetX();

    // Move the hero forward, unless at bottom of the screen
    if (currentY < lowerBorder)
    {
        this->SetLocation(currentX, currentY + 64);
    }
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

/**
 * Update function for vehicle. Checks if a vehicle needs to be reset
 * to the other side of the screen.
 * \param elapsed Time elapsed
 */
void CHero::Update(double elapsed)
{
    SetLocation(GetX() + mSpeed * elapsed, GetY());
}