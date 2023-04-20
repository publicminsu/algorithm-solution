#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<bool> isVisted(N + 1);
    for (int i = 2; i <= N; ++i)
    {
        for (int j = i; j <= N; j += i)
        {
            if (isVisted[j])
                continue;
            isVisted[j] = true;
            if (!--K)
            {
                cout << j;
                return 0;
            }
        }
    }
    return 0;
}