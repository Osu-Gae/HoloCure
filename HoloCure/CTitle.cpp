#include "pch.h"
#include "CTitle.h"
#include "CSoundMgr.h"
CTitle::CTitle()
{
}

CTitle::~CTitle()
{
}

void CTitle::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Title/MainBackGround.bmp", L"MainBackGround");
	CPngMgr::Get_Instance().Insert_Png(L"../Image/Title/MainBackGround.png", L"MainBackGround");
	CPngMgr::Get_Instance().Insert_Png(L"../Image/Title/TitleLogo.png", L"TitleLogo");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Title/TitleLogo1.bmp", L"TitleLogo");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Title/SettingMenu.bmp", L"SettingMenu");
	CSoundMgr::Get_Instance()->PlayBGM(L"Main.wav", SOUND_BGM);
	
}

void CTitle::Update()
{
	if (GetAsyncKeyState('P'))
	{
		CSceneMgr::Get_Instance().Scene_Change(CSceneMgr::SCENEID::STAGE);
	}
}

void CTitle::LateUpdate()
{
}

void CTitle::Render(HDC hDC, int _iScrollX, int _iScrollY)
{
	HDC	hMemDC1 = CBmpMgr::Get_Instance()->Find_Img(L"MainBackGround");
	HDC	hMemDC2 = CBmpMgr::Get_Instance()->Find_Img(L"TitleLogo");
	
	BitBlt(hDC,
		0,
		0,
		WINCX,
		WINCY,
		hMemDC1,
		0, 0,
		SRCCOPY);
	// CPngMgr::Get_Instance().DrawPng(hDC, L"TitleLogo", 307, 0, 615, 259);
	CPngMgr::Get_Instance().DrawPngWithAlpha(hDC, L"TitleLogo", 307, 0, 615, 259, 0.5f);
}

void CTitle::Release()
{
}
