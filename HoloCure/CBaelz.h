#pragma once
#include "CMonster.h"
class CBaelz : public CMonster
{
public:
	CBaelz();
	~CBaelz();

public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hDC, const int& _iScrollX, const int& _iScrollY) override;
	void Release() override;
	void Pattern();
private:
	float m_fAttackTime;
	float m_fPatternTime;
	int m_ipattern;

	// µÓ¿Â æ¿
	float m_fSpawnScene = 5.f;
	int spawnx = 1380;
};

