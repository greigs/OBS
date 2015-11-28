/*=====================================================================
File:      substring.cpp

Summary:   illustrates how a Managed Extensions __gc class can be used
as a proxy class (or wrapper) for an unmanaged C++ class in a DLL
---------------------------------------------------------------------
This file is part of the Visual J# .NET Code Samples.

Copyright (C) 2001 Microsoft Corporation.  All rights reserved.

This source code may be used only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.
=====================================================================*/
//
// substring.cpp : Defines the entry point for the DLL application.
//
#include <windows.h>
#include "stdafx.h"
#include "Main2.h"

#pragma warning( disable : 4091 )
BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	return TRUE;
}
__declspec(dllexport)
class substring
{
public:
	__declspec(dllexport) substring();
	__declspec(dllexport) substring(const char * const);
	__declspec(dllexport) ~substring();

	__declspec(dllexport) const char * getstring() const { return str; }
	__declspec(dllexport) char * suffix(int n);
private:
	char * str;
	unsigned short len;
};

substring::substring()
{
	WinMain2();

	str = (char *)LocalAlloc(0, sizeof(char));
	str[0] = '\0';
	len = 0;
}

substring::substring(const char * const str0)
{
	len = (unsigned short)strlen(str0);
	str = (char *)LocalAlloc(0, sizeof(char)*(len + 1));

	unsigned short i;
	for (i = 0; i < len; i++)
		str[i] = str0[i];

	str[i] = '\0';

	
}

char * substring::suffix(int pos)
{
	int suffix_length;
	pos--;
	if (pos < 0) pos = 0;
	suffix_length = len - pos + 1;

	if (suffix_length > 0)
	{
		char * suff = new char[suffix_length];
		for (unsigned short i = pos; i < len + 1; i++)
			suff[i - pos] = str[i];
		return suff;
	}
	else
		return 0;
}

substring::~substring()
{
	LocalFree(str);
	len = 0;
}

