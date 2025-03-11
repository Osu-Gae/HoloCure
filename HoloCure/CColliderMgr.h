#pragma once
#include "CObj.h"
class CColliderMgr
{
public:
	static void Collision_Circle(list<shared_ptr<CObj>> DstList , list<shared_ptr<CObj>> SrcList); //플레이어 충돌 용 
	static void Collision_Monster(list<shared_ptr<CObj>>& DstList);
	static bool Check_Collison(shared_ptr<CObj> Dst , shared_ptr<CObj> Src);
};

