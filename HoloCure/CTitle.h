#pragma once
#include "CScene.h"
#include "CBmpMgr.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CPngMgr.h"
#include "CStartButton.h"

class CTitle : public CScene
{
public:
	CTitle();
	virtual ~CTitle();
public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hDC, int _iScrollX, int _iScrollY) override;
	virtual void Release() override;
private:
	CStartButton button;
};

