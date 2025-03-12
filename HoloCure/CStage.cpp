#include "pch.h"
#include "CStage.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

void CStage::Initialize()
{
	// 플레이어 초기화
	shared_ptr<CPlayer> player = make_shared<CPlayer>();
	player->Initialize();
	CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_PLAYER, player);

	shared_ptr<CMonster> monster1 = make_shared<CMonster>();
	monster1->Initialize();
	monster1->Set_Id(3);
	monster1->Set_Pos(800, 100);
	CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_MONSTER, monster1);

	shared_ptr<CMonster> monster2 = make_shared<CMonster>();
	monster2->Initialize();
	monster2->Set_Id(15);
	monster2->Set_Pos(100, 100);
	CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_MONSTER, monster2);

	CTileMgr::Get_Instance().Initialize();


	CPngMgr::Get_Instance().Initailize();
}

void CStage::Update()
{
	CTileMgr::Get_Instance().Update();
	CObjMgr::Get_Instance().Update();
	CUiMgr::Get_Instance()->Update();
}

void CStage::LateUpdate()
{
	CTileMgr::Get_Instance().LateUpdate();
	CObjMgr::Get_Instance().Late_Update();
}

void CStage::Render(HDC hDC, int _iScrollX, int _iScrollY)
{
	CTileMgr::Get_Instance().Get_Instance().Render(hDC, _iScrollX, _iScrollY);
	CObjMgr::Get_Instance().Render(hDC, _iScrollX , _iScrollY);
	CUiMgr::Get_Instance()->Render(hDC, _iScrollX, _iScrollY);
}

void CStage::Release()
{
	CUiMgr::Get_Instance()->Destroy_Instance();
}
