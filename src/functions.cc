#include <functions/functions.h>
#include <math.h>

int sum_stub(int lhs, int rhs) {
    return lhs + rhs;
}

int fact(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    return n * fact(n - 1);
}

class user_bank::Account{
private: 
    enum class TypeScore
    {
        calculated, deposit, credit
    };
    char all_name;
    float balance;
    float percent;
public:
    float accrual() {
        switch (TypeScore)
        {
        case user_bank::Account::TypeScore::calculated:

            break;
        case user_bank::Account::TypeScore::deposit:
            this->balance *= this->percent / 12;
            break;
        case user_bank::Account::TypeScore::credit:
            float bal = this->balance;
            if (bal < 0)
                bal = abs(bal) * (this->percent) / 12;
            break;
        default:
            break;
        };
    }
    char* getName() {
        return &(this->all_name);
    };
    float getBalance() {
        return this->balance;
    };
    float getPercent() {
        return this->percent;
    };
}
