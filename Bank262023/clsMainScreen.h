#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsWithdrawScreen.h"
#include "clsManageUsersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"Global.h"
#include<iomanip>

using namespace std;

class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6, eManageUsers = 7,eLoginRegister=8 ,eExit = 9
	};

	static short _ReadMenueOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do ?[1 to 9]? ";
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 9, "Enter Number Between 1 to 9");
		return Choice;

	}
	static void _GoBackToMainMeneu() {
		cout << setw(37) << left << "" << "\n\tPress any Key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenue();
					}
	static void _ShowAllClientsScreen() {
		cout << "\nClient List Screen will be here...\n";
		clsClientListScreen::ShowClientsList();


	}
	static void _ShowAddNewClientsScreen() {
		cout << "\nAdd New Client Screen will be here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();


	}
	static void _ShowDeleteClientScreen() {

		cout << "\nDelete Client Screen will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();

	}
	static void _ShowUpdateClientScreen() {

		cout << "\nUpdate Client Screen will be here...\n";
		clsUpdateClientScreen::ShowUpdateClient();
		

	}

	static void _ShowFindClientScreen() {

		cout << "\nFind Client Screen will be here...\n";

		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsMenue() {
		cout << "\nTransactions Menue will be here..\n";

		clsTransactionsScreen::ShowTransactionsMenue();


	}
	static void _ShowMangaeUserMenue() {

		cout << "\nUsers Menue will be here...\n";
		clsManageUsersScreen::ShowManageUsersMenue();
					}
	/*static void _ShowEndScreen() {
		cout << "\nEnd Screen will be here...\n";
	}*/
	static void _ShowLoginRegisterScreen() {
		cout << "\nLogin Register will be here...\n";
		clsLoginRegisterScreen::ShowLoginRegisterScreen();

	}
	static void _Logout() {
CurrentUser = clsUser::Find("", "");

	}
	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOptin) {
		switch (MainMenueOptin)
		{
		case enMainMenueOptions::eListClients:
		
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMeneu();
			break;
		
		case enMainMenueOptions::eAddNewClient:
		
			system("cls");
			_ShowAddNewClientsScreen();

			_GoBackToMainMeneu();
			break;
		
		case enMainMenueOptions::eDeleteClient:
		
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMeneu();
			break;
		
		case enMainMenueOptions::eUpdateClient:
		
			system("cls");
			_ShowUpdateClientScreen();
						_GoBackToMainMeneu();
			break;
		
		case enMainMenueOptions::eFindClient:

		
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMeneu();
			break;

		
		case enMainMenueOptions::eShowTransactionsMenue:
					
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMeneu();
			break;

		
		case enMainMenueOptions::eManageUsers:
		
			system("cls");
			_ShowMangaeUserMenue();
			_GoBackToMainMeneu();
			break;

		case enMainMenueOptions::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMeneu();
			break;

		
		case enMainMenueOptions::eExit:
		
		    system("cls");
			 _Logout();
		     break;

		
		}
	}

	public :

		
		static void ShowMainMenue() {

			system("cls");
			_DrawScreenHeader("\t\tMain Screen");
			cout << setw(37) << left << "" << "===============================================\n";
			cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
			cout << setw(37) << left << "" << "=================================================\n";
			cout << setw(37) << left << "" << "\t [1] Show Client List.\n";
			cout << setw(37) << left << "" << "\t [2] Add New Client.\n";
			cout << setw(37) << left << "" << "\t [3] Delete Client.\n";
			cout << setw(37) << left << "" << "\t [4] Update Client Info.\n";
			cout << setw(37) << left << "" << "\t [5] Find Clients.\n";
			cout << setw(37) << left << "" << "\t [6] Transcations.\n";
			cout << setw(37) << left << "" << "\t [7] Manage Users.\n";
			cout << setw(37) << left << "" << "\t [8] Login Register.\n";
			cout << setw(37) << left << "" << "\t [9] Logout.\n";
			cout << setw(37) << left << "" << "==================================================\n";
			_PerfromMainMenueOption((enMainMenueOptions)_ReadMenueOption());




		}


};

