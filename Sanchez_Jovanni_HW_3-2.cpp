// Jovanni Sanchez
// October 15, 2024
// Homework 3 Part 1

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    double userBankBalance;
    double totalDepositValue;
    double totalWithdrawlValue;

    inputFile.open("transactions.txt");   // Open the input file
    outputFile.open("bankStatement.txt"); // Opens an output file for later

    inputFile >> userBankBalance;

    outputFile << "STARTING BALANCE: $" << userBankBalance << "\n\n";

    outputFile << "TYPE......AMOUNT" << setw(20) << setfill('.') << "BALANCE\n";

    while (!inputFile.eof()) // While we have not reached the end of the file
    {
        int formatOffset = 14;
        char typeOfTransaction;
        double valueOfTransaction;

        inputFile >> typeOfTransaction >> valueOfTransaction;

        switch (typeOfTransaction)
        {
        case 'W':
            // Withdraw
            userBankBalance -= valueOfTransaction;
            totalWithdrawlValue += valueOfTransaction;
            break;
        case 'D':
            // Deposit
            userBankBalance += valueOfTransaction;
            totalDepositValue += valueOfTransaction;
            break;
        }

        if (valueOfTransaction < 10 && valueOfTransaction >= 1)
        {
            formatOffset = 17;
        }
        else if (valueOfTransaction < 100 && valueOfTransaction >= 10)
        {
            formatOffset = 16;
        }
        else if (valueOfTransaction < 1000 && valueOfTransaction >= 100)
        {
            formatOffset = 15;
        }

        outputFile << typeOfTransaction << ".........$" << valueOfTransaction
                   << setw(formatOffset) << setfill('.') << "$"
                   << userBankBalance << "\n";
    }

    outputFile << "\n\n";
    outputFile << "ENDING BALANCE: $" << userBankBalance << "\n";
    outputFile << "TOTAL WITHDRAWALS: $" << totalWithdrawlValue << "\n";
    outputFile << "TOTAL DEPOSITS: $" << totalDepositValue;

    return 0;
}
