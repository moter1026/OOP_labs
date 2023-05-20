
#include <iostream>
#include <string.h>
#include <limits>
#include <windows.h>
#include "account/user.h"
#include "account/account.h"

using namespace std;

void Create_account(user_bank::User& user) {
	std::cout << "\n Введите латинскими буквами какой счёт вы хотите открыть(Calculated, credit, deposit)" << endl;
	float balance, percent;
	string type_of_score;
	std::cin >> type_of_score;
	if (_stricmp("calculated", type_of_score.c_str()) == 0) {
		std::cout << "Введите баланс расчётного счёта" << endl;
		std::cin >> balance;
		user_bank::Account new_account = user.create_account(type_of_score, balance, 0);
		std::cout << "Вы успешно создали расчётный счёт!" << endl;
		std::cout << "Он выглядит так: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else if (_stricmp("deposit", type_of_score.c_str()) == 0) {
		std::cout << "Введите баланс депозитного счёта" << endl;
		std::cin >> balance;
		std::cout << "\nВведите проценты депозитного счёта" << endl;
		std::cin >> percent;
		user_bank::Account new_account = user.create_account(type_of_score, balance, percent);
		std::cout << "Вы успешно создали депозитный счёт!" << endl;
		std::cout << "Он выглядит так: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else if (_stricmp("credit", type_of_score.c_str()) == 0) {
		std::cout << "Введите баланс кредитного счёта" << endl;
		std::cin >> balance;
		std::cout << "\nВведите проценты кредитного счёта" << endl;
		std::cin >> percent;
		user_bank::Account new_account = user.create_account(type_of_score, balance, percent);
		std::cout << "Вы успешно создали кредитный счёт!" << endl;
		std::cout << "Он выглядит так: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else
	{
		std::cout << "Вы ввели неизвестный тип аккаунта, поэтому мы не создали никакого аккаунта" << endl;
		return;
	}
}
void Create_account(user_bank::User& user, int index) {
	std::cout << "\n Введите маленькими латинскими буквами какой счёт вы хотите открыть" << endl;
	float balance, percent;
	string type_of_score;
	std::cin >> type_of_score;
	if (_stricmp("calculated", type_of_score.c_str()) == 0) {
		std::cout << "Введите баланс расчётного счёта" << endl;
		std::cin >> balance;
		user_bank::Account new_account = user.create_new_account_in_index(index, type_of_score, balance, 0);
		std::cout << "Вы успешно создали аккаунт с расчётным счётом!" << endl;
		std::cout << "Он выглядит так: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else if (_stricmp("deposit", type_of_score.c_str()) == 0) {
		std::cout << "Введите баланс депозитного счёта" << endl;
		std::cin >> balance;
		std::cout << "\nВведите проценты депозитного счёта" << endl;
		std::cin >> percent;
		user_bank::Account new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
		std::cout << "Вы успешно создали аккаунт с депозитным счётом!" << endl;
		std::cout << "Он выглядит так: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else if (_stricmp("credit", type_of_score.c_str()) == 0) {
		std::cout << "Введите баланс кредитного счёта" << endl;
		std::cin >> balance;
		std::cout << "\nВведите проценты кредитного счёта" << endl;
		std::cin >> percent;
		user_bank::Account new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
		std::cout << "Вы успешно создали аккаунт с кредитным счётом!" << endl;
		std::cout << "Он выглядит так: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else
	{
		std::cout << "Вы ввели неизвестный тип аккаунта, поэтому мы поэтому мы не создали никакого аккаунта" << endl;
		return;
	}
}
int main_menu(user_bank::User& user ) {
	try
	{
		int n;
		std::cout << "Введите:" << endl;
		std::cout << "*\t 1, чтобы вывести полностью все данные" << endl;
		std::cout << "*\t 2, чтобы создать новый счёт" << endl;
		std::cout << "*\t 3, чтобы создать новый счёт по индексу" << endl;
		std::cout << "*\t 4, чтобы удалить счёт по индексу" << endl;
		std::cout << "*\t 5, чтобы найти счёт с максимальным балансом" << endl;
		std::cout << "*\t 6, изменить счета по процентам" << endl;
		std::cout << "*\t 7, чтобы завершить работу программы" << endl;
		std::cin >> n;
		int index;
		switch (n)
		{
		case 1:
			std::cout << user << endl;
			break;
		case 2:
			Create_account(user);
			break;
		case 3:
			std::cout << "Введите индекс(не отрицательный), по которому хотите добавить новый элемент." << endl;
			std::cin >> index;
			Create_account(user, index);
			break;
		case 4:
			cout << "Введите индекс(не отрицательный) элемента, который хотите удалить." << endl;
			std::cin >> index;
			user.delete_account_with_index(index);
			break;
		case 5:
			std::cout << "Счёт с максимальным балансом: " << endl;
			std::cout << user[user.find_max_balance()] << endl;
			break;
		case 6:
			std::cout << "изменили счета по процентам" << endl;
			for (int i = 0; i < user.get_count_accounts(); i++)
			{
				user[i].accrual();
			}
			break;
		case 7:
			return 0;
			break;
		default:
			break;
		}
		return 1;
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
		return 1;
	}
}
using namespace std;
int main() {
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "ru");
		std::cout << "В данном консольном приложении вы можете попробовать вызвать различные методы из заголовочных файлов" << endl;
		std::cout << "user.h \tи\t account.h" << endl;

		string name;
		std::cout << "Для начала введите Фамилию пользователя, для когорого будут создаваться счета." << endl;
		std::cin >> name;
		user_bank::User	UserObj(name);

		while (main_menu(UserObj)) {}

		return 0;
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}