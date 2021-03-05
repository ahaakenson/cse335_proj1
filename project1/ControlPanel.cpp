/**
 * \file ControlPanel.cpp
 *
 * \author Michael Dittman
 */

/**
 * \file ControlPanel.cpp
 *
 * \author Matthew Norris
 */

#include "pch.h"
#include "ControlPanel.h"
#include <string>

using namespace std;
using namespace Gdiplus;


/**
 * Control panel constructor
 * \param game The game this control panel is a part of
 */
CControlPanel::CControlPanel(CGame* game)
{
    mGame = game;
}

/**
 * Function that will draw the timer
 * \param graphics The graphics context to draw on
 */
void CControlPanel::Draw(Gdiplus::Graphics* graphics)
{

    wstring minutes = to_wstring(mMinutes);

   // string minutes = to_string(mMinutes);
    string seconds = to_string(mSeconds);

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 24);

    // If the total elapsed time is less than this number, draw the level
    if (mTime < 6)
    {
        SolidBrush green(Color(144, 238, 144));
        graphics->DrawString(L"Level 1", -1,
            &font, PointF(1024, 2), &green);
    }
    else
    {
        // Start drawing the time
    }


    // Draw the Cargo
    SolidBrush orange(Color(255, 165, 0));


    graphics->DrawString(L"Cargo 1", -1,
        &font, PointF(1024, 40), &orange);

    graphics->DrawString(L"Cargo 2", -1,
        &font, PointF(1024, 80), &orange);

    graphics->DrawString(L"Cargo 3", -1,
        &font, PointF(1024, 120), &orange);


}



/**
 * Function that will update the timer, every second
 * \param elapsed 
 */
void CControlPanel::Update(double elapsed)
{
    // mTime accumulates time since last draw
    mTime += elapsed;

    // Convert to minutes
    int minutes = mTime / 60;
    int seconds = (int)(mTime-minutes) % 60;

    // Set minutes and seconds
    mMinutes = minutes;
    mSeconds = seconds;

}

//Need a drawsstring function, still unsure on how to 
//convert double to string
