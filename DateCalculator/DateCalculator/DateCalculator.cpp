#include "pch.h"
#include "DateCalculator.hpp"
#include <iostream>
#include <typeinfo>

// TODO: Where calculation functionality will go

using namespace DateCalculator;

static bool isLeapYear(unsigned int year) 
{
    if (year % 4 != 0) 
    {
        return false;
    }
    else if (year % 100 != 0) 
    {
        return true;
    }
    else if (year % 400 != 0) 
    {
        return false;
    }
    else {
        return true;
    }
}

Date::Date(unsigned int month, unsigned int day, unsigned int year)
{
    // determine if year is valid


    // determine if month is valid


    // determine if day is valid


    day_ = day;
    month_ = month;
    year_ = year;
}

Date::~Date()
{
    // No Memory to Free
}

unsigned int Date::GetYear() const
{
    return year_;
}

unsigned int Date::GetMonth() const
{
    return month_;
}

unsigned int Date::GetDay() const
{
    return day_;
}

void Date::SetYear(unsigned int year)
{
    year_ = year;
}

void Date::SetMonth(unsigned int month)
{
    month_ = month;
}

void Date::SetDay(unsigned int day)
{
    day_ = day;
}

void Date::Display() const
{
    std::cout << typeid(this).name() << " : " << month_ << "/" << day_ << "/" << year_ << std::endl;
}

unsigned int Difference::BetweenDays(unsigned int x, unsigned int y)
{
    return 0;
}

unsigned int Difference::BetweenMonths(unsigned int x, unsigned int y)
{
    
    return 0;
}

unsigned int Difference::BetweenYears(unsigned int x, unsigned int y)
{
    
    return 0;
}

Date Difference::BetweenDates(Date x, Date y)
{
    Date foo(0, 0, 0);

    return foo;
}