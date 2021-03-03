/**
 * \file Decor.cpp
 *
 * \author Andrew Haakenson
 */

#include "pch.h"
#include "Decor.h"
#include "Game.h"

/**
 * Constructor for CDecor.
 * 
 * \param game Pointer to the game this decor is a part of
 * \param bitmap Bitmap of this item's image
 */
CDecor::CDecor(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap) :
	CItem(game, bitmap)
{
}

/**
 * Constructor for CDecor.
 *
 * \param game Pointer to the game this decor is a part of
 */
CDecor::CDecor(CGame* game) :
	CItem(game)
{
}

/**
 * Draws a decor object onto the screen
 *
 * \param graphics Graphics device to draw on
 */
void CDecor::Draw(Gdiplus::Graphics* graphics)
{
	Gdiplus::Bitmap* itemImage = this->GetImage();
	double wid = itemImage->GetWidth();
	double hit = itemImage->GetHeight();

	// Repeats image in both directions 
	for (int x = 0; x < mRepeatX; x++)
	{
		for (int y = 0; y < mRepeatY; y++)
		{
			// POSSIBLY TEMPORARY
			// Multiplies coordinates by 64 until we have a concrete virtual pixel solution
			// EDIT: Ethan - moved conversion of mX and mY to pixels into CItem XmlLoad()
			graphics->DrawImage(itemImage,
				float(GetX() + x * 64.0), float(GetY() + y * 64.0),
				(float)itemImage->GetWidth() + 1, (float)itemImage->GetHeight() + 1);
		}
	}
}

/**
 * Load the attributes for a decor node.
 * 
 * \param node The Xml node we are loading the decor from
 */
void CDecor::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	CItem::XmlLoad(node);

	// Save repeats in each direction
	int repeatX = node->GetAttributeIntValue(L"repeat-x", 1);
	int repeatY = node->GetAttributeIntValue(L"repeat-y", 1);
	mRepeatX = repeatX;
	mRepeatY = repeatY;
}