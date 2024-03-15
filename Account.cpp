#include "Account.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Account::Money::Money() {
    hryvnia = 0;
    kopiyky = 0;
}

Account::Money::Money(long hryvnia, unsigned char kopiyky) {
    this->hryvnia = hryvnia;
    this->kopiyky = kopiyky;
}

Account::Money Account::Money::Add(const Money& secondValue) const {
    long totalHryvnia = hryvnia + secondValue.hryvnia;
    int totalKopiyky = kopiyky + secondValue.kopiyky;

    if (totalKopiyky >= 100) {
        totalHryvnia += totalKopiyky / 100;
        totalKopiyky %= 100;
    }

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Account::Money Account::Money::Subtract(const Money& secondValue) const {
    long totalHryvnia = hryvnia - secondValue.hryvnia;
    int totalKopiyky = kopiyky - secondValue.kopiyky;

    if (totalKopiyky < 0) {
        totalHryvnia -= 1;
        totalKopiyky += 100;
    }

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Account::Money Account::Money::DivideInt(int divisor) const {
    long totalHryvnia = hryvnia / divisor;
    int totalKopiyky = (hryvnia % divisor) * 100 / divisor + kopiyky / divisor;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Account::Money Account::Money::DivideDouble(double divisor) const {
    double totalMoney = static_cast<double>(hryvnia * 100 + kopiyky) / divisor;
    long totalHryvnia = static_cast<long>(totalMoney) / 100;
    int totalKopiyky = static_cast<int>(totalMoney) % 100;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Account::Money Account::Money::Multiply(double multiplier) const {
    double totalMoney = static_cast<double>(hryvnia * 100 + kopiyky) * multiplier;
    long totalHryvnia = static_cast<long>(totalMoney) / 100;
    int totalKopiyky = static_cast<int>(totalMoney) % 100;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

bool Account::Money::IsEqual(const Money& secondValue) const {
    return hryvnia == secondValue.hryvnia && kopiyky == secondValue.kopiyky;
}

bool Account::Money::IsLessThan(const Money& secondValue) const {
    if (hryvnia == secondValue.hryvnia) {
        return kopiyky < secondValue.kopiyky;
    }
    return hryvnia < secondValue.hryvnia;
}

bool Account::Money::IsGreaterThan(const Money& secondValue) const {
    if (hryvnia == secondValue.hryvnia) {
        return kopiyky > secondValue.kopiyky;
    }
    return hryvnia > secondValue.hryvnia;
}

void Account::Money::Display() const {
    cout << hryvnia << "," << static_cast<int>(kopiyky);
}

void Account::Init(const string& ownerLastName, const string& accountNumber, double interestRate, const Money& balance) {
    this->ownerLastName = ownerLastName;
    this->accountNumber = accountNumber;
    this->interestRate = interestRate;
    this->balance = balance;
}

void Account::ChangeOwner(const string& newOwnerLastName) {
    ownerLastName = newOwnerLastName;
}

void Account::Withdraw(const Money& amount) {
    if (balance.IsGreaterThan(amount)) {
        balance = balance.Subtract(amount);
        cout << "Withdrawal successful." << endl;
    } else {
        cout << "Insufficient funds." << endl;
    }
}

void Account::Deposit(const Money& amount) {
    balance = balance.Add(amount);
    cout << "Deposit successful." << endl;
}

void Account::AddInterest() {
    Money interest = balance.Multiply(interestRate);
    balance = balance.Add(interest);
}

void Account::ConvertToDollars() {
    double exchangeRate = 0.026;
    balance = balance.Multiply(exchangeRate);
}

void Account::ConvertToEuros() {
    double exchangeRate = 0.91;
    balance = balance.Multiply(exchangeRate);
}

void Account::ConvertToHryvnya() {
    double exchangeRate = 42.38;
    balance = balance.Multiply(exchangeRate);
}

void Account::Read() {
    cout << "Enter owner's last name: ";
    cin >> ownerLastName;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter interest rate: ";
    cin >> interestRate;

    cout << "Enter balance (in hryvnia and kopiyky): ";
    long hryvnia;
    unsigned char kopiyky;
    cin >> hryvnia >> kopiyky;
    balance = Money(hryvnia, kopiyky);
}

void Account::Display() const {
    cout << "Owner: " << ownerLastName << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Interest Rate: " << interestRate << endl;
    cout << "Balance: ";
    balance.Display();
    cout << endl;
}

string Account::ToString() const {
    stringstream sout;
    sout << balance.GetHryvnia() << " hryvnia " << static_cast<int>(balance.GetKopiyky()) << " kopiyok";
    return sout.str();
}

string Account::AmountInWords() const {
    const string _thousands[10] = { "", "tysyacha", "dvi tysiachy", "try tysiachy", "4otyry tysiachy", "p’jat tysiach", "6ist tysiach", "sim tysiach", "visim tysiach", "dev’jat tysiach" };
    const string _centuries[10] = { "", "sto", "dvisti", "trysta", "4onyrysta", "p’jatsot", "6istsot", "simsot", "visimsot", "dev’jatsot" };
    const string _decades[10] = { "", "", "dvadciat’", "trydciat’", "sorok", "p’jatdesiat", "6istdesiat", "simdesiat", "visimdesiat", "dev’janosto" };
    const string _digits[20] = { "", "odyn", "dva", "try", "4otyry", "p’jat’", "6ist’", "sim", "visim", "dev’jat’", "desiat’", "odynadciad’", "dvanadciad’", "trynadciad’", "4otyrnadciad’", "p’jatnadciad’", "6istnadciad’", "simnadciad’", "visimnadciad’", "dev’jatnadciad’" };

    long absBalance = abs(balance.GetHryvnia());
    int thousands = absBalance / 1000;
    absBalance %= 1000;
    int cen = absBalance / 100;
    absBalance %= 100;
    int dec = absBalance / 10;
    int dig = absBalance % 10;

    string amountInWords = "";
    if (thousands > 0)
        amountInWords += _thousands[thousands] + " ";

    amountInWords += _centuries[cen] + " " + _decades[dec] + " " + _digits[dig];

    amountInWords += " hryvnia " + to_string(balance.GetKopiyky()) + " kopiyok";

    return amountInWords;
}
