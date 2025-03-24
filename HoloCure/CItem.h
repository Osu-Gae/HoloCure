#pragma once
#include "CCamera.h"
#include "CObjMgr.h"
#include "CTimeMgr.h"
#include "CBullet.h"
#include "CLava.h"
#include "CBoomerang.h"
#include "BulletAx.h"
#include "CPoison.h"
#include "CSoundMgr.h"
#include "CJirungE.h"
class CItem
{
public:
	CItem();
	~CItem();
public:
	void Initialize();
	void Update();
	void Render(HDC _hDC, int x, int y);
	void LevelUp() { m_ilevel++; }
public:
	void SetItemId(int _id) { m_iItemId = _id;}
	int GetItemId() { return m_iItemId; }
private:
	int m_iItemId;
	int m_ilevel;
	float m_fCoolTime;
};

