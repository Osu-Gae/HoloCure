#pragma once
#include "CBmpMgr.h"
class CKillUi
{
public:
	CKillUi();
	~CKillUi();
public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void Release();
public:
	void UpKillCount() { m_iKillCount++; }
	int GetKillCount() { return m_iKillCount; }
private:
	int m_iKillCount;
};

