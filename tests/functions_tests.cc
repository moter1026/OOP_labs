#include <gtest/gtest.h>
#include <functions/functions.h>

TEST(AccountTests, AccountTest1) {

	int type = 1;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 330000);
	float balance = Matvey.accounts[0].getBalance();
	EXPECT_EQ(balance ,330000);
}

TEST(AccountTests, AccountTest2) {
	int type = 2;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 330000, 12.4);
	float balance = Matvey.accounts[0].getBalance();
	EXPECT_EQ(balance, 330000);
}

TEST(AccountTests, AccountTest3) {
   
}

TEST(AccountTests, AccountTest4) {
   
}

TEST(AccountTests, AccountTest5) {
  
}

TEST(AccountTests, AccountTest6) {
   
}

TEST(AccountTests, AccountTest7) {
   
}
