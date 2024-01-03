#include "Question1.h"
#include <iostream>
#include <limits>
#include <errno.h>
#include <fstream>

using namespace std;

void Question1::answer()
{
    /* I use these integers for the while-loops to ask if the user wants to continue the program running or staying logged in.
    They will type in 1 to keep the integer as it is and keep the condition true so the loop will continue
    OR
    They will type in 0 to change the integer and make the condition false so the loop will break. */
    int continueChoice = 1;
    int continueChoiceLoggedIn = 1;

    string adminUsername = "admin";
    string adminPassword = "password123";
    string username, password, carpetColour;
    int orderNumber, carpetPrice;
    float carpetAmount, totalCost;

    /* I use these booleans for the do-while-loop to keep them running until we have a condition that we want and then we make the boolean true so it breaks the loop. */
    bool inputCheck1 = false;
    bool inputCheck2 = false;
    bool inputCheck3 = false;
    bool continueInputCheck1 = false;
    bool continueInputCheck2 = false;

    /* This while-loop is to keep the program running. At the end of the while-loop, it will ask if the user would like to continue or exit.
    If the user chooses to continue, the value of continueChoice will stay at 1 therefore the loop will run again.
    If the user chooses to exit, the value of continueChoice will become 0 which will break the loop and exit the program.
    I use cin>>continueChoice to get the user's input to get the value of continueChoice which will either be 1 to continue or 0 to exit.
    I have validation as well so that if the user's input is a different number or even a word, the program will not accept it and ask them to try again.
    e.g. If the user types 3 the value will be incorrect and they will be asked to try again. */

    while (continueChoice == 1)
    {
        cout << "== Magic Carpet Company ==" << endl;
        cout << "Welcome to the Magic Carpet Company order program." << endl;
        cout << "Please enter a username: ";
        cin >> username;
        cout << "Please enter a password: ";
        cin >> password;

        /* This if-statement to determine if the username and password inputted by the user is correct or not. */
        if (username == adminUsername && password == adminPassword)
        {
            cout << "Login successful!" << endl;

            /* Another while-loop but this is to keep the user logged in. It follows the same logic as the previous while-loop. */
            while (continueChoiceLoggedIn == 1)
            {
                cout << "== Magic Carpet Company ==" << endl;
                cout << "The Magic Carpet Company order system requires these inputs:" << endl;
                cout << "Order number, colour of carpet desired and the amount of carpet required (in square metres)." << endl;
                cout << "These are the carpet colours and prices per square metre." << endl;
                cout << "Red carpet:  £100 per square metre" << endl;
                cout << "Blue carpet: £150 per square metre" << endl;
                cout << "Green carpet: £200 per square metre" << endl;

                /* This is a do-while-loop which is very similar to a while loop but it checks for the condition at the end of the loop to determine
                whether the loop will continue or break.

                The reason I am using this do-while-loop is for validation so that I can check if cin>>orderNumber is the correct type of input I am expecting.
                e.g. If the user inputs "order", the input will not be accepted and the program will ask them to try again and enter a number as "order"
                is a string of text and not an integer that the program is expecting.

                We use an if-statement to give it the condition that it has to meet or else the program will not accept it.
                Here, it says that if the input for cin>>orderNumber fails [cin.fail()], it will give an error and the program will ask the
                user to try again.

                */
                do
                {
                    cout << "Please enter an order number: ";
                    cin >> orderNumber;

                    if (cin.fail())
                    {
                        cout << "Value must be a number, please try again and enter an order number." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else
                    {
                        inputCheck1 = true;
                    }
                } while (inputCheck1 == false);

                /* This is similar to the previous do-while-loop with an if-statement which is used for validating the input of the carpet colour.
                Any inputs other than "Red", "Blue", or "Green" will not be accepted and the program will ask them to try again. */
                do
                {
                    cout << "Please enter your desired carpet colour from Red, Blue or Green (case sensitive): ";
                    cin >> carpetColour;
                    if (carpetColour == "Red")
                    {
                        carpetPrice = 100;
                        inputCheck2 = true;
                    }
                    else if (carpetColour == "Blue")
                    {
                        carpetPrice = 150;
                        inputCheck2 = true;
                    }
                    else if (carpetColour == "Green")
                    {
                        carpetPrice = 200;
                        inputCheck2 = true;
                    }
                    else
                    {
                        cout << "Value must either be Red, Blue or Green (case sensitive). Please try again by entering your desired carpet colour." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (inputCheck2 == false);

                /* This is another do-while-loop with an if-statement to validate the input for amount of carpet required.
                The program will expect a number as an input and will reject any other kind of input. */
                do
                {
                    cout << "Please enter the amount of carpet required (in square metres): ";
                    cin >> carpetAmount;
                    if (cin.fail())
                    {
                        cout << "Value must be a number, please try again and enter the amount of carpet required (in square metres).\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else
                    {
                        inputCheck3 = true;
                    }
                } while (inputCheck3 == false);

                // This calculates the carpet price.
                totalCost = carpetAmount * carpetPrice;

                cout << "== Your order ==\n";
                cout << "Order number: " << orderNumber << "\n";
                cout << "Colour: " << carpetColour << "\n";
                cout << "Quantity: " << carpetAmount << " square metres\n";
                cout << "Total Cost: £" << totalCost << "\n\n";

                /* This code is to output the information to a text file called "orders.txt". std::ios_base::app allows
                multiple orders to be recorded into the text file. */
                ofstream MyFile("orders.txt", std::ios_base::app);
                MyFile << "Order number: " << orderNumber << "\n"
                    << "Colour: " << carpetColour << "\n"
                    << "Quantity: " << carpetAmount << " square metres\n"
                    << "Total Cost: £" << totalCost << "\n\n";

                cout << "Would you to make another order or log out? Please type and enter: \n";

                /* This do-while-loop is validation for the program to make another order or log out.
                It will only accept values of 1 or 0 and will reject any other input. We have an if-statement inside for that
                logic. */
                do
                {
                    cout << "1 to make another order.\n";
                    cout << "0 to log out.\n";
                    cin >> continueChoiceLoggedIn;
                    if (cin.fail() || continueChoiceLoggedIn > 1 || continueChoiceLoggedIn < 0)
                    {
                        cout << "Incorrect value. Value must either be 1 or 0. Please try again by typing and entering: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else
                    {
                        continueInputCheck2 = true;
                        continueChoice = 0;
                    }
                } while (continueInputCheck2 == false);
            }
        }

        else
        {
            cout << "Incorrect login. Please type and enter: \n";

            // Validation for program to continue running or exit.
            do
            {
                cout << "1 to try again.\n";
                cout << "0 to exit the program.\n";
                cin >> continueChoice;
                if (cin.fail() || continueChoice > 1 || continueChoice < 0)
                {
                    cout << "Incorrect value. Value must either be 1 or 0. Please try again by typing and entering: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    continueInputCheck2 = true;
                }
            } while (continueInputCheck2 == false);
        }
    }
}
