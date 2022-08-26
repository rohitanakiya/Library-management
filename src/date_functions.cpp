#include "Include/date_functions.h"
#include <iostream>

int valid_date_checker(int issue_month, int issue_year, int issue_date){
    if((issue_year > 2040) || (issue_year<2000)){
        //cout << "Invalid Date Added ! Operation Failed" <<endl;
        return 0;
    }
    else{
        if ((issue_month > 12) || (issue_month < 0)){
            //cout << "Invalid Date Added ! Operation Failed" << endl;
            return 0;
        }
        else{
            if ((issue_year %4 == 0)){
                if (issue_month == 2){
                    if(issue_date > 29 || issue_date < 0){
                        //cout << "Invalid Date Added ! Operation Failed" << endl;
                        return 0;
                    }
                }
                else if(issue_month == 4 || issue_month == 6 || issue_month == 9 || issue_month == 11){
                    if(issue_date > 30 || issue_date < 0){
                        //cout << "Invalid Date Added ! Operation Failed" << endl;
                        return 0;                        
                    }
                }
                else{
                    if(issue_date > 31 || issue_date < 0){
                        //cout << "Invalid Date Added ! Operation Failed" << endl;
                        return 0;                        
                    }                    
                }
            }
            else{
                if (issue_month == 2){
                    if(issue_date > 28 || issue_date < 0){
                        //cout << "Invalid Date Added ! Operation Failed" << endl;
                        return 0;
                    }
                }
                else if(issue_month == 4 || issue_month == 6 || issue_month == 9 || issue_month == 11){
                    if(issue_date > 30 || issue_date < 0){
                        //scout << "Invalid Date Added ! Operation Failed" << endl;
                        return 0;                        
                    }
                }
                else{
                    if(issue_date > 31 || issue_date < 0){
                        //cout << "Invalid Date Added ! Operation Failed" << endl;
                        return 0;                        
                    }                    
                }

            }
        }

    }
    return 1;
}

int count_leap_years(int date, int month, int year){
    int years = year;

    if(month <=2){
        years--;
    }

    return years/4 - years/100 + years/400;
}

long long int days_calculator(int day_1, int month_1, int year_1, int day_2, int month_2, int year_2){
    const long long int monthDays[12]= { 31, 28, 31, 30, 31, 30,  31, 31, 30, 31, 30, 31 };
    
    long long int days_1 = 365*year_1 + day_1;
    for (int i = 0; i< month_1-1; i++){
        days_1 += monthDays[i];
    }

    days_1 += count_leap_years(day_1,month_1,year_1);

    long long int days_2 = 365*year_2 + day_2;
    for (int i = 0; i< month_2-1; i++){
        days_2 += monthDays[i];
    }

    days_2 += count_leap_years(day_2,month_2,year_2);


    return(days_2 - days_1);


}


long long int date_to_numeric(int d, int m, int y){
    m = (m + 9) % 12;
    y = y - m/10;
    return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 );

}

std::vector<int> numeric_to_date(long long int g){  
    std::vector<int> date;
    int y,ddd,mi,mm,dd;
    y = (10000*g + 14780)/3652425;
    ddd = g - (365*y + y/4 - y/100 + y/400);
    if (ddd < 0){
        y = y - 1;
        ddd = g - (365*y + y/4 - y/100 + y/400);
    }
    mi = (100*ddd + 52)/3060;
    mm = (mi + 2)%12 + 1;
    y = y + (mi + 2)/12;
    dd = ddd - (mi*306 + 5)/10 + 1;
    date.push_back(dd);
    date.push_back(mm);
    date.push_back(y);
    return(date);

}

