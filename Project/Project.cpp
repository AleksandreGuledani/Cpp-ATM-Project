#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "LimitsImplementation.h"
using namespace std;
int main() {
    ifstream ifs("cardInformation.txt");
    string cardNumber, expirationDate, cvc, pinCode;
    double balance, creditLimit;
    ifs >> cardNumber >> expirationDate >> cvc >> balance >> pinCode >> creditLimit;
    ifs.close();

    CreditCard userCard(cardNumber, expirationDate, cvc, balance, pinCode, creditLimit);

    string inputCardNumber, inputExpirationDate, inputCvc, inputPinCode;
    bool isValid = false;
    cout << "Welcome to our ATM. Enter your card information to continue:  " << endl;
    while (!isValid) {
        cout << "Enter Card Number: ";
        cin >> inputCardNumber;
        cout << "Enter Expiration Date(MM/YY): ";
        cin >> inputExpirationDate;
        cout << "Enter CVC: ";
        cin >> inputCvc;

        if (userCard.validate(inputCardNumber, inputExpirationDate, inputCvc)) {
            cout << "Card is valid." << endl;
            cout << "Enter Pincode: ";
            cin >> inputPinCode;
            if (userCard.checkPin(inputPinCode)) {
                isValid = true;
                cout << "Pincode is valid!" << endl << endl;
                cout << "Your information: " << endl << userCard;
            }
            else {
                cout << "Pincode is not valid!" << endl;
            }
        }
        else {
            cout << "Card is invalid. Please try again." << endl;
        }
    }

    bool exit = false;
    while (!exit) {
        int choice;
        cout <<"\n1. View Balance\n2. Withdraw Money\n3. Deposit Money\n4. View Last 5 Transactions\n5. Change PIN\n6. Currency Conversion\n7. See your current information\n8. Check Withdrawal Limit\n9. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << endl;
            userCard.viewBalance();
            break;
        case 2: {
            double amount;
            cout << endl << "Enter amount to withdraw: ";
            cin >> amount;
            userCard.withdraw(amount);
            break;
        }
        case 3: {
            double amount;
            cout << endl << "Enter amount to deposit: ";
            cin >> amount;
            userCard.deposit(amount);
            break;
        }
        case 4:
            cout << endl;
            userCard.viewLastFiveTransactions();
            break;
        case 5: {
            string newPin;
            cout << endl << "Enter new PIN: ";
            cin >> newPin;
            userCard.changePin(newPin);
            cout << "Pincode has successfully been changed!" << endl;
            break;
        }
        case 6: {
            double amount;
            string currency;
            cout << endl << "Enter amount in GEL: ";
            cin >> amount;
            cout << "Enter currency (USD, EUR): ";
            cin >> currency;
            userCard.currencyConversion(amount, currency);
            cout << endl;
            break;
        }
        case 7:
            cout << endl << "Your information: " << endl << userCard << endl;
            break;
        case 8:
            userCard.viewWithdrawalLimit();
            break;
        case 9:
            cout << "Thank you for using our ATM!" << endl;
            exit = true;
            break;
        default:
            cout << "Invalid option!" << endl;
        }
    }
}

