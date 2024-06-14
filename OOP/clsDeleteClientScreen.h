#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsClient.h";
#include"clsInputValidate.h";
using namespace std;

class clsDeleteClientScreen:protected clsScreen
{
    static void _PrintClient(clsClient Client)
    {
        cout << "\nClient card:";
        cout << "\n________________________________________\n";
        cout << "\nFirst name    :" << Client.FirstName;
        cout << "\nLast name     :" << Client.LastName;
        cout << "\nEmail         :" << Client.Email;
        cout << "\nPone          :" << Client.Phone;
        cout << "\nAcc. Number   :" << Client.AccountNumber();
        cout << "\nPassword      :" << Client.PinCode;
        cout << "\nAccount balane:" << Client.AccountBalance;
        cout << "\n________________________________________\n";

    }
public:
    static void ShowDeleteClientScreen() {
        if (!clsScreen::CheekAccessRights(clsUser::pDeleteClient)) {
            return;
        }
        clsScreen::_DrawScreenHeader("Delete client screen");
        string AccountNumber;
        cout << "\nPlease enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        cout << "\nAccount number is found successfully -):\n";
        clsClient Client = clsClient::Find(AccountNumber);
        _PrintClient(Client);
        char Answer = 'n';
        cout << "\nAre you sure do you want delete this client! Y/N: ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            if (Client.Delete()) {
                cout << "\nDone: Client deleted successfully -).\n";
                _PrintClient(Client);
            }
            else {
                cout << "\nError: Client Was not deleted -(!!\n";
            }
        }
    }

};

