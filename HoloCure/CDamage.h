#pragma once
#include "CObj.h"
#include "CBmpMgr.h"
class CDamage : public CObj
{
public:
	CDamage();
	~CDamage();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Set_Damage(const int& _damage) { m_idamageVal = _damage; }
private:
	int m_idamageVal;
	float m_flifeTime;
};

