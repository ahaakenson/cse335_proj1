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

    /// Copy constructor (disabled)
    CHero(const CHero&) = delete;

    CHero::CHero(CGame* game);

    virtual std::shared_ptr<xmlnode::CXmlNode> 
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:
    double mSpeedX = 0;
    double mSpeedY = 0;

};

