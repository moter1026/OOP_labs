#include <gtest/gtest.h>
#include <account/account.h>
#include <iostream>
#include <math.h>
//namespace user_bank {
	//enum class TypeScore {
	//	calculated = 1,
	//	deposit,
	//	credit
	//};
//};

using namespace std;

TEST(AccountTests, AccountTest1) {
	setlocale(LC_ALL, "ru");
	user_bank::TypeScore type = user_bank::TypeScore::calculated;
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 33000);
	float balance = Matvey.accounts[0].getBalance();
	EXPECT_EQ(balance ,33000);
}

TEST(AccountTests, AccountTest2) {
	setlocale(LC_ALL, "ru");
	user_bank::TypeScore type = user_bank::TypeScore::credit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 330000, 12.4);
	float balance = Matvey.accounts[0].getBalance();
	EXPECT_EQ(balance, 330000);
}

TEST(AccountTests, AccountTest3) {
	setlocale(LC_ALL, "ru");

	user_bank::TypeScore type = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 100000, 8.7);
	float balance = Matvey.accounts[0].getBalance();
	EXPECT_EQ(balance, 100000);
}

TEST(AccountTests, FindMaxBalanceTest) {
	setlocale(LC_ALL, "ru");

	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_calculated, 30000);

	user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
	Matvey.create_new_account(type_credit, 150000, 4);

	int index_of_max_balance_in_accounts = Matvey.find_max_balance();
	
	EXPECT_EQ(index_of_max_balance_in_accounts, 2);
}

TEST(AccountTests, AccrualTest) {
	setlocale(LC_ALL, "ru");

	user_bank::User Matvey("Pikhurov Matvey");
	float percent;

	user_bank::TypeScore type_of_account = user_bank::TypeScore::deposit;
	percent = 8;
	Matvey.create_new_account(type_of_account, 100000, percent);

	/*user_bank::TypeScore type_of_account = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_of_account, 100000);*/

	/*user_bank::TypeScore type_of_account = user_bank::TypeScore::credit;
	percent = 7;
	Matvey.create_new_account(type_of_account, -100000, percent);*/

	float first_balance = Matvey.accounts[0].getBalance();
	cout << first_balance << endl;

	Matvey.accounts[0].accrual();
	float second_balance = Matvey.accounts[0].getBalance();
	cout << second_balance << endl;

	switch (type_of_account)
	{
	case user_bank::TypeScore::deposit:
		EXPECT_EQ(ceil( (second_balance - first_balance)/first_balance * 10 )/10 , ceil(percent / 12 * 10) / 10);
		break;
	case user_bank::TypeScore::credit:
		EXPECT_EQ(ceil(fabs( ((first_balance - second_balance)/(first_balance)) )*10)/10 , ceil(percent/12*10)/10);
		break;
	default:
		EXPECT_EQ(second_balance, first_balance);
		break;
	}

}
