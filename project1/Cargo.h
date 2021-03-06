/**
 * \file Cargo.h
 *
 * \author(s) Ethan Strain, Matthew Norris
 *
 * Class to handle cargo type items
 */

#pragma once

#include "Item.h"
#include "Hero.h"

#include <memory>
#include <string>

/**
 * Class to handle cargo items
 */
class CCargo :
    public CItem
{
public:

	/// Default contructor (disabled)
	CCargo() = delete;

	/// Copy constructor (disabled)
	CCargo(const CCargo&) = delete;

	CCargo(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap);

	CCargo(CGame* game);

	/** Returns whether or not Cargo is being carried by the Hero
	 * \return True if Cargo is being carried */
	bool GetCarryStatus() { return mCarriedByHero; }

	virtual void Draw(Gdiplus::Graphics* graphics);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	void PickUp();

	void Release();

	bool HitTest(int x, int y);

	void Update(double elapsed, std::shared_ptr<CHero> hero);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitCargo(this); }

private:

	/// Flag for if the cargo is currently being held by the hero
	bool mCarriedByHero = false;

	/// Flag for if the cargo object has been left alone for too long
	/// with the CCargo object that eats it
	bool mEaten = false;

	/// name of the Cargo object that gets displayed on the Control Panel
	std::wstring mName;

	/// Cargo ID to identify object internally
	std::wstring mId;

	/// Image filename when object is in place
	std::wstring mImage;

	/// Image filename when object is being carried
	std::wstring mCarriedImage;

};

