#pragma once
#include <vector>
int valid_date_checker(int issue_month, int issue_year, int issue_date );
int count_leap_years(int day, int month, int year);
long long int days_calculator(int day_1, int month_1, int year_1, int day_2, int month_2, int year_2);
long long int date_to_numeric(int day, int month, int year);
std::vector<int> numeric_to_date(long long int g);

