#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;

public:
    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
        }
    }

    int getBalance() {
        return balance;
    }
};

int main() {

    BankAccount acc;

    acc.deposit(1000);
    acc.withdraw(200);

    cout << "Balance: " << acc.getBalance() << endl;

    return 0;
}