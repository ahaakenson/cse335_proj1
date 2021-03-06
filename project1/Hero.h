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

    //CHero::CHero(CGame* game);
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

private:

    std::wstring mName;

};

