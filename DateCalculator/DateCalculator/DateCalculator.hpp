#pragma once

#include <string>

#define MINIMUM_YEAR 1601

namespace DateCalculator
{
    enum MONTH
    {
        JAN = 1,    // january
        FEB = 2,    // february
        MAR = 3,    // march
        APR = 4,    // april
        MAY = 5,    // may
        JNE = 6,    // june
        JLY = 7,    // july
        AUG = 8,    // august
        SEP = 9,    // september
        OCT = 10,   // october
        NOV = 11,   // november
        DEC = 12    // december
    };

    class Date
    {
    private:
        unsigned int year_ = MINIMUM_YEAR;
        MONTH month_ = JAN;
        unsigned int day_ = 1;

        bool isLeapYear = false;
        unsigned int daysInMonth = 31;

    public:
        Date(MONTH month, unsigned int day, unsigned int year);

        unsigned int GetYear() const;
        MONTH GetMonth() const;
        unsigned int GetDay() const;

        // gets days from minimum year (january 1st of that year).
        unsigned int getDaysFromMinimum() const;

        // Add one date to another to get another date
        friend Date operator+(Date const& arg1, Date const& arg2);

        // Subtract one date from another to get a new date
        friend std::string operator-(Date const& lhs, Date const& rhs);

        // Does lhs date come after rhs date?
        friend bool operator>(Date const& lhs, Date const& rhs);

        // Is date1 == date2 ?
        friend bool operator==(Date const& lhs, Date const& rhs);
    };
}
