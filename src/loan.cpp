#include "loan.h"
#include <cmath>
#include <stdexcept>

/**
 * @brief Validates parameters and initializes the loan.
 */
Loan::Loan(long double amount, long double rate, long double years) {
    if (amount <= 0)
        throw std::invalid_argument("Loan amount must be positive.");
    if (rate <= 0)
        throw std::invalid_argument("Interest rate must be positive.");
    if (years <= 0)
        throw std::invalid_argument("Number of years must be positive.");

    this->amount = amount;
    this->rate = rate;
    this->years = years;
}

/**
 * @brief Calculates total interest using safe fused multiply-add.
 */
long double Loan::calculateTotalInterest() const {
    long double r = rate / 100.0L;

    // Safe interest = amount * r * years
    return std::fma(amount * r, years, 0.0L);
}

/**
 * @brief Calculates total payable amount.
 */
long double Loan::calculateTotalAmount() const {
    return amount + calculateTotalInterest();
}

/**
 * @brief Calculates monthly EMI.
 */
long double Loan::calculateMonthlyAmount() const {
    long double months = years * 12.0L;

    return calculateTotalAmount() / months;
}
