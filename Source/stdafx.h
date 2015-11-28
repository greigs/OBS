/*=====================================================================
File:      stdafx.h

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
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <iostream>
using std::cout; using std::endl;

// TODO: reference additional headers your program requires here
