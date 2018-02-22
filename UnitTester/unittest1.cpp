#include "stdafx.h"
#include "CppUnitTest.h"
#include "../HW03/readint.h"  // This must GO AFTER CppUnitTest.h!!!!
#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{
	TEST_CLASS(READINT_TEST) // This our test suite for testing isTriangle()
	{
	public:
		TEST_METHOD(TestCase1) // Test case 1: invalid input
		{
			// crate a string stream object with the desired input
			istringstream ss("Hello\n0");

			// Replace the cin read buffer with the read buffer from the string stream 
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test.
			// cin will now read contents from your stringstream and not from the keyboard.
			// We expect the correct value returned is 0, ignoring the Hello string.
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			// Restore cin to the way it was before
			cin.rdbuf(orig_cin);

			// Close the file stream
			//ss.close();
		}



		TEST_METHOD(TestCase2) // Test case 2: for invalid argument
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 5, 1);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}
	
		TEST_METHOD(TestCase3) // Test case 2: for invalid argument
		{
			// crate a string stream object with the desired input
			istringstream ss("-3\n5\n10\n-2\n3");

			// Replace the cin read buffer with the read buffer from the string stream 
			streambuf *orig_cin = cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test.
			// cin will now read contents from your stringstream and not from the keyboard.
			// We expect the correct value returned is 0, ignoring the Hello string.
			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			// Restore cin to the way it was before
			cin.rdbuf(orig_cin);

			// Close the file stream
			//ss.close();
		}
		TEST_METHOD(TestCase4) // Test case 2: for invalid argument
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 0, 0);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};

}