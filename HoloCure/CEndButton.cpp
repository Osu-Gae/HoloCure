#include "pch.h"
#include "CEndButton.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CPngMgr.h"
CEndButton::CEndButton()
{
}

CEndButton::~CEndButton()
{
}

void CEndButton::Update()
{
	Update_Rect();
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	if (PtInRect(&m_tRect, pt))
	{
		m_bIsMouseUp = true;
		// mouse left click
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
		{
			if(id==0)
				CSceneMgr::Get_Instance().Get_Instance().Scene_Change(CSceneMgr::STAGE);
			else
				CSceneMgr::Get_Instance().Get_Instance().Scene_Change(CSceneMgr::TITLE);
		}
	}
	else
	{
		m_bIsMouseUp = false;
	}
}
int CEndButton::Update1()
{
	Update_Rect();
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	if (PtInRect(&m_tRect, pt))
	{
		m_bIsMouseUp = true;
		// mouse left click
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
		{
			if (id == 0)
			{
				CSceneMgr::Get_Instance().Get_Instance().Scene_Change(CSceneMgr::STAGE);
				return 1;
			}
			else
			{
				CSceneMgr::Get_Instance().Get_Instance().Scene_Change(CSceneMgr::TITLE);
				return 1;
			}
		}
		
	}
	else
	{
		m_bIsMouseUp = false;
	}
	return 0;
}


void CEndButton::Initialize()
{
	m_tInfo = { 0,0,580,108 };

}

void CEndButton::LateUpdate()
{
}

void CEndButton::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	//StartMenu
	if (m_bIsMouseUp)
	{
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"StartMenu", m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, 0, 0, m_tInfo.fCX, m_tInfo.fCY);
		SetTextColor(hDC, RGB(0, 0, 0));
	}
	else
	{
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"StartMenu", m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, 0, m_tInfo.fCY, m_tInfo.fCX, m_tInfo.fCY);
		SetTextColor(hDC, RGB(255, 255, 255));
	}
	
	if (id == 0)
	{
		TextOut(hDC, m_tRect.left + 160, m_tRect.top + 35, L"RESTART", 7);
	}
	else
	{
		TextOut(hDC, m_tRect.left + 180, m_tRect.top + 35, L"MENU", 4);
	}
}

void CEndButton::Release()
{
}


