#include "pch.h"
#include "CppUnitTest.h"
#include "assert.h"
#include "../lab10.1A/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentTests
{
    TEST_CLASS(StudentTests)
    {
    public:

        TEST_METHOD(TestCountSatisfactoryGrades)
        {
          
            Student students[] = {
                {"Alice", 1, COMPUTER_SCIENCE, 3, 4, 5},  // Satisfactory Physics, Math, IT
                {"Bob", 2, INFORMATICS, 2, 4, 3},        // Satisfactory Math, IT
                {"Charlie", 3, MATH_ECON, 5, 4, 2},      // Satisfactory Math
                {"David", 4, PHYS_INF, 3, 3, 4}          // Satisfactory Physics, Math, IT
            };
            int N = sizeof(students) / sizeof(students[0]);

            // Variables to store the counts of satisfactory grades
            int satisfactoryPhysics = 2, satisfactoryMath = 3, satisfactoryIT = 3;

         
            CountSatisfactoryGrades(students, N);

            // Assert: Check the expected values
            Assert::AreEqual(satisfactoryPhysics, 2); // Alice and David have satisfactory Physics grades
            Assert::AreEqual(satisfactoryMath, 3);    // Alice, Bob, and David have satisfactory Math grades
            Assert::AreEqual(satisfactoryIT, 3);      // Alice, Bob, and David have satisfactory IT grades
        }
    };
}


        