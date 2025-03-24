#include "pch.h"
#include "BulletAx.h"

BulletAx::BulletAx() : m_iInit_x(0), m_iInit_y(0),  m_fDeathTime(0.f)
{
}

BulletAx::~BulletAx()
{
}

void BulletAx::Initialize()
{
    m_tFrame = { 0 , 7, 0 ,CTimeMgr::GetInstance().GetTime(),0.02 };
    m_fDeathTime = 3.f;
    m_fRadius = 30.f;
    m_tInfo = { 0,0,92,92 };
	m_iAttack = 8;
}

void BulletAx::Update()
{
    theta += speed; 
    double r = a * exp(b * theta); 
    m_tInfo.fX = r * cos(theta) + m_iInit_x; 
    m_tInfo.fY = r * sin(theta) + m_iInit_y;
    m_fDeathTime -= CTimeMgr::GetInstance().GetDeltaTime();
    if (m_fDeathTime < 0)
    {
        m_bDead = true;
    }
}

void BulletAx::LateUpdate()
{
    if (m_tFrame.dwTime + m_tFrame.dwSpeed < CTimeMgr::GetInstance().GetTime())
    {
        ++m_tFrame.iStart;

        if (m_tFrame.iStart > m_tFrame.iEnd)
            m_tFrame.iStart = 0;
        m_tFrame.dwTime = CTimeMgr::GetInstance().GetTime();
    }
    Update_Rect();
}



void BulletAx::Release()
{
}

void BulletAx::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
    GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
        m_tRect.top + _iScrollY, 92, 92, CBmpMgr::Get_Instance()->Find_Img(L"Item_4"),
        m_tFrame.iStart*92, 0,
        92, 92,
        RGB(36, 74, 53));
//#ifdef _DEBUG
//    Ellipse(hDC, m_tInfo.fX-m_fRadius + _iScrollX, m_tInfo.fY - m_fRadius + _iScrollY, m_tInfo.fX+ _iScrollX + m_fRadius, m_tInfo.fY + _iScrollY+ m_fRadius);
//#endif // _DEBUG

    // Ellipse(hDC, m_tInfo.fX - m_fRadius + _iScrollX, m_tInfo.fY - m_fRadius + _iScrollY, m_tInfo.fX + m_fRadius + _iScrollX, m_tInfo.fY + m_fRadius + _iScrollY);

}
