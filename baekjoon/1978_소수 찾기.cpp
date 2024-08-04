#include <iostream>
using namespace std;
int N, answer, num;
bool isNotPrime[1001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 2; i * i < 1001; ++i)
    {
        for (int j = i + i; j < 1001; j += i)
        {
            isNotPrime[j] = true;
        }
    }

    isNotPrime[1] = true;

    cin >> N;

    while (N--)
    {
        cin >> num;

        if (!isNotPrime[num])
        {
            ++answer;
        }
    }

    cout << answer;
    return 0;
}