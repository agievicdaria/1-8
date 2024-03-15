#include "Account.h"
#include <iostream>
using namespace std;

int main() {
    Account account;

    account.Read();
    account.Display();

    account.Withdraw(Account::Money(200, 30));
    account.Display();

    account.Deposit(Account::Money(500, 25));
    account.Display();

    account.ChangeOwner("Black");

    account.AddInterest();
    account.Display();

    account.ConvertToDollars();
    account.Display();

    account.ConvertToEuros();
    account.Display();

    account.ConvertToHryvnya();
    cout << "Account balance: " << account.ToString() << endl;

    string amountInWords = account.AmountInWords();
    cout << "Amount in words: " << amountInWords << endl;

    Account::Money amount1(300, 50);
    Account::Money amount2(500, 25);

    cout << "Amount 1: ";
    amount1.Display();
    cout << endl;

    cout << "Amount 2: ";
    amount2.Display();
    cout << endl;

    Account::Money dividedByInt = amount1.DivideInt(2);
    Account::Money dividedByDouble = amount2.DivideDouble(1.5);

    cout << "Amount 1 divided by 2: ";
    dividedByInt.Display();
    cout << endl;

    cout << "Amount 2 divided by 1.5: ";
    dividedByDouble.Display();
    cout << endl;

    if (amount1.IsEqual(amount2)) {
        cout << "Amount 1 is equal to Amount 2." << endl;
    } else {
        cout << "Amount 1 is not equal to Amount 2." << endl;
    }

    return 0;
}