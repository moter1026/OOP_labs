#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER
#define N 255
#define MAX_COUNT_ACCOUNTS 7
#pragma once


namespace user_bank {
	class Account {
	private:
		enum class TypeScore {
			calculated = 1,
			deposit,
			credit
		};
		TypeScore type;
		float balance;
		float percent;
	public:
		Account();
		Account(int type_of_score);
		void accrual(float balance, float percent);
		float getBalance();
		float getPercent();
	};

	class User {
	private:
		char all_name[N * 2];
		int count_accounts = 0;
	public:
		Account accounts[MAX_COUNT_ACCOUNTS];
		User(const char* name);
		char* get_all_name();
		int find_max_balance();
		void create_new_account(int type, float balance, ...);
	};
};
#endif
