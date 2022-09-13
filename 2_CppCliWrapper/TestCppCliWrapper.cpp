#include <msclr\auto_gcroot.h>

using namespace System::Runtime::InteropServices; // Marshal

class TestWrapperPrivate
{
public: msclr::auto_gcroot<CSharpLib::TestCsharp^> testT;
};

class __declspec(dllexport) TestWrapper
{
private: TestWrapperPrivate* _private;

public: TestWrapper()
{
	_private = new TestWrapperPrivate();
	_private->testT = gcnew CSharpLib::TestCsharp();
}


public: TestWrapper(const char* initText)
{
	_private = new TestWrapperPrivate();
	_private->testT = gcnew CSharpLib::TestCsharp();
}

public: const char* GetString(const char* symbol)
{
	//_private = new TestWrapperPrivate();
	//_private->testT = gcnew CSharpLib::TestCsharp();

	System::String^ managedCapi = _private->testT->GetString(gcnew System::String(symbol));

	return (const char*)Marshal::StringToHGlobalAnsi(managedCapi).ToPointer();
}

public: ~TestWrapper()
{
	delete _private;
}
};
