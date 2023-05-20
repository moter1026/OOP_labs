
#include <iostream>
#include <string.h>
#include <limits>
#include <windows.h>
#include "account/user.h"
#include "account/account.h"

using namespace std;

void Create_account(user_bank::User& user) {
	std::cout << "\n ������� ���������� ������� ����� ���� �� ������ �������(Calculated, credit, deposit)" << endl;
	float balance, percent;
	string type_of_score;
	std::cin >> type_of_score;
	if (_stricmp("calculated", type_of_score.c_str()) == 0) {
		std::cout << "������� ������ ���������� �����" << endl;
		std::cin >> balance;
		user_bank::Account new_account = user.create_account(type_of_score, balance, 0);
		std::cout << "�� ������� ������� ��������� ����!" << endl;
		std::cout << "�� �������� ���: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else if (_stricmp("deposit", type_of_score.c_str()) == 0) {
		std::cout << "������� ������ ����������� �����" << endl;
		std::cin >> balance;
		std::cout << "\n������� �������� ����������� �����" << endl;
		std::cin >> percent;
		user_bank::Account new_account = user.create_account(type_of_score, balance, percent);
		std::cout << "�� ������� ������� ���������� ����!" << endl;
		std::cout << "�� �������� ���: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else if (_stricmp("credit", type_of_score.c_str()) == 0) {
		std::cout << "������� ������ ���������� �����" << endl;
		std::cin >> balance;
		std::cout << "\n������� �������� ���������� �����" << endl;
		std::cin >> percent;
		user_bank::Account new_account = user.create_account(type_of_score, balance, percent);
		std::cout << "�� ������� ������� ��������� ����!" << endl;
		std::cout << "�� �������� ���: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else
	{
		std::cout << "�� ����� ����������� ��� ��������, ������� �� �� ������� �������� ��������" << endl;
		return;
	}
}
void Create_account(user_bank::User& user, int index) {
	std::cout << "\n ������� ���������� ���������� ������� ����� ���� �� ������ �������" << endl;
	float balance, percent;
	string type_of_score;
	std::cin >> type_of_score;
	if (_stricmp("calculated", type_of_score.c_str()) == 0) {
		std::cout << "������� ������ ���������� �����" << endl;
		std::cin >> balance;
		user_bank::Account new_account = user.create_new_account_in_index(index, type_of_score, balance, 0);
		std::cout << "�� ������� ������� ������� � ��������� ������!" << endl;
		std::cout << "�� �������� ���: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else if (_stricmp("deposit", type_of_score.c_str()) == 0) {
		std::cout << "������� ������ ����������� �����" << endl;
		std::cin >> balance;
		std::cout << "\n������� �������� ����������� �����" << endl;
		std::cin >> percent;
		user_bank::Account new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
		std::cout << "�� ������� ������� ������� � ���������� ������!" << endl;
		std::cout << "�� �������� ���: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else if (_stricmp("credit", type_of_score.c_str()) == 0) {
		std::cout << "������� ������ ���������� �����" << endl;
		std::cin >> balance;
		std::cout << "\n������� �������� ���������� �����" << endl;
		std::cin >> percent;
		user_bank::Account new_account = user.create_new_account_in_index(index, type_of_score, balance, percent);
		std::cout << "�� ������� ������� ������� � ��������� ������!" << endl;
		std::cout << "�� �������� ���: " << endl;
		std::cout << new_account << endl;
		return;
	}
	else
	{
		std::cout << "�� ����� ����������� ��� ��������, ������� �� ������� �� �� ������� �������� ��������" << endl;
		return;
	}
}
int main_menu(user_bank::User& user ) {
	try
	{
		int n;
		std::cout << "�������:" << endl;
		std::cout << "*\t 1, ����� ������� ��������� ��� ������" << endl;
		std::cout << "*\t 2, ����� ������� ����� ����" << endl;
		std::cout << "*\t 3, ����� ������� ����� ���� �� �������" << endl;
		std::cout << "*\t 4, ����� ������� ���� �� �������" << endl;
		std::cout << "*\t 5, ����� ����� ���� � ������������ ��������" << endl;
		std::cout << "*\t 6, �������� ����� �� ���������" << endl;
		std::cout << "*\t 7, ����� ��������� ������ ���������" << endl;
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
			std::cout << "������� ������(�� �������������), �� �������� ������ �������� ����� �������." << endl;
			std::cin >> index;
			Create_account(user, index);
			break;
		case 4:
			cout << "������� ������(�� �������������) ��������, ������� ������ �������." << endl;
			std::cin >> index;
			user.delete_account_with_index(index);
			break;
		case 5:
			std::cout << "���� � ������������ ��������: " << endl;
			std::cout << user[user.find_max_balance()] << endl;
			break;
		case 6:
			std::cout << "�������� ����� �� ���������" << endl;
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
		std::cout << "� ������ ���������� ���������� �� ������ ����������� ������� ��������� ������ �� ������������ ������" << endl;
		std::cout << "user.h \t�\t account.h" << endl;

		string name;
		std::cout << "��� ������ ������� ������� ������������, ��� �������� ����� ����������� �����." << endl;
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