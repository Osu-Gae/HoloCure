#include "pch.h"
#include "CPlayer.h"
#include "CItem.h"
#include "CUiMgr.h"
CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('L'))
	{
		CUiMgr::Get_Instance()->m_LevelUi.LevelUp();
	}

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
	if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
	{
		if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
		{
			m_tInfo.fX -= m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime() / 1.141421f;
			m_tInfo.fY += m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime()/  1.41421f;
			m_tFrame.iMotion = State::RUN;

		}
		else if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
		{
			m_tInfo.fX -= m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime() / 1.141421f;
			m_tInfo.fY -= m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime() / 1.41421f;
			m_tFrame.iMotion = State::RUN;

		}
		else
		{
			m_tInfo.fX -= m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
			m_tFrame.iMotion = State::RUN;
		}
		m_bReverse = true;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
		{
			m_tInfo.fX += m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime() / 1.141421f;
			m_tInfo.fY += m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime() / 1.41421f;
			m_tFrame.iMotion = State::RUN;

		}
		else if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
		{
			m_tInfo.fX += m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime() / 1.141421f;
			m_tInfo.fY -= m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime() / 1.41421f;
			m_tFrame.iMotion = State::RUN;
		}
		else
		{
			m_tInfo.fX += m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
			m_tFrame.iMotion = State::RUN;

		}
		m_bReverse = false;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
	{
		m_tInfo.fY -= m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tFrame.iMotion = State::RUN;

	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
	{
		m_tInfo.fY += m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
		m_tFrame.iMotion = State::RUN;

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
	CUiMgr::Get_Instance()->m_PlayerUi.SetHpMax(m_iMaxHp);
	CUiMgr::Get_Instance()->m_PlayerUi.SetHp(m_iHp);
	CUiMgr::Get_Instance()->m_ExpBar.SetMaxExp(100);
	CUiMgr::Get_Instance()->m_ExpBar.SetExp(0);
	m_iMaxExp = 100;

}

void CPlayer::Update()
{
	/*CTimeMgr::GetInstance().Update();
	std::wstring title = L"Time: " + std::to_wstring(m_iHp);
	SetWindowText(g_hWnd, title.c_str()); */

	for (auto& el : m_vecActiveItem)
	{
		el.Update();
	}
	

	m_fInvincibleTime -= CTimeMgr::GetInstance().GetDeltaTime();
	Key_Input();
	Move_Frame();
	// 사실 이 부분은 옵서버 패턴으로 하는게 좋긴 하겠으나 ;; 
	CUiMgr::Get_Instance()->m_PlayerUi.SetHp(m_iHp);
	CUiMgr::Get_Instance()->m_ExpBar.SetExp(m_iExp);

	if (m_iExp > m_iMaxExp)
	{
		m_iExp -= m_iMaxExp;
		CUiMgr::Get_Instance()->m_LevelUi.LevelUp();
	}

	CObj::Update_Rect();
	

}

void CPlayer::LateUpdate()
{
	Playerx = m_tInfo.fX;
	Playery = m_tInfo.fY;
}

void CPlayer::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	CPngMgr::Get_Instance().DrawPngWithAlpha(hDC, L"PlayerUiT"s, 0, 0, 398, 174, 0.5f);
	// 체력 출력 
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Red_Hp");
	HDC hMemDC2 = CBmpMgr::Get_Instance()->Find_Img(L"Green_Hp");

	BitBlt(hDC, m_tInfo.fX + _iScrollX - 32, m_tInfo.fY - 50 + _iScrollY, 64, 6, hMemDC, 0, 0, SRCCOPY);
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
	/*#ifdef _DEBUG
		Ellipse(hDC, m_tInfo.fX - m_fRadius + _iScrollX, m_tInfo.fY - m_fRadius + _iScrollY, m_tInfo.fX + m_fRadius + _iScrollX, m_tInfo.fY + m_fRadius + _iScrollY);
	#endif */

	// 아이템 슬롯
		for (int i = 0; i < m_vecActiveItem.size(); ++i)
		{
			m_vecActiveItem[i].Render(hDC,110 + 48 * i, 55);
		}
		for (int i = 0; i < m_vecPassiveItem.size(); ++i)
		{
			m_vecPassiveItem[i].Render(hDC, 110 + 48 * i, 120);
		}

}

void CPlayer::Release()
{

}

void CPlayer::Push_Item(CItem _item, ItemType _type)
{
	if (_type == ItemType::Active)
	{
		for (auto& el : m_vecActiveItem)
		{
			if (el.GetItemId() == _item.GetItemId())
			{
				el.LevelUp();
				return;
			}
		}
		m_vecActiveItem.push_back(_item);
	}
	else
	{
		for (auto& el : m_vecPassiveItem)
		{
			if (el.GetItemId() == _item.GetItemId())
			{
				el.LevelUp();
				return;
			}
		}
		m_vecPassiveItem.push_back(_item);
	}
}
