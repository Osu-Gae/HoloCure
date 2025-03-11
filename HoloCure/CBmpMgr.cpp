#include "pch.h"
#include "CBmpMgr.h"

CBmpMgr* CBmpMgr::m_pInstance = nullptr;

CBmpMgr::CBmpMgr()
{
}

CBmpMgr::~CBmpMgr()
{
	Release();
}

HDC CBmpMgr::Find_Img(const TCHAR* pImgKey)
{
	auto	iter = find_if(m_mapBit.begin(), m_mapBit.end(), tagFinder(pImgKey));

	if (iter == m_mapBit.end())
		return nullptr;

	return iter->second->Get_MemDC();
}

void CBmpMgr::Initialize()
{
	Insert_Bmp(L"../Image/BackBuffer.bmp", L"Back");
	Insert_Bmp(L"../Image/Obj/Ground/G.bmp", L"Ground");
}

void CBmpMgr::Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey)
{
	auto	iter = find_if(m_mapBit.begin(), m_mapBit.end(), tagFinder(pImgKey));

	if (iter == m_mapBit.end())
	{
		CMyBmp* pMyBmp = new CMyBmp;

		pMyBmp->Load_Bmp(pFilePath);

		m_mapBit.insert({ pImgKey, pMyBmp });
	}
}

void CBmpMgr::Release()
{
	for (auto& Pair : m_mapBit)
	{
		Pair.second->Release();
		delete Pair.second;
		Pair.second = nullptr;
	}
	m_mapBit.clear();

}
