#include "pch.h"
#include "CColliderMgr.h"

void CColliderMgr::Collision_Circle(list<shared_ptr<CObj>> DstList, list<shared_ptr<CObj>> SrcList)
{
	for (auto& pDst : DstList)
	{
		for (auto& pSrc : SrcList)
		{
			if (Check_Collison(pDst, pSrc) && pDst->Get_InvisibleTime() < 0)
			{
				pDst->Set_HP(pSrc->Get_Attack());
				pDst->Set_InvisibleTime(0.15f);
			}
		}
	}
}

void CColliderMgr::Collision_Monster(list<shared_ptr<CObj>>& DstList)
{
	for (auto& pDst : DstList)
	{
		for (auto& pSrc : DstList)
		{
			if (pDst == pSrc)
				continue;
			if (Check_Collison(pDst, pSrc))
			{
				// ���� �о 
				float x = pDst->Get_Pos_x() - pSrc->Get_Pos_x(); // ������ Dst�� ������ // ������� �ݴ�
				float y = pDst->Get_Pos_y() - pSrc->Get_Pos_y();

				// normalize
				float dis = sqrtf(x * x + y * y);
				x /= dis;
				y /= dis;
				pDst->Set_Plus_Pos(x * 5, y * 5);
				pSrc->Set_Plus_Pos(-x * 5, -y * 5);
			}
		}
	}
}

bool CColliderMgr::Check_Collison(shared_ptr<CObj> Dst, shared_ptr<CObj> Src)
{
	float	fRadius = Dst->Get_Radius() + Src->Get_Radius();

	// fabsf : ���� ���� ������ִ� �Լ�

	float	fWidth = fabsf(Dst->Get_Pos_x() - Src->Get_Pos_x());
	float	fHeight = fabsf(Dst->Get_Pos_y() - Src->Get_Pos_y());

	// sqrt : ��Ʈ�� �����ִ� �Լ�
	float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	return fRadius >= fDiagonal;
}


