#include <iostream>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    int num = N;

    for (int i = 2; i * i <= N && num != 1; ++i)
    {
        while (num % i == 0)
        {
            cout << i << "\n";
            num /= i;
        }
    }

    if (num == 1)
    {
        return 0;
    }
    cout << num;
    return 0;
}