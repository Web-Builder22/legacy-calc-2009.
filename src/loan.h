#ifndef LOAN_H
#define LOAN_H

#include <stdexcept>

/**
 * @class Loan
 * @brief Handles loan calculations such as total amount, total interest, and monthly EMI.
 *
 * This class uses long double for high precision and prevents invalid inputs
 * through strict validation in the constructor.
 */
class Loan {
private:
    long double amount;   ///< Principal loan amount
    long double rate;     ///< Annual interest rate (percentage)
    long double years;    ///< Loan tenure in years

public:

    /**
     * @brief Constructs a Loan object with validated parameters.
     *
     * @param amount Principal loan amount (must be > 0)
     * @param rate Annual interest rate in percentage (must be > 0)
     * @param years Loan duration in years (must be > 0)
     *
     * @throws std::invalid_argument if any parameter is invalid.
     */
    Loan(long double amount, long double rate, long double years);

    /**
     * @brief Calculates the total interest payable using safe math.
     *
     * @return long double Total interest amount.
     */
    long double calculateTotalInterest() const;

    /**
     * @brief Calculates the total amount payable (principal + interest).
     *
     * @return long double Total payable amount.
     */
    long double calculateTotalAmount() const;

    /**
     * @brief Calculates the monthly EMI amount.
     *
     * @return long double Monthly payment amount.
     */
    long double calculateMonthlyAmount() const;
};

#endif // LOAN_H
