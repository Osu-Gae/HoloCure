#include "pch.h"
#include "CSpawnMgr.h"
#include "CObjMgr.h"
#include "CFubuki.h"
#include "CBaelz.h"

CSpawnMgr* CSpawnMgr::m_pInstance = nullptr;
CSpawnMgr::CSpawnMgr()
{
}

CSpawnMgr::~CSpawnMgr()
{
}

void CSpawnMgr::Update()
{
	// 0.3초마다 몬스터 생성 
	static float m_fSpawn = 0.f;
	m_fSpawn += CTimeMgr::GetInstance().GetDeltaTime();
	m_fTime += CTimeMgr::GetInstance().GetDeltaTime();
	if (m_fSpawn > 0.5f)
	{
		float angle = (rand() % 360 ) * PI / 180.f;
		CObjMgr::Get_Instance().Spawn_Monster(min(36,int(m_fTime) / 7), Playerx + int(cosf(angle) * 1500), Playery + int(sinf(angle) * 1500));
		m_fSpawn = 0.f;
	}
	// 1분이 지나면 푸부키 보스 생성
	if (state == S)
	{
		float angle = (rand() % 360) * PI / 180.f;
		if (m_fTime > 80)
		{
			shared_ptr<CFubuki> Fubuki = make_shared<CFubuki>();
			Fubuki->Initialize();
			Fubuki->Set_Pos(Playerx + int(cosf(angle) * 1000), Playery +int(sinf(angle) * 1000));
			CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_MONSTER, Fubuki);
			state = F;
		}
	}
	else if (state == F)
	{
		float angle = (rand() % 360) * PI / 180.f;
		if (m_fTime > 120)
		{
			shared_ptr<CBaelz> Boss = make_shared<CBaelz>();
			Boss->Initialize();
			Boss->Set_Pos(Playerx + int(cosf(angle) * 1000), Playery+ int(sinf(angle) * 1000));
			CObjMgr::Get_Instance().Add_Object(OBJID::OBJ_MONSTER, Boss);
			state = B;
		}
	}
	// 2분이 지나면 벨즈 보스 생성 
}
