/**
 * \file ControlPanel.h
 *
 * \author Matthew Norris
 *
 * 
 */

#pragma once

#include "Game.h"


class CControlPanel
{
public: 

	/// Default constructor (disabled)
	CControlPanel() = delete;

	/// Copy constructor (disabled)
	CControlPanel(const CControlPanel&) = delete;

	CControlPanel(CGame* game);

	//Function that will draw our timer, and other control panel graphics
	virtual void Draw(Gdiplus::Graphics* graphics);

	//Function to constantly update timer
	void Update(double elapsed);

	/**
	* Set the level this control panel belongs to
	* \param level The level this control panel belongs to
	*/
	void SetLevel(std::shared_ptr<CLevel> level, const int levelNumber) { mLevel = level, mLevelNumber = levelNumber; }


private: 
	
	/// The game this control panel belongs to
	CGame* mGame;

	/// The level this control panel is a part of
	std::shared_ptr<CLevel> mLevel = nullptr;

	/// The level number
	int mLevelNumber = 0;

	/// Total time
	double mTime = 0;

	/// Minutes
	int mMinutes = 0;

	/// Seconds
	int mSeconds = 0;
	
};

