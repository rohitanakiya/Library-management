#pragma once
#include<string>
#include "Librarian.h"

class book {
    public:
    std::string author;
    std::string title;
    long long int ISBN;
    std::string publication;
    int issue_status;
    int issue_month;
    int issue_date;
    int issue_year;
    long long int issuer_ID;
    long long int issuer_type;
    
    //Functions
    void display();
    void book_request();
    void show_duedate(int type);
    book();

    //Friend Class
    friend class librarian;
};