#pragma once
#include<vector>
#include "user.h"
#include "Librarian.h"
#include "Student.h"
#include "Professor.h"

class user_database{
    public:
    std::vector<user> user_list;
    std::vector<student> student_list;
    std::vector<professor> professor_list;
    std::vector<librarian> librarian_list;

    //Functions
    void add();
    void update();
    void remove();
    std::vector<long long int> search(long long int ID);
    void display();
    void show_students();
    void show_professors();
    void show_librarians();

    //Friend Classes
    friend class librarian;
};