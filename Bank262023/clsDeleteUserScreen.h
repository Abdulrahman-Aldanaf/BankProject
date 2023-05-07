#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen

{
private:
	static void _PrintUser(clsUser User) {

		cout << "\nUser Card: ";
		cout << "\n_________________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName  :" << User.LastName;
		cout << "\nFullName: " << User.FullName();
		cout << "\nEmail :" << User.Email;
		cout << "\nPhone : " << User.Phone;
		cout << "\nUser Name: " << User.UserName;
		cout << "\nPassword  :" << User.Password;
		cout << "\nPermissions: " << User.Permissions;
		cout << "\n_________________\n";

	}

public :

	static void ShowDeleteUserScreen() {
		_DrawScreenHeader("\tDelete User Screen");


		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "\nUser is not found, choose another one : ";
			UserName = clsInputValidate::ReadString();

		}
		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		cout << "\nAre you sure want to delete this User y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {

			if (User1.Delete()) {
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(User1);

			}
			else
			{
				cout << "\nError User was not Deleted\n";


			}

		}

	}





};

