#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"Global.h";
#include"clsMainScreen.h";
#include"clsUtil.h";
using namespace std;

class clsLoginScreen:protected clsScreen
{
	static bool _Login() {
		bool LoginFail = false;
		string UserName, Password;
		short FailLoginCount = 0;
		do {
			if (LoginFail) {
				FailLoginCount++;
				cout << "\nInvalide username/password!";
				cout << "\nYou have " << (3-FailLoginCount) << " trial(s) to login.\n";
			}
			if (FailLoginCount == 3) {
				cout << "\nYou are locked after 3 faild trials.\n";
				return false;
			}
			cout << "\nEnter UserName: ";
			UserName = clsInputValidate::ReadString();
			cout << "\nEnter Password: ";
		    Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFail = CurrentUser.IsEmpty();
			
		} while (LoginFail);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenueScreen();
	}
public:
	
	static bool ShowLoginScreen() {
		
		system("cls");
		clsScreen::_DrawScreenHeader("      Login screen");
		return _Login();
	}

};

