#pragma once

#include "CObj.h"
#include "CColliderMgr.h"
#include "CMonster.h"
#include "CExp.h"
class CObjMgr
{
private:
	CObjMgr();
	CObjMgr(const CObjMgr& rhs) = delete;		// 아예 삭제하여 호출 불가
	CObjMgr& operator=(CObjMgr& rObj) = delete;
	~CObjMgr();

public:
	shared_ptr<CObj> Get_Player() { return m_ObjList[OBJ_PLAYER].back(); }

public:
	void		Add_Object(OBJID eID, shared_ptr<CObj> pObj = nullptr);
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void		Release();
	void		Delete_Obj(OBJID eID);
	void		Spawn_Monster(int _id, int _x, int _y );
	void		Spawn_Exp(int _exp, int _x, int _y);
	void		Clear_Bullet()
	{
		m_ObjList[OBJ_BULLET].clear();
	}
public:
	static CObjMgr& Get_Instance()
	{
		static CObjMgr Instance;
		return Instance;
	}


private:
	list<shared_ptr<CObj>>			m_ObjList[OBJ_END];
	
	// 오브젝트 풀
	list<shared_ptr<CObj>>		m_MonsterList;
	list<shared_ptr<CExp>>          m_ExpList;


};

