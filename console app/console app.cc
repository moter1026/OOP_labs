#include <iostream>
#include <string.h>
#include <limits>
#include <windows.h>
#include "account/user.h"
#include "account/account.h"

void Create_account(user_bank::User& user) {
	cout << "\n Введите маленькими латинскими буквами какой счёт вы хотите открыть" << endl;
	string type;
	float balance, percent;
	user_bank::TypeScore type_of_score;
	cin >> type;
	if (type == "calculated") {
		user_bank::Account new_account;
		type_of_score = user_bank::TypeScore::calculated;
		cout << "Введите баланс расчётного счёта" << endl;
		cin >> balance;
		new_account = user.create_account(type_of_score, balance, 0);
		cout << "Вы успешно создали аккаунт с расчётным счётом!" << endl;
		cout << "Он выглядит так: " << endl;
		cout << new_account << endl;
		return;
	}
	else if (type == "deposit") {
		user_bank::Account new_account;
		type_of_score = user_bank::TypeScore::deposit;
		cout << "Введите баланс депозитного счёта" << endl;
		cin >> balance;
		cout << "\nВведите проценты депозитного счёта" << endl;
		cin >> percent;
		new_account = user.create_account(type_of_score, balance, percent);
		cout << "Вы успешно создали аккаунт с депозитным счётом!" << endl;
		cout << "Он выглядит так: " << endl;
		cout << new_account << endl;
		return;
	}
	else if (type == "credit") {
		user_bank::Account new_account;
		type_of_score = user_bank::TypeScore::credit;
		cout << "Введите баланс депозитного счёта" << endl;
		cin >> balance;
		cout << "\nВведите проценты депозитного счёта" << endl;
		cin >> percent;
		new_account = user.create_account(type_of_score, balance, percent);
		cout << "Вы успешно создали аккаунт с депозитным счётом!" << endl;
		cout << "Он выглядит так: " << endl;
		cout << new_account << endl;
		return;
	}
	else
	{
		user_bank::Account new_account;
		type_of_score = user_bank::TypeScore::none;
		new_account = user.create_account(type_of_score, 0, 0);
		cout << "Вы ввели неизвестный тип аккаунта, поэтому мы создали аккаунт типа 'none' с нулевым балансом и процентами" << endl;
		cout << "Он выглядит так: " << endl;
		cout << new_account << endl;
		return;
	}
}
void Create_account(user_bank::User& user, int index) {
	cout << "\n Введите маленькими латинскими буквами какой счёт вы хотите открыть" << endl;
	string type;
	float balance, percent;
	user_bank::TypeScore type_of_score;
	cin >> type;
	if (type == "calculated") {
		user_bank::Account new_account;
		type_of_score = user_bank::TypeScore::calculated;
		cout << "Введите баланс расчётного счёта" << endl;
		cin >> balance;
		new_account = user.create_new_account_in_index(index, type_of_score, balance, 0);
		cout << "Вы успешно создали аккаунт с расчётным счётом!" << endl;
		cout << "Он выглядит так: " << endl;
		cout << new_account << endl;
		return;
	}
	else if (type == "deposit") {
		user_bank::Account new_account;
		type_of_score = user_bank::TypeScore::deposit;
		cout << "Введите баланс депозитного счёта" << endl;
		cin >> balance;
		cout << "\nВведите проценты депозитного счёта" << endl;
		cin >> percent;
		new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
		cout << "Вы успешно создали аккаунт с депозитным счётом!" << endl;
		cout << "Он выглядит так: " << endl;
		cout << new_account << endl;
		return;
	}
	else if (type == "credit") {
		user_bank::Account new_account;
		type_of_score = user_bank::TypeScore::credit;
		cout << "Введите баланс депозитного счёта" << endl;
		cin >> balance;
		cout << "\nВведите проценты депозитного счёта" << endl;
		cin >> percent;
		new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
		cout << "Вы успешно создали аккаунт с депозитным счётом!" << endl;
		cout << "Он выглядит так: " << endl;
		cout << new_account << endl;
		return;
	}
	else
	{
		user_bank::Account new_account;
		type_of_score = user_bank::TypeScore::none;
		new_account = user.create_new_account_in_index(index, type_of_score, 0, 0);
		cout << "Вы ввели неизвестный тип аккаунта, поэтому мы создали аккаунт типа 'none' с нулевым балансом и процентами" << endl;
		cout << "Он выглядит так: " << endl;
		cout << new_account << endl;
		return;
	}
}
int main_menu(user_bank::User& user) {
	int n;
	cout << "Введите:" << endl;
	cout << "*\t 1, чтобы вывести полностью все данные" << endl;
	cout << "*\t 2, чтобы создать новый счёт" << endl;
	cout << "*\t 3, чтобы создать новый счёт по индексу" << endl;
	cout << "*\t 4, чтобы удалить счёт по индексу" << endl;
	cout << "*\t 5, чтобы найти счёт с максимальным балансом" << endl;
	cout << "*\t 6, чтобы завершить работу программы" << endl;
	cin >> n;
	int index;
	switch (n)
	{
	case 1:
		cout << user << endl;
		break;
	case 2:
		Create_account(user);
		break;
	case 3:
		cout << "Введите индекс(не отрицательный), по которому хотите добавить новый элемент." << endl;
		cin >> index;
		Create_account(user, index);
		break;
	case 4:
		cout << "Введите индекс(не отрицательный) элемента, который хотите удалить." << endl;
		cin >> index;
		user.delete_account_with_index(index);
		break;
	case 5:
		cout << "Счёт с максимальным балансом: " << endl;
		try
		{
			cout << user[user.find_max_balance()] << endl;
		}
		catch (const std::runtime_error& e)
		{
			e.what();
		}
		break;
	case 6:
		return 0;
		break;
	default:
		break;
	}
	return 1;
}
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	cout << "В данном консольном приложении вы можете попробовать вызвать различные методы из заголовочных файлов" << endl;
	cout << "user.h \tи\t account.h" << endl;

	string name;
	cout << "Для начала введите Фамилию пользователя, для когорого будут создаваться счета." << endl;
	cin >> name;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	user_bank::User	UserObj(name);
	//cout << UserObj << endl;
	/*cout << "\n\n Чтобы создать новый аккант, введите тип аккаунта, затем баланс и проценты для тех счетов, которым это необходимо." << endl;
	cout << "Типы счетов: calculated, credit, deposit" << endl;
	int check_cin;
	while (true)
	{
		cout << "*\t Чтобы вызвать пояснение по кажлому счёту введите 1" << endl;
		cout << "*\t Чтобы вывести информацию о ваших счетах введите 2" << endl;
		cout << "*\t если хотите сразу ввести данные, то введите что - дибо другое" << endl;
		cin >> check_cin;
		if (check_cin == 1)
		{
			cout << "calculated - Расчётный счёт у которого нет процентов годовых. Деньги на таком просто хранятся" << endl;
			cout << "credit - Кредитный счёт. На таком счёте есть проценты годовых, если у вас есть долг, то с каждым месяцем долг будет увеличиваться на (баланс)*(проценты годовых)/12" << endl;
			cout << "deposit - Депозитный счёт. На таком счёте тоже есть проценты, только с каждым месецем ваш счёт растёт на (баланс)*(проценты годовых)/12" << endl;
			break;
		}else if (check_cin == 2)
		{
			cout << UserObj << endl;
			break;
		}
		else
			break;
	}*/
	while (main_menu(UserObj)){}
	/*while (true)
	{
		int c;
		cout << "Введите 0, чтобы завершить работу программы." << endl;
		cout << "Введите что-либо другое, чтобы создать новый аккаунт." << endl;
		cin >> c;
		if (!c)
		{
			return 0;
		}
		else {
			Create_account(UserObj);
		}
	}*/

	//system("pause");
	return 0;
}