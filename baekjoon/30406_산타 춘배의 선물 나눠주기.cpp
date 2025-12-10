#include <iostream>
using namespace std;

int cnts[4];
int N;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        int num;
        cin >> num;
        ++cnts[num];
    }
}

int calc(int a, int b)
{
    int value = a ^ b;

    int cnt = min(cnts[a], cnts[b]);
    cnts[a] -= cnt;
    cnts[b] -= cnt;

    return value * cnt;
}

int main()
{
    input();
    cout << (calc(0, 3) + calc(1, 2) + calc(0, 2) + calc(1, 3) + calc(0, 1) + calc(2, 3));
    return 0;
}