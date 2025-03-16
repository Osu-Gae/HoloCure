#include "pch.h"
#include "CExpBar.h"

CExpBar::CExpBar() :m_iExp(0), m_iMaxExp(100), frame(0)
{

}

CExpBar::~CExpBar()
{
}

void CExpBar::Initialize()
{
	m_iMaxExp = 100;
	m_iExp = 60;
}

void CExpBar::Update()
{
	frame++;
	frame %= 61;
}

void CExpBar::LateUpdate()
{
}

void CExpBar::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{

	CPngMgr::Get_Instance().DrawPngWithAlpha(hDC, L"ExpBar", 0, 0,
		1280, 50, 0.5);
	HDC memDc = CBmpMgr::Get_Instance()->Find_Img(L"ExpAni");	
	// RGB(0,0,0) 제거하고 출력
	GdiTransparentBlt(hDC, 0, 0,
		int(1280 * float(float(m_iExp) / m_iMaxExp)), 50, memDc,
		1280 * frame, 0,
		int(1280 * float(float(m_iExp) / m_iMaxExp)), 50,
		RGB(0, 0, 0));
	
}

void CExpBar::Release()
{
}
