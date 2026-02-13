#include "Card.h"
Card::Card(const string& cn, const string& ed, const string& cv, double bal, const string& pc)
    : cardNumber(cn), expirationDate(ed), cvc(cv), balance(bal), pinCode(pc) {}
   
bool Card::validate(const string& inputCardNumber, const string& inputExpirationDate, const string& inputCvc) {
    return inputCardNumber == cardNumber && inputExpirationDate == expirationDate && inputCvc == cvc;
}

bool Card::checkPin(const string& inputPinCode) {
    return inputPinCode == pinCode;
}

void Card::viewBalance() {
    cout << "Current Balance: " << balance << endl;
}

void Card::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        string transaction = "Withdrawal: " + to_string(amount);
        recordTransaction(transaction);
    }
    else {
        cout << "Your request exceeds the amount of money you have in the bank!" << endl;
    }
}

void Card::recordTransaction(const string& transaction) {
    ofstream ofs("transactions.txt", ios::app);
    ofs << transaction << endl;
    ofs.close();
}

void Card::deposit(double amount) {
    balance += amount;
    string transaction = "Deposit: " + to_string(amount);
    recordTransaction(transaction);
}

void Card::viewLastFiveTransactions() {
    ifstream ifs1("transactions.txt");
    string transaction;
    transactionHistory.clear();
    while (getline(ifs1, transaction)) {
        transactionHistory.push_back(transaction);
    }
    if (transactionHistory.size() >= 5) {
        cout << "Last 5 Transactions:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << transactionHistory[transactionHistory.size() - 1 - i] << endl;
        }
    }
    else if(transactionHistory.size()>0 && transactionHistory.size() < 5) {
        cout << "Last 5 Transactions:" << endl;
        for (int i = 0; i < transactionHistory.size(); i++) {
            cout << transactionHistory[i] << endl;
        }
    }
    else if(transactionHistory.empty()){
        cout << "Transactions have not been made yet"<<endl;
    }
}

void Card::changePin(const string& newPin) {
    pinCode = newPin;
}

void Card::currencyConversion(double amount, const string& currency) {
    if (currency == "USD") {
        cout << amount << " GEL  is: " << (double)amount * 0.35<<'$';
    }
    else if (currency == "EUR") {
        cout << amount << " GEL is: " << (double)amount * 0.33<<" In EUR";
    }
    else {
        cout << "Unavailable Currency" << endl;
    }
}

ostream& operator<<(ostream& out, const Card& C) {
    out << "Card Number: " << C.cardNumber << endl
        << "Expiration Date: " << C.expirationDate << endl
        << "CVC code: " << C.cvc << endl
        << "Balance: " << C.balance << endl
        << "Pincode: " << C.pinCode << endl << endl;
    return out;
}