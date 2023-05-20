#define MAX_COUNT_ACCOUNTS 16
#include <iostream>
#include <memory>
#include <string>
#pragma once
namespace user_bank {
	class Account {
	protected:
				std::string					_type;
				float						_balance;
				float						_percent;
	public:
		Account() = default;
		Account(float balance, float percent);
		virtual void						accrual() {};
		//virtual float						getPercent() const noexcept { return 0; };
		virtual float						getPercent() const noexcept;
		virtual void						print(std::ostream& stream) const;
		virtual std::shared_ptr<Account>	clone() const { return std::make_shared<Account>(); };
		bool								operator==(Account user_cpy);
				Account&					deleteScore() noexcept;
				std::string					getType() const;
				float						getBalance() const noexcept;
				void						setBalance(float balance);
		virtual ~Account() = default;
	};

	class AccountCalculated: public Account {
	private:
		//std::string					_type = "Calculated";
	public:
		AccountCalculated();
		AccountCalculated(float balance);
		AccountCalculated(float balance, float percent);
		std::shared_ptr<Account>	clone() const override;
		void						print(std::ostream& stream) const override;
		void						accrual() override;
	};
	
	class AccountCredit		: public Account {
	private:
		//std::string					_type = "Credit";
	public:
		AccountCredit();
		AccountCredit(float balance, float percent);
		std::shared_ptr<Account>	clone() const override;
		void						accrual() override;
		void						setPercent(float percent);
	};
	
	class AccountDeposit	: public Account {
	private:
		//std::string					_type = "Deposit";
	public:
		AccountDeposit();
		AccountDeposit(float balance, float percent);
		std::shared_ptr<Account>	clone() const override;
		void						accrual() override;
		void						setPercent(float percent);
	};


	std::ostream& operator << (std::ostream& stream, Account& item);
	/*std::ostream& operator << (std::ostream& stream, AccountCalculated& item);
	std::ostream& operator << (std::ostream& stream, AccountCredit& item);
	std::ostream& operator << (std::ostream& stream, AccountDeposit& item);*/
};
