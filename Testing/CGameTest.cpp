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
#include <regex>
#include <streambuf>
#include <fstream>
#include "Game.h"


using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CGameTest)
	{
	public:

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

		/**
		 * Read a file into a wstring and return it.
		 * \param filename Name of the file to read
		 * \return File contents
		 */
		wstring ReadFile(const wstring& filename)
		{
			ifstream t(filename);
			wstring str((istreambuf_iterator<char>(t)),
				istreambuf_iterator<char>());

			return str;
		}

		/**
		* Test to ensure a file is compatible with game
		*/
		void TestIsXml(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			Assert::IsTrue(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
			Assert::IsTrue(regex_search(xml, wregex(L"<level/>")));
		}

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

		TEST_METHOD(TestCGameLoad)
		{

			// Create a path to temporary files
			wstring tempPath = TempPath();

			CGame game;

			wstring file1 = tempPath + L"level0";

			wstring path = L".\\levels\\";
			wstring file2 = path + L"level1.xml";

			// Load level 1 and save it to temp folder
			game.Load(file2);
			wstring file3 = tempPath + L"level1.xml";
			game.Save(file3);

			TestIsXml(file3);
		}

	};
}