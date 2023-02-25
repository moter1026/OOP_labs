#include <gtest/gtest.h>
#include <functions/functions.h>
//namespace user_bank {
	//enum class TypeScore {
	//	calculated = 1,
	//	deposit,
	//	credit
	//};
//};

TEST(AccountTests, AccountTest1) {
	user_bank::TypeScore type = user_bank::TypeScore::calculated;
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 33000, 12.5);
	float balance = Matvey.accounts[0].getBalance();
	EXPECT_EQ(balance ,33000);
}

TEST(AccountTests, AccountTest2) {
	user_bank::TypeScore type = user_bank::TypeScore::credit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 330000, 12.4);
	float balance = Matvey.accounts[0].getBalance();
	EXPECT_EQ(balance, 330000);
}

TEST(AccountTests, AccountTest3) {
	user_bank::TypeScore type = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 100000, 8.7);
	float balance = Matvey.accounts[0].getBalance();
	EXPECT_EQ(balance, 100000);
}

TEST(AccountTests, FindMaxBalanceTest) {
	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_calculated, 150000);

	user_bank::TypeScore type_credit = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_credit, 30000, 4);


	EXPECT_EQ(balance, 100000);
}
