/**
 * \file Hero.h
 *
 * \author(s) Michael Dittman,
 *
 * Class that describes the Hero
 */

#pragma once
#include "Item.h"


/**
 * Class that describes the Hero
 */
class CHero : public CItem
{

public:
    /// Default constructor (disabled)
    CHero() = delete;

    /// Copy constructor
    CHero(const CHero&);

    CHero::CHero(CGame* game, std::shared_ptr<Gdiplus::Bitmap> bitmap);

    virtual std::shared_ptr<xmlnode::CXmlNode> 
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    void moveForward();

    void moveBackward();

    void moveLeft();

    void moveRight();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitHero(this); }

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** Clones a hero by invoking the copy constructor, returns an item pointer
    * \return pointer to a copied object
    */
    virtual std::shared_ptr<CItem> clone() const { return std::make_shared<CHero>(*this); }

    /** Clones a hero by invoking the copy constructor, returns a hero pointer
    * \return pointer to a copied hero
    */
    std::shared_ptr<CHero> cloneHero() const { return std::make_shared<CHero>(*this); }

    /** Gets whether hero is on boat
    * \return whether hero is on a boat.
    */
    bool GetOnBoat() { return mOnBoat; }

    /** Sets whether hero is on boat
    * \param onBoat whether hero is on a boat.
    */
    void SetOnBoat(bool onBoat) { mOnBoat = onBoat; }

    /** Sets speed of hero
    * \param speed Speed of hero
    */
    void SetSpeed(double speed) { mSpeed = speed; }

    void Update(double elapsed);
private:
    /// Name of hero
    std::wstring mName;
    /// Speed of hero (non zero when on boat)
    double mSpeed = 0.0;
    /// Whether the hero is floating on a boat
    bool mOnBoat = false;
};

