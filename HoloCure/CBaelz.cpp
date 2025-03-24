#include "pch.h"
#include "CBaelz.h"

CBaelz::CBaelz() : m_ipattern(0), m_fAttackTime(0.f), m_fPatternTime(0.f)
{
}

CBaelz::~CBaelz()
{
}

void CBaelz::Initialize()
{
	m_tInfo = { 0,0,190,240 };
	m_tFrame = { 0, 23, 1, CTimeMgr::GetInstance().GetTime(), 0.05f };
	m_fSpeed = 150.f;
	m_fRadius = 70.f;
	m_iExp = 5;
	m_iAttack = 2;
	m_iHp = 1600;
	m_fAttackTime = 5.f;
}

void CBaelz::Update()
{

	// 씬 업데이트
	if (m_fSpawnScene > 0)
	{
		m_fSpawnScene -= CTimeMgr::GetInstance().GetDeltaTime();
		spawnx -= 600 * CTimeMgr::GetInstance().GetDeltaTime();
	}

	Pattern();
	float dis = sqrtf(pow(Playerx - m_tInfo.fX, 2) + pow(Playery - m_tInfo.fY, 2));
	if (dis != 0)
	{
		m_tInfo.fX += (Playerx - m_tInfo.fX) / dis * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tInfo.fY += (Playery - m_tInfo.fY) / dis * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
	}
	CObj::Update_Rect();

	m_fInvincibleTime -= CTimeMgr::GetInstance().GetDeltaTime();
	m_fAttackTime -= CTimeMgr::GetInstance().GetDeltaTime();
	static int count1 = 0;
	if (m_tFrame.iStart == 21)
	{
		count1++;
		if (count1 % 2==0)
		{
			if (m_tFrame.iMotion == 0)
			{
				m_ipattern = 2;
			}
			else if (count1 == 20)
			{
				count1 = 0;
				m_tFrame.iMotion = 0;
				m_tFrame.iStart = 0;
			}
			else
			{
				m_ipattern = 1;
			}
		}
	}
	
	Move_Frame();
}

void CBaelz::LateUpdate()
{
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
		// CUiMgr::Get_Instance()->m_KillUi.UpKillCount();
		// CObjMgr::Get_Instance().Spawn_Exp(m_iExp, m_tInfo.fX, m_tInfo.fY);
	}
}

void CBaelz::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	if (m_fSpawnScene > 0)
	{
		GdiTransparentBlt(hDC,
			spawnx, 0,
			1280, 720, CBmpMgr::Get_Instance()->Find_Img(L"BAELZ_spawn"),
			0, 0,
			1280, 720,
			RGB(36, 74, 53));
	}
	if (!m_bReverse)
	{
		GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
			m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Baelz"),
			m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY,
			m_tInfo.fCX, m_tInfo.fCY,
			RGB(36, 74, 53));

	}
	else
	{
		GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
			m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Baelz_Rev"),
			4560-m_tInfo.fCX - m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY,
			m_tInfo.fCX, m_tInfo.fCY,
			RGB(36, 74, 53));
	}

	if (m_tFrame.iMotion == 0 && m_tFrame.iStart == m_tFrame.iEnd-1)
	{
		m_tFrame.iMotion = 1;
		m_tFrame.iStart = 0;
	}
}

void CBaelz::Release()
{
}

void CBaelz::Pattern()
{
	m_fPatternTime -= CTimeMgr::GetInstance().GetDeltaTime();
	if (m_ipattern == 0)
	{
		return ;
	}
	// 0.1초씩 4발 발사
	static int count = 0;
	if (m_ipattern == 1)
	{
		if (m_fPatternTime < 0)
		{
			// 총알 생성
			float radian = atan2f(m_tInfo.fY - Playery, Playerx - m_tInfo.fX);
			float degree = radian * 180 / 3.14f;
			CObjMgr::Get_Instance().Spawn_BossBullet(m_tInfo.fX, m_tInfo.fY, degree);
			count++;
			m_fPatternTime = 0.1f;
		}
		if (count == 4)
		{
			count = 0;
			m_ipattern = 0;
		}
	}
	else if (m_ipattern == 2)
	{
		if (m_fPatternTime < 0)
		{
			static int delta = 0;
			for (int i = 0; i < 14; i++)
			{
				CObjMgr::Get_Instance().Spawn_BossBullet(m_tInfo.fX, m_tInfo.fY, delta + 360 / 15 * i);
			}
			delta += 10;
			m_fPatternTime = 0.1f;
			count++;
		}
		if (count == 4)
		{

			count = 0;
			m_ipattern = 0;
		}
	}


}
