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
 * \param filename file where image is stored
 */
CDecor::CDecor(CGame* game, const std::wstring& filename) : 
	CItem(game, filename)
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
				//float(GetX() - wid / 2 + x * 64), float(GetY() - hit / 2 + y * 64),
				float(GetX() + x * 64), float(GetY() + y * 64),
				(float)itemImage->GetWidth(), (float)itemImage->GetHeight());
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