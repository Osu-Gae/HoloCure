#pragma once

#include "CObj.h"
#include "CColliderMgr.h"
#include "CMonster.h"
#include "CExp.h"
#include "CDamage.h"
#include "CBossBullet.h"
#include "CFanDie.h"
class CObjMgr
{
private:
	CObjMgr();
	CObjMgr(const CObjMgr& rhs) = delete;		// 아예 삭제하여 호출 불가
	CObjMgr& operator=(CObjMgr& rObj) = delete;
	~CObjMgr();

public:
	shared_ptr<CObj> Get_Player() { return m_ObjList[OBJ_PLAYER].back(); }
	list<shared_ptr<CObj>> Get_List(OBJID _id)
	{
		return m_ObjList[_id];
	}

public:
	void		Add_Object(OBJID eID, shared_ptr<CObj> pObj = nullptr);
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void		Release();
	void		Delete_Obj(OBJID eID);
	void		Spawn_Monster(int _id, int _x, int _y );
	void		Spawn_Exp(int _exp, int _x, int _y);
	void		Spawn_Damage(int _damage, int _x, int _y);
	void		Spawn_BossBullet(int _x, int _y, int _angle);
	void		Spawn_FanDie(int _x, int _y);
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

	void Set_Stop() { TimeStop = true; }
	void Release_Stop() { TimeStop = false; }
	bool Get_TimeStop() {
		return TimeStop;
	}
private:
	list<shared_ptr<CObj>>			m_ObjList[OBJ_END];
	
	// 오브젝트 풀
	list<shared_ptr<CObj>>		m_MonsterList;
	list<shared_ptr<CExp>>          m_ExpList;
	list<shared_ptr<CDamage>>			m_DamageList;
	list<shared_ptr< CBossBullet>> m_BossBulletList;
	list<shared_ptr<CFanDie>> m_FanDieList;

	bool TimeStop = false;


};

