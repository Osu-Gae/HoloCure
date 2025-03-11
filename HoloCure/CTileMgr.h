#pragma once
#include "CObj.h"
#include "CTile.h"
class CTileMgr
{
private:
	CTileMgr();
	~CTileMgr();

public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void Release();

public:
	static CTileMgr& Get_Instance()
	{
		static CTileMgr m_pInstance;
		return m_pInstance;
	}

private:

	vector<shared_ptr<CObj>> m_vecTile;
};
