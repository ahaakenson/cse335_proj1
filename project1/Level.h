/**
 * \file Level.h
 *
 * \author Andrew Haakenson
 *
 * Class representing a level.
 */

#pragma once
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "Item.h"
#include "Hero.h"


 /**
 Class representing a rectangle like a stripe on the road. 
  */
class CLevel
{
public:
	/// default constructor (disabled)
	CLevel() = delete;
	CLevel(CGame* game);

	void Load(const std::wstring& filename);
	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, const double speed = 0.0, const int width = 0);
	void Add(std::shared_ptr<CItem> item);
	/** Getter for item vector
	 * 
	 * \return item vector
	 */
	std::vector<std::shared_ptr<CItem>> GetItems() { return mItemVec; }

	/**
	 * Getter for hero pointer for this level
	 * 
	 * \return hero pointer
	 */
	std::shared_ptr<CHero> GetHero() { return mHero; }
private:
	/// Map holding the bitmaps associated with IDs
	std::map<std::wstring, std::vector<std::shared_ptr<Gdiplus::Bitmap>>> mImageMap; 
	/// Vector holding all items for that level
	std::vector<std::shared_ptr<CItem>> mItemVec; 
	/// Pointer to game
	CGame* mGame; 
	/// Pointer to hero of this level
	std::shared_ptr<CHero> mHero; 
};

