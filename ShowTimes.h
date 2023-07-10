#define infinite while(true)
#define space "\t\t"
#define elif else if
#define br '\n'
#define bye return 0
#define ll long long
#define ld long double
#define dl double
#define fl float
#define str string
#define red system("color 04")
#define green system("color 02")
#define cls system("cls")

#pragma once
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
class ShowTimes
{
public:
	vector <str> strDay = { "Sunday",
		"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" },
	strMonth = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	
	vector <vector <int>> START, END;
	vector <int> Date_Time;
	int MonthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int intMonth(str monthName) // return the number of month
	{
		auto it = find(strMonth.begin(), strMonth.end(), monthName);
		int m = distance(strMonth.begin(), it) + 1;
		return m;
	}
	void setTime(int hours, int minutes, int seconds)
	{
		if (seconds >= 60)
		{
			minutes++;
			seconds %= 60;
		}
		if (minutes >= 60)
		{
			hours++;
			minutes %= 60;
		}
		if (hours >= 24)
			hours %= 24;
	}
	void setDate(int year, int month, int day)
	{
		if (day > MonthDays[month - 1])
		{
			if (month == 2 && year % 4 == 0 && day > MonthDays[month - 1] + 1)
				day %= MonthDays[month - 1] + 1;
			else
				day %= MonthDays[month - 1];
			month++;
		}
		if (month > 12)
		{
			month %= 12;
			year++;
		}
	}
	vector<int> realTime()
	{
		time_t current_time = time(nullptr);

		// convert the current time to a local time
		tm* local_time = localtime(&current_time);

		// extract the hours, minutes, and seconds from the local time
		int hh = local_time->tm_hour;
		int mm = local_time->tm_min;
		int ss = local_time->tm_sec;
		vector <int> arrTime {ss, mm, hh};
		return arrTime;
	}
	vector<int> realDate()
	{
		// get the current time
		time_t current_time = time(nullptr);

		// convert the current time to a local time
		tm* local_time = localtime(&current_time);

		// extract the year, month, and day from the local time
		int year = local_time->tm_year + 1900;
		int month = local_time->tm_mon + 1;
		int day = local_time->tm_mday;
		vector<int> arrDate = { day,month,year };
		return arrDate;
	}
public:
	void startTime()
	{
		cls;
		int year, month, day, hours, minutes, seconds;
		vector<int> RealDate = realDate(), RealTime = realTime();
		cout << space << "\t[Start ShowTime]\n";
		do {
			cout << space << "Date :\n";
			cout << space << "  Year : ", cin >> year;
			cout << space << " Month : ", cin >> month;
			cout << space << "  Day  : ", cin >> day;
			if (year < RealDate[2] || month < RealDate[1] || day < RealDate[0])
			{
				cout << space << "\t[Invalid Date]";
				Sleep(2000);
				cls;
			}
		} while (year < RealDate[2] || month < RealDate[1] || day < RealDate[0]);

		do {
			cout << space << "Time :\n";
			cout << space << " HH : ", cin >> hours;
			cout << space << " MM : ", cin >> minutes;
			cout << space << " SS : ", cin >> seconds;
			if (hours < RealTime[2] || minutes < RealTime[1] || seconds < RealTime[0])
			{
				cout << space << "\t[Invalid Time]";
				Sleep(2000);
				cls;
			}
		} while (hours < RealTime[2] || minutes < RealTime[1] || seconds < RealTime[0]);
		setTime(hours, minutes, seconds);
		setDate(year, month, day);
		Date_Time.push_back(seconds); // index 0
		Date_Time.push_back(minutes); // index 1
		Date_Time.push_back(hours);	   // index 2
		Date_Time.push_back(day);	   // index 3
		Date_Time.push_back(month);	   // index 4
		Date_Time.push_back(year);	   // index 5
		START.push_back(Date_Time);
		Date_Time.clear();
	}
	/*
	void startTime(int year, str month, int day, int hours, int minutes, int seconds)
	{
		int M = intMonth(month);
		setTime(hours, minutes, seconds);
		setDate(year, M, day);
		Date_Time.push_back(year);
		Date_Time.push_back(M);
		Date_Time.push_back(day);
		Date_Time.push_back(hours);
		Date_Time.push_back(minutes);
		Date_Time.push_back(seconds);
		START.push_back(Date_Time);
		Date_Time.clear();
	}*/
	void duration()
	{
		str done; int year = 0, month = 0, day = 0, hours, minutes, seconds;
		vector <int> RealTime = realTime();
		/*	//				On Trial
			vector<int> RealDate = realDate(), RealTime = realTime();
			cout << space << "\t[Set Show Time]\n";
			do {
				cout << space << "Date :\n";
				cout << space << "  Year : ", cin >> year;
				cout << space << " Month : ", cin >> month;
				cout << space << "  Day  : ", cin >> day;
				if (year < RealDate[2] || month < RealDate[1] || day < RealDate[0])
				{
					cout << space << "\t[Invalid Date]";
					Sleep(2000);
					cls;
				}
			} while (year < RealDate[2] || month < RealDate[1] || day < RealDate[0]);
		*/

		do {
			cout << space << "Time :\n";
			cout << space << " HH : ", cin >> hours;
			cout << space << " MM : ", cin >> minutes;
			cout << space << " SS : ", cin >> seconds;
		} while (false);
		setTime(hours, minutes, seconds);
		setDate(year, month, day);
		Date_Time.push_back(START.back()[0] + seconds); // index 0
		Date_Time.push_back(START.back()[1] + minutes); // index 1
		Date_Time.push_back(START.back()[2] + hours);	 // index 2
		Date_Time.push_back(START.back()[3] + day);		 // index 3
		Date_Time.push_back(START.back()[4] + month);	 // index 4
		Date_Time.push_back(START.back()[5] + year);	 // index 5
		setTime(Date_Time[2], Date_Time[1], Date_Time[0]);
		setDate(Date_Time[5], Date_Time[4], Date_Time[3]);
		cout << space << "END ShowTime : " << Date_Time[3] << " / " << strMonth[Date_Time[4] - 1] << " / " << Date_Time[5] << br
			<< space << Date_Time[2] << " : " << Date_Time[1] << " : " << Date_Time[0] << "  GMT\n";
		cout << "@: ", cin >> done;
		END.push_back(Date_Time);
		Date_Time.clear();
	}
	void availableTime(int index) // the index of movie
	{
		cout << space << "\t[Show Time]\n";
		cout << space << "Start in : " << START[index][5] << " / " << strMonth[START[index][4] - 1] << " / " << START[index][3] << br
			<< space << START[index][2] << " : " << START[index][1] << " : " << START[index][0] << "  GMT\n";
	}
	void DelDate(int index) // the index of movie
	{
		START.erase(START.begin() + index);
		END.erase(END.begin() + index);
	}
};