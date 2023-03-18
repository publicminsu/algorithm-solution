#include <iostream>
#include <vector>
using namespace std;
vector<int> parents;
int find(int num)
{
    if (parents[num] == num)
        return num;
    return parents[num] = find(parents[num]);
}
void merge(int num1, int num2)
{
    num1 = find(num1);
    num2 = find(num2);
    if (num1 > num2)
    {
        parents[num2] = num1;
    }
    else
    {
        parents[num1] = num2;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, ret = 0, p1, p2;
    cin >> n >> m;
    parents = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        parents[i] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> p1 >> p2;
        p1 = find(p1);
        p2 = find(p2);
        if (p1 == p2)
        {
            ret = i;
            break;
        }
        merge(p1, p2);
    }
    cout << ret;
}