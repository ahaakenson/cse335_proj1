/**
 * \file CHeroTest.cpp
 *
 * \author(s) Michael Dittman,
 */

#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <fstream>

#include"Hero.h"
#include "Game.h"
#include <regex>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CHeroTest)
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
		*  Test a game with just the hero
		* /param filename The filename which contains XML to test
		*/
		void TestHeroType(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			// Ensure the Hero is there
			Assert::IsTrue(regex_search(xml, wregex(L"<level><hero.*</level>")));

		}

		void PopulateHero(CGame* game)
		{
			// Create a new hero
			shared_ptr<CHero> hero = make_shared<CHero>(game);
			// Add the hero to the game
			game->Add(hero);
		}

		/**
		* Test to ensure an that a file is empty
		* /param filename The filename which contains XML to test
		*/
		void TestEmpty(wstring filename)
		{
			Logger::WriteMessage(filename.c_str());

			wstring xml = ReadFile(filename);
			Logger::WriteMessage(xml.c_str());

			Assert::IsTrue(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
			Assert::IsTrue(regex_search(xml, wregex(L"<level/>")));

		}

		TEST_METHOD(TestCHeroSave)
		{
			// The save method is not important it is only here to save stuff to
			// the temporary directory to test the loading functions.

			// Create a path to temporary files
			wstring path = TempPath();

			// Create a new game
			CGame game;

			// Make sure an empty game saves ok

			// Create a path
			wstring file1 = path + L"CHeroTestEmpty";

			// Save to that path
			game.Save(file1);

			// Make sure its empty
			TestEmpty(file1);

			// Populate with a hero
			PopulateHero(&game);

			// Create another path
			wstring file2 = path + L"CHeroTestOneHero";
			// Save the game with the hero to that path
			game.Save(file2);

			// Make sure that path has the correct tags
			TestHeroType(file2);

		}

		TEST_METHOD(TestCHeroLoad)
		{

			// Create a path to temporary files
			wstring path = TempPath();

			// Create a new game
			CGame game;

			// Create a new path
			wstring file1 = path + L"EmptyTest";

			// Save the game to that path
			game.Save(file1);

			// Make sure its empty
			TestEmpty(file1);

			// Load it again, save it again, make sure its empty
			game.Load(file1);
			game.Save(file1);
			TestEmpty(file1);

			// Populate the game with a hero
			PopulateHero(&game);

			// Create another path
			wstring file2 = path + L"LoadTestOneHero";

			// Save the game to the path
			game.Save(file2);

			// Make sure there is one hero
			TestHeroType(file2);

			// Unsure of how tags will be handled

			// Load the game
			//game.Load(file2);
			//game.Save(file2);

			//TestHeroType(file2);


		}

		TEST_METHOD(TestCHeroMoveForward)
		{

			// Create a new game
			CGame game;

			// Assign the pressed key to be e
			UINT nChar = 'e';

			

			// Test to be sure of the hero's starting position
			//Assert::IsTrue();

			game.moveHero(nChar);

			 



		}

	};
}