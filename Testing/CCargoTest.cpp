#include "pch.h"
#include "CppUnitTest.h"

#include "Cargo.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// Cargo filename 
const std::wstring CargoImageName = L"images/goose.png";

namespace Testing
{
	TEST_CLASS(CCargoTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCCargoHitTest)
		{
			// Create a cargo to test
			CGame game;
			CCargo cargo(&game, CargoImageName);

			// Give it a location
			cargo.SetLocation(100, 200);

			// Center of the cargo should be true
			Assert::IsTrue(cargo.HitTest(100, 200));

			// Top Left corner of the cargo
			Assert::IsTrue(cargo.HitTest(69, 169));

			// Left of the cargo
			Assert::IsFalse(cargo.HitTest(10, 200));

			// Right of the cargo
			Assert::IsFalse(cargo.HitTest(200, 200));

			// Above the cargo
			Assert::IsFalse(cargo.HitTest(100, 0));

			// Below the cargo
			Assert::IsFalse(cargo.HitTest(100, 300));
		}

	};
}