#pragma once
class CKeyMgr
{
private:
	CKeyMgr();
	~CKeyMgr();

public:
	bool	Key_Pressing(int _iKey);
	bool	Key_Down(int _iKey);
	bool	Key_Up(int _iKey);

	void	Late_Update();

public:
	static CKeyMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CKeyMgr;

		return m_pInstance;
	}

	static void		Destroy_Instance()
	{
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CKeyMgr* m_pInstance;
	bool			m_bKeyState[VK_MAX];

};

