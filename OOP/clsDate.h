#pragma once
#pragma warning (disable :4996)
#include <iostream>
#include<ctime>
#include <vector>
#include<iomanip>
#include"clsString.h";
using namespace std;

class clsDate
{
	short _Day = 1, _Month = 1, _Year = 1900, _Hours = 0, _Minutes = 0, _Seconds = 0;

public:
	clsDate()
	{
		time_t Time = time(0);
		tm* CurrentDate = localtime(&Time);

		_Day = CurrentDate->tm_mday;
		_Month = CurrentDate->tm_mon + 1;
		_Year = CurrentDate->tm_year + 1900;
		_Hours = CurrentDate->tm_hour;
		_Minutes = CurrentDate->tm_min;
		_Seconds = CurrentDate->tm_sec;
		
	}
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(string Date)
	{
		vector<string>DateSplit;
		DateSplit = clsString::Split(Date, "/");
		_Day = stoi(DateSplit[0]);
		_Month = stoi(DateSplit[1]);
		_Year = stoi(DateSplit[2]);
	}
	clsDate(short NumberOfDays, short Year)
	{
		*this = GetDateFromDayOrderInYear(NumberOfDays, Year);
	}

	void SetHours(short Hours) {
		_Hours = Hours;
	}
	short GetHours() {
		return _Hours;
	}
	__declspec(property(get = GetHours, put = SetHours))short Hours;

	void SetMinutes(short Minutes) {
		_Minutes = Minutes;
	}
	short GetMinutes() {
		return _Minutes;
	}
	__declspec(property(get = GetMinutes, put = SetMinutes))short Minutes;

	void SetSeconds(short Seconds) {
		_Seconds = Seconds;
	}
	short GetSeconds() {
		return _Seconds;
	}
	__declspec(property(get = GetSeconds, put = SetSeconds))short Seconds;

	static string PrintSystemTime(clsDate Date) {
		return to_string(Date._Hours) + ":" + to_string(Date._Minutes) + ":" + to_string(Date._Seconds);
	}
	string PrintSystemTime() {
		return PrintSystemTime(*this);
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	static string DateToString(clsDate Date)
	{
		return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}
	string DateToString()
	{
		return  DateToString(*this);
	}

	void Print()
	{
		cout << DateToString();
	}

	static clsDate GetSystemDate()
	{
		//system date
		
		return clsDate();
	}

	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

	static bool isLeapYear(short Year)
	{
		// if year is divisible by 4 AND not divisible by 100
		// OR if year is divisible by 400
		// // then it is a leap year
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	};
	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static short NumberOfDaysInYear(short Year)
	{
		return (isLeapYear(Year)) ? 366 : 365;
	}
	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(short year)
	{
		return NumberOfDaysInYear(year) * 24;
	}
	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short year)
	{
		return NumberOfHoursInYear(year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short year)
	{
		return NumberOfMinutesInYear(year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static short NumberOfDaysInMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	}
	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Year, _Month);
	}

	static short NumberOfHoursInMonth(short year, short month)
	{
		return NumberOfDaysInMonth(year, month) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Year, _Month);
	}

	static	bool IsValidDate(clsDate Date)
	{

		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2)
		{
			if (isLeapYear(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

		if (Date.Day > DaysInMonth)
			return false;

		return true;

	}
	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static int NumberOfMinutesInMonth(short year, short month)
	{
		return NumberOfHoursInMonth(year, month) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Year, _Month);
	}

	static int NumberOfSecondsInMonth(short year, short month)
	{
		return NumberOfMinutesInMonth(year, month) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Year, _Month);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year) 
	{
		short a, y, m; 
		a = (14 - Month) / 12;  
		y = Year - a;    
		m = Month + (12 * a) - 2;
		// Gregorian://0:sun, 1:Mon, 2:Tue...etc 
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7; 
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayShortName(short DayOfWeekOrder) 
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder]; 
	}
	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder());
	}

	static string MonthShortName(short month)
	{
		string monthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return monthNames[month - 1];
	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void MonthCalender(short Year, short Month)
	{
		int NumberOfDays;
		NumberOfDays = NumberOfDaysInMonth(Year, Month);
		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);

		// Print the current month name
		printf("\n__________________%s______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}

		}
		printf("\n___________________________________\n");
	}
	void MonthCalender()
	{
		MonthCalender(_Year, _Month);
	}

	static void  YearCalender(short Year)
	{
		printf("\n  _________________________________\n\n");
		cout << "\t Calander - " << Year << "\n\n";
		printf("  _________________________________\n\n");

		for (short i = 1; i <= 12; i++)
		{
			MonthCalender(Year,i);
			cout << endl;
		}
	}
	void  YearCalender()
	{
		YearCalender(_Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) 
	{
		short TotalDays = 0; 
		for (int i = 1; i <= Month - 1; i++) 
		{ 
			TotalDays += NumberOfDaysInMonth(Year,i); 
		}    
		TotalDays += Day; 
	    return TotalDays; 
	}
	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date.Year = Year;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Year, Date.Month);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	clsDate GetDateFromDayOrderInYear(short DateOrderInYear)
	{
		return GetDateFromDayOrderInYear(DateOrderInYear,this->Year);
	}

	static clsDate DateAddDays(short Days, clsDate Date)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
		short MonthDays = 0;
		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	clsDate DateAddDays(short Days)
	{
		return DateAddDays(Days, *this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ?
			(Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ?
				Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ?
			true : false) : false) : false;
	}
	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
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
		return IsLastMonthInYear(this->Month);
	}
	
	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}
	void AddOneDay()

	{
		*this = AddOneDay(*this);
	}


	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;
		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;
		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}
	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{

		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}
	void IncreaseDateByOneMonth()
	{

		IncreaseDateByOneMonth(*this);

	}

	static clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short Days)
	{

		IncreaseDateByXDays(Days, *this);
	}

	static clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date.Year++;
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date.Year += Years;
		return Date;

	}
	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years
		Date.Year += 10;
		return Date;
	}
	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}
	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years
		Date.Year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years
		Date.Year += 1000;
		return Date;
	}
	clsDate IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{

				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Year,Date.Month);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{

		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
			Date.Month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year,Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}


		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{

		Date.Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
	{

		Date.Year -= Years;
		return Date;
	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years
		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
	{

		Date.Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years
		Date.Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years
		Date.Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	static short IsEndOfWeek(clsDate Date)
	{
		return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur

	   /*
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex >= 5 && DayIndex <= 4);
	   */

	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !IsWeekEnd(Date);

	}

	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{

		clsDate EndOfMontDate;
		EndOfMontDate.Day = NumberOfDaysInMonth(Date1.Year,Date1.Month);
		EndOfMontDate.Month = Date1.Month;
		EndOfMontDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfMontDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date1)
	{

		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);

	}

	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	//i added this method to calculate business days between 2 days
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

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		/*short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}*/

		return CalculateBusinessDays(DateFrom, DateTo);

	}
	//above method is eough , no need to have method for the object

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = AddOneDay(DateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		/* if (IsDate1AfterDate2(Date1,Date2))
			 return enDateCompare::After;*/

			 //this is faster
		return enDateCompare::After;

	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

};