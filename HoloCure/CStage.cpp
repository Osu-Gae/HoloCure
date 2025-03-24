#include "pch.h"
#include "CStage.h"
#include "BulletAx.h"
#include "CColliderMgr.h"
#include "CSpawnMgr.h"
CStage::CStage()
{
}

CStage::~CStage()
{
	Release();
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
	CSoundMgr::Get_Instance()->StopAll();
	CSoundMgr::Get_Instance()->PlayBGM(L"Grassy.mp3", SOUND_BGM);
	CSoundMgr::Get_Instance()->SetChannelVolume(SOUND_BGM, 0.7f);

}

void CStage::Update()
{
	// 테스트용 삭제 예정
	if (CKeyMgr::Get_Instance()->Key_Down('Z'))
	{
		// 삭제 예정
		endCsene.Initialize();
		SetEnd();
	}
	if (end)
	{
		endCsene.Update();
		return;
	}



	CUiMgr::Get_Instance()->Update();
	if (CObjMgr::Get_Instance().Get_TimeStop())
		return;
	CSpawnMgr::Get_Instance()->Update();

	CTileMgr::Get_Instance().Update();
	CObjMgr::Get_Instance().Update();

}

void CStage::LateUpdate()
{



	if (CObjMgr::Get_Instance().Get_TimeStop())
		return;

	CTileMgr::Get_Instance().LateUpdate();
	CObjMgr::Get_Instance().Late_Update();
	CKeyMgr::Get_Instance()->Late_Update();
}

void CStage::Render(HDC hDC, int _iScrollX, int _iScrollY)
{


	CTileMgr::Get_Instance().Get_Instance().Render(hDC, _iScrollX, _iScrollY);
	CObjMgr::Get_Instance().Render(hDC, _iScrollX , _iScrollY);
	CUiMgr::Get_Instance()->Render(hDC, _iScrollX, _iScrollY);
	if (end)
	{
		endCsene.Render(hDC);
	}
}

void CStage::Release()
{
	CObjMgr::Get_Instance().Release();
	CUiMgr::Get_Instance()->Destroy_Instance();
}
