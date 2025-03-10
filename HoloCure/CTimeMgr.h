#pragma once

class CTimeMgr {
private:
    LARGE_INTEGER m_Frequency;  
    LARGE_INTEGER m_PrevTime;   
    LARGE_INTEGER m_CurrTime;   
    double m_DeltaTime;         
    double m_Time;
    CTimeMgr();
    ~CTimeMgr() = default;
    CTimeMgr(const CTimeMgr&) = delete;
    CTimeMgr& operator=(const CTimeMgr&) = delete;

public:
    static CTimeMgr& GetInstance() {
        static CTimeMgr instance;
        return instance;
    }

    void Initialize();
    void Update();
    double GetDeltaTime() const;
    double GetTime() const;
};