#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, R;
vector<int> A;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> L >> R;
    --L;
    A = vector<int>(N);
    for (int &i : A)
    {
        cin >> i;
    }
}

bool solve()
{
    sort(A.begin() + L, A.begin() + R);

    for (int i = 0; i < N - 1; ++i)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    input();
    cout << solve();
    return 0;
}