// ConsoleApplication1.cpp : main project file.


//#using <OBS.lib>
#include "stdafx.h"
//#include "Main2.h"

#include "obswrapper.h"

using namespace System;
 
int main(array<System::String ^> ^args)
{
	return 0;
}

class UnmanagedClass {

public:
	//String^ GetSharedTextureHandle()
	//{
	//	return gcnew String("asdasd");
	//}

	
	
	//void InitInstance()
	//{

	//	obswrapper s0 = obswrapper();
	//	//	WinMain2(); 
	//	Console::WriteLine(L"Hello World");
	//}

	void StartOBS()
	{
		obswrapper s0 = obswrapper();
		s0.StartOBS();
		//WinMain2(); 
		//Console::WriteLine(L"Hello World");
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
	//void InitInstance() {
	//	m_Impl->InitInstance();
	//}

	void StartOBS() {
		m_Impl->StartOBS();
	}


private:
	UnmanagedClass * m_Impl;
};

