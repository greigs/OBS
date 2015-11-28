// ConsoleApplication1.cpp : main project file.


//#using <OBS.lib>
#include "stdafx.h"
//#include "Main2.h"

#include "substring.h"

using namespace System;


public ref class substring_w
{
public:
	String^ find_suffix(String^ s, int pos)
	{
		int length = s->Length;
		char *in_string = new char[length + 1];
		for (unsigned short i = 0; i < length; i++)
		{
			in_string[i] = (char)s[i];
		}
		in_string[length] = '\0';
		substring s0 = substring(in_string);
		delete[] in_string;
		return gcnew String(s0.suffix(pos));
	}

};

int main(array<System::String ^> ^args)
{

	substring s0 = substring();
//	WinMain2();
    Console::WriteLine(L"Hello World"); 
    return 0;
}
