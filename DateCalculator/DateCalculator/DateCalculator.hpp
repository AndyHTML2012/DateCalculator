/*!****************************************************************************
 * @File             DateCalculator.hpp
 * @Author           Andres Trujillo
 * @Date             2/24/2024
 * @Brief            This program for finding the difference between two dates
                     and performing arithmetic operations on dates.
******************************************************************************/
#pragma once

#include <string>
#include <cstdint> // UINT32

constexpr auto MINIMUM_YEAR = 1601;

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

    /*!
     * @brief Object that stores date and its relating information.
     */
    class Date
    {
    private:
        unsigned int year_ = 1970;
        MONTH month_ = JAN;
        unsigned int day_ = 1;

        bool isLeapYear = false;
        unsigned int daysInMonth = 31;

    public:
        Date(MONTH month = JAN, unsigned int day = 1, unsigned int year = 1970);

        unsigned int GetYear() const;                // Get Year
        MONTH GetMonth() const;                      // Get Month
        unsigned int GetDay() const;                 // Get Day

        // gets days from minimum year (january 1st of that year).
        UINT32 getDaysFromMinimum(unsigned int yearToCountFrom) const;

        // Subtract one date from another to get a new date
        // Returns: formatted string of day, month, and year difference between both dates
        friend std::string operator-(Date const& lhs, Date const& rhs);

        // Does lhs date come after rhs date?
        friend bool operator>(Date const& lhs, Date const& rhs);

        // Is date1 == date2 ?
        friend bool operator==(Date const& lhs, Date const& rhs);

        // Copy Assign date
        Date& operator=(Date const& rhs);

        void AddYears(unsigned int yearsToAdd);      // add years to date
        void AddMonths(unsigned int monthsToAdd);    // add months to date
        void AddDays(unsigned int daysToAdd);        // add days to date

        void SubYears(unsigned int yearsToSub);      // sub years from date
        void SubMonths(unsigned int monthsToSub);    // sub months from date
        void SubDays(unsigned int daysToSub);        // sub days from date
    };
}
