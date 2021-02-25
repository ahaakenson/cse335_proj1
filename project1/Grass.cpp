/**
 * \file Grass.cpp
 *
 * \author Matthew Norris
 */


#include "pch.h"
#include "Grass.h"

 /// The Grass' image
const std::wstring GrassImageName = L"images/grass1.png";


/**
 * Constructor for the grass tiles
 * \param game: The game the grass is being constructed for
 */
//CGrass::CGrass(CGame* game) : CDecor(game, GrassImageName)
//{

//}

 /**
  * Destructor
  */
CGrass::~CGrass()
{
}

/**function that will load in the node attributes
* from the xml file
 * 
 * \param node This is the xml node being loaded from
 * the level class
 */ 
void CGrass::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{

}



