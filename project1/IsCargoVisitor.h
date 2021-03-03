/**
 * \file IsCargoVisitor.h
 *
 * \author Nikolai Tolmoff
 *
 * Visitor for checking if an item is Cargo.
 */

#pragma once
#include "ItemVisitor.h"


/**
 * Visitor for checking if an item is Cargo.
 */
class CIsCargoVisitor : public CItemVisitor
{
public:
	virtual void VisitCargo(CCargo* cargo) override;

    /** Returns whether or not the tile is a RocketPad.
    * \returns True if tile is a RocketPad, False otherwise. */
    bool IsCargo() { return mIsCargo; }

    /** Returns rocket pad.
    * \returns The rocket pad that was double clicked. */
    CCargo* Cargo() { return mCargo; }

private:
    bool mIsCargo = false;

    CCargo* mCargo;
};

