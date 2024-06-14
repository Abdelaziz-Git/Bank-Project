#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsClient.h";
#include"clsInputValidate.h";
using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
    static void _ReadClientInfo(clsClient& Client) {

        cout << "-------------------------------------";
        cout << "\nPlease enter first name: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nPlease enter last name: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nPlease enter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nPlease enter Phone number: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nPlease enter Password: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nPlease enter account balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
        cout << "\n-------------------------------------\n";

    }
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

    static void ShowAddNewClientScreen() {
        if (!clsScreen::CheekAccessRights(clsUser::pAddNewClient)) {
            return;
        }
        clsScreen::_DrawScreenHeader("Add new client screen");
        string AccountNumber;
        cout << "\nPlease enter account number ? ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount number is already exist, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsClient NewClient = clsClient::GetAddNewClientObject(AccountNumber);
        cout << "\nAdd new client Info:\n";
        _ReadClientInfo(NewClient);
        clsClient::enSaveResults SaveResults;

        SaveResults = NewClient.Save();
        switch (SaveResults)
        {
        case clsClient::svFaildEmptyObject:
            cout << "\nError client is not added becouse object is empty.\n";
            break;
        case clsClient::svSucceeded:
            cout << "\nClient is added succssfully.";
            _PrintClient(NewClient);
            break;
        case clsClient::svFaildAccountNumberExist:
            cout << "\nError client is not added becouse account number choosed is exist.\n";
            break;

        }
    }

};

