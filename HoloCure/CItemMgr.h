#pragma once
#include "CItem.h"
// 각각의 CItem이 자신의 Bullet을 생성
// Bullet은 일정 시간마다 데미지를 입힘 
class CItemMgr
{
private:
	CItemMgr() = default;
	~CItemMgr()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
public:
	static CItemMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CItemMgr;

		return m_pInstance;
	}

	static void		Destroy_Instance()
	{
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	void Initialize();
	void Update();
	void Render(HDC _hDc);


private:
	static CItemMgr* m_pInstance;
	vector<shared_ptr<CItem>> m_vecAttackItem;
	vector<shared_ptr<CItem>> m_vecShildItem;
};

