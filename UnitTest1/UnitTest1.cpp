#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
#include "../Lab 9.1/Lab 9.1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			struct Student
			{
				int physics;
				int math;
				int inform;
			};
			int N = 3;
			Student* p = new Student[N];
			p[0].physics = 2;
			p[0].math = 2;
			p[0].inform = 2;
			p[1].physics = 4;
			p[1].math = 5;
			p[1].inform = 4;
			p[2].physics = 4;
			p[2].math = 5;
			p[2].inform = 3;
			double res = LineSearch(p, N);
			Assert::AreEqual(res, 1);
		}
	};
}
