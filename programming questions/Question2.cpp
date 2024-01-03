#include "Question2.h"
#include <iostream>
using namespace std;

void Question2::answer()
{
    float i, number, sum, average;
    sum = 0;

    for (i = 0; i < 10; i++)
    {
        cout << "Please enter a number: ";
        cin >> number;
        sum = sum + number;
    }

    average = sum / 10.0;
    cout << "Average of your 10 numbers is: " << average;
}