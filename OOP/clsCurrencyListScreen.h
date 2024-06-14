#pragma once
#include"clsCurrency.h";
#include"clsScreen.h";
#include<iomanip>

class clsCurrencyListScreen:protected clsScreen
{
	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << setw(15) << left << "";
		cout << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
		cout << "|";

	}
	static void _CurrencyListTableHeader()
	{
		cout << setw(15) << left << "";
		cout << "| " << setw(30) << left << "Country";
		cout << "| " << setw(8) << left << "Code";
		cout << "| " << setw(40) << left << "Name";
		cout << "| " << setw(10) << left << "Rate/(1$)";
		cout << "|";
	}

public:
	static void _ShowCurrencyListScreen()
	{
		vector<clsCurrency>vCurrencys = clsCurrency::GetCurrenciesList();
		string Title = "Currencies List Screen";
		string SubTitle = "(" + to_string(vCurrencys.size()) + ") Currency(s)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << endl << setw(15) << left << "";
		cout << "***********************************************************************" <<
			"**************************\n";

		_CurrencyListTableHeader();

		cout << endl << setw(15) << left << "";
		cout << "***********************************************************************" <<
			"**************************\n";

		if (vCurrencys.empty())
		{
			cout << "\n\t\t\t\tNo Available currency in the system\n";
		}
		else
		{
			for (clsCurrency& Cureency : vCurrencys)
			{
				_PrintCurrencyRecord(Cureency);
				cout << endl;
			}
		}
		cout << setw(15) << left << "";
		cout << "*************************************************************************" <<
			"************************\n";
	}
};

