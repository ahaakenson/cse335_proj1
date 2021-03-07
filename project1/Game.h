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
#include<utility>
#include "Item.h"
#include "Hero.h"
#include "Cargo.h"
#include "Level.h"
#include "ControlPanel.h"

class CControlPanel;

/**
 * Class that describes a game of Sparty Crossing.
 */
class CGame
{
public:

	// need contructor etc.. and we should be able to get a black screen
	CGame::CGame();

	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	std::pair<double, double> ScaleCoords(int x, int y);

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

	CCargo* HitTest(int x, int y);

	/// Get the width of the game window
	/// \returns Game window width
	int GetWidth() const { return Width; }

	/// Get the height of the game window
	/// \returns Game window height
	int GetHeight() const { return Height; }

	/// Get a pointer to the Hero
	/// \returns pointer to Hero
	std::shared_ptr<CHero> GetHero() const { return mHero; }

	void UpdateControlPanel(double elapsed);

	void DrawControlPanel(Gdiplus::Graphics* graphics);

	void CollisionTest(int x, int y);

	void BoatTest();

	bool GameState() { return mGameOver; }

	bool GetRoadCheatState() { return mRoadCheatEnabled; }

	bool GetRiverCheatState() { return mRiverCheatEnabled; }

	void SetRoadCheatState(bool state) { mRoadCheatEnabled = state; }

	void SetRiverCheatState(bool state) { mRiverCheatEnabled = state; }

private:
	// game playing area constants:
	// leftmost 1024 x 1024 is the game grid
	// The control panel is the right 200 pixels

	/// Game area width in virtual pixels
	const static int Width = 1224;

	/// Game area height in virtual pixels
	const static int Height = 1024;

	/// Scale for virtual pixels
	float mScale = 0;

	/// X Offset for virtual pixels
	float mXOffset = 0;

	/// Y Offset for virtual pixels
	float mYOffset = 0;

	/// The items that will be contained in the current level
	std::vector<std::shared_ptr<CItem> > mItems;

	/// Levels which can be played
	std::vector<std::shared_ptr<CLevel>> mLevels;

	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Pointer for our hero
	std::shared_ptr<CHero> mHero = nullptr;

	/// Pointer for control panel
	std::shared_ptr<CControlPanel> mControlPanel;

	// Bool to store if the game is over
	bool mGameOver = false;

	/// River Cheat
	bool mRiverCheatEnabled = false;

	/// Road cheat
	bool mRoadCheatEnabled = false;

};

