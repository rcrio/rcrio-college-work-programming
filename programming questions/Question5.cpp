#include "Question5.h"
#include <iostream>
using namespace std;

void Question5::answer()
{
    int number, biggestNumber;
    number = 10;
    biggestNumber = 0;

    while (number > 9)
    {
        cout << "Please insert a number: ";
        cin >> number;
        if (biggestNumber < number)
        {
            biggestNumber = number;
        }
    }

    cout << "The biggest number of your numbers is: " << biggestNumber;
}