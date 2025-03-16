#include "pch.h"
#include "CStage.h"
#include "BulletAx.h"
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
	CItem itemp;
	itemp.SetItemId(0);
	player->Push_Item(itemp, CPlayer::ItemType::Active);
	CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_PLAYER, player);
	CTileMgr::Get_Instance().Initialize();
	shared_ptr<BulletAx> Ax = make_shared<BulletAx>();
	CPngMgr::Get_Instance().Initailize();
	CSoundMgr::Get_Instance()->StopSound(SOUND_BGM);
	CSoundMgr::Get_Instance()->PlayBGM(L"Grassy.mp3", SOUND_BGM);

}

void CStage::Update()
{
	static int count = 0;
	count++;
	if (count > 100)
	{
		CObjMgr::Get_Instance().Spawn_Monster(rand() % 38, Playerx, Playery);
		count = 0;
	}

	CTileMgr::Get_Instance().Update();
	CObjMgr::Get_Instance().Update();
	CUiMgr::Get_Instance()->Update();

}

void CStage::LateUpdate()
{
	CTileMgr::Get_Instance().LateUpdate();
	CObjMgr::Get_Instance().Late_Update();
	CKeyMgr::Get_Instance()->Late_Update();
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
