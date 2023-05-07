#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDepositScreen:protected clsScreen
{

private:

		static void _PrintClient(clsBankClient Client) {
			cout << "\nClient Card";
			cout << "\n__________________";
			cout << "\nFirstName   :" << Client.FirstName;
			cout << "\nLastName    :" << Client.LastName;
			cout << "\nFullName    :" << Client.FullName();
			cout << "\nEmail       :" << Client.Email;
			cout << "\nPhone       :" << Client.Phone;
			cout << "\nAcc.Number  :" << Client.AccountNumber();
			cout << "\nPassWord    :" << Client.PinCode;
			cout << "\nBalance       :" << Client.AccountBalance;
			cout << "\n___________________________\n";
		}
		static string _ReadAccountNumber(){

			string AccountNumber = "";
			
			cout << "\n Please Enter AccountNumber? ";
			 
			cin >> AccountNumber;
			return AccountNumber;


	
		}
public:

	static void ShowDepositScreen() {

		_DrawScreenHeader("\t     Deposit Screen");
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient with [ " << AccountNumber << " ] does not exist.\n";
			AccountNumber = _ReadAccountNumber();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter deposit amount? ";
		Amount = clsInputValidate::ReadDblNumber();
		cout << "\nAre you sure you want to perform this transaction ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {

			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance is: " << Client1.AccountBalance;


		}

		else {
			cout << "\nOperation was cancelled.\n";


		} 

	}


};

