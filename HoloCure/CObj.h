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
	void Set_Plus_Pos(const float& _fX, const float _fY)
	{
		m_tInfo.fX += _fX;
		m_tInfo.fY += _fY;
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
	const float& Get_Radius()
	{
		return m_fRadius;
	}
	const int& Get_HP()
	{
		return m_iHp;
	}
	void Set_HP(const int& _damage)
	{
		m_iHp -= _damage;
	}
	const float& Get_InvisibleTime()
	{
		return m_fInvincibleTime;
	}
	void Set_InvisibleTime(const float& _time)
	{
		m_fInvincibleTime = _time;
	}
	const int& Get_Attack()
	{
		return m_iAttack;
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

	int				m_iHp;
	int				m_iMaxHp;
	int				m_iAttack;
	// 무적 시간
	float			m_fInvincibleTime;
};

