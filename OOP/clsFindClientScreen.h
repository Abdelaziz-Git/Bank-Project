#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsClient.h";
#include"clsInputValidate.h";
using namespace std;
class clsFindClientScreen:protected clsScreen
{
    static void _PrintClient(clsClient Client) {
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
    static void ShowFindClientScreen() {
        if (!clsScreen::CheekAccessRights(clsUser::pFindClient)) {
            return;
        }
        clsScreen::_DrawScreenHeader("Find client screen");
        string AccountNumber;
        cout << "\nPlease enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        cout << "\nAccount number is found successfully -):\n";
        clsClient Client = clsClient::Find(AccountNumber);
        _PrintClient(Client);
    }

};

