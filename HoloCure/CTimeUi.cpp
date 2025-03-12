#include "pch.h"
#include "CTimeUi.h"

CTimeUi::CTimeUi() : m_fTime(0.f)
{
}

CTimeUi::~CTimeUi()
{
}

void CTimeUi::Initialize()
{
}

void CTimeUi::Update()
{
}

void CTimeUi::LateUpdate()
{
}

void CTimeUi::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{

	//StageUi
	// HDC memDc = CBmpMgr::Get_Instance()->Find_Img(L"StageUi");
	GdiTransparentBlt(hDC, (WINCX>>1)-29, 50,
		58, 10, CBmpMgr::Get_Instance()->Find_Img(L"StageUi"),
		0, 0,
		58, 10,
		RGB(0, 0, 0));
	SetBkMode(hDC, TRANSPARENT);
	TCHAR buffer[32];
	wsprintf(buffer, _T("%02d/%02d"), int(m_fTime)/60, int(m_fTime) % 60); // int 값을 문자열로 변환
	TextOut(hDC, (WINCX >> 1) - 20, 70, buffer, lstrlen(buffer));
}

void CTimeUi::Release()
{
}
