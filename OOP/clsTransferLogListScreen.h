#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsClient.h";
class clsTransferLogListScreen:protected clsScreen
{
	static void _PrintTransferLogListTableHeader()
	{
		cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		cout << "| " << setw(20) << left << "Date/Time";
		cout << "| " << setw(16) << left << "S.Acc.Number";
		cout << "| " << setw(16) << left << "D.Acc.Number";
		cout << "| " << setw(10) << left << "Amount";
		cout << "| " << setw(16) << left << "S.Acc.Balance";
		cout << "| " << setw(16) << left << "D.Acc.Balance";
		cout << "| " << setw(10) << left << "UserName" << " |";
		cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	}
	static void _PrintTransferLogRecord(clsClient::stTransferLogRecord TransferLogRecord)
	{
		cout << "| " << setw(20) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(16) << left << TransferLogRecord.SourceClientAccNumber;
		cout << "| " << setw(16) << left << TransferLogRecord.DestinationClientAccNumber;
		cout << "| " << setw(10) << left << TransferLogRecord.TransferAmount;
		cout << "| " << setw(16) << left << TransferLogRecord.SourceClientAccBalance;
		cout << "| " << setw(16) << left << TransferLogRecord.DestinationClientAccBalance;
		cout << "| " << setw(10) << left << TransferLogRecord.UserName << " |";
	}
public:
	static void ShowTransferLogListScreen()
	{
		vector<clsClient::stTransferLogRecord>vTransfersLogRecords;
		vTransfersLogRecords = clsClient::GetTransferLogList();
		string Title = "Transfer log list screen";
		string SubTitle = "( " + to_string(vTransfersLogRecords.size()) + ") Record(s).";
		clsScreen::_DrawScreenHeader(Title, SubTitle);
		_PrintTransferLogListTableHeader();
		if (vTransfersLogRecords.empty())
		{
			cout << "\t\tNo transfers avaible in the system.";
			cout << endl;
		}
		else
		{
			for (clsClient::stTransferLogRecord& TransferLogRecord : vTransfersLogRecords)
			{
				_PrintTransferLogRecord(TransferLogRecord);
				cout << endl;
			}
		}
		
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
			<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	}
};

