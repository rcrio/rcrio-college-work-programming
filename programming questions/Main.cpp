#include <iostream>
#include "Question1.h"
#include "Question2.h"
#include "Question3.h"
#include "Question4.h"
#include "Question5.h"
#include "Question6.h"
#include "Question7.h"
#include "Question8.h"
#include "Question9.h"

using namespace std;

Question1 question1;
Question2 question2;
Question3 question3;
Question4 question4;
Question5 question5;
Question6 question6;
Question7 question7;
Question8 question8;
Question9 question9;

bool programExit = false;
bool menuClose;
bool exitterClose;

void welcome();
void menu();
void exitter();

int main()
{
    welcome();
    while (programExit == false)
    {
        menuClose = false;
        while (menuClose == false)
        {
            menu();
        }
        exitterClose = false;
        while (exitterClose == false)
        {
            exitter();
        }
    }

    return 0;
}

void welcome()
{
    cout << "Welcome to the Programming Coursework for my previous college course.";
    cout << "\nQuestions 1 and 9 are very long, so only the answer will be written.";
    cout << "\nPlease refer to the \"assignment questions.pdf\" in assignment-materials.";
    cout << "\nQuestions 2 - 8 will have their questions and answers in them.";
}

void menu()
{
    int choice;
    try
    {
        cout << "\n\nTo select a question you would like to see the answer to, please type a number from 1 - 9 and press enter:\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            question1.answer();
            menuClose = true;
            break;
        case 2:
            question2.answer();
            menuClose = true;
            break;
        case 3:
            question3.answer();
            menuClose = true;
            break;
        case 4:
            question4.answer();
            menuClose = true;
            break;
        case 5:
            question5.answer();
            menuClose = true;
            break;
        case 6:
            question6.answer();
            menuClose = true;
            break;
        case 7:
            question7.answer();
            menuClose = true;
            break;
        case 8:
            question8.answer();
            menuClose = true;
            break;
        case 9:
            question9.answer();
            menuClose = true;
            break;
        default:
            cout << "Incorrect input, please try again.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    catch (...)
    {
        cout << "Incorrect input, please try again.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void exitter()
{
    string choice;
    cout << "\nWould you like to continue viewing questions or exit the program?";
    cout << "\nType and enter C to continue.";
    cout << "\nType and enter Q to quit.";

    cin >> choice;

    if (choice == "C")
    {
        exitterClose = true;
    }
    else if (choice == "Q")
    {
        exit(0);
    }
    else
    {
        cout << "Incorrect input, please try again.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
