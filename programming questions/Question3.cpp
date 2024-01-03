#include "Question3.h"
#include <iostream>
using namespace std;

void Question3::answer()
{
    float i, number, average;
    cout << "Please enter a number: ";
    cin >> number;


    for (i = 1; i < 13; i++)
    {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}
