#include <account/account.h>
#include <math.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace user_bank;
using namespace std;

//____________________Account________________________
Account::Account(float balance, float percent) {
	this->_balance = balance;
	this->_percent = percent;
}
float	Account::getBalance() const noexcept {
	return this->_balance;
};
void	Account::setBalance(float balance) {
	this->_balance = balance;
}
float		Account::getPercent() const noexcept {
	return this->_percent;
};
bool		Account::operator==(Account user_cpy) {
	if (this->_balance == user_cpy._balance &&
		this->_percent == user_cpy._percent &&
		this->_type == user_cpy._type)
		return true;
	return false;
}
void user_bank::Account::print(std::ostream& stream) const
{
		stream << "Balance: " << this->getBalance() << endl;
		stream << "Percent: " << this->getPercent() << endl;
		stream << "Type: " << this->getType() << endl;
}
Account& Account::deleteScore() noexcept {
	this->_percent = 0;
	this->_balance = 0;
	this->_type = "";
	return *this;
}
std::string Account::getType() const {
	return this->_type;
}




//____________________AccountCalculated________________________
AccountCalculated::AccountCalculated(){
	this->_percent = 0;
	this->_balance = 0;
	this->_type = "Calculated";
}
AccountCalculated::AccountCalculated(float balance) {
	this->_percent = 0;
	this->_balance = balance;
	this->_type = "Calculated";
}
AccountCalculated::AccountCalculated(float balance, float percent) {
	if (percent)
		throw runtime_error("В расчётном счёте не должно быть процентов!");
	this->_percent = 0;
	this->_balance = balance;
	this->_type = "Calculated";
}
std::shared_ptr<Account> AccountCalculated::clone() const
{
	return std::make_shared<AccountCalculated>(this->_balance, this->_percent);
}
void user_bank::AccountCalculated::print(std::ostream& stream) const
{
	stream << "Balance: " << this->getBalance() << endl;
	stream << "Type: " << this->getType() << endl;
}
void user_bank::AccountCalculated::accrual()
{
	this->_balance += this->_balance * this->_percent / 100 / 12;
}


// _________________AccountCredit_________________
AccountCredit::AccountCredit()
{
	this->_balance = 0;
	this->_percent = 0;
	this->_type = "Credit";
}
AccountCredit::AccountCredit(float balance, float percent) {
	this->_percent = percent;
	this->_balance = balance;
	this->_type = "Credit";
}
std::shared_ptr<Account> AccountCredit::clone() const
{
	return make_shared<AccountCredit>(this->_balance, this->_percent);
}
;
void		AccountCredit::accrual() {
	if (this->_balance < 0) {            //Баланс не отрицательный, поэтому изменений нет
        this->_balance -= fabs(this->_balance) * (this->_percent / 100) / 12;
    }
}

//void		AccountCredit::swap(AccountCredit& acc) noexcept {
//	std::swap(this->_balance, acc._balance);
//	std::swap(this->_percent, acc._balance);
//}
void		AccountCredit::setPercent(float percent) {
	this->_percent = percent;
};

// _________________AccountDeposit_________________
AccountDeposit::AccountDeposit() {
	this->_balance = 0;
	this->_percent = 0;
	this->_type = "Deposit";
};
AccountDeposit::AccountDeposit(float balance, float percent) {
	this->_balance = balance;
	this->_percent = percent;
	this->_type = "Deposit";
};
void				AccountDeposit::accrual() {
	this->_balance += this->_balance * this->_percent / 100 / 12;
}

shared_ptr<Account> AccountDeposit::clone() const
{
	return make_shared<AccountDeposit>(this->_balance, this->_percent);
}
void				AccountDeposit::setPercent(float percent) {
	this->_percent = percent;
};


std::ostream&   user_bank::operator<< (std::ostream& stream, user_bank::Account& item) {
	item.print(stream);
	return stream;
}
//std::ostream&   user_bank::operator<< (std::ostream& stream, user_bank::AccountCalculated& item) {
//    stream << "Balance: " << item.getBalance() << endl;
//    stream << "Type: Calculated" << endl;
//    return stream;
//}
//std::ostream& user_bank::operator<< (std::ostream& stream, user_bank::AccountCredit& item) {
//	stream << "Balance: " << item.getBalance() << endl;
//    stream << "Percent: " << item.getPercent() << endl;
//    stream << "Type: Credit" << endl;
//	return stream;
//}
//std::ostream& user_bank::operator<< (std::ostream& stream, user_bank::AccountDeposit& item) {
//	stream << "Balance: " << item.getBalance() << endl;
//	stream << "Percent: " << item.getPercent() << endl;
//	stream << "Type: Deposit" << endl;
//	return stream;
//}