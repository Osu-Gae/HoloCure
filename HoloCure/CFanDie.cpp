#include "pch.h"
#include "CFanDie.h"

CFanDie::CFanDie()
{
}

CFanDie::~CFanDie()
{
}

void CFanDie::Initialize()
{
	m_tInfo = { -5000, -5000, 48,48 };
	m_tFrame = { 0,9,0,CTimeMgr::GetInstance().GetTime(),0.1 };
}

void CFanDie::Update()
{
}

void CFanDie::LateUpdate()
{
	Update_Rect();
	Move_Frame();
}

void CFanDie::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
		m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"FanDie"),
		0, m_tFrame.iStart * m_tInfo.fCY,
		m_tInfo.fCX, m_tInfo.fCY,
		RGB(36, 74, 53));
	if(m_tFrame.iStart == m_tFrame.iEnd)
	{
		m_bDead = true;
	}
}

void CFanDie::Release()
{
}
