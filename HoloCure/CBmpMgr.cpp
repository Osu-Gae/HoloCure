#include "pch.h"
#include "CBmpMgr.h"

CBmpMgr* CBmpMgr::m_pInstance = nullptr;

CBmpMgr::CBmpMgr()
{
}

CBmpMgr::~CBmpMgr()
{
	Release();
}

HDC CBmpMgr::Find_Img(const TCHAR* pImgKey)
{
	auto	iter = find_if(m_mapBit.begin(), m_mapBit.end(), tagFinder(pImgKey));

	if (iter == m_mapBit.end())
		return nullptr;

	return iter->second->Get_MemDC();
}

void CBmpMgr::Initialize()
{
	Insert_Bmp(L"../Image/BackBuffer.bmp", L"Back");
	Insert_Bmp(L"../Image/Obj/Ground/G.bmp", L"Ground");
	Insert_Bmp(L"../Image/Obj/Ui/Red_Hp.bmp", L"Red_Hp");
	Insert_Bmp(L"../Image/Obj/Ui/Green_Hp.bmp", L"Green_Hp");
	Insert_Bmp(L"../Image/Obj/Ui/Watson_Portrait.bmp", L"Watson_Portrait");
	Insert_Bmp(L"../Image/Obj/Ui/ExpAni.bmp", L"ExpAni");
	Insert_Bmp(L"../Image/Obj/Ui/PlayerUi.bmp", L"PlayerUi");
	Insert_Bmp(L"../Image/Obj/Ui/PlayerHp.bmp", L"PlayerHp");
	Insert_Bmp(L"../Image/Obj/Ui/StageUi.bmp", L"StageUi");
	Insert_Bmp(L"../Image/Obj/Ui/Number.bmp", L"Number");
	Insert_Bmp(L"../Image/Obj/Ui/Item_Number.bmp", L"Item_Number");
	
	Insert_Bmp(L"../Image/Obj/Ui/KillCount.bmp", L"KillCount");
	Insert_Bmp(L"../Image/Obj/Item/Item_1.bmp", L"Item_1");
	Insert_Bmp(L"../Image/Obj/Item/Item_2.bmp", L"Item_2");
	Insert_Bmp(L"../Image/Obj/Item/Item_3.bmp", L"Item_3");
	Insert_Bmp(L"../Image/Obj/Item/Item_4.bmp", L"Item_4");
	Insert_Bmp(L"../Image/Obj/Item/Item_5.bmp", L"Item_5");
	Insert_Bmp(L"../Image/Obj/Item/Item_6.bmp", L"Item_6");
	Insert_Bmp(L"../Image/Obj/Item/Item_7.bmp", L"Item_7");
	Insert_Bmp(L"../Image/Obj/Item/Plg.bmp", L"Plg1");
	Insert_Bmp(L"../Image/Obj/Item/Reset.bmp", L"Reset1");
	Insert_Bmp(L"../Image/Obj/Item/Item_Acttive_Slot.bmp", L"Item_Acttive_Slot");
	Insert_Bmp(L"../Image/Obj/Item/Item_Slot.bmp", L"Item_Slot");
	Insert_Bmp(L"../Image/Obj/Monster/Monster.bmp", L"Monster");
	Insert_Bmp(L"../Image/Obj/Monster/Monster_Rev.bmp", L"Monster_Rev");
	Insert_Bmp(L"../Image/Obj/Monster/Monster_Damaged1.bmp", L"Monster_Damaged");
	Insert_Bmp(L"../Image/Obj/Monster/Monster_Damaged_Rev1.bmp", L"Monster_Damaged_Rev");

	Insert_Bmp(L"../Image/Obj/Monster/FanDie.bmp", L"FanDie");

	Insert_Bmp(L"../Image/Obj/Player/Bullet.bmp", L"Bullet");
	Insert_Bmp(L"../Image/Obj/Player/Plg.bmp", L"Plg");
	Insert_Bmp(L"../Image/Obj/Player/Reset.bmp", L"Reset");
	Insert_Bmp(L"../Image/Obj/Exp/Exp_sheet.bmp", L"Exp_sheet");

	Insert_Bmp(L"../Image/Obj/Boss/fubuki.bmp", L"fubuki");
	Insert_Bmp(L"../Image/Obj/Boss/Laser.bmp", L"Laser");
	Insert_Bmp(L"../Image/Obj/Boss/fubuki_Rev.bmp", L"fubuki_Rev");
	Insert_Bmp(L"../Image/Obj/Boss/Laser_Rev.bmp", L"Laser_Rev");
	Insert_Bmp(L"../Image/Obj/Boss/Bullet.bmp", L"BossBullet");
	Insert_Bmp(L"../Image/Obj/Boss/Baelz.bmp", L"Baelz");
	Insert_Bmp(L"../Image/Obj/Boss/Baelz_Rev.bmp", L"Baelz_Rev");
	Insert_Bmp(L"../Image/Obj/Boss/Fubuki_spawn.bmp", L"Fubuki_spawn");
	Insert_Bmp(L"../Image/Obj/Boss/BAELZ_spawn.bmp", L"BAELZ_spawn");
	Insert_Bmp(L"../Image/Obj/Cursor.bmp", L"Cursor");

	// Cursor
}


void CBmpMgr::Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey)
{
	auto	iter = find_if(m_mapBit.begin(), m_mapBit.end(), tagFinder(pImgKey));

	if (iter == m_mapBit.end())
	{
		CMyBmp* pMyBmp = new CMyBmp;

		pMyBmp->Load_Bmp(pFilePath);

		m_mapBit.insert({ pImgKey, pMyBmp });
	}
}

void CBmpMgr::Release()
{
	for (auto& Pair : m_mapBit)
	{
		Pair.second->Release();
		delete Pair.second;
		Pair.second = nullptr;
	}
	m_mapBit.clear();

}
