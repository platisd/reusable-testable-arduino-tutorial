#include "Calculator.h"
#include "gtest/gtest.h"

TEST(calculator_test, add_WhenPositiveArguments_WillReturnCorrectSum)
{
    const auto expectedResult = 52;
    EXPECT_EQ(calculator::add(50, 2), expectedResult);
}

TEST(calculator_test, add_WhenNegativeArguments_WillReturnCorrectSum)
{
    // TODO: Write this test
}

TEST(calculator_test, add_WhenMixedSignArguments_WillReturnCorrectSum)
{
    // TODO: Write this test
}

TEST(calculator_test, subtract_WhenPositiveArguments_WillReturnCorrectSum)
{
    const auto expectedResult = 48;
    EXPECT_EQ(calculator::subtract(50, 2), expectedResult);
}

TEST(calculator_test, subtract_WhenNegativeArguments_WillReturnCorrectSum)
{
    // TODO: Write this test
}

TEST(calculator_test, subtract_WhenMixedSignArguments_WillReturnCorrectSum)
{
    // TODO: Write this test
}