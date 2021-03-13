/**
 * \file Cargo.cpp
 *
 * \author(s) Ethan Strain, Matthew Norris
 */

#include "pch.h"
#include "Cargo.h"
#include "Game.h"

/// Number of pixels wide and tall a tile is.
const double TileToPixels = 64;

/**
 * Constructor for CCargo
 * 
 * \param game Pointer to game object
 * \param bitmap Bitmap of item's image
 * \param carried Bitmap of item's carried image
 */
CCargo::CCargo(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap, std::shared_ptr<Gdiplus::Bitmap> carried) :
	CItem(game, bitmap)
{
	mCarriedItemImage = carried;
}

/**
 * Constructor for CCargo
 *
 * \param game Pointer to the game this decor is a part of
 */
CCargo::CCargo(CGame* game) : CItem(game)
{
}

CCargo::CCargo(const CCargo& cargo) : CItem(cargo)
{
	mCarriedByHero = cargo.mCarriedByHero;
	mEaten = cargo.mEaten;
	mCarriedItemImage = cargo.mCarriedItemImage;
	mName = cargo.mName;
	mId = cargo.mId;
	mImage = cargo.mImage;
	mCarriedImage = cargo.mCarriedImage;
}

/** Draws a cargo object
 * \param graphics Pointer to where to draw cargo
 */
void CCargo::Draw(Gdiplus::Graphics* graphics)
{
	CGame* game = GetGame();

	// if cargo is being carried, draw the cargo at the hero's position
	if (mCarriedByHero && !(game->GetGameLost()))
	{
		double wid = mCarriedItemImage->GetWidth();
		double hit = mCarriedItemImage->GetHeight();

		graphics->DrawImage(mCarriedItemImage.get(),
			float(game->GetHero()->GetX() - wid / 2), float(game->GetHero()->GetY() - hit / 2),
			(float)mCarriedItemImage->GetWidth(), (float)mCarriedItemImage->GetHeight());
	}
	else if (!mCarriedByHero)
	{
		CItem::Draw(graphics);
	}

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

/** Picks up cargo by hero
 */
void CCargo::PickUp()
{
	if (GetGame()->GetHero()->GetY() - GetY() <= TileToPixels &&
		GetGame()->GetHero()->GetY() - GetY() >= -TileToPixels &&
		!(GetGame()->GetHero()->GetCarrying()))
	{
		mCarriedByHero = true;
		GetGame()->GetHero()->SetCarrying(true);
	}

}

/** Releases cargo.
 */
void CCargo::Release()
{
	mCarriedByHero = false;
	GetGame()->GetHero()->SetCarrying(false);
	//mLevel->GetImage([])
	
	//GetGame()->CheckWinState();
}

/** Checks if this cargo was hit by a mouse click.
 * \param x X coordinate of mouse click
 * \param y Y coordinate of mouse click
 * \return True if cargo was clicked by mouse, false otherwise
 */
bool CCargo::HitTest(double x, double y)
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

/**
 * Update function for vehicle
 * \param elapsed Time elapsed
 * \param hero Pointer to the hero
 */
void CCargo::Update(double elapsed, std::shared_ptr<CHero> hero)
{
	if (mCarriedByHero)
	{
		SetLocation(hero->GetX(), hero->GetY());
	} 

	
}