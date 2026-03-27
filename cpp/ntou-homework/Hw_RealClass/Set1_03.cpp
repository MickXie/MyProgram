#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
    }

    double getBalance() const
    {
        return balance;
    }
};

int main()
{
    double initialBalance, depositAmount, withdrawalAmount;
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    BankAccount account(initialBalance);
    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    cout << "Enter withdrawal amount: ";
    cin >> withdrawalAmount;
    cout << "Initial Balance: $" << fixed << setprecision(0) << account.getBalance() << endl;
    account.deposit(depositAmount);
    cout << "Depositing $" << fixed << setprecision(0) << depositAmount << "..." << endl;
    account.withdraw(withdrawalAmount);
    cout << "Withdrawing $" << fixed << setprecision(0) << withdrawalAmount << "..." << endl;
    cout << "Current Balance: $" << fixed << setprecision(0) << account.getBalance() << endl;
    system("pause");
    return 0;
}