#pragma once
#include<iostream>
#include"clsCurrency.h";
#include"clsInputValidate.h";
#include"clsScreen.h";
using namespace std;

class clsCurrencyCalculatorScreen:protected clsScreen
{
	static clsCurrency _ReadCurrencyCode(string Message)
	{
		string CurrencyCode;
		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExisteByCode(CurrencyCode))
		{
			cout << "\nNot found, " << Message;
			CurrencyCode = clsInputValidate::ReadString();
		}
		return clsCurrency::FindByCode(CurrencyCode);
	}
	static float _ReadAmount()
	{
		cout << "\nEnter amount to exchange: ";
		return clsInputValidate::ReadFloatNumber();
	}
	static void _PrintCurrencyInfo(clsCurrency Currency)
	{
		cout << "\n**********************************\n";
		cout << "Country: " << Currency.Country() << endl;
		cout << "Code: " << Currency.CurrencyCode() << endl;
		cout << "Name: " << Currency.CurrencyName() << endl;
		cout << "Rate(1$): " << Currency.Rate();
		cout << "\n**********************************\n";
	}
	static void _PrintCalculationResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		cout << "\nConvert from:";
		_PrintCurrencyInfo(CurrencyFrom);

		float AmountInDollar = CurrencyFrom.ConvertToUSD(Amount);
		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInDollar << " USD" << endl;

		if (CurrencyTo.CurrencyCode() != "USD")
		{
			cout << "\nConverting from USD to " << CurrencyTo.CurrencyCode();
			_PrintCurrencyInfo(CurrencyTo);

			float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = ";
			cout << AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode() << endl;
		}
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'n';
		do
		{
			system("cls");
			clsScreen::_DrawScreenHeader("Currency calculator screen");
			clsCurrency CurrencyFrom = _ReadCurrencyCode("\nPlease enter currency1 code from: ");
			clsCurrency CurrencyTo = _ReadCurrencyCode("\nPlease enter currency2 code To: ");
			float Amount = _ReadAmount();
			_PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);
			Answer = clsInputValidate::ReadAnswer("\nDo you want perform another calculation? Y/N? ");
		} while (tolower(Answer) == 'y');
		
	}

};

