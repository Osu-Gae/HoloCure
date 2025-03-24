#pragma once
#include "CObj.h"
class CEndButton : public CObj
{ 
public:
	CEndButton();
	~CEndButton();
public:

	// CObj을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	int Update1();
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Set_id() { id = 1; }
public:
	int id = 0;
private:
	bool m_bIsMouseUp = false;
};

