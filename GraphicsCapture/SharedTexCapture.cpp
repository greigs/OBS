/********************************************************************************
 Copyright (C) 2012 Hugh Bailey <obs.jim@gmail.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
********************************************************************************/


#include "GraphicsCapture.h"
#include <dxgi.h>
#include <d3d10.h>
#include <sstream>
#include <iostream>
#include <chrono>
#include <thread>


template <class T>
inline std::string to_string(const T& t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

void SharedTexCapture::Destroy()
{
    delete sharedTexture;
    sharedTexture = NULL;

    delete copyTexture;
    copyTexture = NULL;

    bInitialized = false;

    texData = NULL;

    if(sharedMemory)
        UnmapViewOfFile(sharedMemory);

    if(hFileMap)
        CloseHandle(hFileMap);
}

bool SharedTexCapture::Init(CaptureInfo &info)
{
    String strFileMapName;
    strFileMapName << TEXTURE_MEMORY << UIntString(info.mapID);

    hFileMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, strFileMapName);
    if(hFileMap == NULL)
    {
        AppWarning(TEXT("SharedTexCapture::Init: Could not open file mapping: %d"), GetLastError());
        return false;
    }

    sharedMemory = (LPBYTE)MapViewOfFile(hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, info.mapSize);
    if(!sharedMemory)
    {
        AppWarning(TEXT("SharedTexCapture::Init: Could not map view of file"));
        return false;
    }

    //Log(TEXT("using shared texture capture"));

    //---------------------------------------

    texData = (SharedTexData*)sharedMemory;
    texData->frameTime = 1000000/API->GetMaxFPS()/2;

    sharedTexture = GS->CreateTextureFromSharedHandle(info.cx, info.cy, (HANDLE)texData->texHandle);
    if(!sharedTexture)
    {
        AppWarning(TEXT("SharedTexCapture::Init: Could not create shared texture"));
        return false;
    }

	sharedTextureExt = GS->CreateSharedTexture2(info.cx, info.cy);
	copyTexture = GS->CreateTexture(info.cx, info.cy, (GSColorFormat)info.format, 0, FALSE, TRUE);

    Log(TEXT("SharedTexCapture hooked"));

    bInitialized = true;
    return true;
}
Texture* tx2;

Texture* SharedTexCapture::LockTexture()
{


	IDXGIKeyedMutex *g_pDXGIKeyedMutex;

	IDXGIResource *sharedResource10;
	ID3D10Texture2D *tx = (ID3D10Texture2D*)sharedTextureExt->GetD3DTexture();

	tx->QueryInterface(__uuidof(IDXGIResource), (void**)(&sharedResource10));

	HANDLE sharedHandle;
	sharedResource10->GetSharedHandle(&sharedHandle);
	long handlelng = HandleToLong(sharedHandle);
	std::wstring str1 = std::to_wstring(handlelng);
	const wchar_t * str2 = str1.c_str();

	AppWarning(str2);


	GS->CopyTexture(sharedTextureExt, sharedTexture);

	std::this_thread::sleep_for(std::chrono::milliseconds(50));

	bool result;

	//D3D10_MAPPED_TEXTURE2D map;
	//if (SUCCEEDED(result = tx->Map(0, D3D10_MAP_READ, 0, &map))){

	//}

	GS->CopyTexture(copyTexture, sharedTextureExt);

	std::this_thread::sleep_for(std::chrono::milliseconds(2000));





//	DWORD width = sharedTexture->Width();
//	DWORD height = sharedTexture->Height();

//	tx2 = GS->CreateTextureFromSharedHandle(width, height, sharedHandle);
	
//	ID3D10Texture2D *tx3 = (ID3D10Texture2D *)tx2->GetD3DTexture();

	//GS->CopyTexture(copyTexture, tx2);

    return copyTexture;
}

void SharedTexCapture::UnlockTexture()
{

	//IDXGIKeyedMutex *g_pDXGIKeyedMutex;
	//ID3D10Texture2D *tx = (ID3D10Texture2D*)sharedTextureExt->GetD3DTexture();
	//tx->QueryInterface(__uuidof(IDXGIKeyedMutex), (LPVOID*)&g_pDXGIKeyedMutex);
	//HRESULT result = g_pDXGIKeyedMutex->ReleaseSync(0);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));



}
