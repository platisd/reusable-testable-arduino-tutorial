#include "Calculator.h"
#include "gtest/gtest.h"

TEST(calculator_test, add_WhenPositiveArguments_WillReturnCorrectSum)
{
    const auto expectedResult = 52;
    EXPECT_EQ(calculator::add(50, 2), expectedResult);
}

TEST(calculator_test, add_WhenNegativeArguments_WillReturnCorrectSum)
{
    const auto expectedResult = 3;
    EXPECT_EQ(calculator::subtract(-10, -13), expectedResult);
}

TEST(calculator_test, add_WhenMixedSignArguments_WillReturnCorrectSum)
{
    const auto expectedResult = 214;
    EXPECT_EQ(calculator::subtract(101, -113), expectedResult);
}

TEST(calculator_test, subtract_WhenPositiveArguments_WillReturnCorrectSum)
{
    const auto expectedResult = 745;
    EXPECT_EQ(calculator::subtract(800, 55), expectedResult);
}

TEST(calculator_test, subtract_WhenNegativeArguments_WillReturnCorrectSum)
{
    const auto expectedResult = -10;
    EXPECT_EQ(calculator::subtract(-20, -10), expectedResult);
}

TEST(calculator_test, subtract_WhenMixedSignArguments_WillReturnCorrectSum)
{
    const auto expectedResult = -28;
    EXPECT_EQ(calculator::subtract(-23, 5), expectedResult);
}

TEST(calculator_test, divide_WhenExactDivision_WillReturnCorrectResult)
{
    const auto expectedResult = 5;
    EXPECT_EQ(calculator::divide(25, 5), expectedResult);
}

TEST(calculator_test, divide_WhenNotExactDivision_WillReturnCorrectResult)
{
    const auto expectedResult = -0.5;
    EXPECT_EQ(calculator::divide(-100, 200), expectedResult);
}

TEST(calculator_test, divide_WhenDivisionByZero_WillCrash)
{
    EXPECT_DEATH(calculator::divide(1, 0), "");
}