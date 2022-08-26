#pragma once
#include<vector>
#include<string>
#include "Book.h"
#include "Librarian.h"
class book_database{
    public:
    std::vector<book> book_list;

    //Functions
    void display(void);
    void add(void);
    void update(void);
    void remove(void);
    long long int search(long long int ISBN_requested);

    //Friend Classes
    friend class librarian;
};