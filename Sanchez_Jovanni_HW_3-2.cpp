// Jovanni Sanchez
// October 15, 2024
// Homework 3 Part 1


#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

int main ( ) 
{
    ifstream inputFile;
    ofstream outputFile;
    double userBankBalance;
    double totalDepositValue;
    double totalWithdrawlValue;

    inputFile.open("transactions.txt"); // Open the input file
    outputFile.open("bankStatement.txt"); // Open an output file for later

    inputFile >> userBankBalance;

    outputFile << "STARTING BALANCE: $" << userBankBalance << "\n\n"; 

    outputFile << "TYPE......AMOUNT" << setw(20) << setfill('.') << "BALANCE\n"; 

    while (!inputFile.eof())
    {
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

        outputFile << typeOfTransaction << ".........$" << valueOfTransaction 
        << setw(24) << setfill('.') << "$" << userBankBalance << "\n"; 
    }
    outputFile << "\n\n";
    outputFile << "ENDING BALANCE: $" << userBankBalance << "\n";
    outputFile << "TOTAL WITHDRAWALS: $" << totalWithdrawlValue << "\n";
    outputFile << "TOTAL DEPOSITS: $" << totalDepositValue;
    return 0;
}
