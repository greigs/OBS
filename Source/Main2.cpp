#include "Main.h"
extern "C" __declspec(dllexport) IStream* __stdcall WinMain2()
{
	return WinMain(0, 0, 0, 0);
}
