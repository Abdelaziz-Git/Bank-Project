#pragma once
#include<iostream>
#include<string>
#include"clsUser.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
using namespace std;

class clsAddNewUserScreen :protected clsScreen
{
	static int _ReadPermissions() {
		char Answer='n';
		int Permission = 0;
		cout << "\nEnter permissions:";
		cout << "\nDo you want to give full access? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			return Permission = clsUser::enPermissions::pAll;
		}
		cout << "\nDo you want to give access to:";
		cout << "\nShow clients list? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			Permission = clsUser::enPermissions::pClientsList;
		}
		cout << "\nAdd new client? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			Permission += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\nDelete client? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			Permission += clsUser::enPermissions::pDeleteClient;
		}
		cout << "\nUpdate client? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			Permission += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\nFind client? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			Permission += clsUser::enPermissions::pFindClient;
		}
		cout << "\nTransactions? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			Permission += clsUser::enPermissions::pTransactions;
		}
		cout << "\nManage users? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			Permission += clsUser::enPermissions::pManageUsers;
		}
		cout << "\nLogin register? Y/N? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			Permission += clsUser::enPermissions::pLoginRegister;
		}
		return Permission;
	}
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
	static void _ReadUserInfo(clsUser& User) {
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();
		User.Permissions = _ReadPermissions();
	}

public:
	static void ShowAddNewUserScreen() {
		clsScreen::_DrawScreenHeader("Add New User Screen");
		string UserName = "";
		cout << "\nPlease enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName)) {
			cout << "\nUserName is already user, please enter another one: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(User);
		clsUser::enSaveResults SaveResults;
		SaveResults = User.Save();
		switch (SaveResults)
		{
		case clsUser::svFaildEmptyObject:
			cout << "\nError: because object is empty!";
			break;
		case clsUser::svSucceeded:
			cout << "\nUser is added successfully.";
			_PrintUserCard(User);
			break;
		case clsUser::svFaildUserExist:
			cout << "\nError: because user is exist!";
			break;
		}
	}
};

