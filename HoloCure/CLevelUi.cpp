#include "pch.h"
#include "CLevelUi.h"

CLevelUi::CLevelUi()
{
	m_vecLevelUpItem.resize(4);
	for (int i = 0; i < 4; i++)
	{
		m_vecLevelUpItem[i].SetXY(800, 200 + 150 * i);
	}
	m_vecid.resize(12);
	for (int i = 0; i < 12; i++)
	{
		m_vecid[i] = i;
	}
}

CLevelUi::~CLevelUi()
{
}

void CLevelUi::Initialize()
{
}

void CLevelUi::Update()
{
	if (m_bShow)
	{
		for (int i = 0; i < 4; i++)
			m_vecLevelUpItem[i].Update();
	}
}

void CLevelUi::LateUpdate()
{
}

void CLevelUi::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	if (m_bShow)
	{
		for (int i = 0; i < 4; i++)
			m_vecLevelUpItem[i].Render(hDC, _iScrollX, _iScrollY);
		// GdiTransparentBlt(hDC, 0, 0, 800, 600, CBmpMgr::Get_Instance()->FindImage(L"LevelUp"), 0, 0, 800, 600, RGB(255, 0, 255));
	}
}

void CLevelUi::Release()
{
}

void CLevelUi::LevelUp()
{
	// 시간 멈추는거 추가해야 함
	m_bShow = true;
	Randomid();
	for (int i = 0; i < 4; i++)
	{
		m_vecLevelUpItem[i].SetItemId(m_vecid[i]);
	}
}

void CLevelUi::Randomid()
{
	for (int i = 0; i < 100; i++)
	{
		swap(m_vecid[rand() % 12], m_vecid[rand() % 12]);
	}
}
