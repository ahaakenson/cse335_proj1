/**
 * \file DecorTypeVisitor.h
 *
 * \author(s) Michael Dittman, Ethan Strain
 *
 * Class that describes the CDecorTypeVisitor
 */

#pragma once
#include "ItemVisitor.h"
#include <string>

/**
 * Class that describes the CDecorTypeVisitor
 */
class CDecorTypeVisitor : public CItemVisitor
{
public:
    virtual void VisitDecor(CDecor* decor) override;

    CDecor* Decor() { return mDecor; }

    std::wstring ReturnId() { return mDecorId; }

private:

    /// The pointer to the visited decor tile
    CDecor* mDecor;

    /// The id of the visited decor tile
    std::wstring mDecorId;
};

