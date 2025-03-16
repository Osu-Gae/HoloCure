#pragma once
#include "CObj.h"
#include "CBmpMgr.h"
class CLava : public CObj 
{
public:
	CLava();
	virtual ~CLava();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
private:
	int loop;
};

