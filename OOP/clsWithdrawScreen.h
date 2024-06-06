#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"clsInputValidate.h";

class clsWithdrawScreen:protected clsScreen
{
    static string _ReadAccountNumber() {
        cout << "\nPlease enter account number? ";
        return clsInputValidate::ReadString();
}
static void _PrintClient(clsBankClient Client)
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
    static void ShowWithdrawScreen() {
        clsScreen::_DrawScreenHeader("Withdraw screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nClient with [" << AccountNumber << "] is not exist, please enter another one: ";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter withdraw amount? ";
        cin >> Amount;
        
        char Answer = 'n';
        cout << "\nAre you sure do you want perform this transaction? Y/N? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            if (Client1.Withdraw(Amount)) {
                cout << "\nAmount withdraw successfully.";
                cout << "\nNew balance is " << Client1.AccountBalance;
            }
            else {
                cout << "\nCannot withdraw, insuffecient balance!";
                cout << "\nAmount to withdraw is " << Amount;
                cout << "\nYour balance is: " << Client1.AccountBalance;
            }
        }
    }
};

