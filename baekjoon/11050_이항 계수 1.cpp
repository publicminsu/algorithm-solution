#include <iostream>
using namespace std;
int N, K, answer = 1;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for (int i = N; i > N - K; --i)
    {
        answer *= i;
    }
    for (int i = K; i > 1; --i)
    {
        answer /= i;
    }
    cout << answer;
    return 0;
}