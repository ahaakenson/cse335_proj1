/**
 * \file Cargo.cpp
 *
 * \author(s) Ethan Strain
 */


#include "pch.h"
#include "Cargo.h"



/**
 * Constructor for CCargo
 * 
 * \param game Pointer to game object
 * \param filename File where the image is stored
 */
CCargo::CCargo(CGame* game, const std::wstring& filename) :
	CItem(game, filename)
{
}

void CCargo::Draw(Gdiplus::Graphics* graphics)
{
	// If mCarriedByHero is true, and no other objects are being carried,
	// should be drawn on top of hero (should this be in derived classes?)

}


/**
 * Load the attributes that are universal to Cargo
 * 
 * \param node The Xml node to load Cargo attributes from
 */
void CCargo::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	CItem::XmlLoad(node);

	// load cargo specific xml info
	mId = node->GetAttributeValue(L"cargo id", L"");
	mName = node->GetAttributeValue(L"name", L"");

	mImage = node->GetAttributeValue(L"image", L"");
	mCarriedImage = node->GetAttributeValue(L"image", L"");
}


void CCargo::PickUp()
{
}


void CCargo::Release()
{
}
