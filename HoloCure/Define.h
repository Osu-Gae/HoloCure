#pragma once

#define WINCX 1280
#define WINCY 720

#define PI 3.141592f

#define VK_MAX 0xff

extern HWND g_hWnd;
extern int Playerx, Playery;

enum OBJID { OBJ_MONSTER, OBJ_PLAYER, OBJ_FURNITURE ,OBJ_ITEM, OBJ_UI, OBJ_BUTTON, OBJ_MOUSE, OBJ_END };

typedef struct tagInfo
{

	float	fX, fY;
	float	fCX, fCY;

}INFO;

struct tagFinder
{
	tagFinder(const TCHAR* pTag) : m_pTag(pTag) {}

	template<typename T>
	bool	operator()(T& MyPair)
	{
		return !lstrcmp(MyPair.first, m_pTag);
	}


	const TCHAR* m_pTag;
};

typedef struct tagFrame
{
	int		iStart;  // 움직임 x값 
	int		iEnd;
	int		iMotion; // 상태 y값
	double	dwTime;
	double	dwSpeed;

}FRAME;