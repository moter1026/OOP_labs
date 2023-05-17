//#include <iostream>
//#include <string.h>
//#include <limits>
//#include <windows.h>
//#include "account/user.h"
//#include "account/account.h"
//
//void Create_account(user_bank::User& user) {
//	cout << "\n ������� ���������� ���������� ������� ����� ���� �� ������ �������" << endl;
//	string type;
//	float balance, percent;
//	user_bank::TypeScore type_of_score;
//	cin >> type;
//	if (type == "calculated") {
//		user_bank::Account new_account;
//		type_of_score = user_bank::TypeScore::calculated;
//		cout << "������� ������ ���������� �����" << endl;
//		cin >> balance;
//		new_account = user.create_account(type_of_score, balance, 0);
//		cout << "�� ������� ������� ������� � ��������� ������!" << endl;
//		cout << "�� �������� ���: " << endl;
//		cout << new_account << endl;
//		return;
//	}
//	else if (type == "deposit") {
//		user_bank::Account new_account;
//		type_of_score = user_bank::TypeScore::deposit;
//		cout << "������� ������ ����������� �����" << endl;
//		cin >> balance;
//		cout << "\n������� �������� ����������� �����" << endl;
//		cin >> percent;
//		new_account = user.create_account(type_of_score, balance, percent);
//		cout << "�� ������� ������� ������� � ���������� ������!" << endl;
//		cout << "�� �������� ���: " << endl;
//		cout << new_account << endl;
//		return;
//	}
//	else if (type == "credit") {
//		user_bank::Account new_account;
//		type_of_score = user_bank::TypeScore::credit;
//		cout << "������� ������ ����������� �����" << endl;
//		cin >> balance;
//		cout << "\n������� �������� ����������� �����" << endl;
//		cin >> percent;
//		new_account = user.create_account(type_of_score, balance, percent);
//		cout << "�� ������� ������� ������� � ���������� ������!" << endl;
//		cout << "�� �������� ���: " << endl;
//		cout << new_account << endl;
//		return;
//	}
//	else
//	{
//		user_bank::Account new_account;
//		type_of_score = user_bank::TypeScore::none;
//		new_account = user.create_account(type_of_score, 0, 0);
//		cout << "�� ����� ����������� ��� ��������, ������� �� ������� ������� ���� 'none' � ������� �������� � ����������" << endl;
//		cout << "�� �������� ���: " << endl;
//		cout << new_account << endl;
//		return;
//	}
//}
//void Create_account(user_bank::User& user, int index) {
//	cout << "\n ������� ���������� ���������� ������� ����� ���� �� ������ �������" << endl;
//	string type;
//	float balance, percent;
//	user_bank::TypeScore type_of_score;
//	cin >> type;
//	if (type == "calculated") {
//		user_bank::Account new_account;
//		type_of_score = user_bank::TypeScore::calculated;
//		cout << "������� ������ ���������� �����" << endl;
//		cin >> balance;
//		new_account = user.create_new_account_in_index(index, type_of_score, balance, 0);
//		cout << "�� ������� ������� ������� � ��������� ������!" << endl;
//		cout << "�� �������� ���: " << endl;
//		cout << new_account << endl;
//		return;
//	}
//	else if (type == "deposit") {
//		user_bank::Account new_account;
//		type_of_score = user_bank::TypeScore::deposit;
//		cout << "������� ������ ����������� �����" << endl;
//		cin >> balance;
//		cout << "\n������� �������� ����������� �����" << endl;
//		cin >> percent;
//		new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
//		cout << "�� ������� ������� ������� � ���������� ������!" << endl;
//		cout << "�� �������� ���: " << endl;
//		cout << new_account << endl;
//		return;
//	}
//	else if (type == "credit") {
//		user_bank::Account new_account;
//		type_of_score = user_bank::TypeScore::credit;
//		cout << "������� ������ ����������� �����" << endl;
//		cin >> balance;
//		cout << "\n������� �������� ����������� �����" << endl;
//		cin >> percent;
//		new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
//		cout << "�� ������� ������� ������� � ���������� ������!" << endl;
//		cout << "�� �������� ���: " << endl;
//		cout << new_account << endl;
//		return;
//	}
//	else
//	{
//		user_bank::Account new_account;
//		type_of_score = user_bank::TypeScore::none;
//		new_account = user.create_new_account_in_index(index, type_of_score, 0, 0);
//		cout << "�� ����� ����������� ��� ��������, ������� �� ������� ������� ���� 'none' � ������� �������� � ����������" << endl;
//		cout << "�� �������� ���: " << endl;
//		cout << new_account << endl;
//		return;
//	}
//}
//int main_menu(user_bank::User& user) {
//	int n;
//	cout << "�������:" << endl;
//	cout << "*\t 1, ����� ������� ��������� ��� ������" << endl;
//	cout << "*\t 2, ����� ������� ����� ����" << endl;
//	cout << "*\t 3, ����� ������� ����� ���� �� �������" << endl;
//	cout << "*\t 4, ����� ������� ���� �� �������" << endl;
//	cout << "*\t 5, ����� ����� ���� � ������������ ��������" << endl;
//	cout << "*\t 6, ����� ��������� ������ ���������" << endl;
//	cin >> n;
//	int index;
//	switch (n)
//	{
//	case 1:
//		cout << user << endl;
//		break;
//	case 2:
//		Create_account(user);
//		break;
//	case 3:
//		cout << "������� ������(�� �������������), �� �������� ������ �������� ����� �������." << endl;
//		cin >> index;
//		Create_account(user, index);
//		break;
//	case 4:
//		cout << "������� ������(�� �������������) ��������, ������� ������ �������." << endl;
//		cin >> index;
//		user.delete_account_with_index(index);
//		break;
//	case 5:
//		cout << "���� � ������������ ��������: " << endl;
//		try
//		{
//			cout << user[user.find_max_balance()] << endl;
//		}
//		catch (const std::runtime_error& e)
//		{
//			e.what();
//		}
//		break;
//	case 6:
//		return 0;
//		break;
//	default:
//		break;
//	}
//	return 1;
//}
//using namespace std;
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	setlocale(LC_ALL, "ru");
//	cout << "� ������ ���������� ���������� �� ������ ����������� ������� ��������� ������ �� ������������ ������" << endl;
//	cout << "user.h \t�\t account.h" << endl;
//
//	string name;
//	cout << "��� ������ ������� ������� ������������, ��� �������� ����� ����������� �����." << endl;
//	cin >> name;
//	user_bank::User	UserObj(name);
//	while (main_menu(UserObj)){}
//	return 0;
//}
#include <iostream>
#include <string.h>
#include <limits>
#include <windows.h>
#include "account/user.h"
#include "account/account.h"

void Create_account(user_bank::User& user) {
	try {

		cout << "\n ������� ���������� ���������� ������� ����� ���� �� ������ �������" << endl;
		string type;
		float balance, percent;
		user_bank::TypeScore type_of_score;
		cin >> type;
		if (type == "calculated") {
			user_bank::Account new_account;
			type_of_score = user_bank::TypeScore::calculated;
			cout << "������� ������ ���������� �����" << endl;
			cin >> balance;
			new_account = user.create_account(type_of_score, balance, 0);
			cout << "�� ������� ������� ������� � ��������� ������!" << endl;
			cout << "�� �������� ���: " << endl;
			cout << new_account << endl;
			return;
		}
		else if (type == "deposit") {
			user_bank::Account new_account;
			type_of_score = user_bank::TypeScore::deposit;
			cout << "������� ������ ����������� �����" << endl;
			cin >> balance;
			cout << "\n������� �������� ����������� �����" << endl;
			cin >> percent;
			new_account = user.create_account(type_of_score, balance, percent);
			cout << "�� ������� ������� ������� � ���������� ������!" << endl;
			cout << "�� �������� ���: " << endl;
			cout << new_account << endl;
			return;
		}
		else if (type == "credit") {
			user_bank::Account new_account;
			type_of_score = user_bank::TypeScore::credit;
			cout << "������� ������ ���������� �����" << endl;
			cin >> balance;
			cout << "\n������� �������� ���������� �����" << endl;
			cin >> percent;
			new_account = user.create_account(type_of_score, balance, percent);
			cout << "�� ������� ������� ������� � ��������� ������!" << endl;
			cout << "�� �������� ���: " << endl;
			cout << new_account << endl;
			return;
		}
		else
		{
			user_bank::Account new_account;
			type_of_score = user_bank::TypeScore::none;
			new_account = user.create_account(type_of_score, 0, 0);
			cout << "�� ����� ����������� ��� ��������, ������� �� ������� ������� ���� 'none' � ������� �������� � ����������" << endl;
			cout << "�� �������� ���: " << endl;
			cout << new_account << endl;
			return;
		}
	}
	catch (std::runtime_error e) {
		cout << e.what() << endl;
	}
}
void Create_account(user_bank::User& user, int index) {
	try
	{
		cout << "\n ������� ���������� ���������� ������� ����� ���� �� ������ �������" << endl;
		string type;
		float balance, percent;
		user_bank::TypeScore type_of_score;
		cin >> type;
		if (type == "calculated") {
			user_bank::Account new_account;
			type_of_score = user_bank::TypeScore::calculated;
			cout << "������� ������ ���������� �����" << endl;
			cin >> balance;
			new_account = user.create_new_account_in_index(index, type_of_score, balance, 0);
			cout << "�� ������� ������� ������� � ��������� ������!" << endl;
			cout << "�� �������� ���: " << endl;
			cout << new_account << endl;
			return;
		}
		else if (type == "deposit") {
			user_bank::Account new_account;
			type_of_score = user_bank::TypeScore::deposit;
			cout << "������� ������ ����������� �����" << endl;
			cin >> balance;
			cout << "\n������� �������� ����������� �����" << endl;
			cin >> percent;
			new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
			cout << "�� ������� ������� ������� � ���������� ������!" << endl;
			cout << "�� �������� ���: " << endl;
			cout << new_account << endl;
			return;
		}
		else if (type == "credit") {
			user_bank::Account new_account;
			type_of_score = user_bank::TypeScore::credit;
			cout << "������� ������ ���������� �����" << endl;
			cin >> balance;
			cout << "\n������� �������� ���������� �����" << endl;
			cin >> percent;
			new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
			cout << "�� ������� ������� ������� � ��������� ������!" << endl;
			cout << "�� �������� ���: " << endl;
			cout << new_account << endl;
			return;
		}
		else
		{
			user_bank::Account new_account;
			type_of_score = user_bank::TypeScore::none;
			new_account = user.create_new_account_in_index(index, type_of_score, 0, 0);
			cout << "�� ����� ����������� ��� ��������, ������� �� ������� ������� ���� 'none' � ������� �������� � ����������" << endl;
			cout << "�� �������� ���: " << endl;
			cout << new_account << endl;
			return;
		}
	}
	catch (const std::runtime_error e)
	{
		cout << e.what() << endl;
	}
}
int main_menu(user_bank::User& user) {
	int n;
	cout << "�������:" << endl;
	cout << "*\t 1, ����� ������� ��������� ��� ������" << endl;
	cout << "*\t 2, ����� ������� ����� ����" << endl;
	cout << "*\t 3, ����� ������� ����� ���� �� �������" << endl;
	cout << "*\t 4, ����� ������� ���� �� �������" << endl;
	cout << "*\t 5, ����� ����� ���� � ������������ ��������" << endl;
	cout << "*\t 6, �������� ����� �� ���������" << endl;
	cout << "*\t 7, ����� ��������� ������ ���������" << endl;
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
		cout << "������� ������(�� �������������), �� �������� ������ �������� ����� �������." << endl;
		cin >> index;
		Create_account(user, index);
		break;
	case 4:
		cout << "������� ������(�� �������������) ��������, ������� ������ �������." << endl;
		cin >> index;
		user.delete_account_with_index(index);
		break;
	case 5:
		cout << "���� � ������������ ��������: " << endl;
		try
		{
			cout << user[user.find_max_balance()] << endl;
		}
		catch (const std::runtime_error& e)
		{
			cout << e.what() << endl;
		}
		break;
	case 6:
		cout << "�������� ����� �� ���������" << endl;
		try
		{
			for (int i = 0; i < user.get_count_accounts(); i++)
			{
				user[i].accrual();
			}
		}
		catch (const std::runtime_error& e)
		{
			cout << e.what() << endl;
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
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	cout << "� ������ ���������� ���������� �� ������ ����������� ������� ��������� ������ �� ������������ ������" << endl;
	cout << "user.h \t�\t account.h" << endl;

	string name;
	cout << "��� ������ ������� ������� ������������, ��� �������� ����� ����������� �����." << endl;
	cin >> name;
	user_bank::User	UserObj(name);
	
	while (main_menu(UserObj)) {}
	
	return 0;
}