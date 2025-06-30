#include <iostream>
#include <unordered_set>
using namespace std;
using ll = long long;

int N;
bool isNotPrime[1000001];
unordered_set<int> isUsed;
ll answer = 1;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 2; i * i < 1000001; ++i)
    {
        if (isNotPrime[i])
        {
            continue;
        }

        for (int j = i + i; j < 1000001; j += i)
        {
            isNotPrime[j] = true;
        }
    }

    cin >> N;
    for (int i = 0, A; i < N; ++i)
    {
        cin >> A;

        if (!isNotPrime[A] && isUsed.find(A) == isUsed.end())
        {
            isUsed.insert(A);
            answer *= A;
        }
    }

    if (answer == 1)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }

    return 0;
}