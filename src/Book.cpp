#include "Include/Book.h"
#include "Include/date_functions.h"
#include <iostream>

using namespace std;
book::book(){
    issue_status = 0;
}

void book::display(){
    cout << endl;
    cout << "Title : " << title <<endl;
    cout << "Author : "<< author <<endl;
    cout << "ISBN : "<< ISBN <<endl;
    cout << "Publication : "<< publication <<endl;

    return;
}

void book::book_request(){
    if (issue_status == 0){
        cout << "The book is available for issue" <<endl<<endl;
    }
    else{
        cout << "The book is unavaialable for issue"<<endl<<endl;
    }
}

void book::show_duedate(int type){
    if(issue_status == 0){
        cout << "The book has not been issued yet "<<endl <<endl;
    }
    else{
        if(type == 0){
            long long int g = date_to_numeric(issue_date, issue_month, issue_year);
            g+=30;
            std::vector<int> date_1 = numeric_to_date(g);
            cout << "The return date is " << date_1[0] <<"/" << date_1[1] <<"/" << date_1[2] << endl <<endl; 
        }
        else{
            long long int g = date_to_numeric(issue_date, issue_month, issue_year);
            g+=60;
            std::vector<int> date_1 = numeric_to_date(g);
            cout << "The return date is " << date_1[0] <<"/" << date_1[1] <<"/" << date_1[2] << endl <<endl; 
        }
    }
    return;
}
