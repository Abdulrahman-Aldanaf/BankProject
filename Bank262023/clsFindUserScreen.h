#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsPerson.h"
#include"iomanip"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsFindUserScreen:protected clsScreen
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

public:
	static void ShowFindUserScreen() {
		_DrawScreenHeader("\t Find User Screen");
		string UserName;
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, chooese another one: ";
			UserName = clsInputValidate::ReadString();
					}
		clsUser User1 = clsUser::Find(UserName);
		if (!User1.IsEmpty()) {

			cout << "\nUser Found :-)\n";
		}

		else
		{
			cout << "\nUser Was not Found :(\n";

					}
		_PrintUser(User1);

	}




};

