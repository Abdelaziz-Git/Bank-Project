#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"
using namespace std;

class clsCurrency
{
	enum enMode { eEmptyMode = 1, eUpdateMode = 2 };
	enMode _Mode;
	string _Country = "";
	string _CurrencyCode = "";
	string _CurrencyName = "";
	float _Rate = 0;

	static clsCurrency _ConvertLineToCurrecyObject(string Line, string Seperator = "#//#")
	{
		vector<string>CurrencyRecord = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::eUpdateMode,CurrencyRecord[0], CurrencyRecord[1],
			CurrencyRecord[2], stof(CurrencyRecord[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency,string Seperator="#//#")
	{
		string CurrencyLine = "";
		CurrencyLine += Currency.Country() + Seperator;
		CurrencyLine += Currency.CurrencyCode() + Seperator;
		CurrencyLine += Currency.CurrencyName() + Seperator;
		CurrencyLine += to_string(Currency.Rate());
		return CurrencyLine;
	}

	static vector<clsCurrency>_LoadCurrencysDataFromFile()
	{
		vector<clsCurrency>vCurrencys;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsCurrency Currency = _ConvertLineToCurrecyObject(Line);
				vCurrencys.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencys;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrencys)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			string Line;
			for (clsCurrency& Currency : vCurrencys)
			{
				Line = _ConvertCurrencyObjectToLine(Currency);
				MyFile << Line << endl;
			}
			MyFile.close();
		}
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::eEmptyMode,"", "", "", 0);
	}

	void _Update()
	{
		vector<clsCurrency>vCurrencys = _LoadCurrencysDataFromFile();
		for (clsCurrency& CurrencyFile : vCurrencys)
		{
			if (CurrencyFile.Country() == _Country && CurrencyFile.CurrencyCode() == _CurrencyCode)
			{
				CurrencyFile = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencys);
	}

public:
	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	bool IsEmpty()
	{
		return _Mode == enMode::eEmptyMode;
	}

	static vector<clsCurrency>GetAllUSDRates()
	{
		return _LoadCurrencysDataFromFile();
	}

	static   clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrecyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static   clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrecyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExisteByCode(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return !Currency.IsEmpty();
	}

	static bool IsCurrencyExisteByCountry(string CountryName)
	{
		clsCurrency Currency = FindByCountry(CountryName);
		return !Currency.IsEmpty();
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}
	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2To)
	{
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2To.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		return (float)(AmountInUSD * Currency2To.Rate());
	}
};

