#pragma once

#include "CObj.h"
#include "CColliderMgr.h"
class CObjMgr
{
private:
	CObjMgr();
	CObjMgr(const CObjMgr& rhs) = delete;		// 아예 삭제하여 호출 불가
	CObjMgr& operator=(CObjMgr& rObj) = delete;
	~CObjMgr();

public:
	shared_ptr<CObj> Get_ObjBack(OBJID eID) { return m_ObjList[eID].back(); }

public:
	void		Add_Object(OBJID eID, shared_ptr<CObj> pObj = nullptr);
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC, const int& _iScrollX, const int& _iScrollY);
	void		Release();
	void		Delete_Obj(OBJID eID);


public:
	static CObjMgr& Get_Instance()
	{
		static CObjMgr Instance;
		return Instance;
	}


private:
	list<shared_ptr<CObj>>			m_ObjList[OBJ_END];


};

