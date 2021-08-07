#include "Date.h"

Date::Date()
    :day(1), month(1), year(2001)
{

}

Date::Date(const Date& date)
    : day(date.day), month(date.month), year(date.year)
{

}

Date::Date(int day, int month, int year)
    :day(day), month(month), year(year)
{

}

bool Date::operator==(const Date& date)
{
    return ( this->day == date.day && this->month == date.month && this->year == date.year);
}
