﻿// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가
#include "targetver.h"
// #define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include "Define.h"
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <array>
#include <algorithm>	
#include <string>
#include <memory>
#include <cmath>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")


#include <Vfw.h>
#pragma comment(lib, "vfw32.lib")

#include <io.h>
#include <iostream>

#include "fmod.h"
#include "fmod.hpp"

#pragma comment(lib, "fmodex_vc.lib")

using namespace Gdiplus;
using namespace std;



#endif //PCH_H
