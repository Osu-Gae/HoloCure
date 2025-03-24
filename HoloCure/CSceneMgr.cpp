#include "pch.h"
#include "CSceneMgr.h"
#include "CCamera.h"
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
		m_pScene.reset();
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
		CCamera::Get_Instance().ClearXY();
		m_ePreScene = m_eCurScene;
	}
	else
	{
		// ªË¡¶
		m_pScene.reset();
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
		CCamera::Get_Instance().ClearXY();
		m_ePreScene = m_eCurScene;
	}
}

void CSceneMgr::Initialize()
{
	Scene_Change(SCENEID::LOGO);
}

void CSceneMgr::Update()
{
	CCamera::Get_Instance().Update();
	m_pScene->Update();
}

void CSceneMgr::LateUpdate()
{
	m_pScene->LateUpdate();
}

void CSceneMgr::Render(HDC hDC)
{
	CCamera::Get_Instance().Get_ScrollX();
	m_pScene->Render(hDC, CCamera::Get_Instance().Get_ScrollX(), CCamera::Get_Instance().Get_ScrollY());
}

void CSceneMgr::Release()
{
}
