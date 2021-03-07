/**
 * \file Game.cpp
 *
 * \author(s) Ethan Strain, Michael Dittman, 
 */


#include "pch.h"
#include "Game.h"
#include "XmlNode.h"
#include "Hero.h"
#include "Decor.h"
#include "Rectangle.h"
#include <memory>
#include <map>
#include <utility>
#include <algorithm>
#include "Cargo.h"
#include "Car.h"
#include "IsCargoVisitor.h"
#include "IsVehicleVisitor.h"
#include "IsBoatVisitor.h"
#include "ControlPanel.h"
#include "DecorTypeVisitor.h"

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

    mControlPanel = std::make_shared<CControlPanel>(this);

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

    // Iterate through all of the items in mItems
    // and draw them.
    for (auto item : mItems)
    {
        // For every item, draw the item
        item->Draw(graphics);
    }

    DrawControlPanel(graphics);
    
}


/**
 * Helps handle a mouse click on the game area.
 * Scales the coordinates into virtual pixels.
 * \param x X location clicked on
 * \param y Y location clicked on
 */
std::pair<double, double> CGame::ScaleCoords(int x, int y)
{
    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;

    return std::make_pair(oX, oY);
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
                    // If the type was decor
                    if (node->GetType() == NODE_ELEMENT && node->GetName() == L"decor")
                    {
                        wstring imageName = node->GetAttributeValue(L"image", L"");
                        wstring id = node->GetAttributeValue(L"id", L"");
                        imageMap[id] = L".\\images\\" + imageName;
                    }
                    
                    // This isn't working the way it should be

                    // If the type was car
                    if (node->GetType() == NODE_ELEMENT && node->GetName() == L"car")
                    {
                        wstring imageName = node->GetAttributeValue(L"image", L"");
                        wstring id = node->GetAttributeValue(L"id", L"");
                        imageMap[id] = L".\\images\\" + imageName;

                        XmlItem(node);

                    }

                    // If type was boat
                    /*
                    if (node->GetType() == NODE_ELEMENT && node->GetName() == L"boat")
                    {
                        wstring imageName = node->GetAttributeValue(L"image", L"");
                        wstring id = node->GetAttributeValue(L"id", L"");
                        imageMap[id] = L".\\images\\" + imageName;

                        XmlItem(node);

                    }
                    */
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

    // Clear the control panel
    mControlPanel->Clear();

    // Reset the game loss state
    mGameOver = false;
}



/**
 * Function for the game to move it's hero.
 * \param nChar The character the was pressed.
 */
void CGame::moveHero(UINT nChar)
{
    bool validKeyPress = false;
    // This works but I don't like that it uses a number not the char

    // Call the appropriate move function based on what key was hit
    switch (nChar)
    {
    
    // Move hero backward
    case 68:
    case 40:
        mHero->moveBackward();
        validKeyPress = true;
        break;

    // Move hero forward 
    case 69:
    case 38:
        mHero->moveForward();
        validKeyPress = true;
        break;

    // Move the hero right
    case 70:
    case 39:
        mHero->moveRight();
        validKeyPress = true;
        break;
    
    // Move the hero left
    case 83:
    case 37:
        mHero->moveLeft();
        validKeyPress = true;
        break;

    }

    // Key press actually moved hero, check if he stepped on a boat
    if (validKeyPress)
    {
        BoatTest();
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
        //item = make_shared<CDecor>(this, imageMap[id]);
    }
    else if (type == L"rect")
    {
        item = make_shared<CRectangle>(this);
    }
    else if (type == L"car")
    {
        wstring id = node->GetAttributeValue(L"id", L"");
        //item = make_shared<CCar>(this, imageMap[id]);
    }

    // Add item to game item vector if it exists
    if (item != nullptr)
    {
        item->XmlLoad(node);
        Add(item);
    }

}


/**
 * Handle updates for animation
 * \param elapsed The time since the last update
 */
void CGame::Update(double elapsed)
{


    for (auto item : mItems)
    {
        CIsVehicleVisitor vehicleVisitor;
        item->Accept(&vehicleVisitor);
        if (vehicleVisitor.IsVehicle())
        {
            vehicleVisitor.Vehicle()->Update(elapsed);
        }

        CIsCargoVisitor cargoVisitor;
        item->Accept(&cargoVisitor);
        if (cargoVisitor.IsCargo())
        {
            cargoVisitor.Cargo()->Update(elapsed, mHero);
        }
    }
    // Update the hero in case he's on a boat
    mHero->Update(elapsed);

    // Don't need to check for car/river collisions when on a boat
    if (!mHero->GetOnBoat()) 
    {
        CollisionTest(mHero->GetX(), mHero->GetY());
    }
    

}

/**
 * Loads level from level vector
 * 
 * \param level int of level to load (e.g. 0 for level 0)
 */
void CGame::Load(const int level)
{
    Clear();
    // Add Decor and vehicle copies to items vector
    for (auto& levelItem : mLevels[level]->GetItems())
    {
        auto item = levelItem->clone();
        Add(item);
    }

    // Make a clone of hero and set pointer to that
    mHero = mLevels[level]->GetHero()->cloneHero();
    Add(mHero);

    // Add cargo copies to items vector
    for (auto& cargoItem : mLevels[level]->GetCargo())
    {
        auto item = cargoItem->clone();
        Add(item);

    }

    // number of cargo
    int cargoNumber = 0;

    // Cargo Visitor 
    CIsCargoVisitor visitor;

    // Load the names of the cargo into the control panel
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++) // Iterate through the items and detemrine if they are cargo
    {
        // Accept the visitor
        (*i)->Accept(&visitor);

        // If the item is cargo
        if (visitor.IsCargo() && cargoNumber < 3)
        {

            // Push back the cargo item name
            mControlPanel->SetCargoItem(visitor.Cargo()->GetName());
            cargoNumber++;

        }
    }

    // Set the location of the hero
    mHero->SetLocation(480, 928);

    // Set this control panel to the level
    mControlPanel->SetLevel(mLevels[level], level);

    return;
}

/**
 * Adds a level to level vector
 *
 * \param level level object to add to level vector
 */
void CGame::Add(std::shared_ptr<CLevel> level)
{
    mLevels.push_back(level);
}


/**
 * Accept a visitor for the collection
 * \param visitor The visitor for the collection
 */
void CGame::Accept(CItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}


/**  Test an x,y click location to see if it clicked
* on some cargo item in the game.
* \param x X location
* \param y Y location
* \returns Pointer to cargo item we clicked on or nullptr if none.
*/
CCargo* CGame::HitTest(int x, int y)
{
    CIsCargoVisitor visitor;

    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        (*i)->Accept(&visitor);
        if (visitor.IsCargo() && visitor.Cargo()->HitTest(x, y))
        {
            return visitor.Cargo();
        }
    }

    return  nullptr;
}


/**
 * Update the control panel
 */
void CGame::UpdateControlPanel(double elapsed)
{

    mControlPanel->Update(elapsed);

}


/**
 * Draw the control panel
 */
void CGame::DrawControlPanel(Gdiplus::Graphics* graphics)
{

    mControlPanel->Draw(graphics);

}


/**
 * Collision test for Hero
 * \param x The x coordinate for the hero
 * \param y The y coordinate for the hero
 */
void CGame::CollisionTest(int x, int y)
{
    CDecorTypeVisitor decorVisitor;
    CIsVehicleVisitor visitor;

    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        (*i)->Accept(&visitor);

        if (visitor.IsVehicle() && visitor.Vehicle()->HitTest(x, y) && (GetRoadCheatState() == false))
        {

            mGameOver = true;

        }

        (*i)->Accept(&decorVisitor);

        // Check if we are colliding with a river
        if (decorVisitor.ReturnId() == L"r001" && decorVisitor.Decor()->HitTest(x, y) && (GetRiverCheatState() == false))
        {

            mGameOver = true;

        }
    }

}

/** Tests whether hero stepped onto a boat, then locks his position with boat
 */
void CGame::BoatTest()
{
    CIsBoatVisitor visitor;

    for (auto& item : mItems)
    {
        item->Accept(&visitor);

        // Item is a boat and same tile as hero
        if (visitor.IsBoat() && visitor.Boat()->HitTest(mHero->GetX(), mHero->GetY()))
        {
            CBoat* boat = visitor.Boat();
            // Set speed and location, then return since we're done searching
            mHero->SetSpeed(boat->GetSpeed());
            mHero->SetOnBoat(true);
            mHero->SetLocation(boat->GetX(), boat->GetY());
            return;
        }
    }
    mHero->SetSpeed(0.0);
    mHero->SetOnBoat(false);
}


void CGame::CheckWinState()
{
    mGameWon = true;

    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        CIsCargoVisitor visitor;
        (*i)->Accept(&visitor);

        if (visitor.IsCargo() && visitor.Cargo()->GetY() > 64)
        {
            mGameWon = false;
        }
    }
}
