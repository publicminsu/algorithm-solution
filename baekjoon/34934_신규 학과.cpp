#include <iostream>

using namespace std;

int N;
string name;
int year;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    while (N--)
    {
        cin >> name >> year;

        if (year == 2026)
        {
            cout << name;
        }
    }
    return 0;
}