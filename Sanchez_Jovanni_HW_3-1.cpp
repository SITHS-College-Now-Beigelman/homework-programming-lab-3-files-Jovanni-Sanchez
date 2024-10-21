// Jovanni Sanchez
// October 15, 2024
// Homework 3 Part 1

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    /* Before I can do anything, I need an input file. Here I define variables
    inputFile and userBankBalance. Next, I make the program open the inputFile. Opening
    the inputFile allows the program to start reading the inputFile. The program will read
    the first line of the file for the initial value of the user's bank balance. */

    ifstream inputFile;
    double userBankBalance;

    inputFile.open("transactions.txt");

    inputFile >> userBankBalance;
    cout << "Your initial Bank Balance is: $" << userBankBalance;

    /* I know the user made 6 transactions, so I use a for loop to iterate through the six
    transactions using the variable remainingTransactions. Before reading the inputfile, I
    setup variables typeOfTrasaction, nameOfTransaction, and valueOfTransaction. The program
    will look for typeOfTransaction (a singular character or symbol) and valueOfTransaction
    (a number of any size). Once both are found in a line, the program moves on and reads the
    next line. The program will keep reading until it has reached the loop limit
    (six remainingTransactions). */

    int remainingTransactions;

    for (remainingTransactions = 0; remainingTransactions <= 6; remainingTransactions++)
    {

        char typeOfTransaction;
        string nameOfTransaction;
        double valueOfTransaction;

        inputFile >> typeOfTransaction >> valueOfTransaction;

        /* Here I tell the program how to differentiate between transactions.

        If typeOfTransaction is 'W', then it's a withdrawl. When the user withdraws, I take out
        the valueOfTransaction from the userBankBalance and set the nameOfTransaction to 'Withdrawl.

        If typeOfTransaction is 'D', then it's a Deposit.  When the user deposits, I add the
        valueOfTransaction to the userBankBalance and set the nameOfTransaction to 'Deposit'.

        If typeOfTransaction is not defined, then it's a generic transaction. The program will
        fallback to taking out the valueOfTransaction from the userBankBalance and setting the
        nameOfTransaction to 'Transaction'. */

        switch (typeOfTransaction)
        {
        case 'W':
            // Withdrawl
            nameOfTransaction = "Withdrawl";
            userBankBalance -= valueOfTransaction;
            break;
        case 'D':
            // Deposit
            nameOfTransaction = "Deposit";
            userBankBalance += valueOfTransaction;
            break;
        default:
            // Transaction
            nameOfTransaction = "Transaction";
            userBankBalance -= valueOfTransaction;
            break;
        }

        /* Once the program has read six lines, I print the new bank balance after the user's
        transaction then print out the name and value of the current transaction. */

        cout << "\nYour new bank balance is: $" << userBankBalance
             << ". The value of your " << nameOfTransaction
             << " is: $" << valueOfTransaction;
    }

    return 0;
}
