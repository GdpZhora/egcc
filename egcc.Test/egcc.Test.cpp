#include "pch.h"
#include "CppUnitTest.h"
#include "../egcc/all.h"
#include <string>
//#include <CppUnitTestAssert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace egccTest
{
	TEST_CLASS(egccTest)
	{
	public:

		TEST_METHOD(TestMillingCode)
		{
			std::string code;
			code = "int a = 2;";


			//std::string result = "\nint\na\n=\n2\n;";
			std::string result = ";";
			ParserCode parser = ParserCode();
			parser.LoadTextCode(&code);
			parser.MillingCode();
			Assert::AreEqual(result, parser.codeMilled);
			
		}
	};
}
