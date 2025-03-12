#include "pch.h"
#include "CTileMgr.h"
#include "CCamera.h"
CTileMgr::CTileMgr()
{
}

CTileMgr::~CTileMgr()
{
}

void CTileMgr::Initialize()
{
	for(int i=0;i<16;i++)
		for (int j = 0; j < 16; j++)
		{
			shared_ptr<CTile> tile = make_shared<CTile>(i, j);
			tile->Initialize();
			m_vecTile.push_back(tile);
		}
}

void CTileMgr::Update()
{
	int offsetX = Playerx / 160; 
	int offsetY = Playery / 160;

	// 플레이어하고 6칸 떨어지면 맵 16만큼 이동
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			shared_ptr<CTile> tile = dynamic_pointer_cast<CTile>(m_vecTile[i * 16 + j]);
			int x = tile->Get_XPos();
			int y = tile->Get_YPos();

			if (x > offsetX + 6)
				tile->Set_XYPos(x - 16, y);
			else if (x < offsetX - 6)
				tile->Set_XYPos(x + 16, y);
			if (y > offsetY + 6)
				tile->Set_XYPos(x, y - 16);
			else if (y < offsetY - 6)
				tile->Set_XYPos(x, y + 16);
		
		}
	}
}

void CTileMgr::LateUpdate()
{
}

void CTileMgr::Render(HDC hDC ,const int& _iScrollX, const int& _iScrollY)
{
	int	iScrollX = -(int)CCamera::Get_Instance().Get_ScrollX() / 160-2;
	int	iScrollY = -(int)CCamera::Get_Instance().Get_ScrollY() / 160-2;

	int	 iMaxX = iScrollX + WINCX / 160 + 3;
	int	 iMaxY = iScrollY + WINCY / 160 + 3;
	for (int i = 0;i<16;i++)
	{
		for (int j = 0; j < 16; j++)
		{
			shared_ptr<CTile> tile = dynamic_pointer_cast<CTile>(m_vecTile[i * 16 + j]);
			int x = tile->Get_XPos();
			int y = tile->Get_YPos();
			if (x >= iScrollX && x <= iMaxX && y >= iScrollY && y <= iMaxY)
			{
				tile->Render(hDC, _iScrollX, _iScrollY);
			}
		}
		

	}
	// m_vecTile[0]->Render(hDC, _iScrollX, _iScrollY);
	// CPngMgr::Get_Instance().DrawPng(hDC, L"Ground", 0, 0, 2560, 2560);
	//CPngMgr::Get_Instance().DrawPngPart(hDC, L"Ground", _iScrollX, _iScrollY, 2560, 2560, 0, 0, 2560, 2560);
}

void CTileMgr::Release()
{
}

