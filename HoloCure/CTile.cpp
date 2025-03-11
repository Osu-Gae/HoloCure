#include "pch.h"
#include "CTile.h"
#include "CBmpMgr.h"
CTile::CTile(int x , int y)
	:m_iXPos(x), m_iYPos(y) {
}

CTile::~CTile()
{
	Release();
}

void CTile::Initialize()
{
	m_tInfo.fCX = TILEXY;
	m_tInfo.fCY = TILEXY;

}

void CTile::Update()
{


	// CObj::Update_Rect();
}

void CTile::LateUpdate()
{
}

void CTile::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	/*CPngMgr::Get_Instance().DrawPngPart(hDC, L"Ground",
		m_iXPos * 160 + _iScrollX, m_iYPos * 160 + _iScrollY,
		m_tInfo.fCX, m_tInfo.fCY,
		((m_iXPos + 16) % 16) * m_tInfo.fCX, ((m_iYPos + 16) % 16) * m_tInfo.fCY,
		m_tInfo.fCX, m_tInfo.fCY);*/
	HDC tempDC = CBmpMgr::Get_Instance()->Find_Img(L"Ground");
	int x = m_iXPos;
	int y = m_iYPos;
	while (x < 0)
		x += 16;
	while (y < 0)
		y += 16;
	BitBlt(hDC, m_iXPos * 160 + _iScrollX, m_iYPos * 160 + _iScrollY, 
		160,160, 
		tempDC, (x%16) * m_tInfo.fCX, (y%16) * m_tInfo.fCY, SRCCOPY);
}

void CTile::Release()
{
}
