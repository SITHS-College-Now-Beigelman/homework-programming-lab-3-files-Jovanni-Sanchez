// Jovanni Sanchez
// October 15, 2024
// Homework 3 Part 2

#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    /* Before I can do anything, I need an input file and an output file.
    Here I define variables inputFile and outputFile. Next, I make the program
    open both files. Opening the files allows the program to start reading
    the inputFile and writing to the outputFile (alongside creating an outputFile
    if it doesn't exist). */

    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("transactions.txt");
    outputFile.open("bankStatement.txt");

    /* After opening the inputFile, I define userBankBalance as the number extracted
    from the first line within inputFile. After I write STARTING BALANCE: $ followed
    by the userBankBalance. Finally, I write the top portion of the format needed in
    the outputFile. The end goal is to make the outputFile excatly like a bank
    statement. */

    double userBankBalance;

    inputFile >> userBankBalance;
    outputFile << "STARTING BALANCE: $" << userBankBalance << "\n\n";
    outputFile << "TYPE......AMOUNT" << setw(20) << setfill('.') << "BALANCE\n";

    /* Before I read any further into the file, I defire totalDepositValue and
    totalWithdrawlValue. As I read further into the inputFile for withdrawls and
    deposits made in the transaction history, I will add the value of each deposit
    and withdrawl into it's respective total. */

    double totalDepositValue;
    double totalWithdrawlValue;

    /* While the program hasn't reached the end of the input file, each line
    will be read. The program will look for typeOfTransaction (a singular character
    or symbol) and valueOfTransaction (a number of any size). Once both are found in
    a line, the program moves on and reads the next line. The program will keep
    reading until it has reached the end of the inputFile. */

    while (!inputFile.eof())
    {
        char typeOfTransaction;
        double valueOfTransaction;

        inputFile >> typeOfTransaction >> valueOfTransaction;

        /* Here I tell the program how to differentiate between transactions.

        If typeOfTransaction is 'W', then it's a withdrawl.
        When the user withdraws, I take out the valueOfTransaction from the
        userBankBalance and add the valueOfTransaction to the totalWithdrawlValue.

        If typeOfTransaction is 'D', then it's a Deposit.
        When the user deposits, I add the valueOfTransaction to the userBankBalance
        and add the valueOfTransaction to the totalDepositValue.

        If typeOfTransaction is not defiened, then the program will fallback to a generic
        transaction, which will deduct the valueOfTransaction from the userBankBalance
        but will not add it to a total. */

        switch (typeOfTransaction)
        {
        case 'W':
            // Withdrawl
            userBankBalance -= valueOfTransaction;
            totalWithdrawlValue += valueOfTransaction;
            break;
        case 'D':
            // Deposit
            userBankBalance += valueOfTransaction;
            totalDepositValue += valueOfTransaction;
            break;
        default:
            // Transaction
            userBankBalance -= valueOfTransaction;
            break;
        }

        /* Before writing the withdrawls and deposits into the outputFile, I define
        a formatOffset. The size of the formatOffset will change based on the digits
        in the valueOfTrasaction. By default the offset is 17 for single digit
        numbers, but changes to 16 for double digits, 15 for triple digits, and 14
        for quadruple digits. (This does not account for decimals. Of course, the
        inputFile has no decimals, but if it did, the condition to define the
        formatOffset would more complicated.) */

        int formatOffset = 17;

        if (valueOfTransaction < 100 && valueOfTransaction >= 10)
        {
            formatOffset = 16;
        }
        else if (valueOfTransaction < 1000 && valueOfTransaction >= 100)
        {
            formatOffset = 15;
        }
        else if (valueOfTransaction < 10000 && valueOfTransaction >= 1000)
        {
            formatOffset = 14;
        }

        /* Now that withdrawls, deposits, and the format's offset have been defined,
        I can start writing to the outputFile. I start each line with the type,
        then the seperator between TYPE and AMOUNT followed by the value of the
        transaction, then another seperator based on the offset between ANOUNT and
        BALANCE followed by the current bank balance. */

        outputFile << typeOfTransaction << ".........$" << valueOfTransaction
                   << setw(formatOffset) << setfill('.') << "$"
                   << userBankBalance << "\n";
    }

    /* Once the program has reached the end of the file, I write the ending
    balance value, total withdrawl value, and total deposit value to the outputFile.
    After that, the program finishes and the outputFile is complete. */

    outputFile << "\n\n";
    outputFile << "ENDING BALANCE: $" << userBankBalance << "\n";
    outputFile << "TOTAL WITHDRAWALS: $" << totalWithdrawlValue << "\n";
    outputFile << "TOTAL DEPOSITS: $" << totalDepositValue;

    return 0;
}
