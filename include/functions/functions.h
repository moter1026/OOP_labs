#pragma once
#define N 255


int sum_stub(int lhs, int rhs);
int fact(int n);

namespace UserBank {
	class Account {
	private:
		enum class TypeScore {
			calculated, deposit, credit
		};
		float balance;
		float percent;
	public:
		float accrual(float balance, float percent);

		char getName();
		float getBalance();
		float getPercent();
	};

	class User {
	private:
		char all_name[N * 3];
		Account scores[10000];
	public:
		void create_new_account();
	};
};
