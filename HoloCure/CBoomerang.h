#pragma once
#include "CObj.h"
class CBoomerang : public CObj
{
public:
	CBoomerang();
	virtual ~CBoomerang();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
private:
	float 	m_fAngle;
	float m_fDeathTime;
};

