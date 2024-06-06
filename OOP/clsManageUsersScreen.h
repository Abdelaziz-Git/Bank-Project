#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"clsUsersListScreen.h";
#include"clsAddNewUserScreen.h";
#include"clsDeleteUserScreen.h";
#include"clsUpdateUserScreen.h";
#include"clsFindUserScreen.h";

class clsManageUsersScreen:protected clsScreen
{
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5
		, MainMenue = 6
	};

	static void _ShowListUsersScreen() {
		//cout << "\nList users will be her.......\n";
		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen() {
		//cout << "\nAdd new user screen will be here........\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen() {
		//cout << "\nDelete secreen will be here........\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen() {
		//cout << "\nUpdate secreen will be here........\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen() {
		//cout << "\Find user secreen will be here........\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static short _ReadManageUsersOptions() {
		cout << "\n" << setw(40) << left << "";
		cout << "Choose whate do you want to do? [1--6]? ";
		return clsInputValidate::ReadShortNumberBetween(1, 6);
	}

	static void _GoBackToManageUsersMenue() {
		cout << "\nPress any key to go back to manage users menue....";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOptions(enManageUsersMenueOptions ManageUsersMenueOptions) {
		switch (ManageUsersMenueOptions)
		{
		case clsManageUsersScreen::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersScreen::MainMenue:
			break;
		}
	}
public:
	static void ShowManageUsersMenue() {
		if (!clsScreen::CheekAccessRights(clsUser::pManageUsers)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("Manage users screen");
		cout << "\n" << setw(40) << left << "" << "=========================================";
		cout << "\n" << setw(40) << left << "" << "\tManage users menue";
		cout << "\n" << setw(40) << left << "" << "=========================================";
		cout << "\n" << setw(40) << left << "" << "[1] list users.";
		cout << "\n" << setw(40) << left << "" << "[2] Add new user.";
		cout << "\n" << setw(40) << left << "" << "[3] Delete user.";
		cout << "\n" << setw(40) << left << "" << "[4] Update user.";
		cout << "\n" << setw(40) << left << "" << "[5] Find user.";
		cout << "\n" << setw(40) << left << "" << "[6] Main menue.";
		cout << "\n" << setw(40) << left << "" << "=========================================\n";
		_PerformManageUsersMenueOptions(enManageUsersMenueOptions(_ReadManageUsersOptions()));
	}
};

