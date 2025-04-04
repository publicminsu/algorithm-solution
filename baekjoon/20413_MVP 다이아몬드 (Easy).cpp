#include <iostream>
using namespace std;

int N, prevValue, answer;
int s, g, p, d;
string mvp;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    cin >> s >> g >> p >> d;
    cin >> mvp;

    for (const char &c : mvp)
    {
        int maxValue;

        switch (c)
        {
        case 'B':
            maxValue = s - 1;
            break;
        case 'S':
            maxValue = g - 1;
            break;
        case 'G':
            maxValue = p - 1;
            break;
        case 'P':
            maxValue = d - 1;
            break;
        case 'D':
            maxValue = d;
            prevValue = 0;
        }

        int value = maxValue - prevValue;
        answer += value;
        prevValue = value;
    }

    cout << answer;
    return 0;
}