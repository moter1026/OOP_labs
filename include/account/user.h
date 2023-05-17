#define N 255
#include "account.h"
#include <string>
#include <vector>
#pragma once

using namespace std;

namespace user_bank {
	class User {
	private:
		string				all_name;
		int					count_accounts = 0;
		Account**			accounts = new Account*[1];
		void				rewrite_array_with_acconts();
	public:
		User();
		User(const char* name);
		User(string name);
		User(const User& user_for_copy);
		string		get_all_name();
		int			get_count_accounts();
		int			find_max_balance();

		Account&	create_account(unsigned int index, TypeScore type, float balance);
		Account&	create_account(unsigned int index, TypeScore type, float balance, float percent);
		Account&	create_account(TypeScore type, float balance);
		Account&	create_account(TypeScore type, float balance, float percent);
		Account&	create_new_account(Account* new_account);

		//Данные функции вставляют по индексу со здвигом
		Account&	create_new_account_in_index(unsigned int index, TypeScore type, float balance);		
		Account&	create_new_account_in_index(unsigned int index, TypeScore type, float balance, float percent);

		Account		delete_account_with_index(unsigned int index);
		void		swap(User& user_swap) noexcept;
		User&		operator=(User user_cpy);
		Account&	operator[](size_t size);
		~User()
		{
			for (int i = 0; i < count_accounts; ++i) {
				delete accounts[i];
			}

			delete[] accounts;

			accounts = nullptr;
			count_accounts = 0;
		}
	};
	std::ostream& operator << (std::ostream& stream, User& item);
	//std::ostream& operator << (std::ostream& stream, const TypeScore item);
};
