#include "pch.h"
#include "CItemMgr.h"
CItemMgr* CItemMgr::m_pInstance = nullptr;

void CItemMgr::Initialize()
{
}

void CItemMgr::Update()
{
	for (int i = 0; i < m_vecAttackItem.size(); i++)
	{
		m_vecAttackItem[i]->Update();
	}
}

void CItemMgr::Render(HDC _hDc)
{
	for (int i = 0; i < m_vecAttackItem.size(); i++)
	{
		// m_vecAttackItem[i]->Render(_hDc, x, ,y);
	}
	for (int i = 0; i < m_vecAttackItem.size(); i++)
	{

	}
}
