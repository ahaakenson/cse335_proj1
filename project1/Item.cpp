/**
 * \file Item.cpp
 *
 * \author Nikolai Tolmoff
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"
#include "XmlNode.h"

using namespace Gdiplus;
using namespace std;

const double tileToPixels = 64;

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
 * Constructor
 * \param game The game this item is a part of.
 */
CItem::CItem(CGame* game) : mGame(game)
{
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
        float(GetX() - wid / 2), float(GetY() - hit / 2),
        (float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
}


/**
 * Function to save items
 * \param node Node to save in file
 * \returns pointer to the node
 */
std::shared_ptr<xmlnode::CXmlNode> CItem::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    return std::shared_ptr<xmlnode::CXmlNode>();
}




/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * \param node The Xml node we are loading the item from
 */
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    double x, y = 0.0;
    x = node->GetAttributeDoubleValue(L"x", 0);
    y = node->GetAttributeDoubleValue(L"y", 0);

    // tile values multiplied by 64 to convert to pixels
    mX = x * tileToPixels;
    mY = y * tileToPixels;

}