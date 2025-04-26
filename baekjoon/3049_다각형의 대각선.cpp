#include <iostream>
using namespace std;
int N, answer = 1;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = N; i >= N - 3; --i)
    {
        answer *= i;
    }

    answer /= 24;

    cout << answer;
    return 0;
}