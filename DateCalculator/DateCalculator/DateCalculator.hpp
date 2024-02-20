#pragma once

#include <string>
#include <cstdint> // UINT32 incase platform only supports 

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
        Date(MONTH month = JAN, unsigned int day = 1, unsigned int year = 1970);

        unsigned int GetYear() const;
        MONTH GetMonth() const;
        unsigned int GetDay() const;

        // gets days from minimum year (january 1st of that year).
        UINT32 getDaysFromMinimum() const;

        // Subtract one date from another to get a new date
        // Returns: formatted string of day, month, and year difference between both dates
        friend std::string operator-(Date const& lhs, Date const& rhs);

        // Does lhs date come after rhs date?
        friend bool operator>(Date const& lhs, Date const& rhs);

        // Is date1 == date2 ?
        friend bool operator==(Date const& lhs, Date const& rhs);

        void AddYear(unsigned int yearsToAdd);      // add years to date
        void AddMonth(unsigned int monthsToAdd);    // add months to date
        void AddDay(unsigned int daysToAdd);        // add days to date
    };
}
