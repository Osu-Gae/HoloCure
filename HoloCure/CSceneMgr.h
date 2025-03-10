#pragma once
#include "CScene.h"
#include "CLogo.h"
#include "CTitle.h"
#include "CStage.h"
class CSceneMgr
{
public:
	enum SCENEID { LOGO, TITLE, STAGE, END };
private:
	CSceneMgr();
	~CSceneMgr();
public:
	void		Scene_Change(SCENEID eScene);
	void		Initialize();
	void		Update();
	void		LateUpdate();
	void		Render(HDC hDC);
	void		Release();
public:
	static CSceneMgr& Get_Instance()
	{
		static CSceneMgr Instance;
		return Instance;
	}
private:
	shared_ptr<CScene>		m_pScene;
	SCENEID					m_eCurScene;
	SCENEID					m_ePreScene;
};

