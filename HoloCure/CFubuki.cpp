#include "pch.h"
#include "CFubuki.h"
CFubuki::CFubuki() : m_bReverse(false), m_fAttackTime(0.f)
{
}

CFubuki::~CFubuki()
{
}

void CFubuki::Initialize()
{
	m_tInfo = { 0,0,328,228 };
	m_tFrame = { 0, 11, 0, CTimeMgr::GetInstance().GetTime(), 0.1 };
	m_fSpeed = 150.f;
	m_fRadius = 70.f;
	m_iExp = 5;
	m_iAttack = 2;
	m_iHp = 1200;
	m_fAttackTime = 5.f;
	m_FubukiBullet.Initialize();
}

void CFubuki::Update()
{
	if (m_fSpawnScene > 0)
	{
		m_fSpawnScene -= CTimeMgr::GetInstance().GetDeltaTime();
		spawnx -= 600 * CTimeMgr::GetInstance().GetDeltaTime();
	}

	if (m_FubukiBullet.fubukiAttack)
	{
		m_FubukiBullet.Update();
	}
	float dis = sqrtf(pow(Playerx - m_tInfo.fX, 2) + pow(Playery - m_tInfo.fY, 2));
	if (dis != 0)
	{
		m_tInfo.fX += (Playerx - m_tInfo.fX) / dis * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tInfo.fY += (Playery - m_tInfo.fY) / dis * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
	}
	CObj::Update_Rect();
	//무적시간 줄이기
	m_fInvincibleTime -= CTimeMgr::GetInstance().GetDeltaTime();
	m_fAttackTime -= CTimeMgr::GetInstance().GetDeltaTime();
	if (m_fAttackTime < 0.f)
	{

		// fubukibullet 애니메이션 시작 
		m_FubukiBullet.fubukiAttack = true;
		m_FubukiBullet.m_bReverse = m_bReverse;
		m_fAttackTime = 5.f;
		CSoundMgr::Get_Instance()->PlaySound(L"alert.wav", SOUND_WARNING,1.f);
	}
	Move_Frame();
}

void CFubuki::LateUpdate()
{
	Update_Rect();

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
	}
	if (m_FubukiBullet.fubukiAttack)
	{
		m_FubukiBullet.LateUpdate();
		m_FubukiBullet.Po(m_tInfo.fX, m_tInfo.fY);
	}
}

void CFubuki::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	if (m_fSpawnScene > 0)
	{
		GdiTransparentBlt(hDC, 
			spawnx, 0,
			1280, 720, CBmpMgr::Get_Instance()->Find_Img(L"Fubuki_spawn"),
			0,0,
			1280, 720,
			RGB(36, 74, 53));
	}
	if (m_FubukiBullet.fubukiAttack)
	{
		m_FubukiBullet.Render(hDC, _iScrollX, _iScrollY);
	}

	if (!m_bReverse)
	{
		GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
			m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"fubuki"),
			m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY,
			m_tInfo.fCX, m_tInfo.fCY,
			RGB(36, 74, 53));
		
	}
	else
	{
		GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
			m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"fubuki_Rev"),
			m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY,
			m_tInfo.fCX, m_tInfo.fCY,
			RGB(36, 74, 53));
	}
}

void CFubuki::Release()
{
}
