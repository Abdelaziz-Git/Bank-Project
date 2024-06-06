#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsUtil.h";
using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(30) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
        cout << "|";

    }
public:
    static void ShowTotalBalancesScreen()
    {
        clsScreen::_DrawScreenHeader("Total balances screen");
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        cout << "\n\t\tBalances list (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "|";
        cout << "\n_______________________________________________________";
        cout << "_________\n" << endl;

        if (vClients.size() == 0) {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }
        else {
            for (clsBankClient Client : vClients) {

                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
        }
        cout << "_______________________________________________________";
        cout << "_________\n" << endl;
        double TotalBalances = clsBankClient::GetTotalBalances();
        cout << "Total balances = " << TotalBalances;
        cout << "\n(" << clsUtil::NumberToText(TotalBalances) << ")";

    }

};

