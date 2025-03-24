#pragma once
#include "CObj.h"
#include "CBmpMgr.h"
class CFanDie : public CObj
{
public:
	CFanDie();
	~CFanDie();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
};

