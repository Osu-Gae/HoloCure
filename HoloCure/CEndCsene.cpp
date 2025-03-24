#include "pch.h"
#include "CEndCsene.h"
#include "CSoundMgr.h"
#include "CUiMgr.h"
CEndCsene::CEndCsene()
{
}

CEndCsene::~CEndCsene()
{
}

void CEndCsene::Initialize()
{
	button1.Initialize();
	button2.Initialize();
	button2.Set_id();
	button1.Set_Pos(715, 300);
	button2.Set_Pos(715, 500); 
	// Game_Over
	CSoundMgr::Get_Instance()->StopAll();
	CSoundMgr::Get_Instance()->PlaySound(L"Game_Over.mp3", SOUND_BGM, 1.f);
	m_iScore = CUiMgr::Get_Instance()->m_KillUi.GetKillCount()*100;

}

void CEndCsene::Update()
{
	m_fTime += CTimeMgr::GetInstance().GetDeltaTime();
	if (m_iState == BLACK)
	{
		// 2초동안 0.5가 됨
		m_fAlpha = m_fTime / 4.f;
		if (m_fTime > 2.f)
		{
			m_iState = COMPLETE;
			m_fTime = 0.f;
		}
		
	}
	else if (m_iState == COMPLETE)
	{
		completey += 100 * CTimeMgr::GetInstance().GetDeltaTime();
		if (m_fTime > 2.f)
		{
			m_buttenShow = true;
			m_iState = END;
		}
	}
	else 
	{
		if (button1.Update1() == 1)
		{
			return;
		}
		button2.Update();
		// 버튼 업데이트 
	}
}

void CEndCsene::Render(HDC _hDC)
{
	CPngMgr::Get_Instance().DrawPngWithAlpha(_hDC, L"Back", 0, 0, 1280, 720,m_fAlpha);
	SetBkMode(_hDC, TRANSPARENT);
	SelectObject(_hDC, hFont);
	SetTextColor(_hDC, RGB(255, 255, 255));
	TextOut(_hDC, completex, completey, L"COMPLETE", 8);

	if (m_buttenShow)
	{
		// int to wstring
		wstring score = to_wstring(m_iScore);
		// Score 글자 뒤에 출력 "SOCRE : m_iScore"
		TextOut(_hDC, 590, 180, L"SCORE:  ", 8);
		TextOut(_hDC, 670, 180, score.c_str(), score.length());
		
		button1.Render(_hDC,0,0);
		button2.Render(_hDC,0,0);
	}
}
