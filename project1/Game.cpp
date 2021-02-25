/**
 * \file Game.cpp
 *
 * \author(s) Ethan Strain, Michael Dittman, 
 */


#include "pch.h"
#include "Game.h"
#include "XMLNode.h"
#include "Hero.h"
#include <memory>

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;


/**
 * Game constructor
 */
CGame::CGame()
{

// Uncomment to see sparty drawn on screen

/*
    shared_ptr<CHero> hero = make_shared<CHero>(this);
    hero->SetLocation(612, 950);
    this->Add(hero);
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
 * Responsible for adding items to mItems
 *
 * \param item The item to add to the vector of items in the current level
 */
void CGame::Add(std::shared_ptr<CItem> item)
{

    mItems.push_back(item);

}

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
        for (auto node : root->GetChildren())
        {

            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
            {
                XmlItem(node);
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


/**
 * 
 * \param elapsed 
 */
void CGame::Update(double elapsed)
{

/*
    
    // uncomment when we implement Update in subclasses

    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
    
*/

}

/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CGame::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{



}
