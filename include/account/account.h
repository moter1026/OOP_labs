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
		float		balance;
		float		percent;
	public:
		Account();
		Account(TypeScore type_of_score);
		void		accrual();
		float		getBalance();
		void		setBalance(float balance);
		float		getPercent();
		void		setPercent(float percent);
		TypeScore	getType();
		Account&	operator=(const Account& r);
	};
};
#endif
