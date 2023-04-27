#include "..\include\account\user.h"
#include "account/user.h"
#include <math.h>
#include <string.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#define N 255
//#define MAX_COUNT_ACCOUNTS 7

using namespace user_bank;
using namespace std;


void check_deposit_or_credit(TypeScore type, float balance, float percent) {
    if (type == TypeScore::calculated)
        throw runtime_error("Ошибка программиста, для рассчётного счёта кол-во процентов годовых не нужно указывать!");
    if (balance < 0 && type != TypeScore::credit)
        throw runtime_error("Нельзя создать не кредитный счёт с балансом меньше 0");
    if (percent < 0)
        throw runtime_error("Нельзя создать счёт с кол-вом процентов годовых меньше 0");
}
void check_calculated(TypeScore type, float balance) {
    if (type != TypeScore::calculated)
        throw runtime_error("Ошибка программиста, для всех типов счёта, кроме рассчётного необходимо передать кол-во процентво годовых!");
    if (balance < 0)
        throw runtime_error("Нельзя создать не кредитный счёт с балансом меньше 0");
}
// Определение работы класса User
//User::User() {
//    strcpy(all_name, " ");
//};

//void User::rewrite_array_with_acconts() {
//    Account *arr = new Account[this->max_count_accounts];
//    for (int i = 0; i < this->max_count_accounts; i++)
//    {
//        arr[i] = this->accounts[i];
//    }
//    delete [] this->accounts;
//    this->max_count_accounts = this->max_count_accounts + 16;
//    this->accounts = new Account[this->max_count_accounts];
//    for (int i = 0; i < this->max_count_accounts; i++)
//    {
//        this->accounts[i] = arr[i];
//    }
//    delete[] arr;
//}
void User::check_capasity_vector_of_accounts() {
    if (accounts.size() == accounts.capacity())
    {
        accounts.resize(accounts.size() + 1);
    }
}
Account& User::create_calculated_account(unsigned int index, TypeScore type, float balance) {
    check_calculated(type, balance);
    check_capasity_vector_of_accounts();
    if (index >= accounts.size())
    {
        this->accounts.push_back(Account(type, balance));
        ++count_accounts;
        return accounts.back();
    }
    else
    {
        this->accounts[index] = Account(type, balance);
        ++count_accounts;
        return accounts[index];
    }
}
Account& User::create_dep_or_cre_account(unsigned int index, TypeScore type, float balance, float percent) {
    check_deposit_or_credit(type, balance, percent);
    check_capasity_vector_of_accounts();
    //Account acc = Account(type, balance);

    if (index  >= accounts.size())
    {
        this->accounts.push_back(Account(type, balance));
        this->accounts.back().setPercent(percent);
        ++count_accounts;
        return accounts.back();
    }
    else
    {
        this->accounts[index] = Account(type, balance);
        this->accounts[index].setPercent(percent);
        ++count_accounts;
        return accounts[index];
    }
}
Account& User::select_account_with_index(unsigned int index) {
    if (index >= this->max_count_accounts)
        throw runtime_error("Индекс, передаваемый в функцию, слишком большой");
    
    return accounts[index];
}




User::User(const char* name) {
    all_name = name;
};
string      User::get_all_name() {
    return this->all_name;
};
int			User::get_count_accounts() {
    return this->count_accounts;
}
int         User::find_max_balance() {
    if (count_accounts <= 0)
        throw runtime_error("Ещё не открыто ни одного счёта");
    float max_balance = select_account_with_index(0).getBalance();
    int index = 0;
    for (int i = 1; i < count_accounts; i++)
    {
        if (max_balance < select_account_with_index(i).getBalance()) {
            max_balance = select_account_with_index(i).getBalance();
            index = i;
        }
    }
    return index;
};
Account&    User::create_new_account(TypeScore type, float balance) {
    Account acc = create_calculated_account(count_accounts, type, balance);
    accounts.push_back(acc);
    return accounts.back();
};
Account&    User::create_new_account(TypeScore type, float balance, float percent) {
    return create_dep_or_cre_account(count_accounts, type, balance, percent);
};
Account&    User::create_new_account_in_index(unsigned int index, TypeScore type, float balance) {
    check_calculated(type, balance);
    Account acc = Account(type, balance);
    accounts.insert(accounts.begin() + index, 1, acc);
    
    return accounts[index];
}
Account&    User::create_new_account_in_index(unsigned int index, TypeScore type, float balance, float percent) {
    check_deposit_or_credit(type, balance, percent);
    if (this->count_accounts == this->max_count_accounts)
    
    for (size_t i = 0; i < this->max_count_accounts; i++)
    {
        if (index < count_accounts - i) {
            Account& left = select_account_with_index(count_accounts - 1 - i);
            Account& right = select_account_with_index(count_accounts - i);
            right = left;
        }
        else if(index < count_accounts)
            return create_dep_or_cre_account(index, type, balance, percent);
        else
            return create_dep_or_cre_account(count_accounts, type, balance, percent);

    }
}
Account     User::delete_account_with_index(unsigned int index) {
    if (!count_accounts)
        throw runtime_error("Нет ни одного аккаунта");
    if (index >= this->max_count_accounts || index >= count_accounts)
        throw runtime_error("Индекс, передаваемый в функцию, слишком большой");

    Account copy_account = select_account_with_index(index);
    for (size_t i = index; i < this->max_count_accounts; i++)
    {
        if (i < count_accounts - 1) {
            Account& left_el = select_account_with_index(i);
            Account& right_el = select_account_with_index(i + 1);
            left_el = right_el;
        }
        else
        {
            Account& del_el = select_account_with_index(i);
            del_el.deleteScore();
            --count_accounts;
            return copy_account;
        }
    }
    
}
Account&    user_bank::User::operator[](size_t size) {
    return select_account_with_index(size);
}
void user_bank::User::swap(User& user_swap) noexcept
{
    std::swap(max_count_accounts, user_swap.max_count_accounts);
    std::swap(all_name, user_swap.all_name);
    std::swap(accounts, user_swap.accounts);
}
;
//void        user_bank::User::swap(user_bank::User& user_swap) noexcept {
//    std::swap(max_count_accounts, user_swap.max_count_accounts);
//    std::swap(all_name, user_swap.all_name);
//    std::swap(accounts, user_swap.accounts);
//};
User&   user_bank::User::operator=(user_bank::User user_cpy) {
    User::swap(user_cpy);
    return *this;
};


