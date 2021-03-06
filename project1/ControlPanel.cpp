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
#include <wchar.h>

using namespace std;
using namespace Gdiplus;


/**
 * Control panel constructor
 * \param game The game this control panel is a part of
 */
CControlPanel::CControlPanel(CGame* game)
{
    mGame = game;
    mLevel = 0;
}

/**
 * Function that will draw the timer
 * \param graphics The graphics context to draw on
 */
void CControlPanel::Draw(Gdiplus::Graphics* graphics)
{

    wstring minutes = to_wstring(mMinutes);

   // string minutes = to_string(mMinutes);
    wstring seconds = to_wstring(mSeconds);

    // Font family for control panel (at the moment)
    FontFamily fontFamily(L"Arial");

    // Font for "Get Ready!"
    Gdiplus::Font getReadyFont(&fontFamily, 16);

    // Font for timer
    Gdiplus::Font timerFont(&fontFamily, 22);

    // Brush for timer and get ready
    SolidBrush white(Color(248, 242, 218));

    // The amount of time to display the level icon for
    const double displayLevelTime = 3.0; // Seconds

    // If the total elapsed time is less than this number, draw "Get ready!"
    if (mTime < displayLevelTime)
    {
        graphics->DrawString(L"Get Ready!", -1,
            &getReadyFont, PointF(1024, 2), &white);
    }
    else
    {

        // Minutes
        graphics->DrawString(L"00", -1,
            &timerFont, PointF(1024, 2), &white);

        // Minutes
        graphics->DrawString(L":", -1,
            &timerFont, PointF(1060, 2), &white);

        // Seconds
        graphics->DrawString(L"00", -1,
            &timerFont, PointF(1070, 2), &white);
    }

    // Font for level
    Gdiplus::Font font(&fontFamily, 24);

     
    // Draw the level number
    SolidBrush green(Color(144, 238, 144));

    switch (mLevelNumber)
    {
    case 0:
        graphics->DrawString(L"Level 0", -1,
            &font, PointF(1024, 40), &green);
        break;
    case 1:
        graphics->DrawString(L"Level 1", -1,
            &font, PointF(1024, 40), &green);
        break;
    case 2:
        graphics->DrawString(L"Level 2", -1,
            &font, PointF(1024, 40), &green);
        break;
    case 3:
        graphics->DrawString(L"Level 3", -1,
            &font, PointF(1024, 40), &green);
        break;
    }

    SolidBrush orange(Color(255, 165, 0));


    // Draw the Cargo

    graphics->DrawString(L"Fox", -1,
        &font, PointF(1024, 90), &orange);

    graphics->DrawString(L"Goose", -1,
        &font, PointF(1024, 130), &orange);

    graphics->DrawString(L"Grain", -1,
        &font, PointF(1024, 170), &orange);


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
