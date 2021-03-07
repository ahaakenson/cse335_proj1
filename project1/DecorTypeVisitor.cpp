/**
 * \file DecorTypeVisitor.cpp
 *
 * \author Michael Dittman
 */

#include "pch.h"
#include "DecorTypeVisitor.h"
#include "Decor.h"

/**
 * 
 * \param decor 
 */
void CDecorTypeVisitor::VisitDecor(CDecor* decor)
{

    mDecor = decor;
    mDecorId = decor->GetId();

}
