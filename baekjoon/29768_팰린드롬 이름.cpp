#include <iostream>
using namespace std;
int N, K;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N - K; ++i)
    {
        cout << 'a';
    }
    for (char i = 'a'; i < K + 'a'; ++i)
    {
        cout << i;
    }
    return 0;
}