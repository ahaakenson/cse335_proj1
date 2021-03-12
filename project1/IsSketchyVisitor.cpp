
#include "pch.h"
#include "IsSketchyVisitor.h"


void CIsSketchyVisitor::VisitSketchy(CSketchyBoat* boat)
{
	mIsSketchy = true;
	mSketchyBoat = boat;
}
