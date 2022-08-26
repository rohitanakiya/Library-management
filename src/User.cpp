#include<iostream>
#include "Include/User.h"

using namespace std;

void :: user::display(){
    cout <<endl;
    cout <<"User name : " << name<<endl;
    cout <<"User ID : " << id<<endl;
    switch(type){
        case 0:
        {
            cout <<"User Type : Student "<<endl;
            break;
        }

        case 1:
        {
            cout <<"User Type : Professor "<<endl;
            break;
        }

        case 2:
        {
            cout <<"User Type : Librarian "<<endl;
            break;
        }

        default:
        {
            cout <<"Unknown error occured <<"<<endl;
            break;
        }
    }
}
