#pragma once
#include "CObj.h"
#include "CMonster.h"
class CColliderMgr
{
public:
	static void Collision_Circle(list<shared_ptr<CObj>> DstList , list<shared_ptr<CObj>> SrcList); //플레이어 충돌 용 
	static void Collision_Monster_Circle(list<shared_ptr<CObj>> DstList, list<shared_ptr<CObj>> SrcList); // 몬스터 충돌 용
	static void Collision_Monster(list<shared_ptr<CObj>>& DstList);
	static void Collision_Exp(list<shared_ptr<CObj>> DstList, list<shared_ptr<CObj>> SrcList);
	static bool Check_Collison(shared_ptr<CObj> Dst , shared_ptr<CObj> Src);
};

