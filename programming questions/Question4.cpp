#include "Question4.h"
#include <iostream>
using namespace std;

void Question4::answer()
{
    float number = 0, sum;
    sum = 0;

    while (number != 0)
    {
        cout << "Please insert a number: ";
        cin >> number;
        sum = sum + number;
    }

    cout << "The sum of your numbers is: " << sum;
}
