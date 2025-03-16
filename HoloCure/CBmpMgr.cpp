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
	Insert_Bmp(L"../Image/Obj/Ui/KillCount.bmp", L"KillCount");
	Insert_Bmp(L"../Image/Obj/Item/Item_1.bmp", L"Item_1");
	Insert_Bmp(L"../Image/Obj/Item/Item_2.bmp", L"Item_2");
	Insert_Bmp(L"../Image/Obj/Item/Item_3.bmp", L"Item_3");
	Insert_Bmp(L"../Image/Obj/Item/Item_4.bmp", L"Item_4");
	Insert_Bmp(L"../Image/Obj/Item/Item_5.bmp", L"Item_5");
	Insert_Bmp(L"../Image/Obj/Item/Item_6.bmp", L"Item_6");
	Insert_Bmp(L"../Image/Obj/Item/Item_7.bmp", L"Item_7");
	Insert_Bmp(L"../Image/Obj/Item/Item_Acttive_Slot.bmp", L"Item_Acttive_Slot");
	Insert_Bmp(L"../Image/Obj/Monster/Monster.bmp", L"Monster");
	Insert_Bmp(L"../Image/Obj/Monster/Monster_Rev.bmp", L"Monster_Rev");
	Insert_Bmp(L"../Image/Obj/Monster/Monster_Damaged.bmp", L"Monster_Damaged");
	Insert_Bmp(L"../Image/Obj/Monster/Monster_Damaged_Rev.bmp", L"Monster_Damaged_Rev");
	Insert_Bmp(L"../Image/Obj/Player/Bullet.bmp", L"Bullet");
	Insert_Bmp(L"../Image/Obj/Player/Plg.bmp", L"Plg");
	Insert_Bmp(L"../Image/Obj/Player/Reset.bmp", L"Reset");
	Insert_Bmp(L"../Image/Obj/Exp/Exp_sheet.bmp", L"Exp_sheet");
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
