#pragma once

namespace DateCalculator
{

    class Date
    {
    private:
        unsigned int year_ = 0;
        unsigned int month_ = 0;
        unsigned int day_ = 0;
    public:
        // Constructor
        Date(unsigned int month, unsigned int day, unsigned int year);

        // Deconstructor
        ~Date();

        // Date Retrievers

        unsigned int GetYear() const;
        unsigned int GetMonth() const;
        unsigned int GetDay() const;

        // Date Modifiers

        void SetYear(unsigned int year);
        void SetMonth(unsigned int month);
        void SetDay(unsigned int day);

        // Print Date in console MONTH/DAY/YEAR style
        void Display() const;

    };

    namespace Difference
    {
        unsigned int BetweenYears(unsigned int x, unsigned int y);
        unsigned int BetweenMonths(unsigned int x, unsigned int y);
        unsigned int BetweenDays(unsigned int x, unsigned int y);

        Date BetweenDates(Date x, Date y);
    }

    //namespace Arithmetic
    //{

    //}

}