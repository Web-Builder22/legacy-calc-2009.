#include <gtest/gtest.h>
#include "loan.h"

TEST(LoanTest, ValidEmiCalculation) {
    Loan l(10000, 10, 2);  // 2 years

    long double emi = l.calculateMonthlyAmount();

    EXPECT_GT((double)emi, 0.0);
}

TEST(LoanTest, InvalidInputThrows) {
    EXPECT_THROW(Loan(-5000, 10, 2), std::invalid_argument);
    EXPECT_THROW(Loan(5000, -10, 2), std::invalid_argument);
    EXPECT_THROW(Loan(5000, 10, -2), std::invalid_argument);
}

TEST(LoanTest, LargeTenureDoesNotOverflow) {
    Loan l(20000, 8, 100);  // 100 years EMI

    EXPECT_TRUE(std::isfinite((double)l.calculateTotalAmount()));
    EXPECT_TRUE(std::isfinite((double)l.calculateMonthlyAmount()));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
