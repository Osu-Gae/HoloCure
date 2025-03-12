#pragma once
#include "CBmpMgr.h"
class CTimeUi
{
public:
	CTimeUi();
	~CTimeUi();
public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void Release();
public:
	void PlusTime(float _fTime) { m_fTime += _fTime; }
private:
	float m_fTime;
};

