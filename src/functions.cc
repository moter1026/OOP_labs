#include <functions/functions.h>
#include <math.h>
#include <string.h>
#define N 255
#define MAX_COUNT_ACCOUNTS 7

using namespace user_bank;

Account::Account() {
        balance = 0;
        TypeScore::calculated;
}
Account::Account(int type_of_score) {
    switch (type_of_score)
    {
    case 1:
        balance = 0;
        type = TypeScore::calculated;
        break;
    case 2:
        balance = 0;
        percent = 0;
        type = TypeScore::deposit;
        break;
    case 3:
        balance = 0;
        percent = 0;
        type = TypeScore::credit;
        break;
    default:
        break;
    }

};
void Account::accrual(float balance, float percent) {
    switch (type)
    {
    case user_bank::Account::TypeScore::calculated:

        break;
    case user_bank::Account::TypeScore::deposit:
        this->balance *= this->percent / 12;
        break;
    case user_bank::Account::TypeScore::credit:
        float bal = this->balance;
        if (bal < 0)
            bal = fabs(bal) * (this->percent) / 12;
        break;
    };
};
float Account::getBalance() {
    return this->balance;
};
float Account::getPercent() {
    return this->percent;
};


User::User(const char* name) {
    strcpy(all_name, name);
};
char* User::get_all_name() {
    return this->all_name;
};
int User::find_max_balance() {
    float max_balance = accounts[0].getBalance();
    int index = 0;
    for (int i = 1; i < MAX_COUNT_ACCOUNTS; i++)
    {
        if (max_balance >= accounts[i].getBalance())
            continue;
        else {
            max_balance = accounts[i].getBalance();
            index = i;
        }
    }
    return index;
};
void User::create_new_account(int type, float balance, ...) {
    accounts[count_accounts] = user_bank::Account(type);
    count_accounts += 1;
};

