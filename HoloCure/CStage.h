#pragma once
#include "CScene.h"
#include "CBmpMgr.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CObjMgr.h"
#include "CPlayer.h"
#include "CPngMgr.h"
#include "CMonster.h"
class CStage : public CScene
{
public:
	CStage();
	virtual ~CStage();
public:
	// CScene��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, int _iScrollX, int _iScrollY) override;
	void Release() override;
};

