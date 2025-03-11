#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Key_Input()
{
	if (m_tFrame.iMotion == State::IDLE)
	{
		Move_Dir();
	}
	else
	{
		if (!CKeyMgr::Get_Instance()->Key_Pressing('W') && !CKeyMgr::Get_Instance()->Key_Pressing('S') && !CKeyMgr::Get_Instance()->Key_Pressing('A') && !CKeyMgr::Get_Instance()->Key_Pressing('D'))
		{
			m_tFrame.iMotion = State::IDLE;
			m_tFrame.iStart = 0;
			m_tFrame.iEnd = 5;
		}
		else
		{
			Move_Dir();
		}
	}
}

void CPlayer::Move_Dir()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
	{
		m_tInfo.fY -= m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tFrame.iMotion = State::RUN;

	}
	if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
	{
		m_tInfo.fY += m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tFrame.iMotion = State::RUN;

	}
	if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
	{
		m_tInfo.fX -= m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tFrame.iMotion = State::RUN;

		m_bReverse = true;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		m_tInfo.fX += m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tFrame.iMotion = State::RUN;

		m_bReverse = false;
	}
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX >> 1 , WINCY >> 1, 128.f, 128.f };
	m_tFrame = { 0 , 5, RUN ,CTimeMgr::GetInstance().GetTime(),0.1 };
	m_fSpeed = 200.f;
	m_fRadius = 20.f;
	m_iHp = 64;
	m_iMaxHp = 64;
}

void CPlayer::Update()
{
	CTimeMgr::GetInstance().Update();
	std::wstring title = L"Time: " + std::to_wstring(m_iHp);
	SetWindowText(g_hWnd, title.c_str()); 
	m_fInvincibleTime -= CTimeMgr::GetInstance().GetDeltaTime();
	Key_Input();
	Move_Frame();
	CObj::Update_Rect();
}

void CPlayer::LateUpdate()
{
	Playerx = m_tInfo.fX;
	Playery = m_tInfo.fY;
}

void CPlayer::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	// 체력 출력 
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Red_Hp");
	HDC hMemDC2 = CBmpMgr::Get_Instance()->Find_Img(L"Green_Hp");
	/*BitBlt(hDC, m_iXPos * 160 + _iScrollX, m_iYPos * 160 + _iScrollY,ddd
		160, 160,
		tempDC, (x % 16) * m_tInfo.fCX, (y % 16) * m_tInfo.fCY, SRCCOPY);*/
	BitBlt(hDC, m_tInfo.fX+ _iScrollX-32, m_tInfo.fY-50+ _iScrollY, 64, 6, hMemDC, 0, 0, SRCCOPY);
	BitBlt(hDC, m_tInfo.fX + _iScrollX - 32, m_tInfo.fY - 50 + _iScrollY, m_iHp, 6, hMemDC2, 0, 0, SRCCOPY);
	if (m_bReverse)
	{
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"Player_watson_Rev", m_tRect.left + _iScrollX, m_tRect.top + _iScrollY,
			m_tInfo.fCX, m_tInfo.fCY, m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY);
	}
	else
	{
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"Player_watson", m_tRect.left + _iScrollX, m_tRect.top + _iScrollY,
			m_tInfo.fCX, m_tInfo.fCY, m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY);
	}

}

void CPlayer::Release()
{
}
