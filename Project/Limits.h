#include "CardImplementation.h"
class CreditCard : public Card {
private:
    double withdrawalLimit;

public:
    CreditCard(const string& cn, const string& ed, const string& cv, double bal, const string& pc, double limit)
        : Card(cn, ed, cv, bal, pc), withdrawalLimit(limit) {}
    void withdraw(double amount) ;
    void checkWithdrawalLimit(double amount);
    void viewWithdrawalLimit();
};

