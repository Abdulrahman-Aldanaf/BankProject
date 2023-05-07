#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsFindClientScreen:protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n_________________";
		cout << "\nFirstName    :" << Client.FirstName;
		cout << "\nLastName     :" << Client.LastName;
		cout << "\nFullName     :" << Client.FullName();
		cout << "\nEmail        :" << Client.Email;
		cout << "\nPhone          :" << Client.Phone;
		cout << "\nAcc.Number   :" << Client.AccountNumber();
		cout << "\nPassword     :" << Client.PinCode;
		cout << "\nBalance        :" << Client.AccountBalance;
		cout << "\n____________________\n";


	}
public:


	static void ShowFindClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {

			return;
		}
		_DrawScreenHeader("\tFind Client Screen");
		string AccountNumber;
		cout << "\nPlease enter account number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another";

				AccountNumber = clsInputValidate::ReadString();
	}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber); 



		if (!Client1.IsEmpty()) {
			cout << "\nClient found :-)\n";

		}
		else {
			cout << "\nClient was not found :-(\n";

		}

		_PrintClient(Client1);
	}



};

