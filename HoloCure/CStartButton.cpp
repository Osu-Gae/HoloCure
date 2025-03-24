#include "pch.h"
#include "CStartButton.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CSoundMgr.h"
CStartButton::CStartButton() : m_bIsMouseUp(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	m_tInfo = { 640,400,444,108 };
	Update_Rect();
}

CStartButton::~CStartButton()
{
}

void CStartButton::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	if (PtInRect(&m_tRect, pt))
	{
		if (m_bIsMouseUp == false)
		{
			// CSoundMgr::Get_Instance()->PlaySound(L"button",SOUND_BUTTON,1.f);
			CSoundMgr::Get_Instance()->StopSound(SOUND_BUTTON);
			CSoundMgr::Get_Instance()->PlaySoundW(L"button.wav", SOUND_BUTTON, 1.f);
		}
		m_bIsMouseUp = true;
		// mouse left click
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
		{
			CSceneMgr::Get_Instance().Get_Instance().Scene_Change(CSceneMgr::STAGE);
		}
	}
	else
	{
		m_bIsMouseUp = false;
	}
}

void CStartButton::Render(HDC _hDC)
{
	SetBkMode(_hDC, TRANSPARENT);
	SelectObject(_hDC, hFontBig);

	if (m_bIsMouseUp)
	{
		CPngMgr::Get_Instance().DrawPngPart(_hDC, L"StartMenu", m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, 0, 0, m_tInfo.fCX, m_tInfo.fCY);
		SetTextColor(_hDC, RGB(0, 0, 0));
	}
	else
	{
		CPngMgr::Get_Instance().DrawPngPart(_hDC, L"StartMenu", m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, 0, m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY);
		SetTextColor(_hDC, RGB(255, 255, 255));
	}
	TextOut(_hDC, m_tRect.left + 150, m_tRect.top + 35, L"START", 5);
}

void CStartButton::Initialize()
{
}

void CStartButton::LateUpdate()
{
}

void CStartButton::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
}

void CStartButton::Release()
{
}
