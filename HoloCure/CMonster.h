#pragma once
#include "CObj.h"
#include "CObjMgr.h"
#include "CBmpMgr.h"

class CMonster : public CObj
{
public:
	CMonster();
	virtual ~CMonster();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Set_Damaged()
	{
		m_bDamaged = true;
		m_bDamagedCount = 10;
	}
public:
	void Set_Id(int n)  
	{
		m_tFrame.iMotion = n;
	}
private:
	bool m_bDamaged;
	int m_bDamagedCount;
};

