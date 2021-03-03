/**
 * \file ItemVisitor.h
 *
 * \author Nikolai Tolmoff
 *
 * Item visitor base class.
 */

#pragma once

// Forward reference to all item types
class CCargo;
class CVehicle;
class CHero;
class CDecor;

/** Item visitor base class */
class CItemVisitor
{
public:
	virtual ~CItemVisitor() {}

	/** Visit a CCargo object
	 * \param cargo Cargo we are visiting */
	virtual void VisitCargo(CCargo* cargo) {}

	/** Visit a CVehicle object
	 * \param vehicle Vehicle we are visiting */
	virtual void VisitVehicle(CVehicle* vehicle) {}

	/** Visit a CHero object
	 * \param hero Hero we are visiting */
	virtual void VisitHero(CHero* hero) {}

	/** Visit a CDecor object
	 * \param decor Decor we are visiting */
	virtual void VisitDecor(CDecor* decor) {}
};

