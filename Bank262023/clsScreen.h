#pragma once
#pragma warning (disable : 4996)
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"


using namespace std;

class clsScreen
{
public:
	
	

	static void _DrawScreenHeader(string Title, string SubTitle = "") {
		time_t now = time(0);
		tm* t = localtime(&now);
	

		cout << "\t\t\t\t\t\t" << clsDate::DateToString(clsDate());
		cout << "\t\t\t" <<CurrentUser.UserName;
		cout << "\n";
		cout << "\t\t\t\t\t________________________________";
		cout << "\n\n\t\t\t\t    "<<Title;
		if (SubTitle != "") {


			cout << "\n\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t____________________________________\n\n";
							}
	static bool CheckAccessRights(clsUser::enPermissions Permission) {
		if (!CurrentUser.CheckAccessPermission(Permission)) {

			cout << "\t\t\t\t___________________________________";
			cout << "\n\n\t\t\t\t Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t__________________________________\n\n";
			return false;

		}
		else
		{
			return true;
		}





	}






};

