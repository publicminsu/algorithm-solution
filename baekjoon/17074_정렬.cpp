#include <iostream>

using namespace std;

int N;
int a[100003];
int cnt, idx;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
    }
}

void checkSorted()
{
    a[0] = -1000000000;
    a[N + 1] = 1000000000;

    for (int i = 2; i <= N; ++i)
    {
        if (a[i] < a[i - 1])
        {
            ++cnt;
            idx = i;
        }
    }
}

int getResult()
{
    switch (cnt)
    {
    case 0:
        return N;
    case 1:
    {
        int result = 0;

        if (a[idx - 1] <= a[idx + 1])
        {
            ++result;
        }
        if (a[idx - 2] <= a[idx])
        {
            ++result;
        }

        return result;
    }
    default:
        return 0;
    }
}

int main()
{
    input();
    checkSorted();
    cout << getResult();
    return 0;
}