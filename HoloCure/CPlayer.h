#pragma once
#include "CObj.h"
#include "CPngMgr.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
public:
	void Key_Input();
	void Move_Dir();
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
private:
	enum State{RUN, IDLE};
};

