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
#include <vector>

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
    FontFamily fontFamily(L"Verdana");

    // Font for "Get Ready!"
    Gdiplus::Font getReadyFont(&fontFamily, 16);

    // Font for timer
    Gdiplus::Font timerFont(&fontFamily, 22);
 
    // Brush for "Level x begin"
    SolidBrush orange(Color(255, 111, 1));

    // Font for "Level x begin"
    Gdiplus::Font levelBeginFont(&fontFamily, 44);

    // Brush for "Get ready!"
    SolidBrush white(Color(248, 242, 218));

    // The amount of time to display the level icon for
    const double displayLevelTime = 3.0; // Seconds

    // If the total elapsed time is less than this number, draw "Get ready!"
    if (mTime < displayLevelTime)
    {
        graphics->DrawString(L"Get Ready!", -1,
            &getReadyFont, PointF(1024, 2), &white);

        // Draw "Level x Begin"
        switch (mLevelNumber)
        {
        case 0:
            graphics->DrawString(L"Level 0 Begin", -1,
                &levelBeginFont, PointF(350,512), &orange);
            break;
        case 1:
            graphics->DrawString(L"Level 1 Begin", -1,
                &levelBeginFont, PointF(350, 512), &orange);
            break;
        case 2:
            graphics->DrawString(L"Level 2 Begin", -1,
                &levelBeginFont, PointF(350, 512), &orange);
            break;
        case 3:
            graphics->DrawString(L"Level 3 Begin", -1,
                &levelBeginFont, PointF(350, 512), &orange);
            break;
        }

    }
    // Draw the timer
    else
    {

        const WCHAR* minute = minutes.c_str();

        graphics->DrawString(minute, -1,
            &timerFont, PointF(1030, 2), &white);

        const WCHAR* second = seconds.c_str();

        graphics->DrawString(second, -1,
            &timerFont, PointF(1080, 2), &white);

        // Minutes
        graphics->DrawString(L":", -1,
            &timerFont, PointF(1060, 2), &white);


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

    SolidBrush pink(Color(255, 192, 203));


    // Draw the Cargo

    graphics->DrawString(L"Fox", -1,
        &font, PointF(1024, 90), &pink);

    graphics->DrawString(L"Goose", -1,
        &font, PointF(1024, 130), &pink);

    graphics->DrawString(L"Grain", -1,
        &font, PointF(1024, 170), &pink);


}



/**
 * Function that will update the timer, every second
 * \param elapsed 
 */
void CControlPanel::Update(double elapsed)
{
    // mTime accumulates time since last draw
    mTime += elapsed;

    double test = floor(mTime);

    // Convert to minutes
    int minutes = mTime / 60;
    int seconds = ((int)mTime) % 60;

    // Set minutes and seconds
    mMinutes = minutes;
    mSeconds = seconds;

}


//Need a drawsstring function, still unsure on how to 
//convert double to string
