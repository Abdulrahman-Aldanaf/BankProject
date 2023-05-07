#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDeleteClientScreen:protected clsScreen

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


public :
	static void ShowDeleteClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;

		}

		_DrawScreenHeader("\tDelete Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Acoount Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose anther: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		cout << "\nAre you sure you want to delete this client y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Delete()) {
				cout << "\nClient Deleted Succefully :-)\n";
				_PrintClient(Client1);


			}
			else
			{
				cout << "\nError Client was not Deleted\n";
			}

		}


		
	}




};

