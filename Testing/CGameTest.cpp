/**
 * \file CGameTest.cpp
 *
 * \author(s) Michael Dittman,
 *
 * Test the functionality of CGame
 */



#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include "Game.h"


using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CGameTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCGameConstruct)
		{
			CGame game;
		}

		/**
		* Create a path to a place to put temporary files
		*/
		wstring TempPath()
		{
			// Create a path to temporary files
			wchar_t path_nts[MAX_PATH];
			GetTempPath(MAX_PATH, path_nts);

			// Convert null terminated string to wstring
			return wstring(path_nts);
		}

		TEST_METHOD(TestCGameLoad)
		{

			// Create a path to temporary files
			wstring path = TempPath();

			CGame game;

			wstring file1 = path + L"level0";

		}

	};
}