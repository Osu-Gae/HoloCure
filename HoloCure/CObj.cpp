#include "pch.h"
#include "CObj.h"

CObj::CObj() : m_fSpeed(0.f), m_bDead(false), m_bReverse(false), m_fRadius(0.f), m_iHp(0), m_iAttack(0), m_fInvincibleTime(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tFrame, sizeof(FRAME));
}

CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY+ (m_tInfo.fCY * 0.5f));
}

void CObj::Move_Frame()
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < CTimeMgr::GetInstance().GetTime())
	{
		++m_tFrame.iStart;

		if (m_tFrame.iStart > m_tFrame.iEnd)
			m_tFrame.iStart = 0;
		m_tFrame.dwTime = CTimeMgr::GetInstance().GetTime();
	}
}
