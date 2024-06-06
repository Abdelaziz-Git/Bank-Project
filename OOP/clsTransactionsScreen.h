#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsMainScreen.h";
#include"clsDepositScreen.h";
#include"clsWithdrawScreen.h";
#include"clsTotalBalancesScreen.h";
#include"clsTransferScreen.h";
#include"clsTransferLogListScreen.h";
using namespace std;

class clsTransactionsScreen:protected clsScreen
{
	enum enTransactionsMenue {
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,
		eTransfer = 4, eTransferLog = 5, eMainMenue = 6
	};

	static void _ShowDepositScreen() {
		//cout << "Deposit screen will be here!!!!!!!!!\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		//cout << "Withdraw screen will be here!!!!!!!!!\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		//cout << "Total balances screen will be here!!!!!!!!!\n";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen() {
		//cout << "\nTransfer screen will be here...\n";
		clsTransferScreen::_ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\nTransfer log will be here.....\n";
		clsTransferLogListScreen::ShowTransferLogListScreen();
	}

	static void _GoBackToTransactionsMenue() {
		cout << "\nPress any key to go back to transactions menue....";
		system("pause>0");
		ShowTransactionsMenueScreen();
	}

	static short _ReadTransactionsMenueOptions() {
		short UserChoise = 1;
		cout << "\n" << setw(40) << left << "";
		cout << "Choose what do you want to do? [1---6]? ";
		UserChoise = clsInputValidate::ReadShortNumberBetween(1, 6);
		return UserChoise;
	}

	static void _PerformTransactionsMenueOptions(enTransactionsMenue TransactionsMenue) {
		switch (TransactionsMenue)
		{
		case clsTransactionsScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
		case clsTransactionsScreen::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
		case clsTransactionsScreen::eMainMenue:
			break;
		}
	}

public:
	static void ShowTransactionsMenueScreen() {
		if (!clsScreen::CheekAccessRights(clsUser::pTransactions)) {
			return;
		}
		system("cls");
		clsScreen::_DrawScreenHeader("Transactions screen");
		cout << "\n" << setw(40) << left << "" << "==================================";
		cout << "\n" << setw(40) << left << "" << "\tTransactions menue";
		cout << "\n" << setw(40) << left << "" << "==================================";
		cout << "\n" << setw(40) << left << "" << "[1] Deposit.";
		cout << "\n" << setw(40) << left << "" << "[2] Withdraw.";
		cout << "\n" << setw(40) << left << "" << "[3] Total balances.";
		cout << "\n" << setw(40) << left << "" << "[4] Transfer.";
		cout << "\n" << setw(40) << left << "" << "[5] Transfer Log.";
		cout << "\n" << setw(40) << left << "" << "[6] Main menue.";
		cout << "\n" << setw(40) << left << "" << "==================================\n";
		_PerformTransactionsMenueOptions(enTransactionsMenue(_ReadTransactionsMenueOptions()));
	}

};

