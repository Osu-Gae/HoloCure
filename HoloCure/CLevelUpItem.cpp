#include "pch.h"
#include "CLevelUpItem.h"
#include "CKeyMgr.h"
#include "CObjMgr.h"
#include "CItem.h"
#include "CPlayer.h"
#include "CUiMgr.h"
CLevelUpItem::CLevelUpItem() : m_iItemId(0), m_ilevel(0), m_bMouseUp(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	m_tInfo = { 0,0,772,136 };
}


CLevelUpItem::~CLevelUpItem()
{
}

void CLevelUpItem::Initialize()
{

}

void CLevelUpItem::Update()
{
	// 마우스 위치가 RECT 안에 있으면 m_bMouseUp = true
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	if (PtInRect(&m_tRect, pt))
	{
		m_bMouseUp = true;
		// mouse left click
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			CItem item;
			item.SetItemId(m_iItemId);
			dynamic_pointer_cast<CPlayer>(CObjMgr::Get_Instance().Get_Player())->Push_Item(item, CPlayer::ItemType::Active);
			CUiMgr::Get_Instance()->m_LevelUi.CloseLevelUp();
		}
	}
	else
	{
		m_bMouseUp = false;
	}


}

void CLevelUpItem::LateUpdate()
{
}

void CLevelUpItem::Render(HDC hDC, const int& _X, const int& _Y)
{
	// 386 68 
	// CPngMgr::Get_Instance().DrawPng(hDC, L"LevelUp", m_tRect.left, m_tRect.top, 386, 68);
	if (m_bMouseUp)
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"LevelUp", m_tRect.left, m_tRect.top, 772, 136, 0,0, 772, 136);
	else
		CPngMgr::Get_Instance().DrawPngPart(hDC, L"LevelUp", m_tRect.left,m_tRect.top, 772, 136, 0, 136, 772, 136);
	//BitBlt(hDC, _X + 10, _Y + 10, 50, 50, CBmpMgr::Get_Instance()->Find_Img(L"Item_Acttive_Slot"), 0, 0, SRCCOPY);
	// BitBlt(hDC, m_tRect.left, m_tRect.top, 50, 50, CBmpMgr::Get_Instance()->Find_Img(L"Item_Acttive_Slot"), 0, 50 * m_ilevel, SRCCOPY);
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, 46, 46, CBmpMgr::Get_Instance()->Find_Img(L"Item_Acttive_Slot"), 0, 46 * m_iItemId, 46, 46, RGB(36, 74, 53));
}

void CLevelUpItem::Release()
{
}
