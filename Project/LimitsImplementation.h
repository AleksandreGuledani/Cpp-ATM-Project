#include "Limits.h"
void CreditCard::withdraw(double amount) {
    if (amount > withdrawalLimit && amount > balance) {
        cout << "Your request exceeds the amount of money you have in the bank!" << endl;
    }
    else if (amount > withdrawalLimit && amount < balance) {
        cout << "Transaction exceeds Withdrawal limit!" << endl;
    }
    else {
        Card::withdraw(amount);
    }
}

void CreditCard::checkWithdrawalLimit(double amount) {
    if (amount > withdrawalLimit) {
        cout << "Transaction exceeds Withdrawal limit!" << endl;
    }
}

void CreditCard::viewWithdrawalLimit() {
    cout << "Withdrawal Limit: $" << withdrawalLimit << endl;
}