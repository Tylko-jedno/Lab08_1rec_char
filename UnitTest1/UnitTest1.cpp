#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab08_1rec_char/Lab08_1rec_char.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(UnitTestProject)
    {
    public:
        TEST_METHOD(TestCountMixedSymbolsAndChars)
        {
            char str[] = "a+b-c=d";

            int result = Count(str);

            Assert::AreEqual(3, result);
        }
        TEST_METHOD(TestChangeMixedSymbolsAndChars)
        {
            const char* str = "a+b-c=d";

            char* result = Change(str);

            Assert::AreEqual("a**b**c**d", result);

            delete[] result;
        }
    };
}