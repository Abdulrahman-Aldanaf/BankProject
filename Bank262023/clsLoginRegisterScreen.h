#pragma once
#include<iostream>
#include"clsUser.h"
#include<iomanip>
#include"clsScreen.h"

class clsLoginRegisterScreen: protected clsScreen
{
private:
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord) {
		cout << setw(8) << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "|" << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "|" << setw(20) << left << LoginRegisterRecord.Password;
		cout << "|" << setw(10) << left << LoginRegisterRecord.Permissions;

	}
public:

	static void ShowLoginRegisterScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister)) {
			return;

		}

		vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecord = clsUser::GetLoginRegisterList();
		string Title = "\nLogin Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_____________________________________";
		cout << "______________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "|" << left << setw(20) << "Password";
		cout << "|" << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_________________________________________";
		cout << "________________________________________\n" << endl;
		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Availble in the System!";
		else
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)

			{
				_PrintLoginRegisterRecordLine(Record);

				cout << endl;
			}
		cout << setw(8) << "" << "\n\t____________________________________";
		cout << "______________________________________\n" << endl;


			
	}



};

