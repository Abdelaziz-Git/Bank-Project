#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsCurrency.h";
#include"clsInputValidate.h";
#include"clsCurrencyListScreen.h";
#include"clsFindCurrencyScreen.h";
#include"clsUpdateCurrencyScreen.h";
#include"clsCurrencyCalculatorScreen.h";
class clsCurrencyExchangeScreen:protected clsScreen
{
	enum enCurrencyExchangeMenue 
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		CurrencyCalculatore = 4, eMainMenue = 5
	};

	static void _ShowListCurrenciesScrenn()
	{
		//cout << "\nListCurrenciesScrenn.........\n\n";
		clsCurrencyListScreen::_ShowCurrencyListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFindScrenn.........\n\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate rate Screnn.........\n\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatoreScreen()
	{
		//cout << "\n_ShowCurrencyCalculatoreScreen.........\n\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\nPress any key to go back to currency exchange menue...";
		system("pause>0");
		_ShowCarrencyExchangeMenueScreen();
	}

	static void _PerformCurrencyExchangeMenueOptions(enCurrencyExchangeMenue ReadCurrencyExchangeMenue)
	{
		switch (ReadCurrencyExchangeMenue)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScrenn();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeScreen::CurrencyCalculatore:
			system("cls");
			_ShowCurrencyCalculatoreScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeScreen::eMainMenue:
			break;
		}
	}

	static short _ReadCurrencyExchangeOptions()
	{
		cout << "\n" << setw(40) << left << "";
		cout << "Choose whate do you want to do? [1--5]? ";
		return clsInputValidate::ReadShortNumberBetween(1, 5);
	}

public:
	static void _ShowCarrencyExchangeMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("Currency exchange menue");

		cout << "\n" << setw(40) << left << "" << "=========================================";
		cout << "\n" << setw(40) << left << "" << "\tMain menue";
		cout << "\n" << setw(40) << left << "" << "=========================================";
		cout << "\n" << setw(40) << left << "" << "[1] List currencies.";
		cout << "\n" << setw(40) << left << "" << "[2] Find currency.";
		cout << "\n" << setw(40) << left << "" << "[3] Update Rate.";
		cout << "\n" << setw(40) << left << "" << "[4] Carrency calculatore.";
		cout << "\n" << setw(40) << left << "" << "[5] Main.";
		cout << "\n" << setw(40) << left << "" << "=========================================\n";
		_PerformCurrencyExchangeMenueOptions(enCurrencyExchangeMenue(_ReadCurrencyExchangeOptions()));
	}
};

