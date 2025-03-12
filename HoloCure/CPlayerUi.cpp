#include "pch.h"
#include "CPlayerUi.h"

CPlayerUi::CPlayerUi() : m_iHp(50), m_iMaxHp(70)
{
}

CPlayerUi::~CPlayerUi()
{
}

void CPlayerUi::Initialize()
{
}

void CPlayerUi::Update()
{
	m_iHp++;
	if (m_iHp > 70)
	{
		m_iHp = 1;
	}
}

void CPlayerUi::LateUpdate()
{
}

void CPlayerUi::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	HDC memDc = CBmpMgr::Get_Instance()->Find_Img(L"PlayerUi");
	// RGB(0,0,0) 제거하고 출력
	GdiTransparentBlt(hDC, 0, 0,
		398, 174, memDc,
		0, 0,
		398, 174,
		RGB(36, 74, 53));
	//PlayerHp
	// 138 30
	// 258 12
	// int(398*(float(m_iHp)/m_iMaxHp)), 12,
	HDC memDc1 = CBmpMgr::Get_Instance()->Find_Img(L"PlayerHp");
	GdiTransparentBlt(hDC, 138, 30,
		int(258 * (float(m_iHp) / m_iMaxHp)), 12, memDc1,
		0, 0,
		int(258 * (float(m_iHp) / m_iMaxHp)), 12,
		RGB(0, 0, 0));

	GdiTransparentBlt(hDC, 16, 28,
		86,76, CBmpMgr::Get_Instance()->Find_Img(L"Watson_Portrait"),
		0, 0,
		86, 76,
		RGB(0, 0, 0));
	SetBkMode(hDC, TRANSPARENT);
	TCHAR buffer[32];
	wsprintf(buffer, _T("%d/%d"), m_iHp,m_iMaxHp); 
	TextOut(hDC, 400, 30, buffer, lstrlen(buffer));
}

void CPlayerUi::Release()
{
}
