#include <iostream>
#include <map>
using namespace std;
string month, day, year, time;
int monthToDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
int GetMonthIndex(const string &monthName)
{
    static const map<string, int> months{
        {"January", 0},
        {"February", 1},
        {"March", 2},
        {"April", 3},
        {"May", 4},
        {"June", 5},
        {"July", 6},
        {"August", 7},
        {"September", 8},
        {"October", 9},
        {"November", 10},
        {"December", 11}};

    const auto iter(months.find(monthName));

    return iter->second;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    cout.precision(10);

    cin >> month >> day >> year >> time;

    int monthIndex = GetMonthIndex(month);

    day.pop_back(); // , 제거

    int intYear = stoi(year);
    bool isLeapYear = (intYear % 400 == 0) || (intYear % 4 == 0 && intYear % 100 != 0); // 윤년

    int sumDay = 0, total = 365;
    for (int i = 0; i < monthIndex; ++i)
    {
        sumDay += monthToDay[i];
    }

    if (isLeapYear)
    {
        ++total;
        if (monthIndex > 1)
        {
            ++sumDay;
        }
    }

    int intDay = stoi(day) - 1; // 당일 제거
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int min = (time[3] - '0') * 10 + (time[4] - '0');

    double answer = (((static_cast<double>(sumDay) + intDay) * 24 + hour) * 60 + min) / (total * 24 * 60) * 100;

    cout << answer;
    return 0;
}