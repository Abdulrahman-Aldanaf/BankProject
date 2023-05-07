
//ProgrammingAdvices.com
//Mohmammed Abu-Hadhoud
#include <iostream>
#include"clsLoginScreen.h"
//#include "clsBankClient.h"
//#include"clsInputValidate.h"
//#include"clsMainScreen.h"
//#include"clsScreen.h"
//#include<iomanip>
//#include"clsDeleteClientScreen.h"
//#include"clsUtil.h"
//#include"clsManageUsersScreen.h"
using namespace std;


//
//void ReadClientInfo(clsBankClient& Client) {
//
//    cout << "\nEnter FirstName:";
//    Client.FirstName = clsInputValidate::ReadString();
//
//    cout << "\nEnter LastName :";
//
//    Client.LastName = clsInputValidate::ReadString();
//    cout << "\nEnter Email: ";
//
//    Client.Email = clsInputValidate::ReadString();
//
//    cout << "\nEnter Phone :";
//    Client.Phone = clsInputValidate::ReadString();
//    cout << "\nEnter Account Balance: ";
//    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
//
//}
//
//
//void AddNewClient() {
//    string AccountNumber = "";
//
//    cout << "\nPlease Enter Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//
//    while (clsBankClient::IsClientExist(AccountNumber)) {
//        cout << "\nAccount Number is already used, choose  anthoer one :";
//        AccountNumber = clsInputValidate::ReadString();
//
//    }
//    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
//
//    ReadClientInfo(NewClient);
//    clsBankClient::enSaveResults SaveResult;
//    SaveResult = NewClient.Save();
//    switch (SaveResult) {
//    case clsBankClient::enSaveResults::svSucceeded:
//    {
//        cout << "\nAccount Addeded Successfully :-)\n";
//        NewClient.Print();
//        break;
//
//    }
//    case clsBankClient::enSaveResults::svFaildEmptyObject:
//    {
//
//        cout << "\nError account was not saved because it s Empty ";
//        break;
//    }
//    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
//    {
//
//        cout << "\nError account was not saved because account number is used!\n";
//        break;
//    }
//       
//    }
//
//
//
//}
//
//void UpdateClient() {
//
//
//    string AccountNumber = "";
//    cout << "\nPlease Enter Client Account Number:";
//    AccountNumber = clsInputValidate::ReadString();
//
//    while (!clsBankClient::IsClientExist(AccountNumber)) {
//        cout << "\nAccount number is not found, choose anthoer one : ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//    Client1.Print();
//    cout << "\n\nUpdate Client Info:";
//    cout << "\n__________________\n";
//
//    ReadClientInfo(Client1);
//    clsBankClient::enSaveResults SaveResults;
//    SaveResults = Client1.Save();
//    switch (SaveResults) {
//
//    case clsBankClient::enSaveResults::svSucceeded:
//    {
//        cout << "\nAccount Updated Successfully :-)\n";
//        Client1.Print();
//        break;
//
//
//    }
//    case clsBankClient::enSaveResults::svFaildEmptyObject:
//    {
//
//        cout << "\nError  aacount was not saved because it is empty";
//        break;
//    }
//
//    }
//}
//
//void DeleteClient() {
//    string AccountNumber = "";
//    cout << "\mPlease Enter Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//    while (!clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount Number is not found, choose another one : ";
//        AccountNumber = clsInputValidate::ReadString();
//
//    }
//    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//    Client1.Print();
//    cout << "\nAre you sure you want to delete this client y/n ? ";
//    char Answer = 'n';
//    cin >> Answer;
//    if (Answer == 'y' || Answer == 'Y') {
//        if (Client1.Delete()) {
//            cout << "\nClient Deleted Successfully :)\n";
//            Client1.Print();
//        }
//        else {
//
//            cout << "\nError Client was not Deleted \n";
//        }
//
//    }
//
//}
//
//    void PrintClientRecordLine(clsBankClient Client) {
//        cout << " | " << setw(15) << left << Client.AccountNumber();
//        cout << " | " << setw(20) << left << Client.FullName();
//        cout << " | " << setw(12) << left << Client.Phone;
//        cout << " | " << setw(30) << left << Client.Email;
//        cout << " | " << setw(10) << left << Client.PinCode;
//        cout << " | " << setw(10) << left << Client.AccountBalance;
//
//    }
//    void ShowClientsListe() {
//        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
//        cout << "\n\t\t\t\t\t\tClient Liste (" << vClients.size() << " ) Clients(s).";
//        cout << "\n__________________________________________________________";
//        cout << "____________________________________________________________\n" << endl;
//        cout << " | " << left << setw(15) << "Account Number";
//        cout << " |" << left << setw(20) << "Client Name";
//        cout << " | " << left << setw(15) << "Phone";
//        cout << " |" << left << setw(20) << "Email";
//        cout << " |" << left << setw(5) << "PinCode";
//        cout << " |" << left << setw(15) << "Balance";
//        cout << "\n________________________________________________";
//        cout << "_______________________________________________________\n" << endl;
//
//        if (vClients.size() == 0) 
//            cout << "\t\t\t\tNo Clients Available in the System!";
//        else 
//            for (clsBankClient Client : vClients) {
//                PrintClientRecordLine(Client);
//                cout << endl;
//
//            }
//        cout << "\n___________________________";
//        cout << "_______________________________\n" << endl;
//
//     
//    }
//
//    void PrintClientRecordBalanceLine(clsBankClient Client) {
//        cout << " |" << setw(15) << left << Client.AccountNumber();
//        cout << " |" << setw(40) << left << Client.FullName();
//        cout << " |" << setw(12) << left << Client.AccountBalance;
//
//
//    }
//
//    void ShowTotalBalances() {
//        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
//        cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Clients(s).";
//        cout << "\n________________________________________________________";
//        cout << "____________________________________________________________";
//        cout << "______________________________________________________________\n" << endl;
//        cout << "| " << left << setw(15) << "Account Number";
//        cout << "| " << left << setw(40) << "Client Name";
//        cout << "| " << left << setw(12) << "Balance";
//        cout << "\n________________________________________________________";
//
//        cout << "______________________________________________________________\n" << endl;
//
//
//
//        double TotalBalances = clsBankClient::GetTotalBalance();
//        if (vClients.size() == 0)
//            cout << "\t\t\t\tNo Clients Available in the system!";
//        else
//            for (clsBankClient Client : vClients) {
//
//                PrintClientRecordBalanceLine(Client);
//                cout << endl;
//
//            }
//
//
//        cout << "\n___________________________________________";
//        cout << "_______________________________________________\n" << endl;
//        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
//        cout << "\t\t\t\t\t       (" <<clsUtil::NumberToText(TotalBalances) << " )";
//
//    }

int main()

{

    //clsMainScreen::ShowMainMenue();
    while (true) {
      if(!clsLoginScreen::ShowLoginScreen());
      break;
    }
  
    system("pause>0");
    return 0;
}