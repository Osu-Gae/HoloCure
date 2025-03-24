#pragma once
#include "CObj.h"
#include "CUiMgr.h"
#include "CObjMgr.h"
#include "CMonster.h"
#include "CSoundMgr.h"
class CFubukiBullet : public CObj
{
public:
	CFubukiBullet() : fubukiAttack(false) , m_bReverse(false){}
	~CFubukiBullet() {}
public:
	void Initialize() 
	{
		m_tInfo = { 0,0,1864,204};
		m_tFrame = { 0, 31, 0, CTimeMgr::GetInstance().GetTime(), 0.05 };
	}
	void Update() 
	{
	}
	void LateUpdate() 
	{ 
		Move_Frame();
		Update_Rect(); 
	}
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) 
	{
		if (m_bReverse)
		{
			GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
				m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Laser_Rev"),
				m_tFrame.iStart * m_tInfo.fCX, 0,
				m_tInfo.fCX, m_tInfo.fCY,
				RGB(36, 74, 53));
	
		}
		else
		{
			GdiTransparentBlt(hDC, m_tRect.left + _iScrollX,
				m_tRect.top + _iScrollY, m_tInfo.fCX, m_tInfo.fCY, CBmpMgr::Get_Instance()->Find_Img(L"Laser"),
				m_tFrame.iStart * m_tInfo.fCX, 0,
				m_tInfo.fCX, m_tInfo.fCY,
				RGB(36, 74, 53));
		}
		if(m_tFrame.iStart == 31)
		{
			fubukiAttack = false;
			m_tFrame.iStart = 0;
		}
	}
	void Release() 
	{
		
	}
	void Po(const int& _iX, const int& _iY) 
	{ 
		m_tInfo.fY = _iY;
		if (m_bReverse)
		{
			m_tInfo.fX = _iX - 1100;
		}
		else
		{
			m_tInfo.fX = _iX + 1100;
		}
	}
public:
	bool fubukiAttack;
	bool m_bReverse;
};

class CFubuki : public CMonster
{
public:
	CFubuki();
	~CFubuki();
public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release();
private:
	CFubukiBullet m_FubukiBullet;
	float m_fAttackTime;
	bool m_bReverse;
	float m_fSpawnScene = 5.f;
	int spawnx = 1380;
};

