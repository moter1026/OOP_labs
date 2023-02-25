#include <functions/functions.h>
#include <math.h>
#include <string.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#define N 255
#define MAX_COUNT_ACCOUNTS 7

using namespace user_bank;
using namespace std;

// Определение работы класса Account
Account::Account() {
        balance = 0;
        TypeScore::calculated;
}
Account::Account(TypeScore type_of_score) {
    try
    {
        switch (type_of_score)
        {
        case TypeScore::calculated:
            balance = 0;
            type = TypeScore::calculated;
            break;
        case TypeScore::deposit:
            balance = 0;
            percent = 0;
            type = TypeScore::deposit;
            break;
        case TypeScore::credit:
            balance = 0;
            percent = 0;
            type = TypeScore::credit;
            break;
        default:
            break;
        }
        if (type != type_of_score)
            throw runtime_error("Не удалось присвоить тип счёта");
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
    }
};
void Account::accrual(float balance, float percent) {
    switch (type)
    {
    case user_bank::TypeScore::calculated:

        break;
    case user_bank::TypeScore::deposit:
        this->balance *= this->percent / 12;
        break;
    case user_bank::TypeScore::credit:
        float bal = this->balance;
        if (bal < 0)
            bal = fabs(bal) * (this->percent) / 12;
        break;
    };
};
float Account::getBalance() {
    return this->balance;
}; 
bool Account::setBalance(float balance) {
    try
    {
        this->balance = balance;
        if (this->balance != balance)
            throw runtime_error("Не удалось установить баланс");
        
        return true;
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        return false;
    }
   
};
float Account::getPercent() {
    return this->percent;
};
bool Account::setPercent(float percent) {
    try
    {
        this->percent = percent;
        if (this->percent != percent)
            throw runtime_error("Не удалось установить значение годовых процентов");
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
    }
}



// Определение работы класса User
User::User() {
    strcpy(all_name, "No name\0");
};
User::User(const char* name) {
    strcpy(all_name, name);
};
char* User::get_all_name() {
    return this->all_name;
};
int User::find_max_balance() {
    try {
        if (count_accounts <= 0)
            throw runtime_error("Ещё не открыто ни одного счёта");
        float max_balance = accounts[0].getBalance();
        int index = 0;
        for (int i = 1; i < count_accounts; i++)
        {
            if (max_balance >= accounts[i].getBalance())
                continue;
            else {
                max_balance = accounts[i].getBalance();
                index = i;
            }
        }
        return index;
    } 
    catch(const runtime_error& e) {
        cerr << e.what() << endl;
        return -1;
    }
    
};
bool User::create_new_account(TypeScore type, float balance) {
    try
    {
        if (type != TypeScore::calculated)
            throw runtime_error("Ошибка программиста, для всех типов счёта, кроме рассчётного необходимо передать кол-во процентво годовых!");
        if (balance < 0)
            throw runtime_error("Нельзя создать счёт с балансом меньше 0");
        accounts[count_accounts] = Account(type);
        accounts[count_accounts].setBalance(balance);

        count_accounts += 1;
        return true;
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        return false;
    }
    
}; 

bool User::create_new_account(TypeScore type, float balance, float percent) {
    try
    {
        if (type == TypeScore::calculated)
            throw runtime_error("Ошибка программиста, для рассчётного счёта кол-во процентов годовых не нужно указывать!");
        if (balance < 0)
            throw runtime_error("Нельзя создать счёт с балансом меньше 0");
        if (percent < 0)
            throw runtime_error("Нельзя создать счёт с кол-вом процентов годовых меньше 0");
        accounts[count_accounts] = Account(type);
        accounts[count_accounts].setBalance(balance);

        count_accounts += 1;
        return true;
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        return false;
    }
    
};


