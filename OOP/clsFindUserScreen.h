#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsUser.h";
#include"clsInputValidate.h";
class clsFindUserScreen:protected clsScreen
{
	static 	void _PrintUserCard(clsUser User)
	{
		cout << "\nUser card:\n";
		cout << "\n________________________________________\n";
		cout << "\nFirst name    :" << User.FirstName;
		cout << "\nLast name     :" << User.LastName;
		cout << "\nEmail         :" << User.Email;
		cout << "\nPone          :" << User.Phone;
		cout << "\nUserName      :" << User.UserName;
		cout << "\nPassword      :" << User.Password;
		cout << "\nPermissions   :" << User.Permissions;
		cout << "\n________________________________________\n";

	}
public:
	static void ShowFindUserScreen() {
		clsScreen::_DrawScreenHeader("Find user screen");
		string UserName = "";
		cout << "\nPlease enter userName: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)){
			cout << "\nUser is not found, enter another one: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		cout << "\nUser is found --)";
		_PrintUserCard(User);
	}
};

