// Jovanni Sanchez
// October 15, 2024
// Homework 3 Part 1

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main ( ) 
{
    ifstream inputFile;
    double userBankBalance;
    int remainingBankTransactions;

    inputFile.open("transactions.txt");

    inputFile >> userBankBalance;
    cout << "Your initial Bank Balance is: $" << userBankBalance;

    for (remainingBankTransactions = 0; remainingBankTransactions <= 6; remainingBankTransactions++)
    {
        char typeOfTransaction;
        double valueOfTransaction;
        string thisTransactionsName;

        inputFile >> typeOfTransaction >> valueOfTransaction;

        switch (typeOfTransaction)
        {
            case 'W':
                // Withdraw
                thisTransactionsName = "Withdrawl";
                userBankBalance -= valueOfTransaction;
                break;
            case 'D':
                // Deposit
                thisTransactionsName = "Deposit";
                userBankBalance += valueOfTransaction;
                break;
        }

        cout << "\nYour new bank balance is: $"<< userBankBalance 
        << ". The value of your " << thisTransactionsName << " is: $"
        << valueOfTransaction;
    }

    return 0;
}
