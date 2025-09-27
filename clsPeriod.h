#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

// Overlapping Situations:
// # Overlapping -> true:
// 1- (Period2 End Date > Period1 Start Date) = Period2 is playing
// 2- (Period1 End Date > Period2 Start Date) = Period1 is playing

// # Overlapping -> false:
// If any period ends before another one start


class clsPeriod
{
public:
	// each period object contains about 2 objects from clsDate

	clsDate StartDate;

	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	static void Print(clsPeriod Period)
	{
		cout << "Start Date: ";
		Period.StartDate.Print();
		cout << "\nEnd Date: ";
		Period.EndDate.Print();
	}

	void Print()
	{
		Print(*this);
	}

	static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		if (clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After)
			return false;
		else
			return true;
	}

	bool IsOverlapPeriods(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false)
	{
		return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	int PeriodLengthInDays(bool IncludeEndDay = false)
	{
		return PeriodLengthInDays(*this, IncludeEndDay);
	}

	static bool IsDateInPeriodRange(clsPeriod Period, clsDate DateToCheck)
	{
		return !(clsDate::CompareDates(DateToCheck, Period.StartDate) == clsDate::enDateCompare::Before
			|| clsDate::CompareDates(DateToCheck, Period.EndDate) == clsDate::enDateCompare::After);
	}

	bool IsDateInPeriodRange(clsDate DateToCheck)
	{
		return IsDateInPeriodRange(*this, DateToCheck);
	}

	static short CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
	{
		short Period1Length = PeriodLengthInDays(Period1, true);
		short Period2Length = PeriodLengthInDays(Period2, true);
		short OverlapDaysCounter = 0;
		if (!IsOverlapPeriods(Period1, Period2))
			return 0;
		if (Period1Length < Period2Length)
		{
			while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInPeriodRange(Period2, Period1.StartDate))
				{
					OverlapDaysCounter++;
				}
				Period1.StartDate = clsDate::AddOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateInPeriodRange(Period1, Period2.StartDate))
				{
					OverlapDaysCounter++;
				}
				Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
			}
		}
		return OverlapDaysCounter;
	}

	short CountOverlapDays(clsPeriod Period2)
	{
		return CountOverlapDays(*this, Period2);
	}
};