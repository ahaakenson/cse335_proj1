/**
 * \file Game.cpp
 *
 * \author(s) Ethan Strain, Michael Dittman, 
 */


#include "pch.h"
#include "Game.h"
#include "XMLNode.h"
#include "Hero.h"
#include "Decor.h"
#include "Rectangle.h"
#include <memory>
#include <iostream>
#include <map>

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;


/// TODO: change this so that images are only loaded once
map<wstring, wstring> imageMap; //< Map holding the image names associated with IDs

/**
 * Game constructor
 */
CGame::CGame()
{

// Draw decor tiles here

// Uncomment to see sparty drawn on screen
    /*
    shared_ptr<CHero> hero = make_shared<CHero>(this);
    hero->SetLocation(612, 912);
    this->Add(hero);
    this->mHero = hero;
    */
}

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

    // Iterate through all of the items in mItems
    // and draw them.
    for (auto item : mItems)
    {
        // For every item, draw the item
        item->Draw(graphics);

    }
    
    // Black lines are still leaking through the space between tiles
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


/**
 * Responsible for adding items to mItems.
 *
 * \param item The item to add to the vector of items in the current level
 */
void CGame::Add(std::shared_ptr<CItem> item)
{

    // Push an item back onto the list of mItems
    mItems.push_back(item);

}


/**
 * Function to save the state of the game.
 * This function is used for testing purposes.
 *
 * \param filename Filename to save
 */
void CGame::Save(const std::wstring& filename)
{

    //
    // Create an XML document
    //
    auto root = CXmlNode::CreateDocument(L"level");

    // Iterate over all items and save them
    for (auto item : mItems)
    {
        item->XmlSave(root);
    }

    try
    {
        root->Save(filename);
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

}


/**
 * Function to load in the contents of each level
 *
 * Load will be called inititally to Add the contents of an
 * XML file to the vector of items. It will be used again
 * when conditions for a new level to be loaded are met,
 * (clear will erase the contents of the old level)
 *
 * \param filename the Filename to load from
 */
void CGame::Load(const std::wstring& filename)
{

    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Once we know it is open, clear the existing data
        Clear();

        //
        // Traverse the children of the root
        // node of the XML document in memory!!!!
        //
        for (auto section : root->GetChildren())
        {

            // Types section of xml document
            if (section->GetType() == NODE_ELEMENT && section->GetName() == L"types")
            {
                // Go through each node in types section
                for (auto node : section->GetChildren())
                {
                    if (node->GetType() == NODE_ELEMENT && node->GetName() == L"decor")
                    {
                        wstring imageName = node->GetAttributeValue(L"image", L"");
                        wstring id = node->GetAttributeValue(L"id", L"");
                        imageMap[id] = L".\\images\\" + imageName;
                    }
                }
            }

            // Background section of xml document
            else if (section->GetType() == NODE_ELEMENT && section->GetName() == L"background")
            {
                // Go through each node in background section
                for (auto node : section->GetChildren())
                {
                    // Decor or rectangle node
                    if (node->GetType() == NODE_ELEMENT && (node->GetName() == L"decor" || node->GetName() == L"rect"))
                    {
                        XmlItem(node);
                    }
                }
            }

        }


    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

}

/**
 * Clear the Game data
 *
 * Deletes all known items in the Game.
 */
void CGame::Clear()
{
    // Removes the contents of the current level
    // (used when a level is completed and we want to load in the items of the next level)
    mItems.erase(mItems.begin(), mItems.end());
}

void CGame::moveHero(UINT nChar)
{

    // Call the appropriate move function based on what key was hit
    switch (nChar)
    {
    
    // This works but I don't like that it uses a number not the char
    case 69:
        mHero->moveForward();
        break;

    }

}

/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CGame::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // We have an item.  What type?
    wstring type = node->GetName();
    if (type == L"decor")
    {
        wstring id = node->GetAttributeValue(L"id", L"");
        item = make_shared<CDecor>(this, imageMap[id]);
    }
    else if (type == L"rect")
    {
        item = make_shared<CRectangle>(this);
    }

    // Add item to game item vector if it exists
    if (item != nullptr)
    {
        item->XmlLoad(node);
        Add(item);
    }

}
