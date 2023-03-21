#include <account/account.h>
#include <math.h>
#include <string.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#define N 255
//#define MAX_COUNT_ACCOUNTS 7

using namespace user_bank;
using namespace std;

// Определение работы класса Account
Account::Account(): balance(0), type(TypeScore::none), percent(0) {}
Account::Account(TypeScore type_of_score): balance(0) {
    switch (type_of_score)
    {
    case TypeScore::calculated:
        type = TypeScore::calculated;
        break;
    case TypeScore::deposit:
        percent = 0;
        type = TypeScore::deposit;
        break;
    case TypeScore::credit:
        percent = 0;
        type = TypeScore::credit;
        break;
    default:
        break;
    }
    if (type != type_of_score)
        throw runtime_error("Не удалось присвоить тип счёта");
};
void        Account::accrual() {
    switch (type)
    {
    case user_bank::TypeScore::calculated:
        break;
    case user_bank::TypeScore::deposit:
        this->balance += this->balance * this->percent / 12;
        break;
    case user_bank::TypeScore::credit:
        if (this->balance < 0) {            //Баланс не отрицательный, поэтому изменений нет
            this->balance -= fabs(this->balance) * (this->percent) / 12;
        }
        break;
    default:
        throw runtime_error("Тип аккаунта не позволяет совершить действия с его счётом!");
        break;
    };
};
float       Account::getBalance() {
    return this->balance;
}; 
void        Account::setBalance(float balance) {
    this->balance = balance;
};
float       Account::getPercent() {
    return this->percent;
};
void        Account::setPercent(float percent) {
    this->percent = percent;
}
TypeScore	Account::getType() {
    return this->type;
}
Account&    Account::overwrite(TypeScore type_of_score, float balance, float percent) {
    this->type = type_of_score;
    this->balance = balance;
    this->percent = percent;

    return *this;
}
Account& Account::overwrite(TypeScore type_of_score, float balance) {
    this->type = type_of_score;
    this->balance = balance;
    this->percent = 0;

    return *this;
}
Account&    Account::deleteScore() {
    this->type = TypeScore::none;
    this->balance = 0;
    this->percent = 0;
    return *this;
}
Account&    Account::operator=(const Account& r) {
    this->type = r.type;
    this->balance = r.balance;
    this->percent = r.percent;

    return *this;
}


