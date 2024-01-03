#include "Question9.h"
#include <iostream>
using namespace std;

void Question9::answer()
{
    // Conversion rates were taken from xe.com on 07/01/2023. They will fluctuate and may be different.
    int continueChoice = 1;

    while (continueChoice == 1)
    {
        int currencyChoice, convertChoice, rounder;
        float currencyAmount, newCurrency, newCurrencyRounded, currencyRate;
        rounder = 0;
        string currencyName1, currencyName2;

        cout << "#=================================#\n";
        cout << "|        Bureau De Change         |\n";
        cout << "|        Currency Exchange        |\n";
        cout << "#=================================#\n\n";

        cout << "#=================================#\n";
        cout << "|  Please enter a number from 1-7 |\n";
        cout << "|  to select your currency        |\n";
        cout << "#=================================#\n";
        cout << "|1|  Euro                         |\n";
        cout << "|2|  US Dollar                    |\n";
        cout << "|3|  Japanese Yen                 |\n";
        cout << "|4|  Pound                        |\n";
        cout << "|5|  Chinese Yuan                 |\n";
        cout << "|6|  Icelandic Krona              |\n";
        cout << "|7|  Hong Kong Dollar             |\n";
        cout << "#=================================#\n";

        cin >> currencyChoice;

        cout << "#=================================#\n";
        cout << "|  Please enter a number from 1-7 |\n";
        cout << "|  to select your conversion      |\n";
        cout << "#=================================#\n";
        cout << "|1|  Convert to Euro              |\n";
        cout << "|2|  Convert to US Dollar         |\n";
        cout << "|3|  Convert to Japanese Yen      |\n";
        cout << "|4|  Convert to Pound             |\n";
        cout << "|5|  Convert to Chinese Yuan      |\n";
        cout << "|6|  Convert to Icelandic Krona   |\n";
        cout << "|7|  Convert to Hong Kong Dollar  |\n";
        cout << "#=================================#\n";

        cin >> convertChoice;

        cout << "#=================================#\n";
        cout << "|  Please enter the amount of     |\n";
        cout << "|  currency you have              |\n";
        cout << "#=================================#\n";

        cin >> currencyAmount;

        if (currencyChoice <= 7 && currencyChoice >= 1 && convertChoice <= 7 && convertChoice >= 1) {
            // Conversion rates
            if (currencyChoice == 1 && convertChoice == 1) {
                currencyName1 = "Euros";
                currencyName2 = "Euros";
                currencyRate = 1;
            }
            else if (currencyChoice == 1 && convertChoice == 2) {
                currencyName1 = "Euros";
                currencyName2 = "US Dollars";
                currencyRate = 1.0656995;
            }
            // ... (other conversion rates)

            newCurrency = currencyAmount * currencyRate;
            rounder = (int)(newCurrency * 100 + 0.5);
            newCurrencyRounded = rounder / 100.0;

            cout << "Your currency (" << currencyName1 << "): " << currencyAmount << endl;
            cout << "Converted currency (" << currencyName2 << "): " << newCurrencyRounded << endl;
        }
        else {
            cout << "Incorrect values.";
        }

        cout << "\n\nWould you like to continue and try another conversion or exit the program?\n";
        cout << "Please type and enter 1 to continue\n";
        cout << "Please type and enter 0 to exit the program\n";
        cin >> continueChoice;
    }
}
