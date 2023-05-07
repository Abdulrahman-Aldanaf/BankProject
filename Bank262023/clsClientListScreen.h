#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>




class clsClientListScreen:protected clsScreen
{
private:
	static void PrintClientRecordLine(clsBankClient Client) {
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "|" << setw(15) << left << Client.Phone;
		cout << "|" << setw(30) << left << Client.Email;
		cout << "|" << setw(10) << left << Client.PinCode;
		cout << "|" << setw(12) << left << Client.AccountBalance;

}
public :
	static void ShowClientsList() {


		if (!CheckAccessRights(clsUser::enPermissions::pListClients)) {
			return;

		}

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Clients(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_____________________________________________";
		cout << "_____________________________________\n"<<endl;
		cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "|" << left << setw(20) << "Email";
		cout << "|" << left << setw(10) << "Pin Code";
		cout << "|" << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_____________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available in the System !";
		else
			for (clsBankClient Client : vClients)

			{
				PrintClientRecordLine(Client);
				cout << endl;

			}
		cout << setw(8) << left << "" << "\n\t______________________________________";
		cout << "___________________________________________\n" << endl;

	}


};

