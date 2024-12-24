#include "pch.h"
#include "CppUnitTest.h"
#include "../math/math.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		float x = 0;
		float y = 1;
		float zero = 0;
		float S = x * log10(cbrt(abs(y)));
		float R = sin((3.14159265358979323846 / 3) * x);
		TEST_METHOD(S_ravno_zero)
		{
			Assert::AreEqual(S, zero);
		}
		TEST_METHOD(R_ravno_zero)
		{
			Assert::AreEqual(R, zero);
		}
		TEST_METHOD(S_i_R_ravni)
		{
			Assert::IsTrue(S == R);
		}
	};
}