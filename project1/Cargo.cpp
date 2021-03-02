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
	mCarriedImage = node->GetAttributeValue(L"carried-image", L"");
}


void CCargo::PickUp()
{
}


void CCargo::Release()
{
}


bool CCargo::HitTest(int x, int y)
{
	
	double wid = GetImage()->GetWidth();
	double hit = GetImage()->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image.
	// Subtracting the center makes x, y relative to the center of
	// the image. Adding half the size makes x, y relative to the top
	// corner of the image.
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}
	else return true;

}