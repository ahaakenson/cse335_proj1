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

/**
 * Class that describes a game of Sparty Crossing.
 */
class CGame
{
public:

	// need contructor etc.. and we should be able to get a black screen
	CGame::CGame();

	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	void ScaleToFit();

	void Add(std::shared_ptr<CItem> item);

	void Save(const std::wstring& filename);

	void Load(const std::wstring& filename);

	void Clear();

	void SetHero(std::shared_ptr<CHero> hero) { mHero = hero; }

	void moveHero(UINT nChar);

	void Update(double elapsed);

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

	void CGame::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Pointer for our hero
	std::shared_ptr<CHero> mHero = nullptr;

};

