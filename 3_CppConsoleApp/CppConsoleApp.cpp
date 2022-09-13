// CppConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestCppCliWrapper.h"

int main()
{
    const char* text = "Hello my C++/CLI word!!!";
    TestWrapper wrapper;
    const char* result = wrapper.GetString(text);
    std::cout << result << std::endl;
}


