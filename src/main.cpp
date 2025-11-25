#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cmath>
#include "loan.h"

using namespace std;

/**
 * @brief Safely reads a numeric value with validation.
 */
long double readValidatedInput(const string &label) {
    long double value;

    while (true) {
        cout << label;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cout << "Invalid input! Please enter a positive numeric value.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return value;
        }
    }
}

/**
 * @brief Attempts to load loan settings from config.txt.
 * If file missing or invalid, returns false.
 */
bool loadConfig(long double &amount, long double &rate, long double &years) {
    ifstream file("config.txt");
    if (!file.is_open()) {
        return false;
    }

    string line;
    try {
        while (getline(file, line)) {
            if (line.rfind("loan_amount=", 0) == 0)
                amount = stold(line.substr(12));
            else if (line.rfind("interest_rate=", 0) == 0)
                rate = stold(line.substr(14));
            else if (line.rfind("number_of_years=", 0) == 0)
                years = stold(line.substr(17));
        }
    }
    catch (...) {
        return false; // invalid format
    }

    return (amount > 0 && rate > 0 && years > 0);
}

/**
 * @brief Main function: Reads config, validates input, and calculates EMI.
 */
int main() {
    long double amount = 0, rate = 0, years = 0;

    cout << "Checking config.txt for loan settings...\n";

    if (!loadConfig(amount, rate, years)) {
        cout << "Config not found or invalid. Please enter values manually.\n";

        amount = readValidatedInput("Enter loan amount: ");
        rate = readValidatedInput("Enter interest rate (%): ");
        years = readValidatedInput("Enter number of years: ");
    }

    // Create loan object
    Loan loan(amount, rate, years);

    cout << "\n===== Loan Summary =====\n";
    cout << "Total Amount: " << loan.calculateTotalAmount() << endl;
    cout << "Total Interest: " << loan.calculateTotalInterest() << endl;
    cout << "Monthly EMI: " << loan.calculateMonthlyAmount() << endl;

    return 0;
}
