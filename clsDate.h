#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
using namespace std;

// Date Library Project - 16/9/2025 - Course#10 - Developer: Mr.Key47

// If there is a method will edit object's properties values, implement it as:
// *this = method(*this) -> *this pointer will be send as current object to handle editing
// and storing processes


class clsDate
{
private:
	short _Day = 0;

	short _Month = 0;

	short _Year = 0;

	enum enDateCompare;

	/*static string _PrintCompareResult(enDateCompare Result)
	{
		switch (Result)
		{
		case enDateCompare::Before:
			return "Date1 before Date2 (-:";

		case enDateCompare::Equal:
			return "Date1 equal Date2 (-:";
		
		default:
			return "Date1 after Date2 (-:";
		}
	}*/

public:
	clsDate()
	{
		*this = GetSystemDate();
	}

	clsDate(string Date)
	{
		StringToDate(*this, Date);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DaysNumber, short Year)
	{
		GetDateFromDayOrderInYear(*this, DaysNumber, Year);
	}

	void setDay(short Day)
	{
		_Day = Day;
	}

	short getDay()
	{
		return _Day;
	}

	__declspec(property(put = setDay, get = getDay)) short Day;

	void setMonth(short Month)
	{
		_Month = Month;
	}

	short getMonth()
	{
		return _Month;
	}

	__declspec(property(put = setMonth, get = getMonth)) short Month;

	void setYear(short Year)
	{
		_Year = Year;
	}

	short getYear()
	{
		return _Year;
	}

	__declspec(property(put = setYear, get = getYear)) short Year;

	static clsDate GetSystemDate()
	{	
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Month, Year;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return clsDate(Day, Month, Year);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static void Print(clsDate Date)
	{
		cout << DateToString(Date) << endl;
	}

	void Print()
	{
		Print(*this);
	}

	static bool IsLeapYear(short Year)
	{
		return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0));
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(short Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}

	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}

	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static short GetDaysNumberOfAMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short arrDaysNumberInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : arrDaysNumberInMonth[Month];
	}

	short GetDaysNumberOfAMonth()
	{
		return GetDaysNumberOfAMonth(_Year, _Month);
	}

	static clsDate GetDateFromDayOrderInYear(clsDate& Date, short DaysNumber, short Year)
	{
		Date.Month = 1;
		while (DaysNumber > 31)
		{
			DaysNumber -= GetDaysNumberOfAMonth(Year, Date.Month);
			++Date.Month;
		}
		Date.Day = DaysNumber;
		Date.Year = Year;
		return Date;
	}

	void GetDateFromDayOrderInYear(short DaysNumber, short Year)
	{
		// send year as new year to generate a new date
		GetDateFromDayOrderInYear(*this, DaysNumber, Year);
	}

	static short NumberOfHoursInAMonth(short Year, short Month)
	{
		return GetDaysNumberOfAMonth(Year, Month) * 24;
	}

	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Year, _Month);
	}

	static int NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Year, _Month);
	}

	static int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Year, _Month);
	}

	static short GetDayOrderInWeek(short Day, short Month, short Year)
	{
		short a = 0, y = 0, m = 0;
		a = (14 - Month) / 12;
		y = Year - a;
		m = (Month + (12 * a)) - 2;
		return ((Day + y) + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short GetDayOrderInWeek()
	{
		return GetDayOrderInWeek(_Day, _Month, _Year);
	}

	static string ShowShortDayName(short DayOrder)
	{
		string arrWeekDays[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrWeekDays[DayOrder];
	}

	string ShowShortDayName()
	{
		return ShowShortDayName(GetDayOrderInWeek()); // call object's date
	}

	static string ShowShortMonthName(short MonthNumber)
	{
		string arrMonths[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return arrMonths[MonthNumber];
	}

	string ShowShortMonthName()
	{
		return ShowShortMonthName(_Month);
	}

	static void PrintCalendarOfMonth(short Year, short Month)
	{
		short NumberOfDays = GetDaysNumberOfAMonth(Year, Month);
		short FirstDayOrder = GetDayOrderInWeek(1, Month, Year);
		cout << "\n____________" << ShowShortMonthName(Month) << "______________\n\n";
		printf(" Sun Mon Tue Wed Thu Fri Sat\n");
		short DaysCounter;
		for (DaysCounter = 0; DaysCounter < FirstDayOrder; DaysCounter++)
		{
			cout << "    ";
		}
		for (short i = 1; i <= NumberOfDays; i++)
		{
			printf("%4d", i);
			if (++DaysCounter == 7)
			{
				DaysCounter = 0;
				cout << '\n';
			}
		}
		cout << "\n_____________________________\n";
	}

	void PrintCalendarOfMonth()
	{
		PrintCalendarOfMonth(_Year, _Month);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n_____________________________\n\n");
		printf("\tCalendar - %d", Year);
		printf("\n_____________________________\n");
		for (short i = 1; i <= 12; i++)
		{
			PrintCalendarOfMonth(Year, i);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;
		for (short MonthNumber = 0; MonthNumber < Month; MonthNumber++)
		{
			TotalDays += GetDaysNumberOfAMonth(Year, MonthNumber);
		}
		TotalDays += Day;
		return TotalDays;
	}

	short NumberOfDaysFromTheBeginningOfTheYear()
	{
		return NumberOfDaysFromTheBeginningOfTheYear(_Day, _Month, _Year);
	}

	static clsDate ShowDateAfterAddedDays(clsDate& Date, short AddedDays)
	{
		short MonthDays = 0;
		// For user's day:
		MonthDays = GetDaysNumberOfAMonth(Date.Year, Date.Month);
		MonthDays -= Date.Day; // calculate how many remining days still to end of user's month.
		AddedDays -= MonthDays;
		++Date.Month; // start from complete and new month
		while (true)
		{
			if (Date.Month > 12)
			{
				Date.Month = 1;
				++Date.Year;
			}
			MonthDays = GetDaysNumberOfAMonth(Date.Year, Date.Month);
			if (AddedDays > MonthDays)
			{
				AddedDays -= MonthDays;
				++Date.Month;
			}
			else
			{
				Date.Day = AddedDays;
				break;
			}
		}
		return Date;
	}

	void ShowDateAfterAddedDays(short AddedDays)
	{
		ShowDateAfterAddedDays(*this, AddedDays);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) ? true : false : false : false;
	}

	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) ? true : false : false : false;
	}

	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!(IsDate1BeforeDate2(Date1, Date2)) && !(IsDate1EqualDate2(Date1, Date2)));
	}

	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == GetDaysNumberOfAMonth(Date.Year, Date.Month));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static clsDate AddOneDay(clsDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
			Date.Day++;

		return Date;
	}

	void AddOneDay()
	{
		AddOneDay(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int NumberOfDays = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			NumberOfDays++;
			Date1 = AddOneDay(Date1);
		}
		return IncludeEndDay ? ++NumberOfDays : NumberOfDays;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static int GetDifferenceInDaysWithSign(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int NumberOfDays = 0;
		short SwapFlag = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlag = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			NumberOfDays++;
			Date1 = AddOneDay(Date1);
		}
		return IncludeEndDay ? ++NumberOfDays * SwapFlag : NumberOfDays * SwapFlag;
	}

	int GetDifferenceInDaysWithSign(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDaysWithSign(*this, Date2, IncludeEndDay);
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth, clsDate DateOfToday)
	{
		int AgeByDays = 0;
		while (IsDate1BeforeDate2(DateOfBirth, DateOfToday))
		{
			AgeByDays += 1;
			DateOfBirth = AddOneDay(DateOfBirth);
		}
		return AgeByDays;
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		// fill empty TempDate
		TempDate.Day = Date1.Day;
		TempDate.Month = Date1.Month;
		TempDate.Year = Date1.Year;

		// fill empty Date1
		Date1.Day = Date2.Day;
		Date1.Month = Date2.Month;
		Date1.Year = Date2.Year;

		// fill empty Date2
		Date2.Day = TempDate.Day;
		Date2.Month = TempDate.Month;
		Date2.Year = TempDate.Year;
	}

	void SwapDates(clsDate& Date2)
	{
		SwapDates(*this, Date2);
	}

	static clsDate IncreaseDateByXDays(clsDate& Date, int NumberOfDays)
	{
		for (short i = 1; i <= NumberOfDays; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(int NumberOfDays)
	{
		IncreaseDateByXDays(*this, NumberOfDays);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{
		return IncreaseDateByXDays(Date, 7);
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate& Date, short NumberOfWeeks)
	{
		for (short i = 1; i <= NumberOfWeeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short NumberOfWeeks)
	{
		IncreaseDateByXWeeks(*this, NumberOfWeeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (IsLastMonthInYear(Date.Month))  // Date --> 31/12/year?
		{
			Date.Month = 1;
			++Date.Year;
		}
		else ++Date.Month;
		short MonthDays = GetDaysNumberOfAMonth(Date.Year, Date.Month);
		if (Date.Day > MonthDays)
			Date.Day = MonthDays;
		// else: Date.Day stay as it is
		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDataByXMonths(clsDate& Date, short NumberOfMonths)
	{
		for (short i = 1; i <= NumberOfMonths; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDataByXMonths(short NumberOfMonths)
	{
		IncreaseDataByXMonths(*this, NumberOfMonths);
	}

	static short IncreaseDateByOneYear(short Year)
	{
		return ++Year;
	}

	void IncreaseDateByOneYear()
	{
		this->_Year = IncreaseDateByOneYear(_Year);
	}

	static short IncreaseDateByXYears(short Year, short NumberOfYears)
	{
		for (short i = 1; i <= NumberOfYears; i++) // Loop for Number of Years
		{
			Year = IncreaseDateByOneYear(Year);
		}
		return Year;
	}

	void IncreaseDateByXYears(short NumberOfYears)
	{
		this->_Year = IncreaseDateByXYears(_Year, NumberOfYears);
	}

	static short IncreaseDateByOneDecade(short Year)
	{
		return Year + 10;
	}

	void IncreaseDateByOneDecade()
	{
		this->_Year = IncreaseDateByOneDecade(_Year);
	}

	static short IncreaseDateByXDecades(short Year, short NumberOfDecades)
	{
		for (short i = 1; i <= NumberOfDecades; i++)
		{
			Year = IncreaseDateByOneDecade(Year);
		}
		return Year;
	}

	void IncreaseDateByXDecades(short NumberOfDecades)
	{
		this->_Year = IncreaseDateByXDecades(_Year, NumberOfDecades);
	}

	static short IncreaseDateByOneCentury(short Year)
	{
		return Year + 100;
	}

	void IncreaseDateByOneCentury()
	{
		this->_Year = IncreaseDateByOneCentury(_Year);
	}

	static short IncreaseDateByOneMillennium(short Year)
	{
		return Year + 1000;
	}

	void IncreaseDateByOneMillennium()
	{
		this->_Year = IncreaseDateByOneMillennium(_Year);
	}

	static bool IsFirstDayInMonth(short Day)
	{
		return Day == 1;
	}

	bool IsFirstDayInMonth()
	{
		return IsFirstDayInMonth(this->_Day);
	}

	static bool IsFirstMonthInYear(short Month)
	{
		return Month == 1;
	}

	bool IsFirstMonthInYear()
	{
		return IsFirstMonthInYear(this->_Month);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{
		if (IsFirstDayInMonth(Date.Day))
		{
			if (IsFirstMonthInYear(Date.Month)) // 1/1/Y
			{
				Date.Day = 31;
				Date.Month = 12;
				--Date.Year;
			}
			else
			{
				--Date.Month;
				Date.Day = GetDaysNumberOfAMonth(Date.Year, Date.Month);
			}
		}
		else
		{
			--Date.Day;
		}
		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate& Date, int NumberOfDays)
	{
		for (short i = 1; i <= NumberOfDays; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(int NumberOfDays)
	{
		DecreaseDateByXDays(*this, NumberOfDays);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate& Date, short NumberOfWeeks)
	{
		for (short i = 1; i <= NumberOfWeeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short NumberOfWeeks)
	{
		DecreaseDateByXWeeks(*this, NumberOfWeeks);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (IsFirstMonthInYear(Date.Month))
		{
			Date.Month = 12;
			--Date.Year;
		}
		else
		{
			--Date.Month;
		}
		short MonthDays = GetDaysNumberOfAMonth(Date.Year, Date.Month);
		if (Date.Day > MonthDays)
		{
			Date.Day = MonthDays;
		}
		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate& Date, short NumberOfMonths)
	{
		for (short i = 1; i <= NumberOfMonths; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short NumberOfMonths)
	{
		DecreaseDateByXMonths(*this, NumberOfMonths);
	}

	static short DecreaseDateByOneYear(short Year)
	{
		return --Year;
	}

	void DecreaseDateByOneYear()
	{
		this->_Year = DecreaseDateByOneYear(_Year);
	}

	static short DecreaseDateByXYears(short Year, short NumberOfYears)
	{
		for (short i = 1; i <= NumberOfYears; i++)
		{
			Year = DecreaseDateByOneYear(Year);
		}
		return Year;
	}

	void DecreaseDateByXYears(short NumberOfYears)
	{
		this->_Year = DecreaseDateByXYears(_Year, NumberOfYears);
	}

	static short DecreaseDateByOneDecade(short Year)
	{
		return Year -= 10;
	}

	void DecreaseDateByOneDecade()
	{
		this->_Year = DecreaseDateByOneDecade(_Year);
	}

	static short DecreaseDateByXDecades(short Year, short NumberOfDecades)
	{
		for (short i = 1; i <= NumberOfDecades; i++)
		{
			Year = DecreaseDateByOneDecade(Year);
		}
		return Year;
	}

	void DecreaseDateByXDecades(short NumberOfDecades)
	{
		this->_Year = DecreaseDateByXDecades(_Year, NumberOfDecades);
	}

	static short DecreaseDateByOneCentury(short Year)
	{
		return Year -= 100;
	}

	void DecreaseDateByOneCentury()
	{
		_Year = DecreaseDateByOneCentury(_Year);
	}

	static short DecreaseDateByOneMillennium(short Year)
	{
		return Year -= 1000;
	}

	void DecreaseDateByOneMillennium()
	{
		_Year = DecreaseDateByOneMillennium(_Year);
	}

	static short GetDayOrderInWeek(clsDate Date)
	{
		return GetDayOrderInWeek(Date.Day, Date.Month, Date.Year);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return GetDayOrderInWeek(Date) == 6; // Day == Saturday?
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short DayOrder = GetDayOrderInWeek(Date);
		return (DayOrder == 5 || DayOrder == 6); // WeekEnd -> Fri and Sat
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilEndOfWeek(clsDate Date)
	{
		return 6 - GetDayOrderInWeek(Date);
	}

	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate CurrentDate)
	{
		clsDate EndOfMonthDate;
		EndOfMonthDate.Day = GetDaysNumberOfAMonth(CurrentDate.Year, CurrentDate.Month);
		EndOfMonthDate.Month = CurrentDate.Month;
		EndOfMonthDate.Year = CurrentDate.Year;
		return GetDifferenceInDays(CurrentDate, EndOfMonthDate, true);
	}

	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}

	static short DaysUntilEndOfYear(clsDate CurrentDate)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = CurrentDate.Year;
		return GetDifferenceInDays(CurrentDate, EndOfYearDate, true);
	}

	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;
			DateFrom = AddOneDay(DateFrom);
		}
		return Days;
	}

	short CalculateBusinessDays(clsDate DateTo)
	{
		return CalculateBusinessDays(*this, DateTo);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	short CalculateVacationDays(clsDate DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationDate(clsDate DateFrom, short VacationDays)
	{
		for (short i = 1; i <= VacationDays; i++)
		{
			if (IsWeekEnd(DateFrom))
			{
				VacationDays++;
			}
			DateFrom = AddOneDay(DateFrom);
		}
		return DateFrom;
	}

	void CalculateVacationDate(short VacationDays)
	{
		*this = CalculateVacationDate(*this, VacationDays);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		else
			return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool IsValidDate(clsDate Date)
	{
		short DaysMonth = GetDaysNumberOfAMonth(Date.Year, Date.Month);
		return (DaysMonth == 0) ? false : (Date.Day == 0 || Date.Day > DaysMonth) ? false : true;
	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string FormatDate(clsDate Date, string Format = "dd/mm/yyyy")
	{
		Format = clsString::ReplaceWordInStringBuiltInFunction(Format, "dd", to_string(Date.Day));
		Format = clsString::ReplaceWordInStringBuiltInFunction(Format, "mm", to_string(Date.Month));
		Format = clsString::ReplaceWordInStringBuiltInFunction(Format, "yyyy", to_string(Date.Year));
		return Format;
	}

	string FormatDate(string Format = "dd/mm/yyyy")
	{
		return FormatDate(*this, Format);
	}

	static clsDate StringToDate(clsDate& Date, string StringDate)
	{
		vector <string> vDate = clsString::Split(StringDate, "/");
		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);
		return Date;
	}

	void StringToDate(string StringDate)
	{
		StringToDate(*this, StringDate);
	}
};