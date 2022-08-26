#include "Include/Student_Menu.h"
#include <iostream>

using namespace std;

student_menu :: student_menu(user_database* all_users, book_database* all_books, student* student_1){
    cout << endl <<  "Welcome to the student portal " << student_1->name << endl << endl ;
    int flag = 1;
    while(flag){
        cout << "Press 1 if you want to display all the books in the database" <<endl;
        cout << "Press 2 if you want to display all your issued books" <<endl;
        cout << "Press 3 if you want to check availability of book" <<endl;
        cout << "Press 4 if you want to check your total fine " <<endl;
        cout << "Press 5 if you want to check return date of your book" << endl;
        cout << "Press 6 if you want to check fine for a particular book" <<endl;
        cout << "Press 7 if you want to logout" <<endl <<endl;
        int option;

        cout << "Enter your option : ";
        cin >> option;
        cout <<endl;

        switch(option){
            case 1:
            {
                cout <<endl <<"All the books in the database is "<< endl;
                all_books->display();
                break;
            }

            case 2:
            {   
                long long int n = student_1->issued_book_list.book_list.size();
                if (n > 0){
                cout << endl <<"Your issued book list is : "<<endl;
                student_1->issued_book_list.display();
                }
                else{
                    cout << "You havent issued any books." <<endl <<endl;
                }
                break;
            }

            case 3:
            {
                cout << "Enter Book ISBN : ";
                long long int ISBN_requested;
                cin >> ISBN_requested;
                cout <<endl;
                long long int index = all_books->search(ISBN_requested);
                book book_1 = all_books->book_list[index];
                book_1.display();
                book_1.book_request();
                break;
            }

            case 4:
            {
                student_1->calculate_fines();
                break;
            }

            case 5:
            {
                cout << "Enter Book ISBN : ";
                long long int requested_ISBN;
                cin >> requested_ISBN;
                cout <<endl;

                long long int index = student_1->issued_book_list.search(requested_ISBN);
                if(index == -1){
                    cout << "No such book has been issued" <<endl <<endl;
                    
                }
                else{
                    student_1->issued_book_list.book_list[index].show_duedate(0);
                }
                break;
            }

            case 6:{
                cout << "The entire issued book list is : " <<endl <<endl;
                student_1->issued_book_list.display();
                cout <<endl;
                cout << "Enter book ISBN : ";
                long long int requested_ISBN;
                cin >> requested_ISBN;

                long long int index = student_1->issued_book_list.search(requested_ISBN);
                if(index==-1){
                    cout <<"You haven't issued this book" << endl <<endl;
                }  
                else{
                    book book_1 = student_1->issued_book_list.book_list[index];
                    student_1 ->calculate_fine_for_book(book_1);
                }
                break;
            }


            case 7:
            {
                flag = 0;
                cout << endl << "Logging out !!" <<endl;
                break;
            }
            
            default:
            {
                cout << "Wrong option entered" <<endl;
                break;
            }
        }
    }

}