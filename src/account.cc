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
Account::Account(TypeScore type_of_score, float set_balance): balance(set_balance), percent(0) {
    switch (type_of_score)
    {
    case TypeScore::calculated:
        type = TypeScore::calculated;
        break;
    case TypeScore::deposit:
        type = TypeScore::deposit;
        break;
    case TypeScore::credit:
        type = TypeScore::credit;
        break;
    default:
        break;
    }
    if (type != type_of_score)
        throw runtime_error("Не удалось присвоить тип счёта");
};
Account::Account(TypeScore type_of_score, float set_balance, float percent): balance(set_balance), percent(percent) {
    switch (type_of_score)
    {
    case TypeScore::calculated:
        type = TypeScore::calculated;
        break;
    case TypeScore::deposit:
        type = TypeScore::deposit;
        break;
    case TypeScore::credit:
        type = TypeScore::credit;
        break;
    default:
        break;
    }
    if (type != type_of_score)
        throw runtime_error("Не удалось присвоить тип счёта");
}
Account::Account(const Account& account_for_copy) {
    this->type = account_for_copy.type;
    this->balance = account_for_copy.balance;
    this->percent = account_for_copy.percent;
}
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
Account&    Account::overwrite(TypeScore type_of_score, float balance) {
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
//Account     Account::operator=(const Account r) {
//    this->type = r.type;
//    this->balance = r.balance;
//    this->percent = r.percent;
//
//    return *this;
//}

std::ostream& user_bank::operator<<(std::ostream& stream, const TypeScore item) {
    //stream << "calculated" << endl;
    switch (item)
    {
    case user_bank::TypeScore::none:
        stream << "none" << endl;
        break;
    case user_bank::TypeScore::calculated:
        stream << "calculated" << endl;
        break;
    case user_bank::TypeScore::deposit:
        stream << "deposit" << endl;
        break;
    case user_bank::TypeScore::credit:
        stream << "credit" << endl;
        break;
    default:
        throw runtime_error("ошибка вывода типа");
        break;
    }
    return stream;
}

std::ostream& user_bank::operator<< (std::ostream& stream, user_bank::Account& item) {
    
    //out << "Balance: " << item.getBalance() << endl;
    if (item.getType() == TypeScore::credit || item.getType() == TypeScore::deposit)
    {
        stream << "Balance: " << item.getBalance() << endl;
        stream << "Percent: " << item.getPercent() << endl;
        stream << "Type: " << item.getType() << endl;
    }
    else
    {
        stream << "Balance: " << item.getBalance() << endl;
        stream << "Type: " << item.getType() << endl;
    }
    
    return stream;
}



