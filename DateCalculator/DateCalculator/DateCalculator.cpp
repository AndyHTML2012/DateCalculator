#include "pch.h" // precompiled header required by visual studio

#include "DateCalculator.hpp"
#include <iostream>

static bool Is_LeapYear(unsigned int year);

/*!****************************************************************************
 * @brief           Exit function and set print error to console.
 * @param errorMsg  Message to print (automatic newline handled by function)
******************************************************************************/
static void ThrowError(std::string errorMsg)
{
    try
    {
        throw std::invalid_argument(errorMsg);
    }
    catch (const std::exception&)
    {
        std::cout << __FILE__ << ": " << errorMsg << std::endl;
        return;
    }
}

namespace DateCalculator
{
    // Create a date: (month, day, year), default date is January 1st, 1970
    Date::Date(MONTH month, unsigned int day, unsigned int year)
    {
        if (year >= MINIMUM_YEAR)
        {
            this->isLeapYear = Is_LeapYear(year);

            // Check if the day is valid for the given month and year
            if (day >= 1 && day <= 31)
            {
                switch (month)
                {
                case JAN:
                    if (day > 31) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case FEB:
                {
                    if (this->isLeapYear == true) {
                        if (day > 29) { ThrowError("Invalid day for month."); }
                        this->daysInMonth = 29;
                    }
                    else {
                        if (day > 28) { ThrowError("Invalid day for month."); }
                        this->daysInMonth = 28;
                    }
                    break;
                }
                case MAR:
                    if (day > 31) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case APR:
                    if (day > 30) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 30;
                    break;
                case MAY:
                    if (day > 31) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case JNE:
                    if (day > 30) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 30;
                    break;
                case JLY:
                    if (day > 31) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case AUG:
                    if (day > 31) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case SEP:
                    if (day > 30) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 30;
                    break;
                case OCT:
                    if (day > 31) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case NOV:
                    if (day > 30) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 30;
                    break;
                case DEC:
                    if (day > 31) { ThrowError("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                default:
                    break;
                }

                // Handle gregorian removed dates in 1752
                if (year == 1752 && month == SEP)
                {
                    if (day > 2 && day < 14)
                    {
                        this->year_ = 0;
                        ThrowError("Date does not exist on gregorian calendar.");
                        return;
                    }
                    else
                    {
                        this->daysInMonth = 19;
                    }
                }

                // If all checks pass, the date is valid
                this->year_ = year;
                this->month_ = month;
                this->day_ = day;
            }
        }
        else 
        {
            ThrowError("Invalid year entered.");
            return;
        }
    }

    unsigned int Date::GetYear() const
    {
        return this->year_;
    }

    MONTH Date::GetMonth() const
    {
        return this->month_;
    }

    unsigned int Date::GetDay() const
    {
        return this->day_;
    }

    UINT32 Date::getDaysFromMinimum() const
    {
        UINT32 days = 0;

        // Add the number of days for each year up to the given year
        for (unsigned int year = MINIMUM_YEAR; year < this->year_; ++year) {
            days += year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? 366 : 365;
        }

        // Add the number of days for each month up to the given month in the given year
        for (unsigned int month = 1; month < this->month_; ++month) {
            days += this->daysInMonth;
        }

        // Add the day of the month
        days += this->day_;

        return days;
    }

    // Get string data of the day, month, year difference between two dates
    std::string operator-(Date const& lhs, Date const& rhs)
    {
        UINT32 days = 0;
        UINT32 dayDiff = 0;
        unsigned int monthDiff = 0;
        unsigned int yearDiff = 0;

        UINT32 d1 = lhs.getDaysFromMinimum();
        UINT32 d2 = rhs.getDaysFromMinimum();

        // DETERMINE WHICH YEAR COMES BEFORE AND COMES AFTER USING > OPERATOR
        if (lhs > rhs)
        {
            days = (d1 - d2);
        }
        else if (rhs > lhs)
        {
            days = (d2 - d1);
        }
        else
        {
            days = 0;
        }

        /*
            FIXME: a better solution should be found to filter days into months and years while
            taking notice of the following annomolys:
            - leap years (the addition of 1 day about every 4 years).
            - September of 1752 (aka. evil)
        */

        // Calculate time difference (in days, months, years)
        yearDiff = days / 365;
        days %= 365;

        // FIXME: find more accurate way of filtering days to months without using magic number
        monthDiff = days / 30;
        days %= 30;

        dayDiff = days;

        // Return the difference
        std::string dateDifference = "Years: " + std::to_string(yearDiff) +
                                  "\rMonths: " + std::to_string(monthDiff) +
                                    "\rDays: " + std::to_string(dayDiff);
        return dateDifference;
    }

    bool operator>(Date const& lhs, Date const& rhs)
    {
        // if lhs year comes after rhs year
        if (lhs.year_ > rhs.year_)
        {
            return true;
        }
        else if (lhs.year_ == rhs.year_)
        {
            // if lhs month comes after rhs month in same year
            if (lhs.month_ > rhs.month_)
            {
                return true;
            }
            else if (lhs.month_ == rhs.month_)
            {
                // if lhs day comes after rhs day in same month
                if (lhs.day_ > rhs.day_)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator==(Date const& lhs, Date const& rhs)
    {
        if (lhs.year_ == rhs.year_ &&
            lhs.isLeapYear == rhs.isLeapYear &&
            lhs.daysInMonth == rhs.daysInMonth)
        {
            if (lhs.month_ == rhs.month_)
            {
                if (lhs.day_ == rhs.day_)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void Date::AddYear(unsigned int yearsToAdd)
    {
        UNREFERENCED_PARAMETER(yearsToAdd);
    }

    void Date::AddMonth(unsigned int monthsToAdd)
    {
        UNREFERENCED_PARAMETER(monthsToAdd);
    }

    void Date::AddDay(unsigned int daysToAdd)
    {
        UNREFERENCED_PARAMETER(daysToAdd);
    }
}

static bool Is_LeapYear(unsigned int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return true;
    }
}
