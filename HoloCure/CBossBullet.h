#pragma once
#include "CObj.h"
class CBossBullet : public CObj
{
public:
	CBossBullet();
	~CBossBullet();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Set_Angle(const float& _fAngle) { m_fAngle = _fAngle; }
private:
	float m_fLifeTime;
	float m_fAngle;
};

