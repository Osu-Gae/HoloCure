#pragma once
#include "CLevelUpItem.h"
class CLevelUi
{
public:
	CLevelUi();
	~CLevelUi();
public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void Release();
	void LevelUp();
	void CloseLevelUp() { m_bShow = false; }
	
private:
	void Randomid();
	vector<CLevelUpItem> m_vecLevelUpItem;
	vector<int> m_vecid;
	bool m_bShow;
};

