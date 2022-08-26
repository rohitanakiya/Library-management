#include <iostream>
#include "Include/User_Database.h"

using namespace std;

void user_database::add(){
    user user_1;
    cin.ignore();
    cout << "Enter username : ";
    getline(cin, user_1.name);
    cout <<endl;
    cout << "Enter Password: ";
    cin >> user_1.password;
    cout<<endl;

    cout << "Enter ID: ";
    cin >> user_1.id;
    cout <<endl;


    cout << "Enter 0 if user is student" <<endl;
    cout << "Enter 1 if user is professor" <<endl;
    cout << "Enter 2 if user is librarian" <<endl<<endl;

    int i;
    cout << "Enter your option : ";
    cin >>i;
    cout <<endl;
    vector<long long int> indices = search(user_1.id);
    

    if (indices[0] == -1){
        switch(i){
            case 0 :
            {   
                user_1.type = 0;
                student student_1;
                student_1.name = user_1.name;
                student_1.id = user_1.id;
                student_1.password = user_1.password;
                student_list.push_back(student_1);
                user_list.push_back(user_1);
                break;
            }
            case 1 :
            {   
                user_1.type = 1;
                professor professor_1;
                professor_1.name = user_1.name;
                professor_1.id = user_1.id;
                professor_1.password = user_1.password;
                professor_list.push_back(professor_1);
                user_list.push_back(user_1);
                break;
            }
            
            case 2:
            {   
                user_1.type = 2;
                librarian librarian_1;
                librarian_1.name = user_1.name;
                librarian_1.id = user_1.id;
                librarian_1.password = user_1.password;
                librarian_list.push_back(librarian_1);
                user_list.push_back(user_1);
                break;
            }
            default :
                cout <<"Incorrect operation the process did not complete. Please try again !" <<endl <<endl;
                break;

        }
    }
    else{
        cout << "A user with that ID already exists !" <<endl <<endl;
    }
    return;
}

vector <long long int> user_database::search(long long int ID){
    vector<long long int> indices;

    long long int i1,i2,i3,i4;
    i1 = -1;
    i2 = -1;
    i3 = -1;
    i4 = -1;

    for (long long int i =0; i<user_list.size(); i++){
        if(user_list[i].id == ID){
            i1 = i;
        }
    }
    if (i1 == -1){
        indices.push_back(i1);
        indices.push_back(i2);
        indices.push_back(i3);
        indices.push_back(i4);
    }
    else{
        indices.push_back(i1);
        for (long long int i = 0; i<student_list.size();++i){
            if(student_list[i].id == ID){
                i2 = i;
            }
        }
        indices.push_back(i2);

        for (long long int i = 0; i<professor_list.size();++i){
            if(professor_list[i].id == ID){
                i3 = i;
            }
        }  
        indices.push_back(i3);    

        for (long long int i = 0; i<librarian_list.size();++i){
            if(librarian_list[i].id == ID){
                i4 = i;
            }
        }  
        indices.push_back(i4); 
    }
    return(indices);
}

void user_database::remove(){
    long long int ID;
    cout <<endl<< "Enter ID:";
    cin >> ID;
    cout << endl;

    vector<long long int> indices = search(ID);

    if(indices[0]==-1){
        cout << "No such user found in the database." <<endl;
        return;
    }
    else{
        user user_1 = user_list[indices[0]];
        switch(user_1.type){
            case 0 :
            {
                student_list.erase(student_list.begin()+indices[1]);
                break;
            } 
            case 1 :
            {
                professor_list.erase(professor_list.begin()+indices[2]);
                break;
            }
            case 2 :
            {
                librarian_list.erase(librarian_list.begin()+indices[3]);
                break;
            }
            default :
            {
                cout << "Unsual error occured." << endl;
                break;
            }
        }
        user_list.erase(user_list.begin()+indices[0]);
        cout << "The user " << user_1.name << " has been removed from the database." << endl<<endl;
    }
    return;
}

void user_database::update(){
    cout << "Enter ID :";
    long long int ID;
    cin >> ID;
    cout <<endl;

    vector<long long int> indices = search(ID);

    if(indices[0]==-1){
        cout << "No such user found in the database." <<endl;
        return;
    }
    else{
        user user_1 = user_list[indices[0]];
        cout << "Press 1 if you want to change user name"<<endl;
        cout << "Press 2 if you want to change user password" << endl;
        cout << "Press 3 if you want to change user id" << endl;
        //cout << "Press 4 if you want to change user type" <<endl;
        cout << "Press 4 if you dont want to change anything"<<endl;
        cout << "Enter your option"<<endl;

        int option;
        cin >> option;

        switch(user_1.type){
            case 0 :   // When original user type is student
            {
                switch(option){
                    case 1:
                    {
                        cout << "Enter new name : ";
                        cin >> student_list[indices[1]].name;
                        cout << endl;
                        user_list[indices[0]].name = student_list[indices[1]].name;
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter new password :";
                        cin >> student_list[indices[1]].password;
                        cout << endl;
                        user_list[indices[0]].password = student_list[indices[1]].password;
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter new id :";
                        cin >> student_list[indices[1]].id;
                        cout << endl;
                        user_list[indices[0]].id = student_list[indices[1]].id;
                        break;
                    }
                    case 4:
                    {

                        break;
                    }
                    default:
                    {
                        cout << "Unsual error occured" <<endl <<endl;
                        break;
                    }
                }
                break;
            } 

            case 1 :  // When original user type is professor
            {

                switch(option){
                    case 1:
                    {
                        cout << "Enter new name : ";
                        cin >> professor_list[indices[2]].name;
                        cout << endl;
                        user_list[indices[0]].name = professor_list[indices[2]].name;
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter new password : ";
                        cin >> professor_list[indices[2]].password;
                        cout << endl;
                        user_list[indices[0]].password = professor_list[indices[2]].password;
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter new id : ";
                        cin >> professor_list[indices[2]].id;
                        cout << endl;
                        user_list[indices[0]].id = professor_list[indices[2]].id;
                        break;
                    }
                    
                    case 5:
                    {
                        
                        break;
                    }
                    default:
                    {

                        break;
                    }
                }     

                break;
            }

            case 2 :    // When original user type is librarian
            {

                switch(option){
                    case 1:
                    {
                        cout << "Enter new name : ";
                        cin >> librarian_list[indices[2]].name;
                        cout << endl;
                        user_list[indices[0]].name = librarian_list[indices[2]].name;
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter new password : ";
                        cin >> student_list[indices[1]].password;
                        cout << endl;
                        user_list[indices[0]].password = librarian_list[indices[2]].password;
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter new id : ";
                        cin >> student_list[indices[1]].id;
                        cout << endl;
                        user_list[indices[0]].id = librarian_list[indices[2]].id;
                        break;
                    }
                
                    case 4: 
                    {
                        
                        break;
                    }
                    default:
                    {
                        cout <<"Wrong option selected"<<endl<<endl;
                        break;
                    }
                }                
                break;
            }
            default :
            {
                cout << "Unsual error occured." << endl;
                break;
            }
        }

    }
    return;
}  

void user_database::display(){

    long long int n1,n2,n3,n4;
    n1 = user_list.size();

    if(n1 == 0){
        cout <<"No users in the database";
    }
    else{
        cout << "The user database is as follows : "<<endl;
        for(long long int i= 0; i<n1;i++){
            user_list[i].display();
            cout <<endl;
        }
    }
    return;
}

void user_database::show_students(){
    long long int n = student_list.size();

    if(n==0){
        cout <<endl<< "No students in the database" <<endl;
    }
    else{
        cout << endl << "The student database is as follows : " <<endl;
        for(long long int i =0; i<n ;i++){
            student student_1 = student_list[i];
            student_1.display();
            cout <<endl;
        }
    }
    return;
}

void user_database::show_professors(){
    long long int n = professor_list.size();
    if (n==0){
        cout << endl << "No professors in the database" <<endl;
    }
    else{
        cout << endl << "The professor database is as follows : " <<endl;
        for(long long int i = 0; i<n;i++){
            professor professor_1 = professor_list[i];
            professor_1.display();
            cout <<endl;
        }
    }
    return;
}

void user_database::show_librarians(){
    long long int n = librarian_list.size();
    if(n==0){
        cout << endl << "No librarians in the database" <<endl;
    }
    else{
        cout << endl << "The librarian database is as follows : " <<endl;
        for(long long int i = 0; i<n;i++){
            librarian librarian_1 = librarian_list[i];
            librarian_1.display();
        }
    }
    return;
}

