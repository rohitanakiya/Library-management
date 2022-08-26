#include "Include/Initialization.h"
#include "Include/User_Database.h"
#include "Include/Login.h"
#include "Include/Book_database.h"
#include <iostream>

using namespace std;

initialization::initialization(){
    cout <<endl;
    cout << "Welcome to the Library Management System !!" <<endl <<endl;
    user_database all_users;
    book_database all_books;

    cout << "Kindly Intialize the user database" <<endl <<endl;
    int flag1 = 1;
    while(flag1){
        cout << "Press 1 if you wish to an user add to the database" <<endl;
        cout << "Press 2 if you wish to an user delete an entry to the database" <<endl;
        cout << "Press 3 if you wish to update an user of the database" <<endl ;
        cout << "Press 4 if you wish to see the entire user database" <<endl;
        cout << "Press 5 if you wish to see the entire student database" <<endl;
        cout << "Press 6 if you wish to see the entire professor database" <<endl;
        cout << "Press 7 if you wish to see the entire librarian database" <<endl;
        cout << "Press 8 if you wish to end the initialization of the user database" <<endl << endl;
        cout << "Enter your option : ";


        int option;
        cin >> option;
        cout << endl;
        switch(option){

            case 1:
            {
                all_users.add();
                break;
            }

            case 2:
            {
                all_users.remove();
                break;
            }

            case 3:
            {
                all_users.update();
                break;
            }

            case 4:
            {   
                all_users.display();
                //all_users.show_students();
                //all_users.show_professors();
                //all_users.show_librarians();
                //flag1 = 0;
                cout << endl;
                //login logging_in(&all_users);
                break;
            }

            case 5:
            {
                all_users.show_students();
                cout <<endl;
                break;
            }

            case 6:
            {
                all_users.show_professors();
                cout <<endl;
                break;
            }

            case 7:
            {
                all_users.show_librarians();
                cout <<endl;
                break;
            }

            case 8:
            {
                flag1 = 0;
                cout <<endl;
                break;
            }

            default:
            {
                cout << "Incorrect option added" <<endl <<endl;
                break;
            }
        }
    }

    cout << "Kindly initialize the book database" << endl << endl;
    int flag2 = 1;
    while(flag2){
        cout << "Press 1 if you wish to add a new book to the database" << endl;
        cout << "Press 2 if you want to remove a book from the database" << endl;
        cout << "Press 3 if you want to update a book from the database" <<endl;
        cout << "Press 4 if you want to view the entire book database" <<endl;
        cout << "Press 5 if you want to end the initialization of the book database" <<endl <<endl;
        cout << "Enter your option : ";
        int option ;
        cin >> option;
        cout <<endl;
        switch(option){
            case 1 :
            {
                all_books.add();
                break;
            }

            case 2:
            {
                all_books.remove();
                break;
            }

            case 3:
            {
                all_books.update();
                break;
            }

            case 4:
            {
                cout << "The entire book list is as follows : "<<endl;
                all_books.display();
                cout <<endl;
                break;
            }

            case 5:
            {
                flag2 = 0;
                cout <<endl;
                break;
            }

            default:
            {
                cout << "Wrong option selected" << endl <<endl;
                break;
            }

        }
    }

    int flag3 = 1;
    while(flag3){
        cout << endl;
        cout << "Press 0 if you want to close the application"<<endl;
        cout << "Press 1 if you want to enter the login portal" <<endl <<endl;
        cout << "Enter your option : ";
        int option;
        cin >> option;
        switch(option){
            case 0 :
            {
                flag3 = 0;
                break;
            }
            case 1 :
            {
                login login_1(&all_users, &all_books);
                break;
            }
            default :
            {
                cout << "Wrong option selected" <<endl <<endl; 
                break;
            }
        }
    }


}