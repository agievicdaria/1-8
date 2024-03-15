// #pragma once
// #include <iostream>
// #include <string>
// #include <sstream>

// class Account {
// private:
//     class Money {
//     private:
//         long hryvnia;
//         unsigned char kopiyky;

//     public:
//         Money() : hryvnia(0), kopiyky(0) {}
//         Money(long hryvnia, unsigned char kopiyky) : hryvnia(hryvnia), kopiyky(kopiyky) {}

//         long GetHryvnia() const { return hryvnia; }
//         unsigned char GetKopiyky() const { return kopiyky; }

//         Money Add(const Money& secondValue) const;
//         Money Subtract(const Money& secondValue) const;
//         Money DivideInt(int divisor) const;
//         Money DivideDouble(double divisor) const;
//         Money Multiply(double multiplier) const;

//         bool IsEqual(const Money& secondValue) const;
//         bool IsLessThan(const Money& secondValue) const;
//         bool IsGreaterThan(const Money& secondValue) const;

//         void Display() const;
//     };

//     std::string ownerLastName;
//     std::string accountNumber;
//     double interestRate;
//     Money balance;

// public:
//     const std::string& GetOwnerLastName() const { return ownerLastName; }
//     const std::string& GetAccountNumber() const { return accountNumber; }
//     double GetInterestRate() const { return interestRate; }
//     const Money& GetBalance() const { return balance; }

//     void Init(const std::string& ownerLastName, const std::string& accountNumber, double interestRate, const Money& balance);
//     void ChangeOwner(const std::string& newOwnerLastName);
//     void Withdraw(const Money& amount);
//     void Deposit(const Money& amount);
//     void AddInterest();
//     void ConvertToDollars();
//     void ConvertToEuros();
//     void ConvertToHryvnya();
//     void Read();
//     void Display() const;
//     std::string ToString() const;
//     std::string AmountInWords() const;
// };

//! 2
#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Account
{
public:
    class Money
    {
    private:
        long hryvnia;
        unsigned char kopiyky;

    public:
        Money();
        Money(long hryvnia, unsigned char kopiyky);

        long GetHryvnia() const { return hryvnia; }
        unsigned char GetKopiyky() const { return kopiyky; }
        void SetHryvnia(long value) { hryvnia = value; }
        void SetKopiyky(unsigned char value) { kopiyky = value; }

        Money Add(const Money &secondValue) const;
        Money Subtract(const Money &secondValue) const;
        Money DivideInt(int divisor) const;
        Money DivideDouble(double divisor) const;
        Money Multiply(double multiplier) const;
        bool IsEqual(const Money &secondValue) const;
        bool IsLessThan(const Money &secondValue) const;
        bool IsGreaterThan(const Money &secondValue) const;
        void Display() const;
    };

private:
    string ownerLastName;
    string accountNumber;
    double interestRate;
    Money balance;

public:
    const string &GetOwnerLastName() const { return ownerLastName; }
    const string &GetAccountNumber() const { return accountNumber; }
    double GetInterestRate() const { return interestRate; }
    const Money &GetBalance() const { return balance; }

    void Init(const string &ownerLastName, const string &accountNumber, double interestRate, const Money &balance);
    void ChangeOwner(const string &newOwnerLastName);
    void Withdraw(const Money &amount);
    void Deposit(const Money &amount);
    void AddInterest();
    void ConvertToDollars();
    void ConvertToEuros();
    void ConvertToHryvnya();
    void Read();
    void Display() const;
    string ToString() const;
    string AmountInWords() const;
};