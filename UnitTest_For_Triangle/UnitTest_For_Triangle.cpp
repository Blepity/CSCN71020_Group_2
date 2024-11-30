#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForTriangle
{
	TEST_CLASS(UnitTestForTriangle)
	{
	public:

		TEST_METHOD(TestForScaleneTriangle)
		{
			int side1 = 6;
			int side2 = 9;
			int side3 = 12;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Scalene triangle", result);
		}


		TEST_METHOD(TestForIsoscelesTriangle)
		{
			int side1 = 4;
			int side2 = 2;
			int side3 = 4;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", result);
		}


		TEST_METHOD(TestForEquilateralTriangle)
		{
			int side1 = 6;
			int side2 = 6;
			int side3 = 6;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Equilateral triangle", result);
		}


		TEST_METHOD(TestForNotATriangle1) {
			int side1 = 9;
			int side2 = 0;
			int side3 = 9;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}


		TEST_METHOD(TestForNotATriangle2) {
			int side1 = -5;
			int side2 = 4;
			int side3 = 3;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}


		TEST_METHOD(TestForNotATriangle3) {
			int side1 = 3;
			int side2 = 4;
			int side3 = 8;
			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(TestForTriangleAngles) {
			double angleA, angleB, angleC;
			int side1 = 8;
			int side2 = 15;
			int side3 = 17;
			bool isValid = TriangleAngles(side1, side2, side3, &angleA, &angleB, &angleC);
			Assert::IsTrue(isValid);
			Assert::AreEqual(28.072, angleA, 0.01);
			Assert::AreEqual(90, angleC, 0.01);

		}

		TEST_METHOD(TestInvlaidTriangleAngles) {
			double angleA, angleB, angleC;
			int side1 = 1;
			int side2 = 2;
			int side3 = 3;
			bool isValid = TriangleAngles(side1, side2, side3, &angleA, &angleB, &angleC);
			Assert::IsFalse(isValid);
		}

		TEST_METHOD(TestForEquilateralTriangleAngles) {
			double angleA, angleB, angleC;
			int side1 = 11;
			int side2 = 11;
			int side3 = 11;
			bool isValid = TriangleAngles(side1, side2, side3, &angleA, &angleB, &angleC);
			Assert::IsTrue(isValid);
			Assert::AreEqual(60, angleA, 0.01);
			Assert::AreEqual(60, angleB, 0.01);
			Assert::AreEqual(60, angleC, 0.01);
		}
	};
}