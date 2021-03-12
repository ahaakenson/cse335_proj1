
#pragma once

#include "ItemVisitor.h"
#include "IsBoatVisitor.h"
#include "SketchyBoat.h"


class CIsSketchyVisitor :
    public CItemVisitor
{
public:
    virtual void VisitSketchy(CSketchyBoat* boat) override;

    /** Returns whether or not the item is a boat.
    * \returns True if item is a boat, False otherwise. */
    bool GetIsSketchy() { return mIsSketchy; }

    /** Returns Vehicle.
    * \returns The vehicle that was visited. */
    CSketchyBoat* GetSketchy() { return mSketchyBoat; }

private:
    bool mIsSketchy = false;

    CSketchyBoat* mSketchyBoat;
};

