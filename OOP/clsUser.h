#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"clsPerson.h";
#include"clsString.h";
#include"clsDate.h";
#include"clsUtil.h";

const string FileUser = "Users.txt";
const string FileLogin = "LoginRegister.txt";

class clsUser :public clsPerson
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2, AddNewMode = 3 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkForDeleted = false;

	static clsUser _ConvertLineToUserObject(string Line) 
	{
		vector<string>vUser = clsString::Split(Line);
		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4],
			clsUtil::DecryptText(vUser[5]), stoi(vUser[6]));
	}
	static clsUser _GetEmptyObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static string _ConvertObjectUserToDataLine(clsUser User) {
		string Line = "";
		Line += User.FirstName + "#//#";
		Line += User.LastName + "#//#";
		Line += User.Email + "#//#";
		Line += User.Phone + "#//#";
		Line += User.UserName + "#//#";
		Line += clsUtil::EncryptText(User.Password) + "#//#";
		Line += to_string(User.Permissions);
		return Line;
	}
	static vector<clsUser>_LoadDataFromFileToVectorUsers() {
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open(FileUser, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
			return vUsers;
		}
	}
	static void _SaveUsersDataToFile(vector<clsUser>vUsers) {
		fstream MyFile;
		MyFile.open(FileUser, ios::out);
		if (MyFile.is_open()) {
			string Line;
			for (clsUser User : vUsers) {
				if (User._MarkForDeleted!=true) {
					Line = _ConvertObjectUserToDataLine(User);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}
	static void _AddDataLineObjectToFie(string Line) {
		fstream MyFile;
		MyFile.open(FileUser, ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << Line << endl;
			MyFile.close();
		}
	}
	void _AddNew() {
		_AddDataLineObjectToFie(_ConvertObjectUserToDataLine(*this));
	}
	void _Update() {
		vector<clsUser>vUsers = _LoadDataFromFileToVectorUsers();
		for (clsUser& User : vUsers) {
			if (User.UserName == this->UserName) {
				User = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);

	}
	string _ConvertDataLoginToDataLine(string Seperator="#//#") 
	{
		clsDate Date;
		string DataLoginLine = "";
		DataLoginLine = Date.DateToString() + " - " + Date.PrintSystemTime() + Seperator;
		DataLoginLine += UserName + Seperator;
		DataLoginLine += clsUtil::EncryptText(Password) + Seperator;
		DataLoginLine += to_string(Permissions);
		return DataLoginLine;
	}
	void _AddDataLineLoginToFile(string Line) {
		fstream MyFile;
		MyFile.open(FileLogin, ios::app | ios::out);
		if (MyFile.is_open()) {
			MyFile << Line << endl;
			MyFile.close();
		}
	}
	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line,string Seperator="#//#") 
	{
		vector<string>vLoginRegisterDataLine = clsString::Split(Line, Seperator);
		stLoginRegisterRecord LoginRegisterRecord;
		LoginRegisterRecord.DateTime = vLoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = vLoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(vLoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions = stoi(vLoginRegisterDataLine[0]);
		return LoginRegisterRecord;
	}
public:
	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissions) :clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	static struct stLoginRegisterRecord {
		string DateTime = "";
		string UserName = "";
		string Password = "";
		short Permissions = 0;
	};

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkForDeleted() {
		return _MarkForDeleted;
	}

	string GetUserName() {
		return _UserName;
	}

	void SetUserName(string UserName){
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	string GetPassword() {
		return _Password;
	}

	void SetPassword(string Password) {
		_Password = Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	int GetPermissions() {
		return _Permissions;
	}

	void SetPermissions(int Permissions) {
		_Permissions = Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	static clsUser Find(string UserName) {
		fstream MyFile;
		MyFile.open(FileUser, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName) {
				    MyFile.close();
				    return User;
				}
			}
			MyFile.close();
			return _GetEmptyObject();
		}
	}

	static clsUser Find(string UserName, string Password) {
		fstream MyFile;
		MyFile.open(FileUser, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
			
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password) {
					MyFile.close();
					return User;
				}
				
			}
			MyFile.close();
			return _GetEmptyObject();
		}
	}

	static bool IsUserExist(string UserName) {
		clsUser User = clsUser::Find(UserName);
		return !User.IsEmpty();
	}

	bool IsUserExist()
	{
		return IsUserExist(_UserName);
	}

	bool Delete() {
		vector<clsUser>vUsers = _LoadDataFromFileToVectorUsers();
		for (clsUser &User : vUsers) {
			if (User.UserName == this->UserName) {
				User._MarkForDeleted = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyObject();
		return true;
	}

	static clsUser GetAddNewUserObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	enum enSaveResults { svFaildEmptyObject = 1, svSucceeded = 2, svFaildUserExist = 3 };
	enSaveResults Save() {
		switch (_Mode)
		{
		case clsUser::EmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case clsUser::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
		
		case clsUser::AddNewMode:
			if (clsUser::IsUserExist(_UserName)) {
				return enSaveResults::svFaildUserExist;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}			
		}
	}

	static vector<clsUser>GetUsersList() {
		return _LoadDataFromFileToVectorUsers();
	}

	enum enPermissions {
		pAll = -1, pClientsList = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8,
		pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLoginRegister = 128
	};

	bool CheekAccessPermissions(enPermissions Permission) {
		if (Permission == enPermissions::pAll) {
			return true;
		}
		if ((this->Permissions & Permission) == Permission)
			return true;
		else
			return false;
	}

	void RegisterLogIn() {
		_AddDataLineLoginToFile(_ConvertDataLoginToDataLine());
	}

	static vector<stLoginRegisterRecord>GetLogInRegisterList() {
		fstream MyFile;
		MyFile.open(FileLogin, ios::in);
		if (MyFile.is_open())
		{
			string Line;
			stLoginRegisterRecord LoginRegisterRecord;
			vector<stLoginRegisterRecord>vLoginRegisterRecord;
			while (getline(MyFile,Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}
			MyFile.close();
			return vLoginRegisterRecord;
		}
	}

};

