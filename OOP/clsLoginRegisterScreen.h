#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsString.h";
#include<iomanip>
class clsLoginRegisterScreen:protected clsScreen
{
	static void _PrintLogInRegisterRecord(clsUser::stLoginRegisterRecord LoginRegisterRecord) {
		cout << "| " << setw(22) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(12) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(12) << left << LoginRegisterRecord.Permissions;
		cout << "|";
	}

public:
	static void ShowLoginRegisterScreen() {
		if (!clsScreen::CheekAccessRights(clsUser::pLoginRegister)) {
			return;
		}

		vector<clsUser::stLoginRegisterRecord>vLoginRegisterList = clsUser::GetLogInRegisterList();
		string Title = "Login register list screen";
		string SubTitle = "(" + to_string(vLoginRegisterList.size()) + ") Record(s).";
		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << "\n\t\t\t\t-----------------------------------------------------------------\n";
		cout << "\t\t\t\t| " << setw(22) << left << "Date/Time";
		cout << "| " << setw(12) << left << "User Name";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions";
		cout << "|";
		cout << "\n\t\t\t\t-----------------------------------------------------------------\n";
		for (clsUser::stLoginRegisterRecord& Record : vLoginRegisterList) {
			cout << "\t\t\t\t";
			_PrintLogInRegisterRecord(Record);
			cout << "\n";
		}
		cout << "\t\t\t\t-----------------------------------------------------------------";
		cout << endl;
	}
};

