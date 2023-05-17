#include <account/user.h>
#include <math.h>
#include <string.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string.h>
#define N 255

using namespace user_bank;
using namespace std;


void check(TypeScore type, float balance, float percent) {
    if (type == TypeScore::calculated && percent != 0)
        throw runtime_error("Ошибка программиста, для рассчётного счёта кол-во процентов годовых не нужно указывать или они должны быть равны 0!");
    if (balance < 0 && type != TypeScore::credit)
        throw runtime_error("Нельзя создать не кредитный счёт с балансом меньше 0");
    if (percent < 0)
        throw runtime_error("Нельзя создать счёт с кол-вом процентов годовых меньше 0");
}

// Определение работы класса User
User::User() {
    all_name = " ";
};
User::User(const char* name) {
    all_name = name;
};
User::User(string name) {
    all_name = name;
};
User::User(const User& user_for_copy) {
    this->all_name = user_for_copy.all_name;
    this->count_accounts = user_for_copy.count_accounts;
    this->accounts = new Account * [this->count_accounts];
    for (int i = 0; i < this->count_accounts; i++)
    {
        this->accounts[i] = user_for_copy.accounts[i];
    }
};
void        User::rewrite_array_with_acconts() {
    Account** acc = new Account * [count_accounts + 1];
    for (int i = 0; i < count_accounts; i++) {
        acc[i] = accounts[i];
    }
    acc[count_accounts] = new Account();
    delete[] accounts;
    accounts = acc;
}
Account& User::create_account(unsigned int index, TypeScore type, float balance) {
    check(type, balance, 0);
    if (index >= this->count_accounts)
    {
        rewrite_array_with_acconts();
        index = this->count_accounts;
    }
    *(accounts[index]) = Account(type, balance);
    accounts[index]->setPercent(0);

    ++this->count_accounts;
    return *(accounts[index]);
}
Account& User::create_account(unsigned int index, TypeScore type, float balance, float percent) {
    check(type, balance, percent);
    if (index >= this->count_accounts)
    {
        rewrite_array_with_acconts();
        index = this->count_accounts;
    }
    *(accounts[index]) = Account(type, balance);
    accounts[index]->setPercent(percent);

    ++this->count_accounts;
    return *(accounts[index]);
}
Account& User::create_account(TypeScore type, float balance, float percent) {
    check(type, balance, percent);
    rewrite_array_with_acconts();
    int index = this->count_accounts;
    *(accounts[index]) = Account(type, balance);
    accounts[index]->setPercent(percent);

    ++this->count_accounts;
    return *(accounts[index]);
}
Account& User::create_account(TypeScore type, float balance) {
    check(type, balance, 0);
    rewrite_array_with_acconts();
    int index = this->count_accounts;
    *(accounts[index]) = Account(type, balance);
    accounts[index]->setPercent(0);

    ++this->count_accounts;
    return *(accounts[index]);
}
string      User::get_all_name() {
    return this->all_name;
};
int			User::get_count_accounts() {
    return this->count_accounts;
}
int         User::find_max_balance() {
    if (this->count_accounts <= 0)
        throw runtime_error("Ещё не открыто ни одного счёта");
    float max_balance = accounts[0]->getBalance();
    int index = 0;
    for (int i = 1; i < this->count_accounts; i++)
    {
        if (max_balance < accounts[i]->getBalance()) {
            max_balance = accounts[i]->getBalance();
            index = i;
        }
    }
    return index;
};
Account& User::create_new_account(Account* new_account) {
    Account** acc = new Account * [count_accounts + 1];
    for (int i = 0; i < count_accounts; i++) {
        acc[i] = accounts[i];
    }
    acc[count_accounts] = new_account;
    delete[] accounts;
    accounts = acc;
    ++count_accounts;
    return *accounts[count_accounts];
};
Account& User::create_new_account_in_index(unsigned int index, TypeScore type, float balance) {
    check(type, balance, 0);
    rewrite_array_with_acconts();
    if (index >= this->count_accounts) {
        index = this->count_accounts;
    }
    for (size_t i = 0; i <= this->count_accounts; i++)
    {
        if (index < this->count_accounts - i) {
            Account& left = *accounts[this->count_accounts - 1 - i];
            Account& right = *accounts[this->count_accounts - i];
            right = left;
        }
        else
            return create_account(index, type, balance);
    }
}
Account& User::create_new_account_in_index(unsigned int index, TypeScore type, float balance, float percent) {
    check(type, balance, percent);
    rewrite_array_with_acconts();
    if (index >= this->count_accounts) {
        index = this->count_accounts;
    }
    for (size_t i = 0; i <= this->count_accounts; i++)
    {
        if (index < this->count_accounts - i) {
            Account& left = *accounts[this->count_accounts - 1 - i];
            Account& right = *accounts[this->count_accounts - i];
            right = left;
        }
        else if (index < this->count_accounts)
            return create_account(index, type, balance, percent);
        else
            return create_account(this->count_accounts, type, balance, percent);

    }
}
Account     User::delete_account_with_index(unsigned int index) {
    if (!this->count_accounts)
        throw runtime_error("Нет ни одного аккаунта");
    if (index >= this->count_accounts)
        throw runtime_error("Индекс, передаваемый в функцию, слишком большой");

    Account copy_account = *accounts[index];
    for (size_t i = index; i < this->count_accounts; i++)
    {
        if (i < int(this->count_accounts) - 1) {
            Account& left_el = *accounts[i];
            Account& right_el = *accounts[i + 1];
            left_el = right_el;
        }
        else
        {
            Account& del_el = *accounts[i];
            del_el.deleteScore();
            --this->count_accounts;
            return copy_account;
        }
    }

}
Account& User::operator[](size_t size) {
    if (size >= count_accounts)
    {
        throw runtime_error("Неверно передан индекс. По данному индексу нет никакого аккаунта!");
    }
    return *accounts[size];
};
void        User::swap(User& user_swap) noexcept
{
    std::swap(all_name, user_swap.all_name);
    std::swap(accounts, user_swap.accounts);
}
User& User::operator=(user_bank::User user_cpy) {
    User::swap(user_cpy);
    return *this;
};

std::ostream& user_bank::operator << (std::ostream& stream, User& user) {
    stream << "Имя пользователя: " << user.get_all_name() << std::endl;
    stream << "Кол-во открытых счетов: " << user.get_count_accounts() << std::endl;
    if (user.get_count_accounts() != 0)
    {
        for (int i = 0; i < user.get_count_accounts(); ++i) {
            stream << "Аккаунт номер " << i << std::endl;
            stream << user[i] << endl;
        }
    }
    return stream;
}
