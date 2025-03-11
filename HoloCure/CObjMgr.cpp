#include "pch.h"
#include "CObjMgr.h"
CObjMgr::CObjMgr()
{
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
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->LateUpdate();

			if (m_ObjList[i].empty())
				break;
		}
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
