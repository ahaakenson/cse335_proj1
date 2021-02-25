/**
 * \file Item.h
 *
 * \author Nikolai Tolmoff
 *
 * Base class for all game items.
 */

#pragma once

#include <string>
#include <memory>
#include "XmlNode.h"

class CGame;

/**
 * Base class for all game items.
 */
class CItem
{
public:
	/// Default contructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	virtual ~CItem();

	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	 * \returns Y location in pixels */
	double GetY() const { return mY; }

	/** The width of the item
	 * \returns width in pixels */
	double GetWidth() const { return mItemImage->GetWidth(); }

	/** The height of the item
	 * \returns height in pixels */
	double GetHeight() const { return mItemImage->GetHeight(); }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Get the game this item is in
	/// \returns Game pointer
	CGame* GetGame() { return mGame; }

	virtual void Draw(Gdiplus::Graphics* graphics);

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

protected:
	CItem(CGame* game, const std::wstring& filename);

private:
	/// The game this item is a part of
	CGame* mGame;

	// Item location on the playing field
	double mX = 0;			///< X location for the center of the item
	double mY = 0;			///< Y location for the center of the item

	// The image of this item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
};

