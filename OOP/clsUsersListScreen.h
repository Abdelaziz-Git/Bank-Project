#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsScreen.h";
#include"clsUser.h";
using namespace std;


class clsUsersListScreen:protected clsScreen
{
	static void _PrintUserRecordLine(clsUser User) {
        cout << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(30) << left << User.FullName();
        cout << "| " << setw(16) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
        cout << "|";
	}
public:
    static void ShowUsersList() {
        vector<clsUser>vUsers = clsUser::GetUsersList();

        string SubTitle = "(" + to_string(vUsers.size()) + ")" + " User(s).";
        clsScreen::_DrawScreenHeader("Users list screen", SubTitle);

        cout << "\n" << setw(10) << left << "";
        cout << "_______________________________________________________";
        cout << "____________________________________________________________" << endl;

        cout << "\n" << setw(10) << left << "";
        cout << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(30) << "Full Name";
        cout << "| " << left << setw(16) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "|";
        cout << "\n" << setw(10) << left << "";

        cout << "_______________________________________________________";
        cout << "____________________________________________________________\n" << endl;


        if (vUsers.size() == 0) {
            cout << "\n" << setw(10) << left << "";
            cout << "\t\t\t\tNo Clients Available In the System!";
        }
        else {
            for (clsUser User : vUsers) {
                cout << "\n" << setw(10) << left << "";
                _PrintUserRecordLine(User);
                cout << endl;
            }
        }
        cout << setw(10) << left << "";
        cout << "_______________________________________________________";
        cout << "____________________________________________________________\n" << endl;
    }
};

