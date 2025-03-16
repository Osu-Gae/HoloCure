#pragma once
#include "CPngMgr.h"
#include "CBmpMgr.h"
class CLevelUpItem
{
public:
	CLevelUpItem();
	~CLevelUpItem();
public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _X, const int& _Y);
	void Release();
	void SetXY(int _x, int _y) { m_tInfo.fX = _x; m_tInfo.fY = _y;  UpdateRect(); }
	void UpdateRect() { m_tRect = { LONG(m_tInfo.fX - m_tInfo.fCX / 2), LONG(m_tInfo.fY - m_tInfo.fCY / 2), LONG(m_tInfo.fX + m_tInfo.fCX / 2), LONG(m_tInfo.fY + m_tInfo.fCY / 2) }; }

	void SetItemId(int _id) { m_iItemId = _id; }
private:
	int m_iItemId;
	int m_ilevel;
	bool m_bMouseUp;
	INFO m_tInfo;
	RECT m_tRect;
};

