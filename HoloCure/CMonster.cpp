#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tInfo = { WINCX >> 1 , WINCY >> 1, 128.f, 128.f };
	m_tFrame = { 0 , 5, 0 ,CTimeMgr::GetInstance().GetTime(),0.1 }; // 여기서는 세번째 인자가 몬스터 종류임 
	m_fSpeed = 150.f;

}

void CMonster::Update()
{
	// 플레이어 방향으로 
	float dis = sqrtf(pow(Playerx - m_tInfo.fX, 2) + pow(Playery - m_tInfo.fY, 2));
	m_tInfo.fX += (Playerx - m_tInfo.fX) / dis * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
	m_tInfo.fY +=  (Playery - m_tInfo.fY) / dis * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
	CObj::Update_Rect();
	std::wstring title = L"Time: " + std::to_wstring(m_tInfo.fX);
	SetWindowText(g_hWnd, title.c_str());
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
}

void CMonster::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	if (!m_bReverse)
	{
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"Monster", m_tRect.left, m_tRect.top,
			m_tInfo.fCX, m_tInfo.fCY, m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY);
	}
	else
	{
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"Monster_Rev", m_tRect.left, m_tRect.top,
			m_tInfo.fCX, m_tInfo.fCY, m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY);
	}
}

void CMonster::Release()
{
}
