#pragma once
#include "CItem.h"
// ������ CItem�� �ڽ��� Bullet�� ����
// Bullet�� ���� �ð����� �������� ���� 
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

