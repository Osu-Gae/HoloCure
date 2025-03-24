#pragma once
class CSpawnMgr
{
public:
	CSpawnMgr();
	~CSpawnMgr();
	static CSpawnMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CSpawnMgr;

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
public:
	void Update();
private:
	float m_fTime = 0.f;
	static CSpawnMgr* m_pInstance;
	int state = S;
private:
	enum {
		S,F,B,E
	};
};

