
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "project1.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"


using namespace std;
using namespace Gdiplus;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Constructor
 */
CChildView::CChildView()
{
	srand((unsigned int)time(nullptr));
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_LEVELMENU_LEVEL0, &CChildView::OnLevelmenuLevel0)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

/**
 * This function is called to draw in the window.
 *
 * This function is called in response to a drawing message
 * whenever we need to redraw the window on the screen.
 * It is responsible for painting the window.
 */
void CChildView::OnPaint() 
{
	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting

	Graphics graphics(dc.m_hDC);	// change paintDC back to dc once CDoubleBufferDC is implemented (to prevent flashing)

	CRect rect;
	GetClientRect(&rect);
	
	mGame.OnDraw(&graphics, rect.Width(), rect.Height());

	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		 * Initialize the elapsed time system
		 */
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);

		// TEMPORARY, ONLY TO TEST DECOR ON SCREEN
		// loads level 1 file
		wstring filename = L".\\levels\\level1.xml";
		mGame.Load(filename);
		Invalidate();
	}

	/*
	 * Compute the elapsed time since the last draw
	 */
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	// mGame.Update(elapsed);
}


/**
 * Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// Initiate movement checks
	mGame.moveHero(nChar);
	Invalidate();

}


void CChildView::OnLevelmenuLevel0()
{
	// loading content from level 1
	wstring filename = L".\\levels\\level1.xml";
	mGame.Load(filename);

	// This is here only for hero testing, remove later
	shared_ptr<CHero> hero = make_shared<CHero>(&mGame);
	hero->SetLocation(512, 928);
	mGame.Add(hero);
	mGame.SetHero(hero);

	Invalidate();


}
