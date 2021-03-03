/**
 * \file Vehicle.h
 *
 * \author Nikolai Tolmoff
 *
 * Base class for vehicles, including cars and boats.
 */

#pragma once

#include <memory>
#include "Item.h"
#include "XmlNode.h"
#include "Game.h"


/**
 * Base class for vehicles, including cars and boats.
 */
class CVehicle : public CItem
{
public:
    /// Default constructor (disabled)
    CVehicle() = delete;

    /// Copy constructor (disabled)
    CVehicle(const CVehicle&) = delete;

    /// Set the speed
    /// \param speed Speed
    void SetSpeed(double speed) { mSpeed = speed; }

    void Update(double elapsed);

    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

protected:
    CVehicle(CGame* game, const std::wstring& filename);

private:
    /// Vehicle speed
    double mSpeed;


};

