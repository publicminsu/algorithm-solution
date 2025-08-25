#include <iostream>
using namespace std;

int N, prevH, h;
long long area;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> h;

        area += abs(h - prevH);
        area += h * 2;
        area += 2;

        prevH = h;
    }

    area += prevH;

    cout << area;
    return 0;
}