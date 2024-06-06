#pragma once
#include"clsBankClient.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
class clsTransferScreen:protected clsScreen
{
	static void _PrintClientCard(clsBankClient Client) {
		cout << "\nClient card";
		cout << "\n************************************";
		cout << "\nFull name: " << Client.FullName();
		cout << "\nAccount number: " << Client.AccountNumber();
		cout << "\nAccount balance: " << Client.AccountBalance;
		cout << "\n************************************";
	}
	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber;
		cout << Message;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}
	static double _ReadAmount(clsBankClient SourceClient)
	{
		double TransferAmount;
		cout << "\n\nEnter transfer amount: ";
		TransferAmount = clsInputValidate::ReadDBLNumber();
		while (TransferAmount > SourceClient.AccountBalance)
		{
			cout << "\nAmount exceeds the available balance!\nPlease enter another amount:";
			TransferAmount = clsInputValidate::ReadDBLNumber();
		}
		return TransferAmount;
	}

public:
	static void _ShowTransferScreen() {
		//Header
		clsScreen::_DrawScreenHeader("     Transfer screen");

		//Client transfer from
		clsBankClient SourceClient = clsBankClient::
			Find(_ReadAccountNumber("\nPlease enter client account number to transfer From: "));
		_PrintClientCard(SourceClient);

		//Client transfer To
		clsBankClient DestinationClient = clsBankClient::
			Find(_ReadAccountNumber("\nPlease enter client account number to transfer From: "));
		_PrintClientCard(DestinationClient);

		double TransferAmount = _ReadAmount(SourceClient);

		//Operation...
		char Answer = clsInputValidate::
			ReadAnswer("\nAre you sure do you want perform this transfer? y/n? ");
		
		if (tolower(Answer) == 'y')
		{
			
			if (SourceClient.Transfer(TransferAmount,DestinationClient))
			{
				cout << "\nTransfer done successfully.\n";
				_PrintClientCard(SourceClient);
				_PrintClientCard(DestinationClient);
			}
			else
			{
				cout << "\nError transfer, please tree in another time!";
			}
			
		}

	}
};

