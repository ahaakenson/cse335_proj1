#include "pch.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "Game.h"
#include "Level.h"
#include <string>
#include <memory>

using namespace Gdiplus;
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

wstring filename = L"images/road1.png";

namespace Testing
{

	/** Mock class for testing CIitem */
	class CItemMock : public CItem
	{
	public:
		CItemMock(CGame* game, shared_ptr<Bitmap> bitmap) : CItem(game, bitmap) {}
	};
	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCItemGettersSetters)
		{
			shared_ptr<Bitmap> itemBitmap = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
			// Construct an item to test
			CGame game;
			CItemMock item(&game, itemBitmap);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(9.3, 15.6);
			Assert::AreEqual(9.3, item.GetX(), 0.0001);
			Assert::AreEqual(15.6, item.GetY(), 0.0001);
			
			// Test GetGame
			Assert::IsTrue(&game == item.GetGame());

			unique_ptr<Bitmap> image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
			item.GetHeight();
			// Test GetWidth and GetHeight
			Assert::AreEqual(image->GetWidth(), item.GetWidth(), 0.0001);
			Assert::AreEqual(image->GetHeight(), item.GetHeight(), 0.0001);
		}

	};
}