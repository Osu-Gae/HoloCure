#include "pch.h"
#include "CBossBullet.h"
#include "CTimeMgr.h"
#include "CBmpMgr.h"
CBossBullet::CBossBullet() : m_fLifeTime(0.f), m_fAngle(0.f)
{
}

CBossBullet::~CBossBullet()
{
}

void CBossBullet::Initialize()
{
	m_tInfo = { 0,0,34,34 };
	m_fSpeed = 300.f;
	m_fLifeTime = 5.f;
	m_iAttack = 2;
	m_fRadius = 10.f;
}

void CBossBullet::Update()
{
	m_tInfo.fX += cosf(m_fAngle * PI / 180.f) * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
	m_tInfo.fY -= sinf(m_fAngle * PI / 180.f) * m_fSpeed * CTimeMgr::GetInstance().GetDeltaTime();
}

void CBossBullet::LateUpdate()
{
	Update_Rect();
	m_fLifeTime -= CTimeMgr::GetInstance().GetDeltaTime();
	if(m_fLifeTime < 0.f) 
		m_bDead = true;
}

void CBossBullet::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
		m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"BossBullet"),
		0, 0,
		m_tInfo.fCX, m_tInfo.fCY,
		RGB(36, 74, 53));
}

void CBossBullet::Release()
{
}
