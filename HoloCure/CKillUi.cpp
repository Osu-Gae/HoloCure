#include "pch.h"
#include "CKillUi.h"

CKillUi::CKillUi() : m_iKillCount(0)
{
}

CKillUi::~CKillUi()
{
}

void CKillUi::Initialize()
{
}

void CKillUi::Update()
{
	m_iKillCount++;
}

void CKillUi::LateUpdate()
{
}

void CKillUi::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	GdiTransparentBlt(hDC, 1000, 70,
		30, 30, CBmpMgr::Get_Instance()->Find_Img(L"KillCount"),
		0, 0,
		30, 30,
		RGB(134, 159, 249));
	SetBkMode(hDC, TRANSPARENT);
	TCHAR buffer[32];
	wsprintf(buffer, _T("%d"), m_iKillCount); // int 값을 문자열로 변환
	TextOut(hDC, 1050, 75, buffer, lstrlen(buffer));
}

void CKillUi::Release()
{
}
