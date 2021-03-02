/**
 * \file ControlPanel.h
 *
 * \author Matthew Norris
 *
 * 
 */

#pragma once

#include "Game.h"


class CControlPanel: public CGame
{
public: 

	/// Default constructor (disabled)
	CControlPanel() = delete;

	/// Copy constructor (disabled)
	CControlPanel(const CControlPanel&) = delete;

	//Function that will draw our timer, and other control panel graphics
	virtual void Draw(Gdiplus::Graphics* graphics);

	//Function to constantly update timer
	void Update(double elapsed);


private: 
	//count for our timer
	double time = 0;
	
};

