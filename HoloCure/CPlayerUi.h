#pragma once
#include "CBmpMgr.h"
#include "CPngMgr.h"
class CPlayerUi
{
public:
	CPlayerUi();
	~CPlayerUi();
public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void Release();
public:
	void SetHp(int _iHp) { m_iHp = _iHp; }
	void SetHpMax(int _iMaxHp) { m_iMaxHp = _iMaxHp; }
public:
	int m_iHp;
	int m_iMaxHp;
};

