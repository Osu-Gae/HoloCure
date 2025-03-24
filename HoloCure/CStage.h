#pragma once
#include "CScene.h"
#include "CBmpMgr.h"
#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CObjMgr.h"
#include "CPlayer.h"
#include "CPngMgr.h"
#include "CMonster.h"
#include "CTileMgr.h"
#include "CUiMgr.h"
#include "CPoison.h"
#include "CLava.h"
#include "CBullet.h"
#include "CBullet.h"
#include "CCamera.h"
#include "CBoomerang.h"
#include "CFubuki.h"
#include "CBaelz.h"
#include "CEndCsene.h"
class CStage : public CScene
{
public:
	CStage();
	virtual ~CStage();
public:
	// CScene을(를) 통해 상속됨
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, int _iScrollX, int _iScrollY) override;
	void Release() override;
// 테스트용 삭제 예정
public:
	void SetEnd() { end = true; }
private:
	CEndCsene endCsene;
	bool end = false;
};

