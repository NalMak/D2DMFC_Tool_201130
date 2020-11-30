#pragma once

#define WINCX 1280
#define WINCY 1080

#define SAFE_RELEASE(p) if(p) { p->Release(); p = nullptr; }