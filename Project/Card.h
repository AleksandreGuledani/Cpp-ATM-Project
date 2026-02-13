using namespace std;
class Card {
protected:
    string cardNumber, expirationDate, cvc, pinCode;
    double balance;
public:
    Card(const string&, const string&, const string&, double, const string&);
    bool validate(const string&, const string&, const string&);
    bool checkPin(const string&);
    void viewBalance();
    virtual void withdraw(double);
    void deposit(double);
    void viewLastFiveTransactions();
    void recordTransaction(const string&);
    void changePin(const string&);
    void currencyConversion(double, const string&);
    friend ostream& operator<<(ostream&, const Card&);
    vector<string> transactionHistory;
};