#include "pch.h"
#include "CUiMgr.h"
CUiMgr* CUiMgr::m_pInstance = nullptr;

CUiMgr::CUiMgr()
{
	m_ExpBar.Initialize();
}

CUiMgr::~CUiMgr()
{
}

void CUiMgr::Update()
{
	m_ExpBar.Update();
	m_PlayerUi.Update(); // 추후 삭제 예정
	m_TimeUi.PlusTime(0.01); // 추수 변경 예정 
	m_LevelUi.Update();
}

void CUiMgr::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	m_ExpBar.Render(hDC, _iScrollX, _iScrollY);
	m_PlayerUi.Render(hDC, _iScrollX, _iScrollY);
	m_TimeUi.Render(hDC, _iScrollX, _iScrollY);
	m_KillUi.Render(hDC, _iScrollX, _iScrollY);
	m_LevelUi.Render(hDC, _iScrollX, _iScrollY);
}
