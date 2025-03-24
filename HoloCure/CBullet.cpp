#include "pch.h"
#include "CBullet.h"

CBullet::CBullet() : m_fAngle(0.f) , m_fDeathTime(0.f)
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 64;
	m_tInfo.fCY = 64;
	m_iAttack = 15;
	m_fRadius = 15.f;
	m_fDeathTime = 4;
}

void CBullet::Update()
{
	m_fDeathTime -= CTimeMgr::GetInstance().GetDeltaTime();
	m_tInfo.fX += cosf(m_fAngle * PI / 180.f) * 500.f * CTimeMgr::GetInstance().GetDeltaTime();
	m_tInfo.fY -= sinf(m_fAngle * PI / 180.f) * 500.f * CTimeMgr::GetInstance().GetDeltaTime();
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

void CBullet::LateUpdate()
{
	if (m_fDeathTime < 0)
	{
		m_bDead = true;
	}
	Update_Rect();
}

void CBullet::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	// BitBlt(hDC, m_tRect.left + _iScrollX, m_tRect.top + _iScrollY, (int)m_tInfo.fCX, (int)m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Bullet"), 0, 0, SRCCOPY);
	HDC	hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Bullet");
	HDC	hPlgDC = CBmpMgr::Get_Instance()->Find_Img(L"Plg");
	HDC	hResetDC = CBmpMgr::Get_Instance()->Find_Img(L"Reset");

	int	iScrollX = (int)CCamera::Get_Instance().Get_ScrollX();
	int	iScrollY = (int)CCamera::Get_Instance().Get_ScrollY();

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

	/*#ifdef _DEBUG
		Ellipse(hDC, m_tInfo.fX - m_fRadius + _iScrollX, m_tInfo.fY - m_fRadius + _iScrollY, m_tInfo.fX + m_fRadius + _iScrollX, m_tInfo.fY + m_fRadius + _iScrollY);
	#endif */

}

void CBullet::Release()
{
}
