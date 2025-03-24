#include "pch.h"
#include "CJirungE.h"

CJirungE::CJirungE() : m_fAngle(0.f), m_fDeathTime(0.f)
{
}

CJirungE::~CJirungE()
{
}

void CJirungE::Initialize()
{
	m_tInfo.fCX = 128;
	m_tInfo.fCY = 128;
	m_iAttack = 15;
	m_fRadius = 15.f;
	m_fDeathTime = 3.f;
	m_fSpeed = 2000;
}

void CJirungE::Update()
{
	m_fDeathTime -= CTimeMgr::GetInstance().GetDeltaTime();
	m_tInfo.fX += cosf(m_fAngle * PI / 180.f) * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
	m_tInfo.fY -= sinf(m_fAngle * PI / 180.f) * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
	float		fDiagonal = sqrtf(((m_tInfo.fCX / 2.f) * (m_tInfo.fCX / 2.f)) + ((m_tInfo.fCY / 2.f) * (m_tInfo.fCY / 2.f)));

	// 좌 상단
	m_tPoint[0].x = LONG((m_tInfo.fCX / 2.f) + (fDiagonal * cosf((m_fAngle + 135.f) * PI / 180.f)));
	m_tPoint[0].y = LONG((m_tInfo.fCY / 2.f) - (fDiagonal * sinf((m_fAngle + 135.f) * PI / 180.f)));

	// 우 상단
	m_tPoint[1].x = LONG((m_tInfo.fCX / 2.f) + (fDiagonal * cosf((m_fAngle + 45.f) * PI / 180.f)));
	m_tPoint[1].y = LONG((m_tInfo.fCY / 2.f) - (fDiagonal * sinf((m_fAngle + 45.f) * PI / 180.f)));

	// 우 하단
	m_tPoint[2].x = LONG((m_tInfo.fCX / 2.f) + (fDiagonal * cosf((m_fAngle + 225.f) * PI / 180.f)));
	m_tPoint[2].y = LONG((m_tInfo.fCY / 2.f) - (fDiagonal * sinf((m_fAngle + 225.f) * PI / 180.f)));
	Update_Rect();

}

void CJirungE::LateUpdate()
{

	if (m_fDeathTime < 0)
	{
		m_bDead = true;
	}
}

void CJirungE::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	HDC	hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Item_6");
	HDC	hPlgDC = CBmpMgr::Get_Instance()->Find_Img(L"Plg1");
	HDC	hResetDC = CBmpMgr::Get_Instance()->Find_Img(L"Reset1");

	/*int	iScrollX = (int)CCamera::Get_Instance().Get_ScrollX();
	int	iScrollY = (int)CCamera::Get_Instance().Get_ScrollY();*/

	PlgBlt(hPlgDC, m_tPoint, hMemDC, 0, 0, (int)m_tInfo.fCX, (int)m_tInfo.fCY, NULL, NULL, NULL);


	GdiTransparentBlt(hDC,
		m_tRect.left + _iScrollX,
		m_tRect.top + _iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hPlgDC,		// 복사할 이미지 dc
		0,
		0,	// 비트맵 출력 자표
		(int)m_tInfo.fCX, // 비트맵 가로, 세로 사이즈
		(int)m_tInfo.fCY,
		RGB(36, 74, 53));	//제거할 픽셀의 색상 값

	BitBlt(hPlgDC, 0, 0, (int)m_tInfo.fCX, (int)m_tInfo.fCY, hResetDC, 0, 0, SRCCOPY);
}

void CJirungE::Release()
{
}
