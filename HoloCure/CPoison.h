#pragma once
#include "CObj.h"
#include "CPngMgr.h"
class CPoison : public CObj
{
public:
	CPoison();
	~CPoison();

public:
	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;

};

