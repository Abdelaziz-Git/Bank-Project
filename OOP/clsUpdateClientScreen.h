#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsClient.h";
#include"clsInputValidate.h";
using namespace std;

class clsUpdateClientScreen:protected clsScreen
{
    static void _ReadClientInfo(clsClient& Client,short Choise) {
        cout << "-------------------------------------";
        switch (Choise)
        {
        case 1:
            cout << "\nPlease enter first name: ";
            Client.FirstName = clsInputValidate::ReadString();
            break;
        case 2:
            cout << "\nPlease enter last name: ";
            Client.LastName = clsInputValidate::ReadString();
            break;
        case 3:
            cout << "\nPlease enter Email: ";
            Client.Email = clsInputValidate::ReadString();
            break;
        case 4:
            cout << "\nPlease enter Phone number: ";
            Client.Phone = clsInputValidate::ReadString();
            break;
        case 5:
            cout << "\nPlease enter Password: ";
            Client.PinCode = clsInputValidate::ReadString();
            break;
        case 6:
            cout << "\nPlease enter account balance: ";
            Client.AccountBalance = clsInputValidate::ReadFloatNumber();
            break;
        }
        
        cout << "-------------------------------------\n";

    }
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
    static void _ChoiseUpdate() {
        cout << "\n================================";
        cout << "\n" << "[1] First name.";
        cout << "\n" << "[2] Last name.";
        cout << "\n" << "[3] Email.";
        cout << "\n" << "[4] Phone.";
        cout << "\n" << "[5] Password.";
        cout << "\n" << "[6] Account balance.";
        cout << "\n================================\n";
    }
public:
    static void ShowUpdateClientScreen() {
        if (!clsScreen::CheekAccessRights(clsUser::pUpdateClient)) {
            return;
        }
        clsScreen::_DrawScreenHeader("Update client screen");
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

        cout << "\nAre you sure do you want update this client! Y/N? ";
        char Answer = 'n';
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            _ChoiseUpdate();
            cout << "Please choose what do you want change [1----6]";
            short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);

            cout << "\nUpdate client Info:\n";
            _ReadClientInfo(Client, Choice);

            clsClient::enSaveResults SaveResults;
            SaveResults = Client.Save();
            switch (SaveResults)
            {
            case clsClient::svFaildEmptyObject:
                cout << "\nError account is not saved becouse object is empty!\n";
                break;
            case clsClient::svSucceeded:
                cout << "\nAccount updated successfully :-).\n";
                _PrintClient(Client);
                break;

            }
        }

       

    }
};

