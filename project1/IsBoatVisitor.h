/**
 * \file IsBoatVisitor.h
 *
 * \author Andrew Haakenson
 *
 * Visitor for checking if an item is a boat.
 */

#pragma once
#include "ItemVisitor.h"
#include "Boat.h"

/** Visitor to visit boats and determine if hero stepped onto a boat
 */
class CIsBoatVisitor :
    public CItemVisitor
{
public:
    virtual void VisitBoat(CBoat* boat) override;

    /** Returns whether or not the item is a boat.
    * \returns True if item is a boat, False otherwise. */
    bool IsBoat() { return mIsBoat; }

    /** Returns Vehicle.
    * \returns The vehicle that was visited. */
    CBoat* Boat() { return mBoat; }

private:
    /// Whether or not the item is a Vehicle.
    bool mIsBoat = false;

    /// The vehicle that was visited.
    CBoat* mBoat;
};

