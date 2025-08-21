#include <iostream>
using namespace std;

int burgers[3];
int drinks[2];

int GetMin(int costs[], int size)
{
    int ret = costs[0];

    for (int i = 1; i < size; ++i)
    {
        ret = min(ret, costs[i]);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int &burger : burgers)
    {
        cin >> burger;
    }

    for (int &drink : drinks)
    {
        cin >> drink;
    }

    cout << (GetMin(burgers, 3) + GetMin(drinks, 2) - 50);

    return 0;
}