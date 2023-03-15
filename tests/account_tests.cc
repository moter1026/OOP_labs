#include <gtest/gtest.h>
#include <account/user.h>
#include <iostream>
#include <math.h>

using namespace std;

TEST(AccountTests, AccountTest1) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание рассчётного счёта" << endl;

	user_bank::TypeScore type = user_bank::TypeScore::calculated;
	user_bank::User Matvey("Пихуров Матвей\0");
	Matvey.create_new_account(type, 33000);
	float balance = Matvey[0].getBalance();
	EXPECT_EQ(balance ,33000);
}

TEST(AccountTests, AccountTest2) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание кредитного счёта" << endl;

	user_bank::TypeScore type = user_bank::TypeScore::credit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 330000, 12.4);
	float balance = Matvey[0].getBalance();
	EXPECT_EQ(balance, 330000);
}

TEST(AccountTests, AccountTest3) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание депозитарного счёта" << endl;

	user_bank::TypeScore type = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_new_account(type, 100000, 8.7);
	float balance = Matvey[0].getBalance();
	EXPECT_EQ(balance, 100000);
}
TEST(AccountTests, AccountTest4) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание рассчётного счёта по индексу" << endl;
	user_bank::User Matvey("Pikhurov Matvey\0");

	// Создаю какое-то число счетов, чтобы проверить создание по индексу
	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	Matvey.create_new_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_calculated, 30000);

	user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
	Matvey.create_new_account(type_credit, 150000, 4);
	//________________________________________________
	switch (Matvey[0].getType())
	{
	case user_bank::TypeScore::calculated:
			cout << "на данный момент по 0 индесу лежит рассчётный счёт" << endl;
			break;
	case user_bank::TypeScore::deposit:
		cout << "на данный момент по 0 индесу лежит депозитный счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "на данный момент по 0 индесу лежит кредитный счёт" << endl;
		break;
	default:
		break;
	}
	Matvey.create_new_account_in_index(0, type_calculated, 333333);
	cout << "\n\n\n" << endl;

	switch (Matvey[0].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "после создания по индексу 0 там лежит (рассчётный) счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "после создания по индексу 0 там лежит (депозитный) счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "после создания по индексу 0 там лежит (кредитный) счёт" << endl;
		break;
	default:
		break;
	}

	EXPECT_EQ(Matvey[0].getType(), type_calculated);
}

TEST(AccountTests, AccountTest5) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание рассчётного счёта по индексу" << endl;
	user_bank::User Matvey("Pikhurov Matvey\0");

	// Создаю какое-то число счетов, чтобы проверить создание по индексу
	user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
	Matvey.create_new_account(type_credit, 150000, 10);

	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	Matvey.create_new_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_calculated, 30000);

	Matvey.create_new_account(type_credit, 150000, 4);
	//________________________________________________
	switch (Matvey[0].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "на данный момент по 0 индесу лежит рассчётный счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "на данный момент по 0 индесу лежит депозитный счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "на данный момент по 0 индесу лежит кредитный счёт" << endl;
		break;
	default:
		break;
	}
	Matvey.create_new_account_in_index(0, type_deposit, 333333, 12.3);
	cout << "\n\n\n" << endl;

	switch (Matvey[0].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "после создания по индексу 0 там лежит (рассчётный) счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "после создания по индексу 0 там лежит (депозитный) счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "после создания по индексу 0 там лежит (кредитный) счёт" << endl;
		break;
	default:
		break;
	}

	EXPECT_EQ(Matvey[0].getType(), type_deposit);
}

TEST(AccountTests, AccountTest6) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание рассчётного счёта по индексу" << endl;
	user_bank::User Matvey("Pikhurov Matvey\0");

	// Создаю какое-то число счетов, чтобы проверить создание по индексу
	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	Matvey.create_new_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_calculated, 30000);

	user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
	Matvey.create_new_account(type_credit, 150000, 4);
	//________________________________________________
	switch (Matvey[0].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "на данный момент по 0 индесу лежит рассчётный счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "на данный момент по 0 индесу лежит депозитный счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "на данный момент по 0 индесу лежит кредитный счёт" << endl;
		break;
	default:
		break;
	}
	Matvey.create_new_account_in_index(0, type_credit, -333333, 10.6);
	cout << "\n\n\n" << endl;

	switch (Matvey[0].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "после создания по индексу 0 там лежит (рассчётный) счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "после создания по индексу 0 там лежит (депозитный) счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "после создания по индексу 0 там лежит (кредитный) счёт" << endl;
		break;
	default:
		break;
	}

	EXPECT_EQ(Matvey[0].getType(), type_credit);
}

TEST(AccountTests, FindMaxBalanceTest) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется нахождение счёта с максимальным балансом" << endl;

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

TEST(AccountTests, AccrualTest1) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется начисление процентов на рассчётный счёт" << endl;

	user_bank::User Matvey("Pikhurov Matvey");

	user_bank::TypeScore type_of_account = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_of_account, 100000);

	float first_balance = Matvey[0].getBalance();
	//cout << first_balance << endl;

	Matvey[0].accrual();
	float second_balance = Matvey[0].getBalance();
	//cout << second_balance << endl;

	EXPECT_EQ(second_balance, first_balance);
}
TEST(AccountTests, AccrualTest2) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется начисление процентов на кредитный счёт" << endl;

	user_bank::User Matvey("Pikhurov Matvey");
	float percent;

	user_bank::TypeScore type_of_account = user_bank::TypeScore::credit;
	percent = 7;
	Matvey.create_new_account(type_of_account, -100000, percent);

	float first_balance = Matvey[0].getBalance();
	//cout << first_balance << endl;

	Matvey[0].accrual();
	float second_balance = Matvey[0].getBalance();
	//cout << second_balance << endl;

	EXPECT_EQ(ceil(fabs(((first_balance - second_balance) / (first_balance))) * 10) / 10, ceil(percent / 12 * 10) / 10);
}
TEST(AccountTests, AccrualTest3) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется начисление процентов на депозитарный счёт" << endl;

	user_bank::User Matvey("Pikhurov Matvey");
	float percent;

	user_bank::TypeScore type_of_account = user_bank::TypeScore::deposit;
	percent = 8;
	Matvey.create_new_account(type_of_account, 100000, percent);

	float first_balance = Matvey[0].getBalance();
	//cout << first_balance << endl;

	Matvey[0].accrual();
	float second_balance = Matvey[0].getBalance();
	//cout << second_balance << endl;

	EXPECT_EQ(ceil((second_balance - first_balance) / first_balance * 10) / 10, ceil(percent / 12 * 10) / 10);

}
TEST(AccountTests, DeleteScore1) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется удаление крайнего с правой стороны элемента" << endl;

	user_bank::User Matvey("Pikhurov Matvey");

	user_bank::TypeScore type_of_account = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_of_account, 100000);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_new_account(type_of_account, 200000, 6.6);

	user_bank::TypeScore before_delete = Matvey[1].getType();

	Matvey.delete_account_with_index(1);

	user_bank::TypeScore after_delete = Matvey[1].getType();


	EXPECT_EQ(after_delete, user_bank::TypeScore::none);

}
TEST(AccountTests, DeleteScore2) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется удаление не крайнего с правой стороны элемента" << endl;

	user_bank::User Matvey("Pikhurov Matvey");

	user_bank::TypeScore type_of_account = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_of_account, 100000);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_new_account(type_of_account, 200000, 6.6);

	type_of_account = user_bank::TypeScore::deposit;
	Matvey.create_new_account(type_of_account, 44000, 7.8);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_new_account(type_of_account, -999999, 1.3);

	type_of_account = user_bank::TypeScore::calculated;
	Matvey.create_new_account(type_of_account, 888888);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_new_account(type_of_account, 200000, 6.6);

	unsigned int before_delete = Matvey.get_count_accounts();

	user_bank::Account el_with_index_3_before = Matvey[3];

	Matvey.delete_account_with_index(3);
	unsigned int after_delete = Matvey.get_count_accounts();

	user_bank::Account el_with_index_3_after = Matvey[3];

	EXPECT_EQ(before_delete - 1, after_delete);

}

