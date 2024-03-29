/*course: CS215 - 004
 *Project: Lab 6 (As part of Project 1)
 *Purpose: Display the year of Super Bowl in Roman Numeral Representation
 *         The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum)
 *         For testing purpose, this program displays the Super Bowls in two-group of 50 years
 *         (1) from year 2000 to year 2049;
 *         (2) from year 5916 to year 5965.
 *Author: Nathan Jones
 */
#include <iostream>
#include <string>

using namespace std;

//Turns a digit into a Roman numeral
string roman_digit(int digit, const string& one, const string& five, const string& ten) {
        string roman;
        switch (digit) {
            case 1: roman = one; break;
            case 2: roman = one + one; break;
            case 3: roman = one + one + one; break;
            case 4: roman = one + five; break;
            case 5: roman = five; break;
            case 6: roman = five + one; break;
            case 7: roman = five + one + one; break;
            case 8: roman = five + one + one + one; break;
            case 9: roman = one + ten; break;
            default: break;
    }
    return roman;
}

//Returns a string form of a Roman Numeral.
//(n must be between 1 and 3999)
string roman_numeral(int n) {
    int ones;
    int tens;
    int hundreds;
    int thousands;

    // Ones place
    ones = n % 10;
    n /= 10;

    // Tens place
    tens = n % 10;
    n /= 10;

    // Hundreds place
    hundreds = n % 10;
    n /= 10;

    // Thousands place
    thousands = n % 10;

    // Call roman_digit
    string unitRoman = roman_digit(ones, "I", "V", "X");
    string tenthRoman = roman_digit(tens, "X", "L", "C");
    string hundredRoman = roman_digit(hundreds, "C", "D", "M");
    string thousandRoman = roman_digit(thousands, "M", " ", " ");

    return thousandRoman + hundredRoman + tenthRoman + unitRoman;

}


int main()
{
    const int START_SUPERBOWL = 1967;  // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum)
    const int FIRST_START = 2000;      // The first group displays Super Bowl starting in year 2000
    const int FIRST_END = 2049;        // The first group displays Super Bowl ending in year 2099
    const int SECOND_START = 5916;     // The second group displays Super Bowl starting in year 5616
    const int SECOND_END = 5965;       // The second group displays Super Bowl ending in year 5965

    // define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;
    // The last Super Bowl which can be represented by Roman Numerals would be: START_SUPERBOWL + MAX_ROMAN - 1;
    const int GROUP = 10;                  // Layout the years in a group of 10

    cout << endl << "\t\t\tSuper Bowl Records" << endl;
    cout << "The first Super Bowl was hold at Los Angeles Memorial Coliseum on January 15, " << START_SUPERBOWL << endl;
    cout << "\tYear\t\tSuper Bowl" << endl;

    // display one group of 50 years of Super Bowl, starting at year 2000 to year 2049
    for (int i = FIRST_START; i <= FIRST_END; i++)
    {
        int year = i - START_SUPERBOWL + 1;
        if (i % GROUP == 0)
            cout << endl << "************************************" << endl << endl;
        cout << "\t" << i << "\t--->\t" << roman_numeral(year) << endl;
    }

    // display another group of 50 years of Super Bowl, starting at year 5916 to year 5965
    cout << endl << endl;
    cout << "Please step into the TIME Machine, aboard this flight, into the future..." << endl;
    cout << "\tYear\t\tSuper Bowl" << endl;
    for (int i = SECOND_START; i <= SECOND_END; i++)
    {
        int year = i - START_SUPERBOWL + 1;
        if (i % GROUP == 0)
            cout << endl << "************************************" << endl << endl;
        cout << "\t" << i << "\t--->\t" << roman_numeral(year) << endl;
    }

    return 0;
}
