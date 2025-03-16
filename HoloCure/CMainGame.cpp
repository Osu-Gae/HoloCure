#include "pch.h"
#include "CMainGame.h"
#include "CSceneMgr.h"
#include "CBmpMgr.h"
#include "CSoundMgr.h"
CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);
	CSoundMgr::Get_Instance()->Initialize();
	CBmpMgr::Get_Instance()->Initialize();
	CSceneMgr::Get_Instance().Initialize();
}

void CMainGame::Update()
{
	CSceneMgr::Get_Instance().Update();
}

void CMainGame::LateUpdate()
{
	CSceneMgr::Get_Instance().LateUpdate();
}

void CMainGame::Render()
{
	HDC hMemDC = CreateCompatibleDC(m_hDC);
	HBITMAP hMemBitmap = CreateCompatibleBitmap(m_hDC, WINCX, WINCY);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hMemBitmap);

	HDC hBackDC = CBmpMgr::Get_Instance()->Find_Img(L"Back");


	// �� ���ۿ� ��� ������
	BitBlt(hMemDC, 0, 0, WINCX, WINCY, hBackDC, 0, 0, SRCCOPY);


	// ���� �� ������
	CSceneMgr::Get_Instance().Render(hMemDC);

	// ���������� �� ������ ������ ȭ������ ����
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	// GDI ���ҽ� ����
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hMemBitmap);
	DeleteDC(hMemDC);
}

void CMainGame::Release()
{
	CSoundMgr::Get_Instance()->Release();
}
