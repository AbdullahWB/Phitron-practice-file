from user import *


def user_interface(bank):
    while True:
        print(
            "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Check Transaction History\n6. Take Loan\n7. Transfer\n8. Exit"
        )
        choice = input("Enter your choice: ")
        if choice == "1":
            name = input("Enter your name: ")
            email = input("Enter your email: ")
            address = input("Enter your address: ")
            account_type = input("Enter account type (Savings/Current): ")
            user = User(name, email, address, account_type)
            bank.users.append(user)
            print(
                f"Account created successfully. Account Number: {user.account.account_number}"
            )
        elif choice == "2":
            account_number = input("Enter your account number: ")
            account = bank.find_account(account_number)
            if account:
                amount = float(input("Enter amount to deposit: "))
                account.deposit(amount)
        elif choice == "3":
            account_number = input("Enter your account number: ")
            account = bank.find_account(account_number)
            if account:
                amount = float(input("Enter amount to withdraw: "))
                account.withdraw(amount)
        elif choice == "4":
            account_number = input("Enter your account number: ")
            account = bank.find_account(account_number)
            if account:
                print(f"Available balance: {account.check_balance()}")
        elif choice == "5":
            account_number = input("Enter your account number: ")
            account = bank.find_account(account_number)
            if account:
                print(f"Transaction history: {account.check_transaction_history()}")
        elif choice == "6":
            account_number = input("Enter your account number: ")
            account = bank.find_account(account_number)
            if account:
                amount = float(input("Enter loan amount: "))
                if account.user.can_take_loan:
                    account.take_loan(amount)
                else:
                    print("Loan feature is currently disabled")
        elif choice == "7":
            account_number = input("Enter your account number: ")
            account = bank.find_account(account_number)
            if account:
                target_account_number = input("Enter the target account number: ")
                target_account = bank.find_account(target_account_number)
                if target_account:
                    amount = float(input("Enter amount to transfer: "))
                    account.transfer(amount, target_account)
                else:
                    print("Account does not exist")
        elif choice == "8":
            break
        else:
            print("Invalid choice")


def admin_interface(bank):
    admin = bank.admin
    while True:
        print(
            "\n1. Create Account\n2. Delete Account\n3. View All Accounts\n4. Total Bank Balance\n5. Total Loan Amount\n6. Toggle Loan Feature\n7. Exit"
        )
        choice = input("Enter your choice: ")
        if choice == "1":
            name = input("Enter name: ")
            email = input("Enter email: ")
            address = input("Enter address: ")
            account_type = input("Enter account type (Savings/Current): ")
            admin.create_account(name, email, address, account_type)
        elif choice == "2":
            account_number = input("Enter account number to delete: ")
            admin.delete_account(account_number)
        elif choice == "3":
            admin.view_all_accounts()
        elif choice == "4":
            admin.total_bank_balance()
        elif choice == "5":
            admin.total_loan_amount()
        elif choice == "6":
            can_take_loan = input("Enable loan feature? (yes/no): ").lower() == "yes"
            admin.set_loan_feature(can_take_loan)
            print(f"Loan feature set to {'enabled' if can_take_loan else 'disabled'}")
        elif choice == "7":
            break
        else:
            print("Invalid choice")



bank = Bank("My Bank")
while True:
    print("\n1. User Interface\n2. Admin Interface\n3. Exit")
    choice = input("Enter your choice: ")
    if choice == "1":
        user_interface(bank)
    elif choice == "2":
        admin_interface(bank)
    elif choice == "3":
        break
    else:
        print("Invalid choice")
