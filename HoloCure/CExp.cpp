#include "pch.h"
#include "CExp.h"

CExp::CExp()
{
}

CExp::~CExp()
{
}

void CExp::Initialize()
{
	// Exp-sheet
	m_tInfo = { -5000, -5000, 128,128 };
	m_bDead = false;
	m_fRadius = 10;
}

void CExp::Update()
{

}

void CExp::LateUpdate()
{
	CObj::Update_Rect();
}

void CExp::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,m_tRect.top + _iScrollY,
		128, 128, CBmpMgr::Get_Instance()->Find_Img(L"Exp_sheet"),
		min(m_iExp/10, 5)*128, 0,
		128, 128,
		RGB(36, 74, 53));
}

void CExp::Release()
{
}
