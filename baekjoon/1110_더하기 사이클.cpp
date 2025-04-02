#include <iostream>

using namespace std;

int N, cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    int num = N;

    do
    {
        int one = num % 10;
        int ten = num / 10;

        num = one * 10 + (one + ten) % 10;

        ++cnt;
    } while (num != N);

    cout << cnt;

    return 0;
}