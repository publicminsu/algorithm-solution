#include <iostream>
using namespace std;
string time;
int cnt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> time;

    for (int i = 0; i < 3; ++i)
    {
        int num = stoi(time.substr(i * 2 + i, 2));

        if (num >= 1 && num <= 12)
        {
            ++cnt;
        }

        if (num > 59)
        {
            cnt = 0;
            break;
        }
    }

    cout << cnt * 2;
    return 0;
}