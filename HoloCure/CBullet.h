#pragma once
#include "CObj.h"
#include "CBmpMgr.h"
#include "CCamera.h"
#include "CTimeMgr.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
private:
	POINT		m_tPoint[3];
	float 	m_fAngle;
};

