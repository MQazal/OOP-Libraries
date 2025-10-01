#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

// Input Validation Library - 10/1/2025 - Course#11 - Developer: Mr.Key47

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
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

	static int ReadIntegerNumber(string ErrorMessage = "\nInvalid input, Enter a number:\n")
	{
		int Number = 0;
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

	static int ReadIntegerNumberInRange(int From, int To, string ErrorMessage = "Number is not within the range, enter again:\n")
	{
		int Number = 0;
		bool ValidNumber = false;
		cout << "\nEnter a number between " << From << " and " << To << ": ";
		do
		{
			Number = ReadIntegerNumber();
			if (!IsNumberBetween(Number, From, To))
			{
				cout << ErrorMessage;
			}
			else
				ValidNumber = true;
		} while (!ValidNumber);
		return Number;
	}

	static double ReadDoubleNumber(string ErrorMessage = "Invalid input, Enter a number:\n")
	{
		double Number = 0.0;
		bool ValidNumber = false;
		do
		{
			cin >> Number;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clean input buffer
				cout << ErrorMessage;
			}
			else
				ValidNumber = true;
		} while (!ValidNumber);
		return Number;
	}

	static double ReadDoubleNumberInRange(double From, double To, string ErrorMessage = "Number is not within the range, enter again:\n")
	{
		double Number = 0.0;
		bool ValidNumber = false;
		cout << "\nEnter a number between " << From << " and " << To << ": ";
		do
		{
			Number = ReadDoubleNumber();
			if (!IsNumberBetween(Number, From, To))
				cout << ErrorMessage;
			else
				ValidNumber = true;

		} while (!ValidNumber);
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};