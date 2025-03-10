#include "pch.h"
#include "CSceneMgr.h"

CSceneMgr::CSceneMgr() : m_ePreScene(SCENEID::END), m_eCurScene(SCENEID::LOGO), m_pScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
}

void CSceneMgr::Scene_Change(SCENEID eScene)
{
	m_eCurScene = eScene;

	if (m_ePreScene != m_eCurScene)
	{

		switch (m_eCurScene)
		{
			case SCENEID::LOGO:
				m_pScene = make_shared<CLogo>();
				break;
			case SCENEID::TITLE:
				m_pScene = make_shared<CTitle>();
				break;
			case SCENEID::STAGE:
				m_pScene = make_shared<CStage>();
				break;
		}

		m_pScene->Initialize();
		m_ePreScene = m_eCurScene;
	}
}

void CSceneMgr::Initialize()
{
	Scene_Change(SCENEID::STAGE);
}

void CSceneMgr::Update()
{
	m_pScene->Update();
}

void CSceneMgr::LateUpdate()
{
	m_pScene->LateUpdate();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC, 0, 0);
}

void CSceneMgr::Release()
{
}
