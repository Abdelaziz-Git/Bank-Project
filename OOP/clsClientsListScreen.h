#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"clsUser.h";
using namespace std;

class clsClientsListScreen:protected clsScreen
{
    static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(18) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
        cout << "|";

    }

public:
    static void ShowClientsList()
    {
        if (!clsScreen::CheekAccessRights(clsUser::pClientsList)){
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string SubTitle = to_string(vClients.size()) + " Client(s).";

        clsScreen::_DrawScreenHeader("Clients list screen", SubTitle);

        cout << "\n" << setw(10) << left << "";
        cout << "_______________________________________________________";
        cout << "_____________________________________________" << endl;
        cout << "\n" << setw(10) << left << "";

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(18) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "|";
        cout << "\n" << setw(10) << left << "";

        cout << "_______________________________________________________";
        cout << "_____________________________________________\n" << endl;

        
        if (vClients.size() == 0) {
            cout << "\n" << setw(10) << left << "";
            cout << "\t\t\t\tNo Clients Available In the System!\n";
        }
        else {
            for (clsBankClient Client : vClients) {
                cout << "\n" << setw(10) << left << "";
                PrintClientRecordLine(Client);
                cout << endl;
            }
        }
        cout << setw(10) << left << "";
        cout << "_______________________________________________________";
        cout << "_____________________________________________\n" << endl;
    }

};

