#pragma once
#include"clsCurrency.h"
#include"clsScreen.h";
#include"clsInputValidate.h"


class clsFindCurrencyScreen :protected clsScreen
{
	enum enMethodToFindCurrency { eByCode = 1, eByCountry = 2 };

	static short _ReadMethodChoice()
	{
		cout << "\nFind by: [1] Code or [2] Country ? ";
		short Choice;
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2);
		return Choice;
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

	static clsCurrency _ReadCountryName()
	{
		cout << "\nPlease enter country name: ";
		string Country = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExisteByCountry(Country))
		{
			cout << "\nNot found, Please enter another country name: ";
			Country = clsInputValidate::ReadString();
		}
		return clsCurrency::FindByCountry(Country);
	}

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

public:

	static void ShowFindCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("Find currency screen");
		enMethodToFindCurrency MethodToFindCurrency =
			enMethodToFindCurrency(_ReadMethodChoice());

		switch (MethodToFindCurrency)
		{
		case clsFindCurrencyScreen::eByCode:
			_PrintCurrencyInfo(_ReadCurrencyCode());
			break;
		case clsFindCurrencyScreen::eByCountry:
			_PrintCurrencyInfo(_ReadCountryName());
			break;
		}
	}
};

