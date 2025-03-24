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
			if (m_iItemId < 6)
			{
				dynamic_pointer_cast<CPlayer>(CObjMgr::Get_Instance().Get_Player())->Push_Item(item, CPlayer::ItemType::Active);
			}
			else
			{
				dynamic_pointer_cast<CPlayer>(CObjMgr::Get_Instance().Get_Player())->Push_Item(item, CPlayer::ItemType::Passive);
			}
			CObjMgr::Get_Instance().Release_Stop();
			CUiMgr::Get_Instance()->m_LevelUi.CloseLevelUp();
			CSoundMgr::Get_Instance()->SetChannelVolume(CHANNELID::SOUND_BGM, 1.f);
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
	GdiTransparentBlt(hDC, m_tRect.left+30, m_tRect.top+50, 46, 36, CBmpMgr::Get_Instance()->Find_Img(L"Item_Slot"), 0, 46 * m_iItemId, 46, 36, RGB(36, 74, 53));

	//SetBkMode(hDC, OPAQUE);
	SetBkMode(hDC, TRANSPARENT);
	SelectObject(hDC, hFont);
	SetTextColor(hDC, RGB(255, 255, 255));
	switch (m_iItemId)
	{
	case 0:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"탄환 주기가 줄어든다",11);
		break;
	case 1:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"데미지가 증가한다", 9);
		break;
	case 2:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"용암 개수가 늘어난다", 11);
		break;
	case 3:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"던지는 주기가 줄어든다", 12);
		break;
	case 4:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"소환되는 주기가 줄어든다", 13);
		break;
	case 5:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"더 빨리 던진다.", 8);
		break;
	case 6:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"이동속도가 10퍼 증가한다", 14);
		break;
	case 7:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"크리티컬 확률이 10퍼 증가한다 ", 17);
		break;
	case 8:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"크리티컬 데미지가 10퍼 증가한다 ", 18);
		break;
	case 9:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"공격 속도가 10퍼 증가한다", 15);
		break;
	case 10:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"적을 죽일 시 일정 확률로 피를 회복한다", 22);
		break;
	case 11:
		TextOut(hDC, m_tRect.left + 100, m_tRect.top + 50, L"최대 HP가 10퍼 증가한다", 15);
		break;
	}
}

void CLevelUpItem::Release()
{
}
