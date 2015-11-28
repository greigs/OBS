// ConsoleApplication1.cpp : main project file.


//#using <OBS.lib>
#include "stdafx.h"
//#include "Main2.h"

#include "substring.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	return 0;
}

class UnmanagedClass {

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

	

	void main()
	{

		substring s0 = substring();
		//	WinMain2();
		Console::WriteLine(L"Hello World");
	}
};


public ref class ManagedClass {
public:
	// Allocate the native object on the C++ Heap via a constructor
	ManagedClass() : m_Impl(new UnmanagedClass) {}

	// Deallocate the native object on a destructor
	~ManagedClass() {
		delete m_Impl;
	}

protected:
	// Deallocate the native object on the finalizer just in case no destructor is called
	!ManagedClass() {
		delete m_Impl;
	}

public:
	void main() {
		m_Impl->main();
	}


private:
	UnmanagedClass * m_Impl;
};

