#include <iostream>
using namespace std;
int N, answer = 6;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 11; i <= N; ++i)
    {
        answer *= i;
    }

    cout << answer;
    return 0;
}