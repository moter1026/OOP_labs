#include "..\include\account\user.h"
#include <account/user.h>
#include <math.h>
#include <string.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string.h>
#include <typeinfo>
#define N 255

using namespace user_bank;
using namespace std;

User::User() noexcept {
    _all_name = " ";
};

User::User(const char* name) noexcept {
    _all_name = name;
};
User::User(string name) noexcept {
    _all_name = name;
};
User::User(const User& user_for_copy) {
    this->_all_name = user_for_copy._all_name;
    this->_accounts = user_for_copy._accounts;
}
string  User::get_all_name() const
{
    return this->_all_name;
}
int		User::get_count_accounts() const {
    return this->_accounts.size(); 
}
int		User::find_max_balance() const {
    if (this->_accounts.size() <= 0)
        throw runtime_error("Ещё не открыто ни одного счёта");
    int index = 0;
    float max_balance = this->_accounts.at(index)->getBalance();
    for (int i = 1; i < this->_accounts.size(); i++)
    {
        if (max_balance < this->_accounts.at(i)->getBalance()) {
            max_balance = this->_accounts.at(i)->getBalance();
            index = i;
        }
    }
    return index;
}

Account& User::create_account(sharedAcc item) {
	_accounts.push_back(item);
	return *_accounts.back();
};
Account& User::create_account(float balance) {
    return *(new AccountCalculated(balance));
}
Account& User::create_account(string type, float balance, float percent) {
    if (_stricmp("deposit", type.c_str() ) == 0) // <string>.c_str Преобразует из std::string в const char*
    {
        if (balance < 0)
            throw runtime_error("В депозитном счёте не может быть отрицательный счёт!");
        std::shared_ptr<AccountDeposit> shared_acc = std::make_shared<AccountDeposit>(balance, percent);
        this->_accounts.push_back(shared_acc);
        return *this->_accounts.back();
    }
    else if (_stricmp("credit", type.c_str()) == 0)
    {
        std::shared_ptr<AccountCredit> shared_acc = std::make_shared<AccountCredit>(balance, percent);
        this->_accounts.push_back(shared_acc);
        return *this->_accounts.back();
    }
    else if (_stricmp("calculated", type.c_str()) == 0)
    {
        if (percent != 0)
            throw runtime_error("В расчётном счёте не могут быть проценты больше 0!");
        std::shared_ptr<AccountCalculated> shared_acc = std::make_shared<AccountCalculated>(balance, percent);
        this->_accounts.push_back(shared_acc);
        return *this->_accounts.back();
    }
}
Account& User::overwrite(unsigned int index, string type, float balance, float percent)
{
    this->_accounts.erase(this->_accounts.begin() + index);
    return create_new_account_in_index(index, type, balance, percent);
}
template<typename T>
Account& User::create_new_account_in_index(unsigned int index, std::shared_ptr<T> item) {
    //vector<std::shared_ptr<AccountCalculated>>::iterator iter = this->_accounts.insert(this->_accounts.begin() + index, item);
    return this->_accounts.insert(this->_accounts.begin() + index, item);
};
Account& User::create_new_account_in_index(unsigned int index, string type, float balance, float percent) {
    if (index > this->_accounts.size()) index = this->_accounts.size();
    if (_stricmp("deposit", type.c_str()) == 0)
    {
        if (balance < 0)
            throw runtime_error("В депозитном счёте не может быть отрицательный счёт!");
        std::shared_ptr<AccountDeposit> shared_acc = std::make_shared<AccountDeposit>(balance, percent);
        return **this->_accounts.insert(this->_accounts.begin() + index, shared_acc);
    }
    else if (_stricmp("credit", type.c_str()) == 0)
    {
        std::shared_ptr<AccountCredit> shared_acc = std::make_shared<AccountCredit>(balance, percent);
        return **this->_accounts.insert(this->_accounts.begin() + index, shared_acc);
    }
    else if (_stricmp("calculated", type.c_str()) == 0)
    {
        std::shared_ptr<AccountCalculated> shared_acc = std::make_shared<AccountCalculated>(balance, percent);
        return **this->_accounts.insert(this->_accounts.begin() + index, shared_acc);
    }
    //return *new AccountCalculated();
}

Account		User::delete_account_with_index(unsigned int index) {
    if (index < this->_accounts.size()-1) {
        Account copy_acc = *this->_accounts.at(index);
        this->_accounts.at(index)->deleteScore();
        this->_accounts.erase(this->_accounts.begin() + index);
        return copy_acc;
    }
    else if (index == this->_accounts.size()-1) {
        Account copy_acc = *this->_accounts.at(index);
        this->_accounts.at(index)->deleteScore();
        this->_accounts.erase(this->_accounts.begin() + index);
        return copy_acc;
    }
    else
    {
        throw runtime_error("По этому индексу нечего удалять!");
    }
};
void        User::swap(User& user_swap) noexcept {
    std::swap(_all_name, user_swap._all_name);
    std::swap(_accounts, user_swap._accounts);
}
User&       User::operator=(user_bank::User user_cpy) {
    User::swap(user_cpy);
    return *this;
};
Account&    User::operator[](unsigned int index) const {
    return *this->_accounts.at(index);
};
std::ostream& operator << (std::ostream& stream, User& item) {
    stream << "Имя пользователя: " << item.get_all_name() << std::endl;
    stream << "Коллчество открытых счетов: " << item.get_count_accounts() << std::endl;
    if (item.get_count_accounts() != 0)
    {
        for (int i = 0; i < item.get_count_accounts(); ++i) {
            stream << "Счёт №" << i << std::endl;
            stream << item[i] << endl;
        }
    }
    return stream;
};

std::ostream& user_bank::operator<<(std::ostream& stream, User& item)
{
    stream << "Имя пользователя: " << item.get_all_name() << std::endl;
    stream << "Количество открытых счетов: " << item.get_count_accounts() << std::endl;
    if (item.get_count_accounts() != 0)
    {
        for (int i = 0; i < item.get_count_accounts(); ++i) {
            stream << "Счёт номер: " << i << std::endl;
            stream << item[i] << endl;
        }
    }
    return stream;
}
