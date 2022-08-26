#include "Include\Login.h"
#include "Include\Student_Menu.h"
#include "Include\Professor_Menu.h"
#include "Include\Librarian_Menu.h"
#include "Include\User_Database.h"
#include <iostream>
#include <string>

using namespace std;
login::login(user_database* all_users, book_database* all_books){
    cout << "Welcome to the login portal" <<endl <<endl;
    cout << "Enter your ID : ";
    long long int ID;
    cin >> ID;
    cout <<endl;

    cout << "Enter Password : ";
    string password;
    cin.ignore();
    getline(cin, password);
    cout <<endl;

    vector<long long int> indices = all_users->search(ID);
    if (indices[0]== -1){
        cout << "No such user found in the database" <<endl<<endl;
    }
    else{
        user user_1 = all_users->user_list[indices[0]];
        if (user_1.password == password){
            switch(user_1.type){

                case 0:
                {
                    student* student_1 = &all_users->student_list[indices[1]];
                    student_menu(all_users,all_books, student_1);
                    break;
                }

                case 1:
                {
                    professor* professor_1 = &all_users->professor_list[indices[2]];
                    professor_menu(all_users,all_books, professor_1);
                    break;
                }

                case 2:
                {
                    librarian* librarian_1 = &all_users->librarian_list[indices[3]];
                    librarian_menu(all_users,all_books, librarian_1);
                    break;
                }

                default :
                {
                    cout << "Unusual error occured !" <<endl <<endl;
                    break;
                }
            }
        }
        else {
            cout << "Incorrect Password" <<endl << endl;
        }
    }

}