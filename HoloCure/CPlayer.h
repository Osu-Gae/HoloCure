#pragma once
#include "CObj.h"
#include "CPngMgr.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CBmpMgr.h"
#include "CUiMgr.h"
#include "CItem.h"
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
	
public:
	enum ItemType {
		Active,
		Passive
	};
	void Push_Item(CItem _item , ItemType _type);

private:
	enum State{RUN, IDLE};
	vector<CItem> m_vecActiveItem;
	vector<CItem> m_vecPassiveItem;
};

