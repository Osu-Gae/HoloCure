#pragma once
#include "CObj.h"
#include "CPngMgr.h"


class CStartButton : public CObj
{
public:
	CStartButton();
	~CStartButton();
public:
	void Update();
	void Render(HDC _hDC);
private:
	bool m_bIsMouseUp;

	// CObj을(를) 통해 상속됨
	void Initialize() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
};

