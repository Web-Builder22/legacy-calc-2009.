Loan Calculator Project
=========================

This project implements a simple loan EMI (Equated Monthly Installment) calculator in C++ with proper modular structure, GoogleTest unit testing, and Doxygen documentation.

Project Structure
-----------------
/project-root
- loan.h               : Loan calculation class (Doxygen documented)
- loan.cpp             : Implementation file (Doxygen documented)
- main.cpp             : Main program using the Loan class (Doxygen documented)
- config.txt           : Hard-coded input values for testing
- tests/loan_test.cpp  : GoogleTest unit tests
- docs/html/index.html : Generated Doxygen documentation

Features
--------
- Calculates total payable amount, interest, and monthly EMI.
- Handles invalid inputs.
- Safe for large tenures.
- Fully unit tested.
- Documented using Doxygen.

Running Tests
-------------
1. Configure GoogleTest using CMake.
2. Build and run tests with:
   mkdir build
   cd build
   cmake ..
   make
   ./runTests

Generate Doxygen Documentation
------------------------------
1. Run:  doxygen -g
2. Edit Doxyfile:
   - RECURSIVE = YES
   - GENERATE_HTML = YES
   - OUTPUT_DIRECTORY = docs
3. Generate with: doxygen Doxyfile

Build & Run Application
-----------------------
g++ main.cpp loan.cpp -o loan_app
./loan_app
make # or compile with: g++ -std=c++11 *.cpp -o calc
./calc -cp -a 100000 -i 12 -n 360
config.txt Format
-----------------
loan_amount=10000
interest_rate=10
number_of_years=2
