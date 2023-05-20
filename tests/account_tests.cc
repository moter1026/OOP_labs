#include <gtest/gtest.h>
#include <account/user.h>
#include <iostream>
#include <math.h>

using namespace std;

TEST(AccountTests, AccountTest1) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется создание рассчётного счёта" << endl;

		user_bank::User Matvey("Пихуров Матвей\0");
		string type = "Calculated";
		Matvey.create_account(type, 33000, 0);
		//Matvey.create_new_account(new user_bank::Account(type, 33000));
		float balance = Matvey[0].getBalance();
		EXPECT_EQ(balance, 33000);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	
}
TEST(AccountTests, AccountTest2) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется создание кредитного счёта" << endl;

		//user_bank::TypeScore type = user_bank::TypeScore::credit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
		user_bank::User Matvey("Pikhurov Matvey\0");
		string type = "Credit";
		Matvey.create_account(type, 330000, 12.4);
		float balance = Matvey[0].getBalance();
		EXPECT_EQ(balance, 330000);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	
}
TEST(AccountTests, AccountTest3) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется создание депозитного счёта" << endl;

		//user_bank::TypeScore type = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
		user_bank::User Matvey("Pikhurov Matvey\0");
		string type = "Deposit";
		Matvey.create_account(type, 100000, 8.7);
		float balance = Matvey[0].getBalance();
		EXPECT_EQ(balance, 100000);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	
}
TEST(AccountTests, CreateElemInIndex1) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется создание депозитного счёта по индексу" << endl;
		user_bank::User Matvey("Pikhurov Matvey\0");

		// Создаю какое-то число счетов, чтобы проверить создание по индексу
		//user_bank::TypeScore type_credit = user_bank::TypeScore::credit;
		string type_credit = "Credit";
		Matvey.create_account(type_credit, 150000, 10);

		//user_bank::TypeScore type_deposit = user_bank::TypeScore::deposit;	// 1 - рассчётный счёт; 2 - депозитный; 3 - кредитный
		string type_deposit = "Deposit";
		Matvey.create_account(type_deposit, 100000, 8.7);

		//user_bank::TypeScore type_calculated = user_bank::TypeScore::calculated;
		string type_calculated = "Calculated";
		Matvey.create_account(type_calculated, 30000, 0);

		Matvey.create_account(type_credit, 150000, 4);
		//________________________________________________
		if (Matvey[0].getType() == "Calculated")
			cout << "\nна данный момент по 0 индесу лежит (рассчётный) счёт" << endl;
		else if (Matvey[0].getType() == "Deposit")
			cout << "\nна данный момент по 0 индесу лежит (депозитный) счёт" << endl;
		else if (Matvey[0].getType() == "Credit")
			cout << "\nна данный момент по 0 индесу лежит (кредитный) счёт" << endl;
		else
			cout << "\nна данный момент по 0 индесу ничего нет" << endl;

		Matvey.create_new_account_in_index(0, type_deposit, 333333, 12.3);
		cout << "\n\n" << endl;

		if (Matvey[0].getType() == "Calculated")
			cout << "\nпосле создания по индексу 0 там лежит (рассчётный) счёт" << endl;
		else if (Matvey[0].getType() == "Deposit")
			cout << "\nпосле создания по индексу 0 там лежит (депозитный) счёт" << endl;
		else if (Matvey[0].getType() == "Credit")
			cout << "\nпосле создания по индексу 0 там лежит (кредитный) счёт" << endl;
		else
			cout << "\nна данный момент по 0 индесу ничего нет" << endl;

		EXPECT_EQ(Matvey[0].getType(), type_deposit);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	
}
TEST(AccountTests, CreateElemInIndex2) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется создание кредитного счёта по индексу" << endl;
		user_bank::User Matvey("Pikhurov Matvey\0");

		// Создаю какое-то число счетов, чтобы проверить создание по индексу
		string type_deposit = "Deposit";	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
		Matvey.create_account(type_deposit, 100000, 8.7);

		string type_calculated = "Calculated";
		Matvey.create_account(type_calculated, 30000, 0);

		string type_credit = "Credit";
		Matvey.create_account(type_credit, 150000, 4);
		//________________________________________________
		if (Matvey[1].getType() == "Calculated")
			cout << "\nна данный момент по 1 индесу лежит (рассчётный) счёт" << endl;
		else if (Matvey[1].getType() == "Deposit")
			cout << "\nна данный момент по 1 индесу лежит (депозитный) счёт" << endl;
		else if (Matvey[1].getType() == "Credit")
			cout << "\nна данный момент по 1 индесу лежит (кредитный) счёт" << endl;
		else
			cout << "\nна данный момент по 1 индесу ничего нет" << endl;

		Matvey.create_new_account_in_index(1, type_credit, -333333, 10.6);
		cout << "\n\n" << endl;

		if (Matvey[1].getType() == "Calculated")
			cout << "\nпосле создания по индексу 1 там лежит (рассчётный) счёт" << endl;
		else if (Matvey[1].getType() == "Deposit")
			cout << "\nпосле создания по индексу 1 там лежит (депозитный) счёт" << endl;
		else if (Matvey[1].getType() == "Credit")
			cout << "\nпосле создания по индексу 1 там лежит (кредитный) счёт" << endl;
		else
			cout << "\nна данный момент по 1 индесу ничего нет" << endl;

		EXPECT_EQ(Matvey[1].getType(), type_credit);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	
}
TEST(AccountTests, CreateElemInIndex3) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется создание рассчётного счёта по индексу" << endl;
		user_bank::User Matvey("Pikhurov Matvey\0");

		// Создаю какое-то число счетов, чтобы проверить создание по индексу
		string type_deposit = "Deposit";	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
		Matvey.create_account(type_deposit, 100000, 8.7);

		string type_calculated = "Calculated";
		Matvey.create_account(type_calculated, 30000, 0);

		string type_credit = "Credit";
		Matvey.create_account(type_credit, 150000, 4);
		//________________________________________________
		if (Matvey[2].getType() == "Calculated")
			cout << "\nна данный момент по 2 индесу лежит (рассчётный) счёт" << endl;
		else if (Matvey[2].getType() == "Deposit")
			cout << "\nна данный момент по 2 индесу лежит (депозитный) счёт" << endl;
		else if (Matvey[2].getType() == "Credit")
			cout << "\nна данный момент по 2 индесу лежит (кредитный) счёт" << endl;
		else
			cout << "\nна данный момент по 2 индесу ничего нет" << endl;

		Matvey.create_new_account_in_index(2, type_calculated, 333333, 0);
		cout << "\n\n" << endl;

		if (Matvey[2].getType() == "Calculated")
			cout << "\nпосле создания по индексу 2 там лежит (рассчётный) счёт" << endl;
		else if (Matvey[2].getType() == "Deposit")
			cout << "\nпосле создания по индексу 2 там лежит (депозитный) счёт" << endl;
		else if (Matvey[2].getType() == "Credit")
			cout << "\nпосле создания по индексу 2 там лежит (кредитный) счёт" << endl;
		else
			cout << "\nна данный момент по 2 индесу ничего нет" << endl;

		EXPECT_EQ(Matvey[2].getType(), type_calculated);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	
}
TEST(AccountTests, CreateElemInBigIndex1) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется создание аккаунта в свободной части массива счетов(необходимо, чтобы элементы были расположены по порядку)" << endl;

		user_bank::User Matvey("Pikhurov Matvey");
		string type_of_new_account = "Credit";

		Matvey.create_account("Deposit", 22222, 12.7);
		Matvey.create_account("Credit", 33333, 7.7);
		Matvey.create_account("Calculated", 44444, 0);

		//EXPECT_EQ(Matvey[Matvey.get_count_accounts()].getType(), user_bank::TypeScore::none);

		Matvey.create_new_account_in_index(Matvey.get_count_accounts() + 3, type_of_new_account, -111111, 1.6);

		EXPECT_EQ(Matvey[Matvey.get_count_accounts() - 1].getType(), type_of_new_account);

		Matvey.create_new_account_in_index(Matvey.get_count_accounts() - 3, type_of_new_account, -111111, 2.6);

		EXPECT_EQ(Matvey[Matvey.get_count_accounts() - 4].getType(), type_of_new_account);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	

}
TEST(AccountTests, OverwWrite) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется перезапись элемента" << endl;

		user_bank::User Matvey("Пихуров Матвей");
		Matvey.create_account("Calculated", 11111, 0);
		Matvey.create_account("Deposit", 22222, 1.1);
		Matvey.create_account("Credit", 33333, 2.2);
		Matvey.create_account("Deposit", 44444, 7.5);
		Matvey.create_account("Calculated", 55555, 0);
		Matvey.create_account("Credit", 66666, 5.5);

		EXPECT_EQ(Matvey[3].getType(), "Deposit");
		EXPECT_EQ(Matvey[3].getBalance(), 44444);
		EXPECT_EQ(Matvey[3].getPercent(), 7.5);

		Matvey.overwrite(3, "Calculated", 99999, 0);

		EXPECT_EQ(Matvey[3].getType(), "Calculated");
		EXPECT_EQ(Matvey[3].getBalance(), 99999);
		EXPECT_EQ(Matvey[3].getPercent(), 0);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	
}
TEST(AccountTests, Perepoln1) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется переполнение массива элементов" << endl;

		user_bank::User Matvey("Пихуров Матвей");
		Matvey.create_account("Calculated", 11111, 0);
		Matvey.create_account("Deposit", 22222, 1.1);
		Matvey.create_account("Credit", 33333, 2.2);
		Matvey.create_account("Deposit", 44444, 7.5);
		Matvey.create_account("Calculated", 55555, 0);
		Matvey.create_account("Credit", 66666, 5.5);
		Matvey.create_account("Calculated", 11111, 0);
		Matvey.create_account("Deposit", 22222, 1.1);
		Matvey.create_account("Credit", 33333, 2.2);
		Matvey.create_account("Deposit", 44444, 7.5);
		Matvey.create_account("Calculated", 55555, 0);
		Matvey.create_account("Credit", 66666, 5.5);
		Matvey.create_account("Calculated", 11111, 0);
		Matvey.create_account("Deposit", 22222, 1.1);
		Matvey.create_account("Credit", 33333, 2.2);
		Matvey.create_account("Deposit", 44444, 7.5);
		Matvey.create_account("Calculated", 11111, 0);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}
TEST(AccountTests, Perepoln2) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется переполнение массива элементов" << endl;

		user_bank::User Matvey("Пихуров Матвей");
		Matvey.create_account("Calculated", 11111, 0);
		Matvey.create_account("Deposit", 22222, 1.1);
		Matvey.create_account("Credit", 33333, 2.2);
		Matvey.create_account("Deposit", 44444, 7.5);
		Matvey.create_account("Calculated", 55555, 0);
		Matvey.create_account("Credit", 66666, 5.5);
		Matvey.create_account("Calculated", 11111, 0);
		Matvey.create_account("Deposit", 22222, 1.1);
		Matvey.create_account("Credit", 33333, 2.2);
		Matvey.create_account("Deposit", 44444, 7.5);
		Matvey.create_account("Calculated", 55555, 0);
		Matvey.create_account("Credit", 66666, 5.5);
		Matvey.create_account("Calculated", 11111, 0);
		Matvey.create_account("Deposit", 22222, 1.1);
		Matvey.create_account("Credit", 33333, 2.2);
		Matvey.create_account("Deposit", 44444, 7.5);


		Matvey.create_new_account_in_index(5, "Calculated", 11111, 0);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}
TEST(AccountTests, FindMaxBalanceTest) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется нахождение счёта с максимальным балансом" << endl;

		string type_deposit = "Deposit";	// 1 - рассчётный счёт; 2 - депозитарный; 3 - кредитный
		user_bank::User Matvey("Pikhurov Matvey\0");
		Matvey.create_account(type_deposit, 100000, 8.7);

		string type_calculated = "Calculated";
		Matvey.create_account(type_calculated, 30000, 0);

		string type_credit = "Credit";
		Matvey.create_account(type_credit, 150000, 4);

		int index_of_max_balance_in_accounts = Matvey.find_max_balance();

		EXPECT_EQ(index_of_max_balance_in_accounts, 2);

		Matvey[0].setBalance(444444);

		index_of_max_balance_in_accounts = Matvey.find_max_balance();

		EXPECT_EQ(index_of_max_balance_in_accounts, 0);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	

}
TEST(AccountTests, AccrualTest1) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется начисление процентов на рассчётный счёт" << endl;

		user_bank::User Matvey("Pikhurov Matvey");

		string type_of_account = "Calculated";
		Matvey.create_account(type_of_account, 100000, 0);

		float first_balance = Matvey[0].getBalance();
		//cout << first_balance << endl;

		Matvey[0].accrual();
		float second_balance = Matvey[0].getBalance();
		//cout << second_balance << endl;

		EXPECT_EQ(second_balance, first_balance);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}
TEST(AccountTests, AccrualTest2) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется начисление процентов на кредитный счёт" << endl;

		user_bank::User Matvey("Pikhurov Matvey");
		float percent = 7, balance = -100000;

		string type_of_account = "Credit";

		Matvey.create_account(type_of_account, balance, percent);
		user_bank::Account& Acc = Matvey[0];

		float first_balance = Acc.getBalance();
		//cout << first_balance << endl;

		Matvey[0].accrual();
		float second_balance = Acc.getBalance();
		//cout << second_balance << endl;
		if (balance < 0)
		{
			EXPECT_EQ(first_balance - fabs(first_balance) * (Acc.getPercent() / 100) / 12, second_balance);
		}
		else
		{
			EXPECT_EQ(first_balance, second_balance);
		}
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}
TEST(AccountTests, AccrualTest3) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется начисление процентов на депозитный счёт" << endl;

		user_bank::User Matvey("Pikhurov Matvey");
		float percent;

		string type_of_account = "Deposit";
		percent = 8;
		Matvey.create_account(type_of_account, 100000, percent);
		user_bank::Account &Acc = Matvey[0];
		float first_balance = Acc.getBalance();
		//cout << first_balance << endl;

		Matvey[0].accrual();
		float second_balance = Acc.getBalance();
		//cout << second_balance << endl;

		EXPECT_EQ((first_balance + first_balance * Acc.getPercent() / 100 / 12), second_balance);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}
TEST(AccountTests, DeleteScore1) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется удаление крайнего с правой стороны элемента" << endl;

		user_bank::User Matvey("Pikhurov Matvey");

		string type_of_account = "Calculated";
		Matvey.create_account(type_of_account, 100000, 0);

		type_of_account = "Credit";
		Matvey.create_account(type_of_account, 200000, 6.6);

		string before_delete = Matvey[1].getType();

		//user_bank::Account acc_del = Matvey.delete_account_with_index(0);
		user_bank::Account acc_del = Matvey.delete_account_with_index(1);

		bool check = false;
		for (int i = 0; i < Matvey.get_count_accounts(); i++)
		{
			if (Matvey[i].getType() == acc_del.getType()
				&& Matvey[i].getBalance() == acc_del.getBalance()
				&& Matvey[i].getPercent() == acc_del.getPercent())
			{
				check = true;
			}
		}

		//string after_delete = Matvey[1].getType();
		EXPECT_EQ(check, false);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
	
}
TEST(AccountTests, DeleteScore2) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВ тесте проверяется удаление не крайнего с правой стороны элемента" << endl;

		user_bank::User Matvey("Pikhurov Matvey");

		string type_of_account = "Calculated";
		Matvey.create_account(type_of_account, 100000, 0);

		type_of_account = "Credit";
		Matvey.create_account(type_of_account, 200000, 6.6);

		type_of_account = "Deposit";
		Matvey.create_account(type_of_account, 44000, 7.8);

		type_of_account = "Credit";
		Matvey.create_account(type_of_account, -999999, 1.3);

		type_of_account = "Calculated";
		Matvey.create_account(type_of_account, 888888, 0);

		type_of_account = "Credit";
		Matvey.create_account(type_of_account, 200000, 6.6);

		unsigned int before_delete = Matvey.get_count_accounts();

		user_bank::Account el_with_index_3_before = Matvey[3];

		Matvey.delete_account_with_index(3);
		unsigned int after_delete = Matvey.get_count_accounts();

		user_bank::Account el_with_index_3_after = Matvey[3];

		EXPECT_EQ(before_delete - 1, after_delete);
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}

TEST(AccountTests, COUT) {
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "\nВывод" << endl;

		user_bank::User Matvey("Pikhurov Matvey");

		string type_of_account = "Calculated";
		Matvey.create_account(type_of_account, 100000, 0);

		type_of_account = "Credit";
		Matvey.create_account(type_of_account, 200000, 6.6);

		Matvey[0] = Matvey[1];

		cout << Matvey[0] << endl;
		//system("pause");
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}
TEST(AccountTests, ConstructCopy) {
	try
	{
		setlocale(LC_ALL, "ru");
		user_bank::User Matvey("Pikhurov Matvey");

		string type_of_account = "Calculated";
		Matvey.create_account(type_of_account, 100000, 0);

		type_of_account = "Credit";
		Matvey.create_account(type_of_account, 200000, 6.6);

		user_bank::User Mot(Matvey);

		cout << Matvey << endl;
		cout << Mot << endl;
		//system("pause");
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}

