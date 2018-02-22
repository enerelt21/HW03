#include "stdafx.h"
#include "CppUnitTest.h"
#include "readint.h"  // This must GO AFTER CppUnitTest.h!!!!
#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{
	TEST_CLASS(READINT_TEST) // This our test suite for testing isTriangle()
	{
	public:
		
		TEST_METHOD(TestCase1) // Test case 2: for invalid argument
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 5, 1);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};

}