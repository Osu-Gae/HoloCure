#pragma once

class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual void	Initialize() = 0;
	virtual void	Update() = 0;
	virtual void	LateUpdate() = 0;
	virtual void	Render(HDC hDC, int _iScrollX, int _iScrollY) = 0;
	virtual void	Release() = 0;
};

