#pragma once
#include "CObj.h"
#include "CPngMgr.h"
class CPoison : public CObj
{
public:
	CPoison();
	~CPoison();

public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;

};

