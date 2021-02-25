/**
 * \file Game.cpp
 *
 * \author(s) Ethan Strain, 
 */


#include "pch.h"
#include "Game.h"

using namespace Gdiplus;

/**
 * Draw the game area
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    // Fill the background with black
    SolidBrush brush(Color::Black);
    graphics->FillRectangle(&brush, 0, 0, width, height);

    //
    // Automatic Scaling
    //
    float scaleX = float(width) / float(Width);
    float scaleY = float(height) / float(Height);
    mScale = min(scaleX, scaleY);

    // Ensure it is centered horizontally
    mXOffset = (float)((width - Width * mScale) / 2);

    // Ensure it is centered vertically
    mYOffset = (float)((height - Height * mScale) / 2);

    graphics->TranslateTransform(mXOffset, mYOffset);
    graphics->ScaleTransform(mScale, mScale);

    // From here on you are drawing virtual pixels

    // TODO: draw game items + background
}


/**
 * Must determine the size of the window and scale to fit the screen.
 * choose a scale so the playing area will fit both horizontally and
 * vertically.
 * 
 * Unsure of parameters
 */
void CGame::ScaleToFit()
{
}
