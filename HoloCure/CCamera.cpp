#include "pch.h"
#include "CCamera.h"

CCamera::CCamera() : m_fScrollX(0.f), m_fScrollY(0.f)
{
}

CCamera::~CCamera()
{
}

void CCamera::Update()
{
	float fx = (WINCX >> 1) - Playerx;
	float fy = (WINCY >> 1) - Playery;
	Set_ScrollX(fx);
	Set_ScrollY(fy);;
}
