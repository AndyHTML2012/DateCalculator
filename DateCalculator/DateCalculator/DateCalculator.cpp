#include "pch.h" // precompiled header required by visual studio

#include "DateCalculator.hpp"
#include <iostream>

static bool Is_LeapYear(unsigned int year)
{
    if (year % 4 != 0) {
        return false;
    }
    else if (year % 100 != 0) {
        return true;
    }
    else if (year % 400 != 0) {
        return false;
    }
    else {
        return true;
    }
}

namespace DateCalculator
{
    // (month, day, year)
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
                    if (day > 31) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case FEB:
                {
                    if (this->isLeapYear == true) {
                        if (day > 29) { throw std::invalid_argument("Invalid day for month."); }
                        this->daysInMonth = 29;
                    }
                    else {
                        if (day > 28) { throw std::invalid_argument("Invalid day for month."); }
                        this->daysInMonth = 28;
                    }
                    break;
                }
                case MAR:
                    if (day > 31) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case APR:
                    if (day > 30) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 30;
                    break;
                case MAY:
                    if (day > 31) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case JNE:
                    if (day > 30) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 30;
                    break;
                case JLY:
                    if (day > 31) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case AUG:
                    if (day > 31) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case SEP:
                    if (day > 30) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 30;
                    break;
                case OCT:
                    if (day > 31) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                case NOV:
                    if (day > 30) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 30;
                    break;
                case DEC:
                    if (day > 31) { throw std::invalid_argument("Invalid day for month."); }
                    this->daysInMonth = 31;
                    break;
                default:
                    break;
                }

                // If all checks pass, the date is valid
                this->year_ = year;
                this->month_ = month;
                this->day_ = day;
            }
        }
        else {
            throw std::invalid_argument("Invalid year entered.");
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

    unsigned int Date::getDaysFromMinimum() const
    {
        unsigned int days = 0;

        // Add the number of days for each year up to the given year
        for (int year = MINIMUM_YEAR; year < this->year_; ++year) {
            days += year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? 366 : 365;
        }

        // Add the number of days for each month up to the given month in the given year
        for (int month = 1; month < this->month_; ++month) {
            days += this->daysInMonth;
        }

        // Add the day of the month
        days += this->day_;

        return days;
    }

    // Add one date to another to get another date
    Date operator+(Date const& arg1, Date const& arg2)
    {
        UNREFERENCED_PARAMETER(arg1);
        UNREFERENCED_PARAMETER(arg2);
        Date newDate(JAN, 1, 1601);
        return newDate;
    }

    // Get string data of the day, month, year difference between two dates
    std::string operator-(Date const& lhs, Date const& rhs)
    {
        unsigned int dayDiff = 0;
        unsigned int monthDiff = 0;
        unsigned int yearDiff = 0;

        // DETERMINE WHICH YEAR COMES BEFORE AND COMES AFTER USING > OPERATOR
        if (lhs > rhs)
        {
            dayDiff = ( lhs.getDaysFromMinimum() - rhs.getDaysFromMinimum() );
        }
        else if (rhs > lhs)
        {
            dayDiff = (rhs.getDaysFromMinimum() - lhs.getDaysFromMinimum());
        }
        else
        {
            dayDiff = 0;
        }

        // ONCE DETERMINED, GET TOTAL DAYS THAT DATE IS FROM THE MINIMUM YEAR, MONTH, AND DAY

        // RETURN TOTAL DAYS FROM THAT DAY


        

        // Return the difference
        std::string dateDifference = "Years: " + std::to_string(yearDiff) +
                                  ", Months: " + std::to_string(monthDiff) +
                                    ", Days: " + std::to_string(dayDiff);
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
        return false;
    }
}