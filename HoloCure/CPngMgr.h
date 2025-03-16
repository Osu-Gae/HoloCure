#pragma once
#include "pch.h"
class CPngMgr {
public:
    void Initailize()
    {
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Player/Player.png", L"Player_watson");
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Player/Player_Rev.png", L"Player_watson_Rev");
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Monster/Monster.png", L"Monster");
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Monster/Monster_Rev.png", L"Monster_Rev");
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Ground/Ground.png", L"Ground");
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Ui/ExpBar.png", L"ExpBar");
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Ui/PlayerUiT.png", L"PlayerUiT");
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Item/Item_1.png", L"Item_1");
        CPngMgr::Get_Instance().Insert_Png(L"../Image/Obj/Ui/LevelUp.png", L"LevelUp");
    }
public:
    static CPngMgr& Get_Instance() {
		static CPngMgr instance;
		return instance;
    }

    void Insert_Png(const wstring& filePath, const wstring& key) {
        if (m_mapPng.find(key) == m_mapPng.end()) {
            Gdiplus::Image* pImage = new Gdiplus::Image(filePath.c_str());
            if (pImage && pImage->GetLastStatus() == Gdiplus::Ok) {
                m_mapPng[key] = pImage;
            }
            else {
                delete pImage;
            }
        }
    }

    Gdiplus::Image* Find_Png(const wstring& key) {
        auto iter = m_mapPng.find(key);
        if (iter != m_mapPng.end()) {
            return iter->second;
        }
        return nullptr;
    }

    void Release() {
        for (auto& pair : m_mapPng) 
        {
            delete pair.second;
            pair.second = nullptr;
        }
        m_mapPng.clear();
    }
    void DrawPng(HDC hDC, const wstring& key, int x, int y, int width, int height) {
        Gdiplus::Image* pImage = Find_Png(key);
        if (pImage) {
            Gdiplus::Graphics graphics(hDC);
            graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
            graphics.DrawImage(pImage, x, y, width, height);
        }
    }
    void DrawPngWithAlpha(HDC hDC, const wstring& key, int x, int y, int width, int height, float alpha) {
        Gdiplus::Image* pImage = Find_Png(key);
        if (pImage) {
            Gdiplus::Graphics graphics(hDC);
            graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);

            // ���� ����� ����� ���� ����
            Gdiplus::ColorMatrix colorMatrix = {
                1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 0.0f, alpha, 0.0f,  // ������ ���� alpha �� ����
                0.0f, 0.0f, 0.0f, 0.0f, 1.0f
            };

            Gdiplus::ImageAttributes imgAttr;
            imgAttr.SetColorMatrix(&colorMatrix, Gdiplus::ColorMatrixFlagsDefault, Gdiplus::ColorAdjustTypeBitmap);

            Gdiplus::Rect rect(x, y, width, height);
            graphics.DrawImage(pImage, rect, 0, 0, pImage->GetWidth(), pImage->GetHeight(), Gdiplus::UnitPixel, &imgAttr);
        }
    }
    void DrawPngPart(HDC hDC, const wstring& key, int destX, int destY, int destWidth, int destHeight, int srcX, int srcY, int srcWidth, int srcHeight) {
        Gdiplus::Image* pImage = Find_Png(key);
        if (pImage) {
            Gdiplus::Graphics graphics(hDC);
            graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);

            // �ڸ� �κ��� �����ϴ� srcRect
            Gdiplus::Rect srcRect(srcX, srcY, srcWidth, srcHeight);

            // �ڸ� �κ��� �׸� ��ġ�� ũ�⸦ �����ϴ� destRect
            Gdiplus::Rect destRect(destX, destY, destWidth, destHeight);

            // �̹��� �ڸ��� �� ���
            graphics.DrawImage(pImage, destRect, srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height, Gdiplus::UnitPixel);
        }
    }
    void DrawPngRotated(HDC hDC, const wstring& key, int x, int y, int width, int height, float angle) {
        Gdiplus::Image* pImage = Find_Png(key);
        if (pImage) {
            Gdiplus::Graphics graphics(hDC);
            graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);

            // �߽��� �������� ȸ���ϱ� ���� ��ȯ ����
            graphics.TranslateTransform(x + width / 2.0f, y + height / 2.0f);
            graphics.RotateTransform(angle);
            graphics.TranslateTransform(-(x + width / 2.0f), -(y + height / 2.0f));

            // �̹��� ���
            graphics.DrawImage(pImage, x, y, width, height);

            // ��ȯ �ʱ�ȭ
            graphics.ResetTransform();
        }
    }
private:
    CPngMgr() = default;
    ~CPngMgr() = default;
    unordered_map<wstring, Gdiplus::Image*> m_mapPng;
};


// ����: PNG �̹������� (50, 50)���� (200, 200) ũ�⸸ �߶� (0, 0) ��ġ�� 100x100 ũ��� ���
//HDC hDC = GetDC(hWnd);
//DrawPngPart(hDC, L"MainBackGround", 0, 0, 100, 100, 50, 50, 200, 200);
//ReleaseDC(hWnd, hDC);

