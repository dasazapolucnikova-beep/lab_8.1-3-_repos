#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS

#include "CppUnitTest.h"
#include "../Project 8.1 (3)/Project 8.1 (3).cpp" // Вкажіть правильний шлях до вашого .cpp файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81
{
	TEST_CLASS(UnitTest81)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// 1. Тест функції Count
			char str1[] = "xyaabbccz";
			int count = Count(str1);
			Assert::AreEqual(3, count);

			// 2. Тест функції Change
			char str2[100] = "xyaabbccz";
			char* dest = Change(str2);

			Assert::AreEqual("xy*********z", dest);
		}
	};
}