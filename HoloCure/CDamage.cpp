#include "pch.h"
#include "CDamage.h"
#include "CTimeMgr.h"
CDamage::CDamage() : m_flifeTime(0.f)
{
}

CDamage::~CDamage()
{
}

void CDamage::Initialize()
{
    m_tInfo = { -5000,-5000,20,14 };
    m_flifeTime = 0.5f;
}

void CDamage::Update()
{
    Set_Plus_Pos(0, -100 * CTimeMgr::GetInstance().GetDeltaTime());
    m_flifeTime -= CTimeMgr::GetInstance().GetDeltaTime();
    if (m_flifeTime < 0)
    {
        m_bDead = true;
    }
}

void CDamage::LateUpdate()
{
    Update_Rect();
}

void CDamage::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
    GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
        m_tRect.top + _iScrollY, 20, 14, CBmpMgr::Get_Instance()->Find_Img(L"Number"),
       0, 14*m_idamageVal,
        20, 14,
        RGB(134, 159, 249));
}

void CDamage::Release()
{
}
