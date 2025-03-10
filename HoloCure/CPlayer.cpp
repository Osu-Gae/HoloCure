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

}

void CPlayer::Update()
{
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
	//CPngMgr::Get_Instance().DrawPng(hDC, L"Player_watson", m_tRect.left, m_tRect.top,m_tInfo.fCX, m_tInfo.fCY);
	if (m_bReverse)
	{
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"Player_watson_Rev", m_tRect.left, m_tRect.top,
			m_tInfo.fCX, m_tInfo.fCY, m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY);
	}
	else
	{
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"Player_watson", m_tRect.left, m_tRect.top,
			m_tInfo.fCX, m_tInfo.fCY, m_tFrame.iStart * m_tInfo.fCX, m_tFrame.iMotion * m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY);
	}

}

void CPlayer::Release()
{
}
