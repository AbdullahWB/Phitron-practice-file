import uuid


class Account:
    def __init__(self, account_type, user) -> None:
        self.account_number = str(uuid.uuid4())
        self.account_type = account_type
        self.balance = 0.0
        self.transactions = []
        self.loan_taken = 0
        self.user = user
        super().__init__()

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            self.transactions.append(f"Deposited: {amount}$")
        else:
            print("Invalid deposit amount...!")

    def withdraw(self, amount):
        if amount <= self.balance:
            self.balance -= amount
            self.transactions.append(f"Withdrawn: {amount}$")
        else:
            print("Withdrawal amount exceeded...!")

    def transfer(self, amount, other_account):
        if amount <= self.balance:
            self.balance -= amount
            other_account.balance += amount
            self.transactions.append(
                f"Transferred: {amount}$ to {other_account.account_number}"
            )
            other_account.transactions.append(
                f"Received: {amount}$ from {self.account_number}"
            )
        else:
            print("Insufficient balance for transfer...!")

    def check_balance(self):
        return self.balance

    def check_transaction_history(self):
        return self.transactions

    def take_loan(self, amount):
        if self.loan_taken < 2:
            self.loan_taken += 1
            self.balance += amount
            self.transactions.append(f"Loan taken: {amount}")
        else:
            print("Maximum loan limit reached...!")


class User:
    def __init__(self, name, email, address, account_type) -> None:
        self.name = name
        self.email = email
        self.address = address
        self.account = Account(account_type, self)
        self.can_take_loan = True
        super().__init__()


class Admin:
    def __init__(self, bank) -> None:
        self.bank = bank
        super().__init__()

    def create_account(self, name, email, address, account_type):
        user = User(name, email, address, account_type)
        self.bank.users.append(user)
        return user

    def delete_account(self, account_number):
        for user in self.bank.users:
            if user.account.account_number == account_number:
                self.bank.users.remove(user)
                print(f"Account {account_number} deleted successfully...")
                return
        print("Account not found...!")

    def view_all_accounts(self):
        for user in self.bank.users:
            print(
                f"User: {user.name}, Account Number: {user.account.account_number}, Balance: {user.account.balance}$"
            )

    def total_bank_balance(self):
        total_balance = sum(user.account.balance for user in self.bank.users)
        print(f"Total bank balance: {total_balance}$")
        return total_balance

    def total_loan_amount(self):
        total_loan = sum(user.account.loan_taken for user in self.bank.users)
        print(f"Total loan amount: {total_loan}$")
        return total_loan

    def set_loan_feature(self, can_take_loan):
        for user in self.bank.users:
            user.can_take_loan = can_take_loan


class Bank:
    def __init__(self, name) -> None:
        self.name = name
        self.users = []
        self.admin = Admin(self)
        super().__init__()

    def find_account(self, account_number):
        for user in self.users:
            if user.account.account_number == account_number:
                return user.account
        print("Account not found...")
        return None
