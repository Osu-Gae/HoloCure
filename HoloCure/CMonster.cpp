#include "pch.h"
#include "CMonster.h"
#include "CUiMgr.h"
#include "CSoundMgr.h"
CMonster::CMonster() : m_bDamaged(false), m_bDamagedCount(0)
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tInfo = { WINCX >> 1 , WINCY >> 1, 128.f, 128.f };
	m_tFrame = { 0 , 5, 0 ,CTimeMgr::GetInstance().GetTime(),0.1 }; // 여기서는 세번째 인자가 몬스터 종류임 
	m_fSpeed = 100.f;
	m_fRadius = 15.f;
	m_iExp = 5;
	m_iAttack = 2;
	m_iHp = 60;
	m_bDead = false;
}

void CMonster::Update()
{
	// 플레이어 방향으로 
	float dis = sqrtf(pow(Playerx - m_tInfo.fX, 2) + pow(Playery - m_tInfo.fY, 2));
	if (dis != 0)
	{
		m_tInfo.fX += (Playerx - m_tInfo.fX) / dis * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tInfo.fY += (Playery - m_tInfo.fY) / dis * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
	}
	CObj::Update_Rect();
	//무적시간 줄이기
	m_fInvincibleTime -= CTimeMgr::GetInstance().GetDeltaTime();
	
	Move_Frame();
}

void CMonster::LateUpdate()
{
	// 방향 으로 reverse 판단
	if (Playerx - m_tInfo.fX < 0)
	{
		m_bReverse = true;
	}
	else
	{
		m_bReverse = false;
	}
	if (m_iHp <= 0)
	{
		m_bDead = true;
		CUiMgr::Get_Instance()->m_KillUi.UpKillCount();
		CObjMgr::Get_Instance().Spawn_Exp(m_iExp, m_tInfo.fX, m_tInfo.fY);
		CObjMgr::Get_Instance().Spawn_FanDie(m_tInfo.fX, m_tInfo.fY-50);
	}
}

void CMonster::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	if (!m_bReverse)
	{
		if (m_bDamaged)
		{
			GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
				m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Monster_Damaged"),
				m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY,
				m_tInfo.fCX, m_tInfo.fCY,
				RGB(36, 74, 53));
			m_bDamagedCount--;
			if (m_bDamagedCount < 0)
			{
				m_bDamaged = false;
			}
		}
		else
		{
			GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
				m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Monster"),
				m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY,
				m_tInfo.fCX, m_tInfo.fCY,
				RGB(36, 74, 53));
		}
	}
	else
	{
		if (m_bDamaged)
		{
			GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
				m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Monster_Damaged_Rev"),
				m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY,
				m_tInfo.fCX, m_tInfo.fCY,
				RGB(36, 74, 53));
			m_bDamagedCount--;
			if (m_bDamagedCount < 0)
			{
				m_bDamaged = false;
			}

		}
		else
		{
			GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
				m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Monster_Rev"),
				m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY,
				m_tInfo.fCX, m_tInfo.fCY,
				RGB(36, 74, 53));
		}


	}
//#ifdef _DEBUG
//	Ellipse(hDC, m_tInfo.fX - m_fRadius + _iScrollX, m_tInfo.fY - m_fRadius + _iScrollY, m_tInfo.fX + m_fRadius + _iScrollX, m_tInfo.fY + m_fRadius + _iScrollY);
//#endif 
}

void CMonster::Release()
{
}
