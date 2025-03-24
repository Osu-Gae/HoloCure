#include "pch.h"
#include "CObjMgr.h"
CObjMgr::CObjMgr() 
{
	m_MonsterList.resize(100);
	auto it = m_MonsterList.begin();
	for (size_t i = 0; i < 100; ++i)
	{
		*it = make_shared<CMonster>();
		(*it)->Set_Dead(true);
		++it;
	}
	m_ExpList.resize(100);
	auto it1 = m_ExpList.begin();
	for (size_t i = 0; i < 100; ++i)
	{
		*it1 = make_shared<CExp>();
		(*it1)->Set_Dead(true);
		++it1;
	}
	m_DamageList.resize(300);
	auto it2 = m_DamageList.begin();
	for (size_t i = 0; i < 300; i++)
	{
		(*it2) = make_shared<CDamage>();
		it2++;
	}
	m_BossBulletList.resize(100);
	auto it3 = m_BossBulletList.begin();
	for (size_t i = 0; i < 100; i++)
	{
		(*it3) = make_shared<CBossBullet>();
		it3++;
	}
	m_FanDieList.resize(100);
	auto it4 = m_FanDieList.begin();
	for (auto i = 0; i < 100; i++)
	{
		(*it4) = make_shared<CFanDie>();
		it4++;
	}
}

CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Add_Object(OBJID eID, shared_ptr<CObj> pObj)
{
	if (OBJ_END <= eID || nullptr == pObj)
		return;

	m_ObjList[eID].push_back(pObj);
}

void CObjMgr::Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); )
		{
			(*iter)->Update();
			++iter;
			// 삭제 코드 
		}
	}
}

void CObjMgr::Late_Update()
{
	CColliderMgr::Collision_Monster(m_ObjList[OBJ_MONSTER]);
	CColliderMgr::Collision_Circle(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_MONSTER]);
	CColliderMgr::Collision_Circle(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_BOSSBULLET]);
	CColliderMgr::Collision_Monster_Circle(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET]);
	CColliderMgr::Collision_Exp(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_EXP]);
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->LateUpdate();
		}
	}
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		m_ObjList[i].remove_if([](shared_ptr<CObj> a) {return a->Get_Dead(); });
	}
}

void CObjMgr::Render(HDC hDC, const int& _iScrollX, const int& _iScrollY)
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			float distance = sqrtf(powf(pObj->Get_Pos_x() - Playerx, 2) + powf(pObj->Get_Pos_y()- Playery, 2));
			if (distance > 1000)
				continue;
			pObj->Render(hDC, _iScrollX, _iScrollY);
		}
	}
}

void CObjMgr::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		m_ObjList[i].clear();
	}
}

void CObjMgr::Delete_Obj(OBJID eID)
{
	m_ObjList[eID].clear();
}

void CObjMgr::Spawn_Monster(int _id, int _x, int _y)
{
	auto it = find_if(m_MonsterList.begin(), m_MonsterList.end(), [](shared_ptr<CObj> a) {return a->Get_Dead(); });
	if (it == m_MonsterList.end())
	{
		shared_ptr<CMonster> monster = make_shared<CMonster>();
		monster->Initialize();
		monster->Set_Pos(_x, _y);
		monster->Set_Id(_id);
		monster->Set_Exp(20 - _id/3);
		Add_Object(OBJ_MONSTER, monster);
	}
	else
	{
		(*it)->Initialize();
		(*it)->Set_Pos(_x, _y);
		dynamic_pointer_cast<CMonster>(*it)->Set_Id(_id);
		(*it)->Set_Exp(20 - _id / 3);
		Add_Object(OBJ_MONSTER, *it);
	}
}

void CObjMgr::Spawn_Exp(int _exp, int _x, int _y)
{
	auto it = find_if(m_ExpList.begin(), m_ExpList.end(), [](shared_ptr<CExp> a) {return a->Get_Dead(); });
	if (it == m_ExpList.end())
	{
		shared_ptr<CExp> exp = make_shared<CExp>();
		exp->Initialize();
		exp->Set_Pos(_x, _y);
		exp->Set_Exp(_exp);
		Add_Object(OBJ_EXP, exp);
	}
	else
	{
		(*it)->Initialize();
		(*it)->Set_Pos(_x, _y);
		(*it)->Set_Exp(_exp);
		Add_Object(OBJ_EXP, *it);
	}
}

void CObjMgr::Spawn_Damage(int _damage, int _x, int _y)
{
	auto it = find_if(m_DamageList.begin(), m_DamageList.end(), [](shared_ptr<CDamage> a) {return a->Get_Dead(); });
	if (it == m_DamageList.end())
	{
		shared_ptr<CDamage> damage = make_shared<CDamage>();
		damage->Initialize();
		damage->Set_Pos(_x, _y);
		dynamic_pointer_cast<CDamage>(damage)->Set_Damage(_damage);
		Add_Object(OBJ_DMG, damage);
	}
	else
	{
		(*it)->Initialize();
		(*it)->Set_Pos(_x, _y);
		dynamic_pointer_cast<CDamage>(*it)->Set_Damage(_damage);
		Add_Object(OBJ_DMG, *it);
	}
}

void CObjMgr::Spawn_BossBullet(int _x, int _y, int _angle)
{
	auto it = find_if(m_BossBulletList.begin(), m_BossBulletList.end(), [](shared_ptr<CBossBullet> a) {return a->Get_Dead(); });
	if(it == m_BossBulletList.end())
	{
		shared_ptr<CBossBullet> bullet = make_shared<CBossBullet>();
		bullet->Initialize();
		bullet->Set_Pos(_x, _y);
		bullet->Set_Angle(_angle);
		Add_Object(OBJ_BOSSBULLET, bullet);
	}
	else
	{
		(*it)->Initialize();
		(*it)->Set_Pos(_x, _y);
		dynamic_pointer_cast<CBossBullet>(*it)->Set_Angle(_angle);
		Add_Object(OBJ_BOSSBULLET, *it);
	}
}

void CObjMgr::Spawn_FanDie(int _x, int _y)
{
	auto it = find_if(m_FanDieList.begin(),m_FanDieList.end(), [](shared_ptr<CFanDie> a) {return a->Get_Dead(); });
	if (it == m_FanDieList.end())
	{
		shared_ptr<CFanDie> fanDie = make_shared<CFanDie>();
		fanDie->Initialize();
		fanDie->Set_Pos(_x, _y);
		Add_Object(OBJ_FANDIE, fanDie);
	}
	else
	{
		(*it)->Initialize();
		(*it)->Set_Pos(_x, _y);
		Add_Object(OBJ_FANDIE, *it);
	}
}

