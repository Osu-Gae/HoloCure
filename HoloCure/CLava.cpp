#include "pch.h"
#include "CLava.h"

CLava::CLava() : loop(0)
{
}

CLava::~CLava()
{
}

void CLava::Initialize()
{
    m_tFrame = { 0 , 29, 0 ,CTimeMgr::GetInstance().GetTime(),0.1};
    m_fRadius = 100.f;
    m_tInfo = { 1500,500,254,254 };
	m_fRadius = 100.f;
	loop = 1;
	m_iAttack = 1;
}

void CLava::Update()
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < CTimeMgr::GetInstance().GetTime())
	{
		++m_tFrame.iStart;
		if (loop && m_tFrame.iStart == 24)
		{
			m_tFrame.iStart -= 15;
			loop--;
		}
		if (m_tFrame.iStart > m_tFrame.iEnd)
			m_bDead = true;
		m_tFrame.dwTime = CTimeMgr::GetInstance().GetTime();
	}
}

void CLava::LateUpdate()
{
	Update_Rect();
}

void CLava::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
		m_tRect.top + _iScrollY, 254, 254, CBmpMgr::Get_Instance()->Find_Img(L"Item_2"),
		m_tFrame.iStart * 254, 0,
		254, 254,
		RGB(36, 74, 53));
}

void CLava::Release()
{
}
