#define N 255
#include "account.h"
#include <string>
#include <vector>
#include <typeinfo>
#pragma once

using namespace std;

namespace user_bank {
	using sharedAcc = std::shared_ptr<Account>;
	class User {
	private:
		string							_all_name;
		vector<sharedAcc>				_accounts;
		//void							rewrite_array_with_acconts();
	public:
		User() noexcept;
		User(string name) noexcept;
		User(const char* name) noexcept;
		User(const User& user_for_copy);
		string		get_all_name() const;
		int			get_count_accounts() const;
		int			find_max_balance() const;

		Account&			create_account(sharedAcc item);
		Account&			create_account(float balance);
		Account&			create_account(string type, float balance, float percent);
		
		//Данные функции вставляют по индексу со здвигом
		template<typename T>
		Account&			create_new_account_in_index(unsigned int index, std::shared_ptr<T> item);
		Account&			create_new_account_in_index(unsigned int index, string type, float balance, float percent);

		Account&			overwrite(unsigned int index, string type,  float balance, float percent);
		Account				delete_account_with_index(unsigned int index);
		void				swap(User& user_swap) noexcept;
		User&				operator=(User user_cpy);
		Account&			operator[](unsigned int index) const;
	};
	void print(const User& item) {
		cout << "Имя пользователя: " << item.get_all_name() << std::endl;
		cout << "Количество открытых счетов: " << item.get_count_accounts() << std::endl;
		if (item.get_count_accounts() != 0)
		{
			for (int i = 0; i < item.get_count_accounts(); ++i) {
				cout << "Счёт номер: " << i << std::endl;
				cout << item[i] << endl;
			}
		}
	}

	std::ostream& operator << (std::ostream& stream, User& item);
};
