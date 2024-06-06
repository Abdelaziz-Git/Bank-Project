#pragma once
#include<iostream>
#include<string>
#include"clsUser.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
using namespace std;
class clsDeleteUserScreen:protected clsScreen
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
	static void ShowDeleteUserScreen() {
		clsScreen::_DrawScreenHeader("Delete user screen");
		string UserName = "";
		cout << "\nPlease enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUserCard(User);
		char Answer = 'n';
		cout << "\nAre you sure do you want deleted this user? y/n? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			User.Delete();
			cout << "\nUser deleted successfully.";
			_PrintUserCard(User);
		}

	}

};

