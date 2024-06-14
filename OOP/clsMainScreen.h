#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"clsClientsListScreen.h";
#include"clsAddNewClientScreen.h";
#include"clsDeleteClientScreen.h";
#include"clsUpdateClientScreen.h";
#include"clsFindClientScreen.h";
#include"clsTransactionsScreen.h";
#include"clsManageUsersScreen.h";
#include"clsLoginRegisterScreen.h";
#include"Global.h";
#include"clsCurrencyExchangeScreen.h";
using namespace std;

class clsMainScreen:protected clsScreen
{
	enum enMainMenueOptions {
		eShowClientsList = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eTransactios = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10
	};

	static void _ShowClientsListScreen() {
		//cout << "Client list will be here.......\n";
		clsClientsListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen() {
		//cout << "Add new Client will be here.......\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen() {
		//cout << "Delete Client will be here.......\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {
		//cout << "Update Client will be here.......\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen() {
		//cout << "Find Client will be here.......\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen() {
		//cout << "Transactios will be here.......\n";
		clsTransactionsScreen::ShowTransactionsMenueScreen();
	}

	static void _ShowManageUsersScreen() {
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen() {
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		//cout << "\nCurrency Exchange will be here.......?//\n";
		clsCurrencyExchangeScreen::_ShowCarrencyExchangeMenueScreen();
	}

	static void _Logout() {
		CurrentUser = clsUser::Find("", "");
	}

	static void _GoBackToMainMenue() {
		cout << "\nPress any key to go back to main menue....";
		system("pause>0");
		ShowMainMenueScreen();
	}

	static void  _PerformMainMenueOptions(enMainMenueOptions MainMenueOptions) {
		switch (MainMenueOptions)
		{
		case clsMainScreen::eShowClientsList:
			system("cls");
			_ShowClientsListScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eTransactios:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
		case clsMainScreen::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
		case clsMainScreen::eLogout:
			system("cls");
			_Logout();
			break;
		}
	}

	static short _ReadMainMenueOptions() {
		short UserChoise = 1;
		cout << "\n" << setw(40) << left << "";
		cout << "Choose what do you want to do? [1---10]? ";
		UserChoise = clsInputValidate::ReadShortNumberBetween(1, 10);
		return UserChoise;
	}

public:
	static void ShowMainMenueScreen() {
		system("cls");
		_DrawScreenHeader("Main screen");

		cout << "\n" << setw(40) << left << "" << "=========================================";
		cout << "\n" << setw(40) << left << "" << "\tMain menue";
		cout << "\n" << setw(40) << left << "" << "=========================================";
		cout << "\n" << setw(40) << left << "" << "[1] Show clients list.";
		cout << "\n" << setw(40) << left << "" << "[2] Add new client.";
		cout << "\n" << setw(40) << left << "" << "[3] Delete client.";
		cout << "\n" << setw(40) << left << "" << "[4] Update client.";
		cout << "\n" << setw(40) << left << "" << "[5] Find client.";
		cout << "\n" << setw(40) << left << "" << "[6] Transactios.";
		cout << "\n" << setw(40) << left << "" << "[7] Manage users.";
		cout << "\n" << setw(40) << left << "" << "[8] Login register.";
		cout << "\n" << setw(40) << left << "" << "[9] Currency exchange.";
		cout << "\n" << setw(40) << left << "" << "[10] Logout.";
		cout << "\n" << setw(40) << left << "" << "=========================================\n";

		_PerformMainMenueOptions(enMainMenueOptions(_ReadMainMenueOptions()));
	}

};

