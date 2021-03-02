/**
 * \file Cargo.h
 *
 * \author(s) Ethan Strain, 
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

	CCargo(CGame* game, const std::wstring& filename);

	virtual void Draw(Gdiplus::Graphics* graphics);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	void PickUp();

	void Release();

	bool HitTest(int x, int y);

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

