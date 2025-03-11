#pragma once
class CCamera
{
public:
	CCamera();
	~CCamera();
public:
	static CCamera& Get_Instance()
	{
		static CCamera m_pInstance;
		return m_pInstance;
	}


public:
	const float&		Get_ScrollX() { return m_fScrollX; } const
	const float&		Get_ScrollY() { return m_fScrollY; } const 

	void		Set_ScrollX(const float& fX) { m_fScrollX = fX; }
	void		Set_ScrollY(const float& fY) { m_fScrollY = fY; }

	void		ClearXY() { m_fScrollX = 0.f; m_fScrollY = 0.f; }
public:
	void Update();
private:

	float			m_fScrollX;
	float			m_fScrollY;

};

