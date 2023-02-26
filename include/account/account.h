#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER
#define N 255
#define MAX_COUNT_ACCOUNTS 7
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
		TypeScore type = TypeScore::none;
		float balance = 0;
		float percent = 0;
	public:
		Account();
		Account(TypeScore type_of_score);
		void accrual();
		float getBalance();
		bool setBalance(float balance);
		float getPercent();
		bool setPercent(float percent);
	};

	class User {
	private:
		char all_name[N * 2];
		int count_accounts = 0;
	public:
		Account accounts[MAX_COUNT_ACCOUNTS];
		User();
		User(const char* name);
		char* get_all_name();
		int find_max_balance();
		bool create_new_account(TypeScore type, float balance);
		bool create_new_account(TypeScore type, float balance, float percent);
	};
};
#endif
