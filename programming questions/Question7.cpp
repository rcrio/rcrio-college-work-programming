#include "Question7.h"
#include <iostream>
using namespace std;

void Question7::answer()
{
    int month, birthdayMonth;
    month = 0;
    cout << "Please enter a number from 1-12 representing your birthday: ";
    cin >> birthdayMonth;


    while (month < 13)
    {
        if (month == birthdayMonth)
        {
            cout << month << " Happy birthday!" << endl;
            month++;
        }
        else
        {
            cout << month << endl;
            month++;
        }
    }
}