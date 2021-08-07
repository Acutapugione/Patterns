#pragma once
struct Date{
    int day;
    int month;
    int year;

    Date();
    Date(const Date& date);
    Date(int day, int month, int year);

    bool operator==(const Date& date);
};
