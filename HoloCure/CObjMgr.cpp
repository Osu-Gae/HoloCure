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
			pObj->Render(hDC, _iScrollX, _iScrollY);
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
		Add_Object(OBJ_MONSTER, monster);
	}
	else
	{
		(*it)->Initialize();
		(*it)->Set_Pos(_x, _y);
		dynamic_pointer_cast<CMonster>(*it)->Set_Id(_id);
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
