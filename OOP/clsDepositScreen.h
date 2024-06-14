#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsClient.h";
#include"clsInputValidate.h";
using namespace std;
class clsDepositScreen:protected clsScreen
{
	static string _ReadAccountNumber() {
		cout << "\nPlease enter account number? ";
		return clsInputValidate::ReadString();
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


public:
	static void ShowDepositScreen() {
        clsScreen::_DrawScreenHeader("Deposit screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsClient::IsClientExist(AccountNumber)) {
            cout << "\nClient with [" << AccountNumber << "] is not exist, please enter another one: ";
            AccountNumber = _ReadAccountNumber();
        }
        clsClient Client1 = clsClient::Find(AccountNumber);
        _PrintClient(Client1);
        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        cin >> Amount;
        char Answer = 'n';
        cout << "\nAre you sure do you want perform this transaction? Y/N? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            if (Client1.Deposit(Amount)) {
                cout << "\nAmount deposited successfully.";
                cout << "\nNew balance is: " << Client1.AccountBalance;
            }
            else {
                cout << "\nError: Deposit failed!!";
            }
        }
        else {
            cout << "\nDeposit operation was canceled!!";
        }

	}

};

