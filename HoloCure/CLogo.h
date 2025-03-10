#pragma once
#include "CScene.h"
#include "CBmpMgr.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"
class CLogo : public CScene
{
public:
	CLogo();
	virtual ~CLogo();

public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, int _iScrollX, int _iScrollY) override;
	void Release() override;

};