#pragma once

#include <iostream>
#include <string>
#include"clsDate.h";
#include <cstdlib>
using namespace std;

class clsUtil
{
public:

	static int ReverseNumbers(int Number)
	{
		// Number = 1234
		int Remainder = 0;
		int Number2 = 0;
		while (Number > 0) // 12321 > 0 ? | 1232 > 0 ? ....
		{
			Remainder = Number % 10; // 12321 % 10 = 1 | 1232 % 10 = 2
			Number /= 10; // 12321 / 10 = 1232 | 1232 / 10 = 123 ....
			Number2 = Number2 * 10 + Remainder;
			// 0 * 10 + 1 = 1 | 1 * 10 + 2 = 12 ....
		}
		return Number2;// Number2 = 12321
	}
	static bool IsPalindromeNumbers(int Number)
	{
		// Number = 12321
		// Number = 1234
		return Number == ReverseNumbers(Number);
		// 12321 == 12321 ? true , ( 1234 == 4321 ? false )
	}
	static string EncryptText(string Text, short EncryptionKey)
	{
		// Text = Saeed
		// EncryptionKey = 2 
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text; // Ucggf
    }
    static string DecryptText(string Text, short EncryptionKey)
    {
		for (int i = 0; i <= Text.length(); i++)
		{
		
			Text[i] = char((int)Text[i] - EncryptionKey);
	
		}
	
		return Text; // Saeed
    }
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To)
	{
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}
	static enum enCharTypes
	{
		SmallLetter = 1, CapitalLetter = 2, Digit = 3, /*SpecialChars = 4,*/ MixChars = 5
	};
	static char GetRandomCharacter(enCharTypes CharType)
	{
		if (CharType == enCharTypes::MixChars)
			CharType = enCharTypes(RandomNumber(1, 3));

		switch (CharType)
		{
		case enCharTypes::SmallLetter:
		{
			return char(RandomNumber(97, 122)); // char( 110 ) = n
			break;
		}
		case enCharTypes::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		//case enCharTypes::SpecialChars:
		//{
		//	return char(RandomNumber(33, 47));
		//	break;
		//}
		case enCharTypes::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		}

	}
	static string GenerateWord(enCharTypes CharType, short Wordlength)
	{
		string Word;
		for (int i = 1; i <= Wordlength; i++) // 1 <= 4 ? | 2 <= 4 ...
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey(enCharTypes CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}
	static void GenerateKeys(short NumberOfKeys, enCharTypes CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Kay [" << i << "] : " << GenerateKey(CharType) << endl;
		}
	}
	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(string& A, string & B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate::SwapDates(Date1, Date2);
	}
	static void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1,
				arrLength) - 1]);
		}
	}
	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1,
				arrLength) - 1]);
		}
	}
	static void FillArrayWithRandomNumbers(int arr[100], int arrLength,short From,short To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}
	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharTypes CharType, short Length)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Length);
	}
	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharTypes CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}
	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}
	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

};

