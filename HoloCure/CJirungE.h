#pragma once
#include "CObj.h"
#include "CBmpMgr.h"
class CJirungE : public CObj
{
public:
	CJirungE();
	~CJirungE();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void Set_Speed(float _fSpeed) { m_fSpeed = _fSpeed; }
private:
	POINT		m_tPoint[3];
	float m_fAngle;
	float m_fDeathTime;
};

