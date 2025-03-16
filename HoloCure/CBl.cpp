#include "pch.h"
#include "CBl.h"

CBl::CBl()
{
}

CBl::~CBl()
{
}

void CBl::Initialize()
{
	m_fRadius = 50.f;
	m_tInfo = { 0,0,64,64 };
}

void CBl::Update()
{
}

void CBl::LateUpdate()
{
}

void CBl::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
		m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Item_5"),
		0, 0,
		64, 64,
		RGB(36, 74, 53));
}

void CBl::Release()
{
}
