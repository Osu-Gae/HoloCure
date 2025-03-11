#pragma once
#include "CTimeMgr.h"
class CObj
{
public:
	CObj();
	~CObj();
public:
	void Set_Pos(const float& _fX, const float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	const float& Get_Pos_x()
	{
		return m_tInfo.fX;
	}
	const float& Get_Pos_y()
	{
		return m_tInfo.fY;
	}
	const RECT& Get_Rect()
	{
		return m_tRect;
	}
	const INFO& Get_Pos()
	{
		return m_tInfo;
	}
	void Update_Rect();
	void Move_Frame();
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;	
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) = 0;
	virtual void Release() = 0;
protected:
	INFO			m_tInfo;
	RECT			m_tRect;   // 이미지용
	FRAME			m_tFrame;
	float			m_fSpeed;
	float			m_fRadius; // 히트박스
	bool            m_bDead;
	bool			m_bReverse;
};

