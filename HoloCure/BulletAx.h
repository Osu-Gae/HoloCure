#pragma once
#include "CBmpMgr.h"
#include "CObj.h"
#include "CTimeMgr.h"
class BulletAx : public CObj
{
public:
	BulletAx();
	~BulletAx();
public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release();
	void Set_XY(int _x, int _y)
	{
		m_iInit_x = _x;
		m_iInit_y = _y;
	}
private:
	double theta = PI;  // 9�� ���� (180��)
	double a = 20.0;     // �ʱ� �ݰ� ũ��
	double b = 0.15;     // �ݰ� ������
	double speed = 0.10; // ȸ�� �ӵ�
	int m_iInit_x, m_iInit_y;
	float m_fDeathTime;

};

