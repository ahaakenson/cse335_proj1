/**
 * \file ControlPanel.cpp
 *
 * \author(s), Matthew Norris, Michael Dittman
 */

#include "pch.h"
#include "ControlPanel.h"
#include <string>
#include <vector>
#include <algorithm>
#include "IsCargoVisitor.h"
#include "Vehicle.h"

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

    // Font family for control panel (at the moment)
    FontFamily fontFamily(L"Verdana");

    // Font for "Get Ready!"
    Gdiplus::Font getReadyFont(&fontFamily, 20);

    // Font for timer
    Gdiplus::Font timerFont(&fontFamily, 22);
 
    // Brush for "Level x begin"
    SolidBrush orange(Color(255, 111, 1));

    // Font for "Level x begin"
    Gdiplus::Font levelBeginFont(&fontFamily, 44, FontStyleBold);

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
                &levelBeginFont, PointF(300,480), &orange);
            break;
        case 1:
            graphics->DrawString(L"Level 1 Begin", -1,
                &levelBeginFont, PointF(300, 480), &orange);
            break;
        case 2:
            graphics->DrawString(L"Level 2 Begin", -1,
                &levelBeginFont, PointF(300, 480), &orange);
            break;
        case 3:
            graphics->DrawString(L"Level 3 Begin", -1,
                &levelBeginFont, PointF(300, 480), &orange);
            break;
        }

    }
    // Draw the timer
    else
    {
        // Convert to wstring
        wstring minutes = to_wstring(mMinutes); // minutes

        wstring seconds = to_wstring(mSeconds); // seconds

        // Convert to WCHAR*
        const WCHAR* minute = minutes.c_str(); // minutes

        const WCHAR* second = seconds.c_str(); // seconds

        // If we are going to draw double digit time
        if (mMinutes > 9)
        {
            // Draw timer
            graphics->DrawString(minute, -1,
                &timerFont, PointF(1040, 2), &white); // minutes
        }
        else
        {
            // Draw timer
            graphics->DrawString(minute, -1,
                &timerFont, PointF(1060, 2), &white); // minutes
        }


        // If the time is less than 10 seconds, draw a leading zero
        if (mSeconds < 10)
        {
            // Draw a leading zero
            graphics->DrawString(L"0", -1,
                &timerFont, PointF(1090, 2), &white); // seconds
            graphics->DrawString(second, -1,
                &timerFont, PointF(1110, 2), &white); // seconds
        }
        // else draw the whole double digit
        else
        {
            graphics->DrawString(second, -1,
                &timerFont, PointF(1090, 2), &white); // seconds
        }

        graphics->DrawString(L":", -1,
            &timerFont, PointF(1075, 2), &white); // colon


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

    int i = 90;
    for (auto name : mCargoNames)
    {

        // Convert to WCHAR*
        const WCHAR* cargoName = name.c_str(); // name
        graphics->DrawString(cargoName, -1, 
            &font, PointF((Gdiplus::REAL)1024, (Gdiplus::REAL)i), &pink); // draw

        i += 40;

    }

    // Font for level loss
    Gdiplus::Font levelLossFont(&fontFamily, 44, FontStyleBold);

    // Get the name of the vehicle that hit sparty
    //wstring vehicleName = mSpartyCar;
   // const WCHAR* vehicleNameChar = vehicleName.c_str();

    const WCHAR* heroName = mHeroName.c_str();


    switch (mGame->GameLossCondition())
    {
    // Sparty hit a car
    case 1:

        // Draw the hero name
        graphics->DrawString(heroName, -1,
            &levelLossFont, PointF(390, 370), &orange); // draw
        graphics->DrawString(L"  was hit by\n     ", -1,
            &levelLossFont, PointF(300, 430), &orange); // draw

        if (mSpartyCar == L"ohio")
        {
            graphics->DrawString(L"Ohio   ", -1,
                &levelLossFont, PointF(420, 490), &orange); // draw
        }
        else if (mSpartyCar == L"michigan")
        {
            graphics->DrawString(L"Michigan", -1,
                &levelLossFont, PointF(360, 490), &orange); // draw
        }
        else if (mSpartyCar == L"nebraska")
        {
            graphics->DrawString(L"Nebraska", -1,
                &levelLossFont, PointF(350, 490), &orange); // draw
        }
        else if (mSpartyCar == L"iowa")
        {
            graphics->DrawString(L"Iowa", -1,
                &levelLossFont, PointF(420, 490), &orange); // draw
        }
        break;

    // Sparty fell in river
    case 2:
        // Draw the hero name
        graphics->DrawString(heroName, -1,
            &levelLossFont, PointF(390, 370), &orange); // draw
        graphics->DrawString(L"has fallen into\n   the river", -1,
            &levelLossFont, PointF(300, 430), &orange); // draw
        break;

    // Cargo ate something
    case 3:
        graphics->DrawString(L"Someone ate something", -1,
            &levelLossFont, PointF(350, 480), &orange); // draw
        break;

    }

    if (mGame->GameWon())
    {
        graphics->DrawString(L"Level Complete!", -1,
            &font, PointF(350, 480), &orange);
    }

}

/**
 * Function that will update the timer, every second
 * \param elapsed 
 */
void CControlPanel::Update(double elapsed)
{
    // mTime accumulates time since last draw
    mTime += elapsed;

    if (mTime > 3)
    {

        mTimerTime += elapsed;

        // Convert to minutes
        int minutes = (int)mTimerTime / 60;
        int seconds = ((int)mTimerTime) % 60;

        // Set minutes and seconds
        mMinutes = minutes;
        mSeconds = seconds;
    }

}

/**
 * Clear the cargo names
 */
void CControlPanel::Clear()
{
    // Set time to zero
    mTime = 0.0;

    // mTimer to zero
    mTimerTime = 0.0;

    // Clear cargo names
    mCargoNames.erase(mCargoNames.begin(), mCargoNames.end());
}

