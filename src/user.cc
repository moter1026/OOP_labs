#include <account/user.h>
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
User::User() {
    strcpy(all_name, " ");
};
User::User(const char* name) {
    strcpy(all_name, name);
};
char*       User::get_all_name() {
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
        if (max_balance >= select_account_with_index(i).getBalance())
            continue;
        else {
            max_balance = select_account_with_index(i).getBalance();
            index = i;
        }
    }
    return index;
};
Account&    User::create_calculated_account(unsigned int index, TypeScore type, float balance) {
    check_calculated(type, balance);
    Account& new_el = select_account_with_index(index);
    new_el = Account(type);    // через конструктор, потому что не могу обратиться к чужой приватной переменной
    new_el.setBalance(balance);
    new_el.setPercent(0);

    ++count_accounts;
    return new_el;
}
Account&    User::create_dep_or_cre_account(unsigned int index, TypeScore type, float balance, float percent) {
    check_deposit_or_credit(type, balance, percent);
    Account& new_el = select_account_with_index(index);
    new_el = Account(type);    // через конструктор, потому что не могу обратиться к чужой приватной переменной
    new_el.setBalance(balance);
    new_el.setPercent(percent);

    ++count_accounts;
    return new_el;
}
Account&    User::create_new_account_in_index(unsigned int index, TypeScore type, float balance) {
    check_calculated(type, balance);
    if (count_accounts >= MAX_COUNT_ACCOUNTS)
        throw runtime_error("Максимальное кол-во аккаунтов уже создано");
    for (size_t i = 0; i < MAX_COUNT_ACCOUNTS; i++)
    {
        if (index < count_accounts - i) {
            Account& left = select_account_with_index(count_accounts - i);
            Account& right = select_account_with_index(count_accounts - i + 1);
            right = left;
        }
        else
            return create_calculated_account(index, type, balance);
    }
}
Account&    User::create_new_account_in_index(unsigned int index, TypeScore type, float balance, float percent) {
    check_deposit_or_credit(type, balance, percent);
    if (index >= MAX_COUNT_ACCOUNTS)
        throw runtime_error("Индекс, передаваемый в функцию, слишком большой");
    if (count_accounts >= MAX_COUNT_ACCOUNTS)
        throw runtime_error("Максимальное кол-во аккаунтов уже создано");

    for (size_t i = 0; i < MAX_COUNT_ACCOUNTS; i++)
    {
        if (index < count_accounts - i) {
            Account& left = select_account_with_index(count_accounts - 1 - i);
            Account& right = select_account_with_index(count_accounts - i);
            right = left;
        }
        else
            return create_dep_or_cre_account(index, type, balance, percent);
    }
}
Account&    User::create_new_account(TypeScore type, float balance) {
    if (count_accounts >= MAX_COUNT_ACCOUNTS)
        throw runtime_error("Максимальное кол-во аккаунтов уже создано");
    return create_calculated_account(count_accounts, type, balance);
};
Account&    User::create_new_account(TypeScore type, float balance, float percent) {
    if (count_accounts >= MAX_COUNT_ACCOUNTS)
        throw runtime_error("Максимальное кол-во аккаунтов уже создано");
    return create_dep_or_cre_account(count_accounts, type, balance, percent);
};
Account&    User::select_account_with_index(unsigned int index) {
    //if (index >= MAX_COUNT_ACCOUNTS || index >= count_accounts)
    if (index >= MAX_COUNT_ACCOUNTS)
        throw runtime_error("Индекс, передаваемый в функцию, слишком большой");
    return accounts[index];
}
Account     User::delete_account_with_index(unsigned int index) {
    if (!count_accounts)
        throw runtime_error("Нет ни одного аккаунта");
    if (index >= MAX_COUNT_ACCOUNTS || index >= count_accounts)
        throw runtime_error("Индекс, передаваемый в функцию, слишком большой");

    Account copy_account = select_account_with_index(index);
    for (size_t i = index; i < MAX_COUNT_ACCOUNTS; i++)
    {
        if (i < count_accounts - 1) {
            Account& left_el = select_account_with_index(i);
            Account& right_el = select_account_with_index(i + 1);
            left_el = right_el;
        }
        else
        {
            Account& del_el = select_account_with_index(i);
            del_el.type = TypeScore::none;
            del_el.balance = 0;
            del_el.percent = 0;
            --count_accounts;
            return copy_account;
        }
    }
    
}
Account&    User::operator[](size_t size) {
    return select_account_with_index(size);
};


