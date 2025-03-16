#include "pch.h"
#include "CItem.h"

CItem::CItem() : m_iItemId(0), m_fCoolTime(0), m_ilevel(1)
{
}

CItem::~CItem()
{
}

void CItem::Initialize()
{
}

void CItem::Update()
{
	if (m_fCoolTime > 0)
	{
		m_fCoolTime -= CTimeMgr::GetInstance().GetDeltaTime();
		return;
	}
	if (m_iItemId == 0)
	{
		shared_ptr<CBullet> bullet = make_shared<CBullet>();
		bullet->Initialize();
		bullet->Set_Pos(Playerx, Playery);
		float angle;
		POINT pt{};
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);
		angle = atan2f((pt.y - float(CCamera::Get_Instance().Get_ScrollY()) - Playery), (pt.x - Playerx - float(CCamera::Get_Instance().Get_ScrollX())));
		bullet->Set_Angle(-angle * 180 / PI);
		CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_BULLET, bullet);
		m_fCoolTime = 1.f/m_ilevel;
		CSoundMgr::Get_Instance()->StopSound(SOUND_BULLET);
		CSoundMgr::Get_Instance()->PlaySound(L"Bullet.wav", SOUND_BULLET, 1.f);
		
	}
	else if (m_iItemId == 1)
	{
		shared_ptr<CPoison> poison = make_shared<CPoison>();
		poison->Initialize();
		CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_BULLET, poison);
		m_fCoolTime = 100000.f;
	}
	else if (m_iItemId == 2)
	{
		shared_ptr<CLava> lava = make_shared<CLava>();
		lava->Initialize();
		lava->Set_Pos(Playerx + rand() % WINCX - WINCX / 2, Playery + rand() % WINCY - WINCY / 2);
		CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_BULLET, lava);
		m_fCoolTime = 3.f;
	}
	else if (m_iItemId == 3)
	{
		shared_ptr<BulletAx> Ax = make_shared<BulletAx>();
		Ax->Initialize();
		Ax->Set_XY(Playerx, Playery);
		CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_BULLET, Ax);
		m_fCoolTime = 2.f;
	}
	else if (m_iItemId == 4)
	{
		shared_ptr<BulletAx> Ax = make_shared<BulletAx>();
		Ax->Initialize();
		Ax->Set_XY(Playerx, Playery);
		CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_BULLET, Ax);
		m_fCoolTime = 2.f;
	}
	else if (m_iItemId == 5)
	{
		shared_ptr<CBoomerang> boomerang = make_shared<CBoomerang>();
		boomerang->Initialize();
		boomerang->Set_Pos(Playerx, Playery);
		boomerang->Set_Angle(rand() % 360);
		CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_BULLET, boomerang);
		m_fCoolTime = 3.f;
	}
	
}


void CItem::Render(HDC _hDC, int x, int y)
{
	GdiTransparentBlt(_hDC, x, y, 46, 46, CBmpMgr::Get_Instance()->Find_Img(L"Item_Slot"), 0, 46*m_iItemId, 46, 46, RGB(36, 74, 53));
}
