#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
 #include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;


class clsTransactionsScreen:protected clsScreen

{
private:
	
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,eTransfer=4,eTransferLog=5
		,eSHowMainMenue = 6
	};


	static short ReadTransactionsMenueOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 6] ? ";
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 6, "Enter Number between 1 to 6 ?");
		return Choice;
	}
	static void _ShowDepositScreen() {
		cout << "\n Deposit Screen will be here.\n";
		clsDepositScreen::ShowDepositScreen();

	}
	static void _ShowWíthdrawScreen() {

		cout << "\nWithdraw Screen will be here.\n";
		clsWithdrawScreen::ShowWithdrawScreen();

					}
	static void _ShowTotalBalancesScreen() {
		cout << "\n Balance Screen will be here.\n";
		clsTotalBalancesScreen::ShowTotalBalances();

	}
	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTransferScreen();

	}
	static void _ShowTransferLogScreen() {
		cout << "\n Transfer Screen will be here.\n";
		clsTransferLogScreen::ShowTransferLogScreen();

	}
	static void _GoBackToTransactionsMenue() {
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();

	}
	static void _PerfromTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption) {
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWíthdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTotalBalance:

		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransfer:

		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;

					}
		case enTransactionsMenueOptions::eTransferLog:
		{

			system("cls");
		_ShowTransferLogScreen();
		_GoBackToTransactionsMenue();
				break;

		}

		case enTransactionsMenueOptions::eSHowMainMenue:
		{
		 


		}
		}
	}

public:

	static void ShowTransactionsMenue() {
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {


			return;

		}

		system("cls");
		_DrawScreenHeader("\t Transactions Screen");
		cout << setw(37) << left << "" << "==========================================\n";
		cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
		cout << setw(37) << left << "" << "==========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] TransferLog.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=========================================\n";
		_PerfromTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
	}

};

