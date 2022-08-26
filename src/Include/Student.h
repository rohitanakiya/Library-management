#pragma once
#include<vector>
#include "Book_database.h"
#include "User.h"
class student: public user{
    public:
    //long long int fine_amount;
    book_database issued_book_list;
    int fine_per_day;
    int issue_length;
    int max_issues_allowed;
    
    //Functions
    void issue_book(book* book_1);
    void calculate_fines();
    //void clear_fine_amount();
    void return_book(book* book_1);
    void calculate_fine_for_book(book book_1);
    student();
};