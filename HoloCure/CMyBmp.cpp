#include "pch.h"
#include "CMyBmp.h"

CMyBmp::CMyBmp()
{
}

CMyBmp::~CMyBmp()
{
	Release();
}

void CMyBmp::Load_Bmp(const TCHAR* pFilePath)
{
	HDC	hDC = GetDC(g_hWnd);

	m_hMemDC = CreateCompatibleDC(hDC);

	ReleaseDC(g_hWnd, hDC);

	m_hBitmap = (HBITMAP)LoadImage(NULL,		// ���α׷� �ν��Ͻ� �ڵ�
		pFilePath,	// ������ ���
		IMAGE_BITMAP, // � Ÿ��
		0, 0,		// ����, ���� ũ��(���Ϸκ��� �о���̱� ������ ���� ������ ������ ���� ����)
		LR_LOADFROMFILE | LR_CREATEDIBSECTION); // LR_LOADFROMFILE : ���Ͽ��� �̹��� �θ���
	// LR_CREATEDIBSECTION : �о�� ������ DIB ���·� ��ȯ

// SelectObject �غ��� DC��  GDI ������Ʈ�� �ҷ��� ��Ʈ���� �����ϱ� ���� ���
//	GDI ������Ʈ�� �����ϱ� ���� ������ ������ �ִ� GDI ������Ʈ�� ��ȯ

	m_hOldbmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);

}

void CMyBmp::Release()
{
	SelectObject(m_hMemDC, m_hOldbmp);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hMemDC);
}
