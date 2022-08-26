#include "Include/Librarian_Menu.h"
#include <iostream>

using namespace std;

librarian_menu::librarian_menu(user_database* all_users, book_database* all_books, librarian* librarian_1){
    cout << endl << "Welcome to the Librarian Portal " << librarian_1->name << endl <<endl;

    int flag = 1;
    while(flag){
        cout <<"Press 1 if you wish to add a book to the book database" <<endl;
        cout <<"Press 2 if you wish to remove a book from the the book database" <<endl;
        cout <<"Press 3 if you wish to update a book from the book database" <<endl;
        cout <<"Press 4 if you wish to add a user to the user database"<<endl;
        cout <<"Press 5 if you wish to remove a user from the user database"<<endl;
        cout <<"Press 6 if you wish to update a user from the user database" <<endl;
        cout <<"Press 7 if you wish to issue a book to a user" <<endl;
        cout <<"Press 8 if you wish to initiate a return of the book by a user" <<endl;
        cout <<"Press 9 if you wish to see the entire user list" <<endl;
        cout <<"Press 10 if you wish to see the entire book list" <<endl;
        cout <<"Press 11 if you wish to see the entire student list"<<endl;
        cout <<"Press 12 if you wish to see the entire professor list"<<endl;
        cout <<"Press 13 if you wish to see the entie librarian list" <<endl;
        cout <<"Press 14 if you wish to see the issuer of a book" <<endl;
        cout <<"Press 15 if you wish to see the fine of a user for an issued book" <<endl;
        cout <<"Press 16 if you wish to logout" <<endl<<endl;
        cout <<"Enter your option : ";
        int option;
        cin >> option;
        cout <<endl;
        switch(option){
            case 1:
            {
                cout << "You have entered the portal to add books to the database!" <<endl<<endl;
                all_books->add();
                break;
            }

            case 2:
            {
                cout <<"You have entered the portal to remove books from the database !" <<endl <<endl;
                all_books->remove();
                cout <<endl;
                break;
            }

            case 3:
            {
                cout <<"You have entered the portal to update books from the database !" <<endl <<endl;
                all_books->update();
                break;
            }

            case 4:
            {
                cout <<"You have entered the portal to add users to the database !"<<endl <<endl;
                all_users->add();
                break;
            }

            case 5:
            {
                cout << "You have entered the portal to remove users from the database !" <<endl <<endl;
                all_users->remove();
                break;
            }

            case 6:
            {
                cout << "You have entered the portal to update users from the database !" <<endl <<endl;
                all_users->update();
                break;
            }

            case 7:
            {
                cout << "You have entered the portal to issue books to the user from the database !" <<endl <<endl;
                cout << "Enter User ID : ";
                long long int requested_ID;
                cin >> requested_ID;
                cout <<endl;
                vector<long long int> user_index = all_users->search(requested_ID);

                cout << "Enter Book ISBN : ";
                long long int requested_ISBN;
                cin >> requested_ISBN;
                cout <<endl;
                long long int book_index = all_books->search(requested_ISBN);

                if(user_index[0] == -1){
                    cout << "No such user found in the database." <<endl <<endl;
                }
                else{
                    if(book_index == -1){
                        cout << "No such book found in the database. " <<endl <<endl;
                    }
                    else{
                        int type = all_users->user_list[user_index[0]].type;
                        book* book_1 = &(all_books->book_list[book_index]);
                        switch(type){
                            case 0:
                            {
                                student student_1 = all_users->student_list[user_index[1]];
                                int n = student_1.issued_book_list.book_list.size();
                                if (n < student_1.max_issues_allowed){
                                    cout << "Issuing the book : " << book_1 ->title <<endl;
                                    cout << "The issuer is : " << student_1.name <<endl <<endl;
                                    student_1.issue_book(book_1);
                                    all_users->student_list[user_index[1]] = student_1;
                                }

                                else{
                                    cout << "You have already issued " << student_1.max_issues_allowed << " ! You have reached your limit" <<endl<<endl;
                                }

                                break;
                            }

                            case 1:
                            {
                                professor professor_1 = all_users->professor_list[user_index[2]];
                                cout << "Issuing the book : " << book_1 ->title <<endl;
                                cout << "The issuer is : " << professor_1.name <<endl << endl;
                                professor_1.issue_book(book_1);   
                                all_users->professor_list[user_index[2]] = professor_1;                        
                                break;
                            }

                            case 2:
                            {
                                cout << "Librarians cant issue book ! Process terminated" <<endl <<endl;
                                break;
                            }

                            default:
                            {
                                cout << "Unsual error occured !" <<endl <<endl;
                                break;
                            }
                        }
                    }
                }

                break;
            }

            case 8:
            {
                cout << "You have entered the portal to return books issued by the user !" <<endl <<endl;
                cout << "Enter User ID : ";
                long long int requested_ID;
                cin >> requested_ID;

                vector<long long int> user_index = all_users->search(requested_ID);

                
                if(user_index[0] == -1){
                    cout << "No such user found in the database." <<endl <<endl;
                }
                else{
                    switch(all_users->user_list[user_index[0]].type){
                        case 0:
                        {
                            cout << "The books issued by the user are : "<<endl <<endl;
                            all_users->student_list[user_index[1]].issued_book_list.display();
                            break;
                        }

                        case 1:
                        {
                            cout << "The books issued by the user are : "<<endl <<endl;
                            all_users->professor_list[user_index[2]].issued_book_list.display();
                            break;
                        }

                        case 2:
                            cout << "Librarians can't issue books !!" <<endl <<endl;

                    }
                    if(all_users->user_list[user_index[0]].type !=2){
                        cout << "Enter Book ISBN : ";
                        long long int requested_ISBN;
                        cin >> requested_ISBN;
                        long long int book_index = all_books->search(requested_ISBN);
                        if(book_index == -1){
                            cout << "No such book found in the database. " <<endl <<endl;
                        }
                        else{
                            cout << "The user is : " <<endl;
                            all_users->user_list[user_index[0]].display();
                            int type = all_users->user_list[user_index[0]].type;
                            book* book_1 = &(all_books->book_list[book_index]);
                            switch(type){
                                case 0:
                                {
                                    student student_1 = all_users->student_list[user_index[1]];   
                                    cout <<endl<< "Returning the book : " << book_1 -> title <<endl<<endl;
                                    student_1.return_book(book_1);
                                    all_users->student_list[user_index[1]] = student_1;


                                    break;
                                }

                                case 1:
                                {
                                    professor professor_1 = all_users->professor_list[user_index[2]];
                                    cout << "Returning the book : " << book_1 ->title <<endl <<endl;
                                    professor_1.return_book(book_1);   
                                    all_users->professor_list[user_index[2]] = professor_1;                        
                                    break;
                                }

                                case 2:
                                {
                                    cout << "Librarians cant issue or return book ! Process terminated" <<endl <<endl;
                                    break;
                                }

                                default:
                                {
                                    cout << "Unsual error occured !" <<endl <<endl;
                                    break;
                                }
                            }
                        }
                    }
                }

                break;
            }


            case 9:
            {
                cout <<"You have entered the portal to see the entire user list !" <<endl<<endl;
                all_users->display();
                break;
            }

            case 10:
            {
                cout <<"You have entered the portal to see the entire book list !" <<endl<<endl;
                all_books->display();
                break;
            }

            case 11:
            {
                cout <<"You have entered the portal to see the entire student list !" <<endl<<endl;
                all_users->show_students();
                break;
            }

            case 12:
            {
                cout <<"You have entered the portal to see the entire professor list !" <<endl<<endl;
                all_users-> show_professors();
                break;
            }
            
            case 13:
            {
                cout << "You have entered the portal to see the entire librarian list !" <<endl <<endl;
                all_users-> show_librarians();
                break;
            }

            case 14:
            {
                cout << "Enter Book ISBN : ";
                long long int requested_ISBN;
                cin >> requested_ISBN;
                cout <<endl;
                long long int index = all_books->search(requested_ISBN);
                if(index == -1){
                    cout << "The book has not been issued by anyone";
                }
                else{
                    book book_1 = all_books->book_list[index];
                    cout << "The book has been issued by user ID : " << book_1.issuer_ID; 
                }


            }

            case 15:
            {
                cout << "Enter User ID : ";
                long long int requested_ID;
                cin >> requested_ID;
                cout << endl;

                vector<long long int> indices = all_users->search(requested_ID);
                if(indices[0]==-1){
                    cout << "No such user exists in the database !" <<endl <<endl;
                }
                else{
                    switch(all_users->user_list[indices[0]].type){

                        case 0: 
                        {
                            student student_1 = all_users->student_list[indices[1]];
                            cout << "The entire issued book list for the user is : "<<endl <<endl;
                            student_1.issued_book_list.display();
                            cout << "Enter Book ISBN : ";
                            long long int requested_ISBN;
                            cin >> requested_ISBN;
                            cout << endl;
                            long long int index = student_1.issued_book_list.search(requested_ISBN);
                            if (index == -1){
                                cout << "No such book has been issued !" <<endl <<endl;
                            }
                            else{
                                student_1.calculate_fine_for_book(student_1.issued_book_list.book_list[index]);
                            }
                            break;
                        }

                        case 1:
                        {
                            professor professor_1 = all_users->professor_list[indices[2]];
                            cout << "The entire issued book list for the user is : "<<endl <<endl;
                            professor_1.issued_book_list.display();
                            cout << "Enter Book ISBN : ";
                            long long int requested_ISBN;
                            cin >> requested_ISBN;
                            cout << endl;
                            long long int index = professor_1.issued_book_list.search(requested_ISBN);
                            if (index == -1){
                                cout << "No such book has been issued !" <<endl <<endl;
                            }
                            else{
                                professor_1.calculate_fine_for_book(professor_1.issued_book_list.book_list[index]);
                            }
                            break;
                        }

                        case 2:
                        {
                            cout << "Librarians cant issue books !" <<endl<<endl;

                            break;
                        }
                        default :
                        {
                            cout << "Unsual error occured !" <<endl <<endl;
                            break;
                        }
                    }
                }

                break;
            }

            case 16:
            {
                flag = 0;
                cout << endl << "Logging out !!" <<endl;
                break;
            }

            default:
            {
                cout << endl << "Wrong option enter" <<endl <<endl;
                break;
            }
        }
    }

}