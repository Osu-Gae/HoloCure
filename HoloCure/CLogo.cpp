#include "pch.h"
#include "CLogo.h"

CLogo::CLogo()
{
}

CLogo::~CLogo()
{
}

void CLogo::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Logo/Logo.bmp", L"Logo");
}

void CLogo::Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance().Scene_Change(CSceneMgr::SCENEID::TITLE);
		return;
	}
}

void CLogo::LateUpdate()
{
}

void CLogo::Render(HDC hDC, int _iScrollX, int _iScrollY)
{
	HDC	hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Logo");

	BitBlt(hDC,
		0,
		0,
		WINCX,
		WINCY,
		hMemDC,
		0, 0,
		SRCCOPY);
}

void CLogo::Release()
{
}
