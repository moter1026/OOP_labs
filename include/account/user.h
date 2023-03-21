#define N 255
#define MAX_COUNT_ACCOUNTS 16
#pragma once
#include "account.h"


namespace user_bank {
	class User {
	private:
		char		all_name[N * 2];
		int			count_accounts = 0;
		Account		accounts[MAX_COUNT_ACCOUNTS];
		Account& create_calculated_account(unsigned int index, TypeScore type, float balance);
		Account& create_dep_or_cre_account(unsigned int index, TypeScore type, float balance, float percent);
		Account& select_account_with_index(unsigned int index);
	public:
		User(const char* name);
		char*		get_all_name();
		int			get_count_accounts();
		int			find_max_balance();
		Account&	create_new_account(TypeScore type, float balance);
		Account&	create_new_account(TypeScore type, float balance, float percent);
		Account&	create_new_account_in_index(unsigned int index, TypeScore type, float balance);
		Account&	create_new_account_in_index(unsigned int index, TypeScore type, float balance, float percent);
		Account		delete_account_with_index(unsigned int index);
		Account&	operator[](size_t size);
	};
};
