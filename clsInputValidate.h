#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

// Input Validation Library - 10/1/2025 - Course#11 - Developer: Mr.Key47

class clsInputValidate
{
public:
	template <typename DataType> static bool IsNumberBetween(DataType Number, DataType From, DataType To)
	{
		return (Number >= From && Number <= To);
	}

	template <typename DataType> static DataType ReadNumber(string ErrorMessage = "\nInvalid input, Enter a number:\n")
	{
		DataType Number = 0;
		bool ValidNumber = false;
		do
		{
			cin >> Number;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << ErrorMessage;
			}
			else
				ValidNumber = true;
		} while (!ValidNumber);
		return Number;
	}

	template <typename DataType> static DataType ReadNumberInRange(DataType From, DataType To, string ErrorMessage = "\nNumber is not within the range, try again:\n")
	{
		DataType Number = 0;
		bool ValidNumber = false;
		do
		{
			Number = ReadNumber<DataType>();
			if (!IsNumberBetween(Number, From, To))
			{
				cout << ErrorMessage;
			}
			else
				ValidNumber = true;
		} while (!ValidNumber);
		return Number;
	}

	static bool IsDateBetween(clsDate Date, clsDate FromDate, clsDate ToDate)
	{
		// Date >= FromDate && Date <= ToDate
		if (clsDate::IsDate1AfterDate2(Date, FromDate) || clsDate::IsDate1EqualDate2(Date, FromDate)
			&&
			clsDate::IsDate1BeforeDate2(Date, ToDate) || clsDate::IsDate1EqualDate2(Date, ToDate))
		{
			return true;
		}

		// Date >= ToDate && Date <= FromDate
		if (clsDate::IsDate1AfterDate2(Date, ToDate) || clsDate::IsDate1EqualDate2(Date, ToDate)
			&&
			clsDate::IsDate1BeforeDate2(Date, FromDate) || clsDate::IsDate1EqualDate2(Date, FromDate))
		{
			return true;
		}

		return false;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString(string Message)
	{
		string Text;
		cout << Message;
		getline(cin >> ws, Text);
		return Text;
	}
};