/**
 * \file Item.cpp
 *
 * \author Nikolai Tolmoff
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param game The game this item is a part of.
 * \param filename The name of the file we are loading from.
 */
CItem::CItem(CGame* game, const std::wstring& filename) : mGame(game)
{
    mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    if (mItemImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }
}

/**
 * Destructor
 */
CItem::~CItem()
{
}

/**
 * Draw the game item
 * \param graphics Graphics device to draw on
 */
void CItem::Draw(Gdiplus::Graphics* graphics)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    graphics->DrawImage(mItemImage.get(),
        float(GetX() + wid / 2), float(GetY() - hit / 2),
        (float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
}