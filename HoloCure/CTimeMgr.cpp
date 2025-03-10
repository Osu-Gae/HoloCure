#include "pch.h"
#include "CTimeMgr.h"

CTimeMgr::CTimeMgr() : m_DeltaTime(0.0), m_Time(0.0)
{
    QueryPerformanceFrequency(&m_Frequency);
}

void CTimeMgr::Initialize() {
    QueryPerformanceCounter(&m_PrevTime);
}

void CTimeMgr::Update() {
    QueryPerformanceCounter(&m_CurrTime);
    m_DeltaTime = static_cast<double>(m_CurrTime.QuadPart - m_PrevTime.QuadPart) / m_Frequency.QuadPart;
    m_Time += m_DeltaTime;
    m_PrevTime = m_CurrTime;
}

double CTimeMgr::GetDeltaTime() const {
    return m_DeltaTime;
}

double CTimeMgr::GetTime() const
{
    return m_Time;
}
