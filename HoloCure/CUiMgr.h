#pragma once
#include "CCamera.h"
#include "CExpBar.h"
#include "CPlayerUi.h"
#include "CTimeUi.h"
#include "CKillUi.h"
#include "CLevelUi.h"
class CUiMgr
{
private:
	CUiMgr();
	~CUiMgr();
public:
	static CUiMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CUiMgr;
		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
	void Update(); // 애니메이션 용
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);

public:
	static CUiMgr* m_pInstance;
	CExpBar m_ExpBar;
	CPlayerUi m_PlayerUi;
	CTimeUi m_TimeUi;
	CKillUi m_KillUi;
	CLevelUi m_LevelUi;
	// exp_bar
	// Hp_bar
	// Kill_count
	// Timer_Count
	// Level
};

