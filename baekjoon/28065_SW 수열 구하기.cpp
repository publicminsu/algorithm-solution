#include <iostream>
#include <vector>
using namespace std;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0, j = 1, K = N; i < N; ++i)
    {
        cout << (i % 2 ? K-- : j++) << " ";
    }

    return 0;
}