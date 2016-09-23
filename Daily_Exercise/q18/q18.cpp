#include <iostream>

using namespace std;

// A templated class.
template <typename T>

class BankAccount {
    private:
        T balance;
    
    public:
        BankAccount(T InitBal) {balance = InitBal;}        // Constructor that takes the initial balance as a parameter.
        ~BankAccount() {}
        T getBalance() {return balance;}        // Get the balance from the account.
        void add(T amount) {balance += amount;}    // Accepts an amount, adds it to balance
        void remove(T amount) {balance -= amount;}  // Accepts an amount, subtracts it from balance
};



int main() {
    
    double amount1 = 0.50;
    int amount2 = 50;
    
    BankAccount<double> bankac1(2000);      // Account that stores dollars and change
    BankAccount<int> bankac2(2000);         // Account that refuses to accept change, but only integers.
    
    // Get the balance from the two accounts.
    cout << bankac1.getBalance() << " " << bankac2.getBalance() << endl;
    
    bankac1.add(amount1);
    bankac2.remove(amount2);

    // Get the balance from the two accounts.
    cout << bankac1.getBalance() << " " << bankac2.getBalance() << endl;
    
    return 0;
}