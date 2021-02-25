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
CHero::CHero(CGame* game) : CItem(game, HeroImageName)
{
}


/**
 * Save the heronode
 * \param node 
 * \returns 
 */
std::shared_ptr<xmlnode::CXmlNode> CHero::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto heroNode = node->AddChild(L"hero");

    return heroNode;

}
