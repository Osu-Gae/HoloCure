#pragma once
#include "CPngMgr.h"
#include "CTimeMgr.h"
#include "CEndButton.h"
class CEndCsene
{
public:
	CEndCsene();
	~CEndCsene();
public:
	void Initialize();
	void Update();
	void Render(HDC _hDC);
private:
	enum {BLACK, COMPLETE, END};
	int m_iState = BLACK;
	float m_fAlpha = 0.f;
	float m_fTime = 0.f;
	int completex = 580;
	int completey = -50;
	bool m_buttenShow = false;
	CEndButton button1, button2;
	int m_iScore = 0;
};

