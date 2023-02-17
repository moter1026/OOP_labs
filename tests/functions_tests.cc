#include <gtest/gtest.h>

#include <functions/functions.h>

TEST(FunctionsTests, SumStubTest1) {
    // Arrange
    int lhs = 5;
    
    // Act
    int r = fact(lhs);
    
    // Assert
    EXPECT_EQ(r, 120);
}

TEST(FunctionsTests, SumStubTest2) {
    // Arrange
    int lhs = -1;
    
    // Act
    int r = fact(lhs);
    
    // Assert
    EXPECT_EQ(r, 0);
}

TEST(FunctionsTests, SumStubTest3) {
    // Arrange
    int lhs = 10;

    // Act
    int r = fact(lhs);

    // Assert
    EXPECT_EQ(r, 3628800);
}
