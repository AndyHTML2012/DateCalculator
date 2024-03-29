/*!****************************************************************************
 * @File             DateCalculator.cpp
 * @Author           Andres Trujillo
 * @Date             2/24/2024
 * @Brief            This program for finding the difference between two dates
                     and performing arithmetic operations on dates.
******************************************************************************/

#include "pch.h" // precompiled header required by visual studio

#include "DateCalculator.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <cmath>

static bool Is_LeapYear(unsigned int year);
static unsigned int Days_InMonth(unsigned int month, unsigned int year);

// Exit function and set print error to console.
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

    UINT32 Date::getDaysFromMinimum(unsigned int yearToCountFrom) const
    {
        UINT32 days = 0;

        static const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Add the number of days for each year up to the given year
        for (unsigned int y = yearToCountFrom; y < year_; ++y) 
        {
            days += ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 366 : 365;
        }

        // Add the number of days for each month up to the given month in the given year
        for (unsigned int m = 1; m < month_; ++m) 
        {
            days += daysInMonth[m - 1];
            if (m == 2 && this->isLeapYear) 
            {
                ++days;
            }
        }

        // Add the day of the month
        days += day_;

        return days;
    }

    // Get string data of the day, month, year difference between two dates
    std::string operator-(Date const& lhs, Date const& rhs)
    {
        UINT32 days = 0;
        UINT32 dayDiff = 0;
        unsigned int monthDiff = 0;
        unsigned int yearDiff = 0;

        UINT32 d1 = lhs.getDaysFromMinimum(MINIMUM_YEAR);
        UINT32 d2 = rhs.getDaysFromMinimum(MINIMUM_YEAR);

        unsigned int currentYear = 0;

        // DETERMINE WHICH YEAR COMES BEFORE AND COMES AFTER USING > OPERATOR
        if (lhs > rhs)
        {
            days = (d1 - d2);
            currentYear = lhs.year_;
        }
        else if (rhs > lhs) // 2024 > 2020
        {
            days = (d2 - d1);
            currentYear = rhs.year_;
        }
        else
        {
            days = 0;
        }

        unsigned int currentTotal = days;
        unsigned int startYear = 0;
        unsigned int endYear = 0;

        if (lhs.year_ > rhs.year_)
        {
            startYear = rhs.year_;
            endYear = lhs.year_;
        }
        else {
            startYear = lhs.year_;
            endYear = rhs.year_;
        }

        // Adjust for leap years and the actual number of days in each month
        for (unsigned int year = startYear; year <= endYear; ++year) 
        {
            for (unsigned int month = 1; month <= 12; ++month) 
            {
                unsigned int days_this_month = Days_InMonth(month, year);
                if (currentTotal >= days_this_month)
                {
                    currentTotal -= days_this_month;
                    if (month == 12) 
                    {
                        ++yearDiff;
                        monthDiff = 0;
                    }
                    else 
                    {
                        ++monthDiff;
                    }
                }
                else 
                {
                    currentTotal = 0;
                    break;
                }
            }
            if (currentTotal == 0)
            {
                break;
            }
        }

        dayDiff = currentTotal;

        // Return the difference
        std::string dateDifference = "Years: " + std::to_string(yearDiff) +
                                  "\nMonths: " + std::to_string(monthDiff) +
                                    "\nDays: " + std::to_string(dayDiff);
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

    Date& Date::operator=(Date const& rhs)
    {
        if (&rhs == this)
        {
            return *this;
        }
        else
        {
            this->year_ = rhs.GetYear();
            this->month_ = rhs.GetMonth();
            this->day_ = rhs.GetDay();
            this->isLeapYear = Is_LeapYear(this->year_);
            this->daysInMonth = Days_InMonth(this->month_, this->year_);

            return *this;
        }
    }

    void Date::AddYears(unsigned int yearsToAdd)
    {
        this->year_ += yearsToAdd;
    }

    void Date::AddMonths(unsigned int monthsToAdd)
    {
        std::array<MONTH, 12> months = {JAN, FEB, MAR, APR, MAY, JNE, JLY, AUG, SEP, OCT, NOV, DEC};
        unsigned int yearsToAdd = 0;

        for (int i = 0; (monthsToAdd / 12) >= 1; ++i)
        {
            yearsToAdd++;
            monthsToAdd -= 12;
        }

        this->AddYears(yearsToAdd);
        MONTH startMonth = this->month_;
        MONTH currentMonth = startMonth;

        for (int m = 0; m < monthsToAdd; ++m)
        {
            if (currentMonth == DEC)
            {
                this->AddYears(1);
                currentMonth = months[0];
            }
            else if (currentMonth < DEC)
            {
                currentMonth = months[currentMonth];
            }
        }

        this->month_ = currentMonth;
    }

    void Date::AddDays(unsigned int daysToAdd)
    {
        while (daysToAdd > 0) 
        {
            unsigned int daysInCurrentMonth = Days_InMonth(this->month_, this->year_);
            if (this->day_ + daysToAdd <= daysInCurrentMonth)
            {
                this->day_ += daysToAdd;
                daysToAdd = 0;
            }
            else 
            {
                daysToAdd -= (daysInCurrentMonth - this->day_ + 1);
                this->day_ = 1;
                AddMonths(1);
            }

            // Special case for dates removed in September 1752
            if (this->year_ == 1752 && this->month_ == SEP)
            {
                if (this->day_ < 14)
                {
                    this->day_ = 14;
                }
            }
        }
    }

    void Date::SubYears(unsigned int yearsToSub)
    {
        for (unsigned int i = 0; (i < yearsToSub) && (this->year_ > 0); ++i)
        {
            this->year_--;
        }
    }

    void Date::SubMonths(unsigned int monthsToSub)
    {
        std::array<MONTH, 12> months = { JAN, FEB, MAR, APR, MAY, JNE, JLY, AUG, SEP, OCT, NOV, DEC };

        while (monthsToSub > 0)
        {
            if (monthsToSub >= this->month_)
            {
                monthsToSub -= this->month_;
                this->month_ = DEC;
                this->SubYears(1);
            }
            else 
            {
                this->month_ = static_cast<MONTH>(this->month_ - monthsToSub);
                monthsToSub = 0;
            }
        }

        // Check if day is valid for the new month, adjust if necessary
        unsigned int daysInMonth = Days_InMonth(this->month_, this->year_);

        if (this->day_ > daysInMonth) 
        {
            this->day_ = daysInMonth;
        }
    }

    void Date::SubDays(unsigned int daysToSub)
    {
        while (daysToSub > 0)
        {
            if (daysToSub >= this->day_)
            {
                daysToSub -= this->day_;
                SubMonths(1);
                day_ = Days_InMonth(this->month_, this->year_);
            }
            else
            {
                this->day_ -= daysToSub;
                daysToSub = 0;
            }

            // Special case for dates removed in September 1752
            if (this->year_ == 1752 && this->month_ == 9)
            {
                if (this->day_ > 2 && this->day_ < 14)
                {
                    // If subtracting days crosses the missing dates, adjust accordingly
                    if (daysToSub >= this->day_ - 2)
                    {
                        daysToSub -= (this->day_ - 2);
                        this->day_ = 2;
                    }
                    else 
                    {
                        this->day_ -= daysToSub;
                        daysToSub = 0;
                    }
                }
            }
        }
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
        return false;
    }
}

static unsigned int Days_InMonth(unsigned int month, unsigned int year) 
{
    // Array of days in each month, assuming non-leap year
    std::vector<unsigned int> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // If it's February and a leap year, return 29 days
    if (month == 2 && Is_LeapYear(year)) 
    {
        return 29;
    }

    // Otherwise, return the number of days from the array
    return days_in_month[month - 1];
}
