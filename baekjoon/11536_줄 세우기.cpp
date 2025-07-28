#include <iostream>
#include <algorithm>

using namespace std;

int N;
string names[20];
string sortedNames[20];

bool isIncreasing()
{
    for (int i = 0; i < N; ++i)
    {
        if (sortedNames[i] != names[i])
        {
            return false;
        }
    }

    return true;
}

bool isDecreasing()
{
    for (int i = 0; i < N; ++i)
    {
        if (sortedNames[i] != names[N - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> names[i];
        sortedNames[i] = names[i];
    }

    sort(sortedNames, sortedNames + N);

    if (isIncreasing())
    {
        cout << "INCREASING";
    }
    else if (isDecreasing())
    {
        cout << "DECREASING";
    }
    else
    {
        cout << "NEITHER";
    }
    return 0;
}