#pragma once
#include "CObj.h"
#include "CPngMgr.h"
#include "CBmpMgr.h"
class CExpBar
{
public:
	CExpBar();
	~CExpBar();
public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void Release();
public:
	int GetExp() { return m_iExp; }
	void SetExp(int _iExp) { m_iExp = _iExp; }
private:
	int m_iExp;
	int m_iMaxExp;
	int frame;
};

