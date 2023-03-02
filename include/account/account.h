#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER
#define N 255
#define MAX_COUNT_ACCOUNTS 16
#pragma once


namespace user_bank {

	enum class TypeScore {
		none = 0,
		calculated,
		deposit,
		credit
	};
	class Account {
		friend class User;
	private:
		TypeScore	type = TypeScore::none;
		float		balance = 0;
		float		percent = 0;
	public:
		Account();
		Account(TypeScore type_of_score);
		void		accrual();
		float		getBalance();
		void		setBalance(float balance);
		float		getPercent();
		void		setPercent(float percent);
		Account& operator=(const Account& r);
	};

	class User {
	private:
		char		all_name[N * 2];
		int			count_accounts = 0;
		Account&	create_calculated_account(unsigned int index, TypeScore type, float balance);
		Account&	create_dep_or_cre_account(unsigned int index, TypeScore type, float balance, float percent);
		Account		accounts[MAX_COUNT_ACCOUNTS];
	public:
		User();
		User(const char* name);
		char*		get_all_name();
		int		get_count_accounts();
		int			find_max_balance();
		Account&	create_new_account(TypeScore type, float balance);
		Account&	create_new_account(TypeScore type, float balance, float percent);
		Account&	create_new_account_in_index(unsigned int index, TypeScore type, float balance);
		Account&	create_new_account_in_index(unsigned int index, TypeScore type, float balance, float percent);
		Account&	select_account_with_index(unsigned int index);
		Account		delete_account_with_index(unsigned int index);
	};
};
#endif
