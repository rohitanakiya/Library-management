#pragma once
#include<vector>
#include "Book_database.h"
#include "User.h"
class professor: public user{
    public:
    long long int fine_amount;
    int fine_per_day;
    book_database issued_book_list;
    int issue_length;
    
    //Functions
    void issue_book( book* book_1);
    void calculate_fines();
    //void clear_fine_amount();
    void return_book( book* book_1);
    void calculate_fine_for_book(book book_1);
    professor();
};