#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"clsPerson.h";
#include"clsString.h";

using namespace std;

const string FileName = "Clients.txt";

class clsClient :public clsPerson
{
private :
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;
	
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	static clsClient _ConvertLineToClientObject(string Line,string Seperator="#//#")
	{
		vector<string>vClientRecord;
		vClientRecord = clsString::Split(Line, Seperator);

		return clsClient(enMode::UpdateMode, vClientRecord[0], vClientRecord[1], vClientRecord[2], vClientRecord[3],
			vClientRecord[4], vClientRecord[5], stof(vClientRecord[6]));
	}

	static string _ConvertClientObjectToLine(clsClient Client, string Seperator = "#//#")
	{
		string ClientRecord = "";
		ClientRecord += Client.FirstName + Seperator;
		ClientRecord += Client.LastName + Seperator;
		ClientRecord += Client.Email + Seperator;
		ClientRecord += Client.Phone + Seperator;
		ClientRecord += Client.AccountNumber() + Seperator;
		ClientRecord += Client.PinCode + Seperator;
		ClientRecord += to_string(Client.AccountBalance);
		return ClientRecord;

	}

	static vector<clsClient>_LoadClientDataFromFile()
	{
		vector<clsClient>vClients;
		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector<clsClient>vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsClient &c : vClients)
			{
				if (c._MarkForDelete == false) {
					Line = _ConvertClientObjectToLine(c);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsClient>vClients;
		vClients = _LoadClientDataFromFile();

		for (clsClient& C : vClients)
		{
			if (C.AccountNumber() == this->_AccountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
	}

	static clsClient _GetEmptyObjectClient()
	{
		return clsClient(enMode::EmptyMode, "", "", "", "", "", "",0);
	}

	static void _AddDataLineToFile(string Line) {
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << Line << endl;
			MyFile.close();
		}
	}

	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _PreparTransferLogRecord(double TransferAmount, clsClient DestinationClient, 
		string UserName, string Seperator = "#//#")
	{
		string DataLine = "";
		DataLine += clsDate::GetSystemDateTimeString() + Seperator;
		DataLine += _AccountNumber + Seperator;
		DataLine += DestinationClient.AccountNumber() + Seperator;
		DataLine += to_string(TransferAmount) + Seperator;
		DataLine += to_string(_AccountBalance) + Seperator;
		DataLine += to_string(DestinationClient.AccountBalance) + Seperator;
		DataLine += UserName;
		return DataLine;
	}
	
	void _RegisterTransferLogDataLine(clsClient DestinationClient, double TransferAmount,
		string UserName, string Seperator = "#//#")
	{
		string DataLine = _PreparTransferLogRecord(TransferAmount, DestinationClient, UserName, Seperator);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogDataLineToRecord(string Line,string Seperator="#//#")
	{
		vector<string>vTransferLogRecord = clsString::Split(Line);
		stTransferLogRecord TransferLogRecord;
		TransferLogRecord.DateTime = vTransferLogRecord[0];
		TransferLogRecord.SourceClientAccNumber= vTransferLogRecord[1];
		TransferLogRecord.DestinationClientAccNumber = vTransferLogRecord[2];
		TransferLogRecord.TransferAmount = stod(vTransferLogRecord[3]);
		TransferLogRecord.SourceClientAccBalance = stod(vTransferLogRecord[4]);
		TransferLogRecord.DestinationClientAccBalance = stod(vTransferLogRecord[5]);
		TransferLogRecord.UserName = vTransferLogRecord[6];
		return TransferLogRecord;
	}

public :
	clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber,
		string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone){
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_Mode = Mode;
	}
	struct stTransferLogRecord
	{
		string DateTime = "";
		string SourceClientAccNumber = "";
		string DestinationClientAccNumber = "";
		double TransferAmount = 0;
		double SourceClientAccBalance = 0;
		double DestinationClientAccBalance = 0;
		string UserName = "";
	};

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalace)
	{
		_AccountBalance = AccountBalace;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	void Print()
	{
		cout << "\nClient card:\n";
		cout << "\n________________________________________\n";
		cout << "\nFirst name    :" <<FirstName;
		cout << "\nLast name     :" << LastName;
		cout << "\nEmail         :" << Email;
		cout << "\nPone          :" << Phone;
		cout << "\nAcc. Number   :" << AccountNumber();
		cout << "\nPassword      :" << PinCode;
		cout << "\nAccount balane:" << AccountBalance;
		cout << "\n________________________________________\n";

	}

	bool isEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsClient Find(string AccountNumber)
	{
	
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyObjectClient();
	}

	static clsClient Find(string AccountNumber, string Password)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsClient Client = _ConvertLineToClientObject(Line);
				if ((Client.AccountNumber() == AccountNumber) && (Client.PinCode == Password))
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyObjectClient();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsClient Client1 = clsClient::Find(AccountNumber);

		return (!Client1.isEmpty());
	}

	bool IsClientExist()
	{
		return IsClientExist(_AccountNumber);
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2 };

	static clsClient GetAddNewClientObject(string AccountNumber) {
		return clsClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsClient::EmptyMode:

			return enSaveResults::svFaildEmptyObject;

		case clsClient::UpdateMode:

			_Update();
			return enSaveResults::svSucceeded;

		case clsClient::AddNewMode:
			if (IsClientExist(_AccountNumber)) {
				return enSaveResults::svFaildAccountNumberExist;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
	}

	bool Delete() {
		vector<clsClient>vClients = _LoadClientDataFromFile();
		for (clsClient& C : vClients) {
			if (C.AccountNumber() == this->AccountNumber()) {
				C._MarkForDelete = true;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyObjectClient();
		return true;
	}

	static vector<clsClient>GetClientsList() {
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances() {
		vector <clsClient>vClients = GetClientsList();
		double TotalBalances = 0;
		for (clsClient Client : vClients) {
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	bool Deposit(double Amount) {
		_AccountBalance += Amount;
		switch (Save())
		{
		case clsClient::svFaildEmptyObject:
			return false;
		case clsClient::svSucceeded:
			return true;
		case clsClient::svFaildAccountNumberExist:
			return false;
		}
	}

	bool Withdraw(double Amount) {
		if (Amount > _AccountBalance) {
			return false;
		}
		else {
			this->_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double Amount, clsClient& DestinationClient)
	{
		if (Amount > this->AccountBalance) {
			return false;
		}
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLogDataLine(DestinationClient, Amount, CurrentUser.UserName);
		return true;
	}

	static vector<stTransferLogRecord> GetTransferLogList()
	{
		fstream MyFile;
		vector<stTransferLogRecord>vTrasfersLogRecords;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open())
		{
			string stLine;
			while (getline(MyFile,stLine))
			{
				stTransferLogRecord TransferLogRecord = _ConvertTransferLogDataLineToRecord(stLine);
				vTrasfersLogRecords.push_back(TransferLogRecord);
			}
			MyFile.close();
		}
		return vTrasfersLogRecords;
	}
};

