/**
 * \file Game.h
 *
 * \author(s) Ethan Strain, 
 *
 * 
 */

#pragma once


/**
 * 
 */
class CGame
{
public:

	// need contructor etc.. and we should be able to get a black screen

	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	void ScaleToFit();

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
};

