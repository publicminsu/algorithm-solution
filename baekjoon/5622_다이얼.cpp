#include <iostream>

using namespace std;

string str;
int totalTime;

int times[] = {
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 7, 7, 7,
    8, 8, 8,
    9, 9, 9, 9};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;
    for (char c : str)
    {
        totalTime += times[c - 'A'] + 1;
    }
    cout << totalTime;
    return 0;
}