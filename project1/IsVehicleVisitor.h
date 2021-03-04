/**
 * \file IsVehicleVisitor.h
 *
 * \author Nikolai Tolmoff
 *
 * Visitor for checking if an item is a Vehicle.
 */

#pragma once
#include "ItemVisitor.h"


 /**
  * Visitor for checking if an item is a Vehicle.
  */
class CIsVehicleVisitor : public CItemVisitor
{
public:
    virtual void VisitVehicle(CVehicle* vehicle) override;

    /** Returns whether or not the item is a Vehicle.
    * \returns True if item is a Vehicle, False otherwise. */
    bool IsVehicle() { return mIsVehicle; }

    /** Returns Vehicle.
    * \returns The vehicle that was visited. */
    CVehicle* Vehicle() { return mVehicle; }

private:
    /// Whether or not the item is a Vehicle.
    bool mIsVehicle = false;

    /// The vehicle that was visited.
    CVehicle* mVehicle;
};

