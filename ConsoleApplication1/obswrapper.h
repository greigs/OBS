/*=====================================================================
File:      substring.h

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


//__declspec(dllexport)
#include <windows.h>
public class obswrapper
{
public:
	obswrapper();
	obswrapper(const char * const);
	~obswrapper();
	//void InitInstance();
	__declspec(dllexport) IStream* __stdcall StartOBS();
private:
	char * str;
	unsigned short len;
};