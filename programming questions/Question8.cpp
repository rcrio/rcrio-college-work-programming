#include "Question8.h"
#include <iostream>
using namespace std;

void Question8::answer()
{
    int number = 0;

    while (number < 13)
    {
        if (number == 2 || number == 9)
        {
            number++;

        }
        else
        {
            cout << number << endl;
            number++;
        }
    }
}
