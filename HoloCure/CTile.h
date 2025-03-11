#pragma once
#include "CObj.h"
#include "CCamera.h"
#include "CPngMgr.h"
class CTile : public CObj
{
public:
	CTile(int x , int y);
	virtual ~CTile();

public:

	// CObj��(��) ���� ��ӵ�
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Set_XYPos(int x, int y) { m_iXPos = x; m_iYPos = y; }
	const int& Get_XPos() {return  m_iXPos; }
	const int& Get_YPos() { return m_iYPos; }

private:
	int		m_iXPos;
	int		m_iYPos;
};