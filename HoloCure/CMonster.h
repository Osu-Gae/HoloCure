#pragma once
#include "CObj.h"
#include "CPngMgr.h"
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
public:
	void Set_Id(int n) // max 38 ���ֿ� �߰� �E���� 
	{
		m_tFrame.iMotion = n;
	}
};

