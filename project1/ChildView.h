
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "Game.h"
#include "Item.h"


#include <memory>

// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

private:
	/// Game object being played
	CGame mGame;

	/// Any item we currently clicked
	std::shared_ptr<CItem> mClickedItem;

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime = 0;	///< Last time we read the timer
	double mTimeFreq = 0;		///< Rate the timer updates

// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

public:
	// was manually added by Ethan, may need to be implemented another way
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCheatmenuRoadcheat();
	afx_msg void OnCheatmenuRivercheat();
};

