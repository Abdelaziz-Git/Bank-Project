#pragma once
#include<iostream>
#include"clsCurrency.h";
#include"clsScreen.h";
#include"clsInputValidate.h";

class clsUpdateCurrencyScreen:protected clsScreen
{
	static clsCurrency _ReadCurrencyCode()
	{
		string CurrencyCode;
		cout << "\nPlease enter currency code: ";
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExisteByCode(CurrencyCode))
		{
			cout << "\nNot found, Please enter another currency code: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		return clsCurrency::FindByCode(CurrencyCode);
	}

	static void _PrintCurrencyInfo(clsCurrency Currency)
	{
		cout << "\nCurrency card:";
		cout << "\n**********************************\n";
		cout << "Country: " << Currency.Country() << endl;
		cout << "Code: " << Currency.CurrencyCode() << endl;
		cout << "Name: " << Currency.CurrencyName() << endl;
		cout << "Rate(1$): " << Currency.Rate();
		cout << "\n**********************************\n";
	}

	static float _ReadNewRate()
	{
		cout << "\nUpdate currency Rate:";
		cout << "\n-------------------------\n";
		cout << "Enter New Rate: ";
		return clsInputValidate::ReadFloatNumber();
	}

public:
	static void ShowUpdateCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("Update currency screen");
		clsCurrency Currency = _ReadCurrencyCode();
		_PrintCurrencyInfo(Currency);
		char Answer = clsInputValidate::ReadAnswer
		("\nAre you sure do you want update the rate of this currency? Y/N? ");
		if (tolower(Answer) == 'y')
		{
			Currency.UpdateRate(_ReadNewRate());
			cout << "\nCurrency rate update successfullu!";
			_PrintCurrencyInfo(Currency);
		}
	}
};

