#include "pch.h"
#include "CBoomerang.h"
#include "CBmpMgr.h"
CBoomerang::CBoomerang() : m_fDeathTime(0.f), m_fAngle(0.f)
{
}

CBoomerang::~CBoomerang()
{
}

void CBoomerang::Initialize()
{
	m_tFrame = { 0, 7, 0, CTimeMgr::GetInstance().GetTime(), 0.05 };
	m_tInfo = { 0, 0, 128.f, 128.f };
	m_fRadius = 50.f;
	m_fDeathTime = 3.f;
}

void CBoomerang::Update()
{
	// 1초동안 angle 방향으로 갔다가
	// 2초동안 angle 반대방향으로 간다.
	if (m_fDeathTime > 2)
	{
		m_tInfo.fX += cos(m_fAngle) * 800 * CTimeMgr::GetInstance().GetDeltaTime();
		m_tInfo.fY += sin(m_fAngle) * 800 * CTimeMgr::GetInstance().GetDeltaTime();
	}
	else
	{
		m_tInfo.fX -= cos(m_fAngle) * 800 * CTimeMgr::GetInstance().GetDeltaTime();
		m_tInfo.fY -= sin(m_fAngle) * 800 * CTimeMgr::GetInstance().GetDeltaTime();
	}


	m_fDeathTime -= CTimeMgr::GetInstance().GetDeltaTime();
	Move_Frame();
	if (m_fDeathTime < 0)
	{
		m_bDead = true;
	}
	Update_Rect();
}

void CBoomerang::LateUpdate()
{
}

void CBoomerang::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
		m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Item_7"),
		m_tFrame.iStart * 128, 0,
		128, 128,
		RGB(36, 74, 53));
}

void CBoomerang::Release()
{
}
