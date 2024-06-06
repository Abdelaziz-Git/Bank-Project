#pragma once
#include<iostream>
#include<iomanip>
#include"Global.h";
#include"clsUser.h";
#include"clsDate.h";

using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle="") {
		cout << setw(40) << left << "";
		cout << "_________________________________________\n\n";
		cout << setw(40) << left << "";
		cout << "\t" << Title;
		if (SubTitle != "") {
			cout << endl << setw(40) << left << "";
			cout << "\t" << SubTitle;
		}
		cout << endl << setw(40) << left << "";
		cout << "_________________________________________\n";

		cout << endl << setw(40) << left << "";
		cout << "User: " << CurrentUser.UserName;

		cout << endl << setw(40) << left << "";
		clsDate Date;
		cout << "Date: " << Date.DateToString() << endl;

	}

	static bool CheekAccessRights(clsUser::enPermissions Permissions) {
		if (!CurrentUser.CheekAccessPermissions(Permissions)) {
			cout << setw(40) << left << "";
			cout << "_____________________________________________________________________\n\n";

			cout << setw(40) << left << "";
			cout << "               Access denied, contact your admin!";

			cout << endl << setw(40) << left << "";
			cout << "_____________________________________________________________________\n";
			return false;
		}
		else
		{
			return true;
		}
	}
};

