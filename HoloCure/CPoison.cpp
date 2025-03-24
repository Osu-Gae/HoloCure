#include "pch.h"
#include "CPoison.h"

CPoison::CPoison()
{
}

CPoison::~CPoison()
{
}

void CPoison::Initialize()
{
      m_tInfo = { 0,0,214,214 };
	  m_iAttack = 3;
	  m_fRadius = 100.f;
}

void CPoison::Update()
{
	m_tInfo.fX = Playerx;
	m_tInfo.fY = Playery;
}

void CPoison::LateUpdate()
{
}

void CPoison::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	CPngMgr::Get_Instance().DrawPngWithAlpha(hDC, L"Item_1", 
		m_tInfo.fX - m_tInfo.fCX / 2 + _iScrollX, m_tInfo.fY - m_tInfo.fCY / 2 + _iScrollY, 
		m_tInfo.fCX, m_tInfo.fCY, 0.5f);
}

void CPoison::Release()
{
}
