/**
 * \file Game.h
 *
 * \author(s) Ethan Strain, Michael Dittman, 
 *
 * Class that describes CGame
 *
 * Contains functionality to draw,
 */

#pragma once

#include<vector>
#include<memory>
#include "Item.h"
#include "Hero.h"
#include "Level.h"

/**
 * Class that describes a game of Sparty Crossing.
 */
class CGame
{
public:

	// need contructor etc.. and we should be able to get a black screen
	CGame::CGame();

	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	void Add(std::shared_ptr<CItem> item);
	void Add(std::shared_ptr<CLevel> level);

	void Save(const std::wstring& filename);

	void Load(const std::wstring& filename);
	void Load(const int level);

	void Clear();

	/** Setter for hero pointer
	 * \param hero pointer for hero of that level
	 */
	void SetHero(std::shared_ptr<CHero> hero) { mHero = hero; }

	void moveHero(UINT nChar);

	void Update(double elapsed);

	void Accept(CItemVisitor* visitor);

private:
	// game playing area constants:
	// leftmost 1024 x 1024 is the game grid
	// The control panel is the right 200 pixels

	/// Game area width in virtual pixels
	const static int Width = 1224;

	/// Game area height in virtual pixels
	const static int Height = 1024;

	float mScale = 0;

	float mXOffset = 0;

	float mYOffset = 0;

	/// The items that will be contained in the current level
	std::vector<std::shared_ptr<CItem> > mItems;

	/// Levels which can be played
	std::vector<std::shared_ptr<CLevel>> mLevels;

	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Pointer for our hero
	std::shared_ptr<CHero> mHero = nullptr;

};

