#pragma once

#define WINCX 1280
#define WINCY 720

#define PI 3.141592f

#define VK_MAX 0xff

#define TILEXY 160

extern HWND g_hWnd;
extern int Playerx, Playery;
extern HFONT hFont;
extern HFONT hFontBig;
enum OBJID { OBJ_BULLET, OBJ_BOSSBULLET, OBJ_EXP,OBJ_MONSTER,OBJ_BOSS, OBJ_FANDIE,OBJ_PLAYER,OBJ_FURNITURE ,OBJ_ITEM, OBJ_DMG,OBJ_UI, OBJ_BUTTON, OBJ_MOUSE, OBJ_END };
enum CHANNELID { SOUND_BUTTON,SOUND_LEVELUP,SOUND_EFFECT,SOUND_DIE, SOUND_WARNING ,SOUND_BULLET, SOUND_EXP , SOUND_BGM, SOUND_END };
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

