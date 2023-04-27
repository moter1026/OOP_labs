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
	Matvey.create_account(type, 33000);
	//Matvey.create_new_account(new user_bank::Account(type, 33000));
	float balance = Matvey[0].getBalance();
	EXPECT_EQ(balance ,33000);
}
TEST(AccountTests, AccountTest2) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание кредитного счёта" << endl;

	user_bank::TypeScore type = user_bank::TypeScore::credit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_account(type, 330000, 12.4);
	float balance = Matvey[0].getBalance();
	EXPECT_EQ(balance, 330000);
}
TEST(AccountTests, AccountTest3) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание депозитного счёта" << endl;

	user_bank::TypeScore type = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_account(type, 100000, 8.7);
	float balance = Matvey[0].getBalance();
	EXPECT_EQ(balance, 100000);
}
TEST(AccountTests, CreateElemInIndex1) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание депозитного счёта по индексу" << endl;
	user_bank::User Matvey("Pikhurov Matvey\0");

	// Создаю какое-то число счетов, чтобы проверить создание по индексу
	user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
	Matvey.create_account(type_credit, 150000, 10);

	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	Matvey.create_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_account(type_calculated, 30000);

	Matvey.create_account(type_credit, 150000, 4);
	//________________________________________________
	switch (Matvey[0].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "\nна данный момент по 0 индесу лежит рассчётный счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "\nна данный момент по 0 индесу лежит депозитный счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "\nна данный момент по 0 индесу лежит кредитный счёт" << endl;
		break;
	default:
		break;
	}

	Matvey.create_new_account_in_index(0, type_deposit, 333333, 12.3);
	cout << "\n\n" << endl;

	switch (Matvey[0].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "\nпосле создания по индексу 0 там лежит (рассчётный) счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "\nпосле создания по индексу 0 там лежит (депозитный) счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "\nпосле создания по индексу 0 там лежит (кредитный) счёт" << endl;
		break;
	default:
		break;
	}

	EXPECT_EQ(Matvey[0].getType(), type_deposit);
}
TEST(AccountTests, CreateElemInIndex2) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание кредитного счёта по индексу" << endl;
	user_bank::User Matvey("Pikhurov Matvey\0");

	// Создаю какое-то число счетов, чтобы проверить создание по индексу
	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	Matvey.create_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_account(type_calculated, 30000);

	user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
	Matvey.create_account(type_credit, 150000, 4);
	//________________________________________________
	switch (Matvey[1].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "\nна данный момент по 1 индесу лежит рассчётный счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "\nна данный момент по 1 индесу лежит депозитный счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "\nна данный момент по 1 индесу лежит кредитный счёт" << endl;
		break;
	default:
		break;
	}
	Matvey.create_new_account_in_index(1, type_credit, -333333, 10.6);
	cout << "\n\n" << endl;

	switch (Matvey[1].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "\nпосле создания по индексу 1 там лежит (рассчётный) счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "\nпосле создания по индексу 1 там лежит (депозитный) счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "\nпосле создания по индексу 1 там лежит (кредитный) счёт" << endl;
		break;
	default:
		break;
	}

	EXPECT_EQ(Matvey[1].getType(), type_credit);
}
TEST(AccountTests, CreateElemInIndex3) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание рассчётного счёта по индексу" << endl;
	user_bank::User Matvey("Pikhurov Matvey\0");

	// Создаю какое-то число счетов, чтобы проверить создание по индексу
	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	Matvey.create_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_account(type_calculated, 30000);

	user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
	Matvey.create_account(type_credit, 150000, 4);
	//________________________________________________
	switch (Matvey[2].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "\nна данный момент по 2 индесу лежит рассчётный счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "\nна данный момент по 2 индесу лежит депозитный счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "\nна данный момент по 2 индесу лежит кредитный счёт" << endl;
		break;
	default:
		break;
	}
	Matvey.create_new_account_in_index(2, type_calculated, 333333);
	cout << "\n\n" << endl;

	switch (Matvey[2].getType())
	{
	case user_bank::TypeScore::calculated:
		cout << "\nпосле создания по индексу 2 там лежит (рассчётный) счёт" << endl;
		break;
	case user_bank::TypeScore::deposit:
		cout << "\nпосле создания по индексу 2 там лежит (депозитный) счёт" << endl;
		break;
	case user_bank::TypeScore::credit:
		cout << "\nпосле создания по индексу 2 там лежит (кредитный) счёт" << endl;
		break;
	default:
		break;
	}

	EXPECT_EQ(Matvey[2].getType(), type_calculated);
}
TEST(AccountTests, CreateElemInBigIndex1) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется создание аккаунта в свободной части массива счетов(необходимо, чтобы элементы были расположены по порядку)" << endl;

	user_bank::User Matvey("Pikhurov Matvey");
	user_bank::TypeScore type_of_new_account = user_bank::TypeScore::credit;

	Matvey.create_account(user_bank::TypeScore::deposit, 22222, 12.7);
	Matvey.create_account(user_bank::TypeScore::credit, 33333, 7.7);
	Matvey.create_account(user_bank::TypeScore::calculated, 44444);

	EXPECT_EQ(Matvey[Matvey.get_count_accounts()].getType(), user_bank::TypeScore::none);

	Matvey.create_new_account_in_index(Matvey.get_count_accounts() + 3, type_of_new_account, -111111, 1.6);

	EXPECT_EQ(Matvey[Matvey.get_count_accounts() - 1].getType(), type_of_new_account);

	Matvey.create_new_account_in_index(Matvey.get_count_accounts() - 3, type_of_new_account, -111111, 2.6);

	EXPECT_EQ(Matvey[Matvey.get_count_accounts() - 4].getType(), type_of_new_account);

}
TEST(AccountTests, OverwWrite) {
	setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется перезапись элемента" << endl;

		user_bank::User Matvey("Пихуров Матвей");
		Matvey.create_account(user_bank::TypeScore::calculated, 11111);
		Matvey.create_account(user_bank::TypeScore::deposit, 22222, 1.1);
		Matvey.create_account(user_bank::TypeScore::credit, 33333, 2.2);
		Matvey.create_account(user_bank::TypeScore::deposit, 44444, 7.5);
		Matvey.create_account(user_bank::TypeScore::calculated, 55555);
		Matvey.create_account(user_bank::TypeScore::credit, 66666, 5.5);

		EXPECT_EQ(Matvey[3].getType(), user_bank::TypeScore::deposit);
		EXPECT_EQ(Matvey[3].getBalance(), 44444);
		EXPECT_EQ(Matvey[3].getPercent(), 7.5);

		Matvey[3].overwrite(user_bank::TypeScore::calculated, 99999);

		EXPECT_EQ(Matvey[3].getType(), user_bank::TypeScore::calculated);
		EXPECT_EQ(Matvey[3].getBalance(), 99999);
		EXPECT_EQ(Matvey[3].getPercent(), 0);
}
TEST(AccountTests, Perepoln1) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется переполнение массива элементов" << endl;

	user_bank::User Matvey("Пихуров Матвей");
	Matvey.create_account(user_bank::TypeScore::calculated, 11111);
	Matvey.create_account(user_bank::TypeScore::deposit, 22222, 1.1);
	Matvey.create_account(user_bank::TypeScore::credit, 33333, 2.2);
	Matvey.create_account(user_bank::TypeScore::deposit, 44444, 7.5);
	Matvey.create_account(user_bank::TypeScore::calculated, 55555);
	Matvey.create_account(user_bank::TypeScore::credit, 66666, 5.5);
	Matvey.create_account(user_bank::TypeScore::calculated, 11111);
	Matvey.create_account(user_bank::TypeScore::deposit, 22222, 1.1);
	Matvey.create_account(user_bank::TypeScore::credit, 33333, 2.2);
	Matvey.create_account(user_bank::TypeScore::deposit, 44444, 7.5);
	Matvey.create_account(user_bank::TypeScore::calculated, 55555);
	Matvey.create_account(user_bank::TypeScore::credit, 66666, 5.5);
	Matvey.create_account(user_bank::TypeScore::calculated, 11111);
	Matvey.create_account(user_bank::TypeScore::deposit, 22222, 1.1);
	Matvey.create_account(user_bank::TypeScore::credit, 33333, 2.2);
	Matvey.create_account(user_bank::TypeScore::deposit, 44444, 7.5);


	Matvey.create_account(user_bank::TypeScore::calculated, 11111);


}
TEST(AccountTests, Perepoln2) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется переполнение массива элементов" << endl;

	user_bank::User Matvey("Пихуров Матвей");
	Matvey.create_account(user_bank::TypeScore::calculated, 11111);
	Matvey.create_account(user_bank::TypeScore::deposit, 22222, 1.1);
	Matvey.create_account(user_bank::TypeScore::credit, 33333, 2.2);
	Matvey.create_account(user_bank::TypeScore::deposit, 44444, 7.5);
	Matvey.create_account(user_bank::TypeScore::calculated, 55555);
	Matvey.create_account(user_bank::TypeScore::credit, 66666, 5.5);
	Matvey.create_account(user_bank::TypeScore::calculated, 11111);
	Matvey.create_account(user_bank::TypeScore::deposit, 22222, 1.1);
	Matvey.create_account(user_bank::TypeScore::credit, 33333, 2.2);
	Matvey.create_account(user_bank::TypeScore::deposit, 44444, 7.5);
	Matvey.create_account(user_bank::TypeScore::calculated, 55555);
	Matvey.create_account(user_bank::TypeScore::credit, 66666, 5.5);
	Matvey.create_account(user_bank::TypeScore::calculated, 11111);
	Matvey.create_account(user_bank::TypeScore::deposit, 22222, 1.1);
	Matvey.create_account(user_bank::TypeScore::credit, 33333, 2.2);
	Matvey.create_account(user_bank::TypeScore::deposit, 44444, 7.5);


	Matvey.create_new_account_in_index( 5,user_bank::TypeScore::calculated, 11111);


}
TEST(AccountTests, FindMaxBalanceTest) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется нахождение счёта с максимальным балансом" << endl;

	user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
	user_bank::User Matvey("Pikhurov Matvey\0");
	Matvey.create_account(type_deposit, 100000, 8.7);

	user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
	Matvey.create_account(type_calculated, 30000);

	user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
	Matvey.create_account(type_credit, 150000, 4);

	int index_of_max_balance_in_accounts = Matvey.find_max_balance();
	
	EXPECT_EQ(index_of_max_balance_in_accounts, 2);

	Matvey[0].setBalance(444444);

	index_of_max_balance_in_accounts = Matvey.find_max_balance();

	EXPECT_EQ(index_of_max_balance_in_accounts, 0);

}
TEST(AccountTests, AccrualTest1) {
	setlocale(LC_ALL, "ru");
	cout << "\nВ тесте проверяется начисление процентов на рассчётный счёт" << endl;

	user_bank::User Matvey("Pikhurov Matvey");

	user_bank::TypeScore type_of_account = user_bank::TypeScore::calculated;
	Matvey.create_account(type_of_account, 100000);

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
	Matvey.create_account(type_of_account, -100000, percent);

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
	Matvey.create_account(type_of_account, 100000, percent);

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
	Matvey.create_account(type_of_account, 100000);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_account(type_of_account, 200000, 6.6);

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
	Matvey.create_account(type_of_account, 100000);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_account(type_of_account, 200000, 6.6);

	type_of_account = user_bank::TypeScore::deposit;
	Matvey.create_account(type_of_account, 44000, 7.8);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_account(type_of_account, -999999, 1.3);

	type_of_account = user_bank::TypeScore::calculated;
	Matvey.create_account(type_of_account, 888888);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_account(type_of_account, 200000, 6.6);

	unsigned int before_delete = Matvey.get_count_accounts();

	user_bank::Account el_with_index_3_before = Matvey[3];

	Matvey.delete_account_with_index(3);
	unsigned int after_delete = Matvey.get_count_accounts();

	user_bank::Account el_with_index_3_after = Matvey[3];

	EXPECT_EQ(before_delete - 1, after_delete);
}

TEST(AccountTests, COUT) {
	setlocale(LC_ALL, "ru");
	cout << "\nВывод" << endl;

	user_bank::User Matvey("Pikhurov Matvey");

	user_bank::TypeScore type_of_account = user_bank::TypeScore::calculated;
	Matvey.create_account(type_of_account, 100000);

	type_of_account = user_bank::TypeScore::credit;
	Matvey.create_account(type_of_account, 200000, 6.6);

	Matvey[0] = Matvey[1];

	cout << Matvey[0] << endl;
	system("pause");

}

