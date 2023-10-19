#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int friendAmount[200001], parents[200001], groupIdx;
unordered_map<string, int> stringMap;
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
        friendAmount[num1] += friendAmount[num2];
    }
    else if (num2 > num1)
    {
        parents[num1] = num2;
        friendAmount[num2] += friendAmount[num1];
    }
}
int stringToInt(string str)
{
    int num;
    if (stringMap.count(str) == 0)
    {
        num = groupIdx++;
        stringMap[str] = num;
    }
    else
    {
        num = stringMap[str];
    }
    return num;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T, F, n1, n2;
    string f1, f2;
    cin >> T;
    for (int i = 0; i < 200001; ++i)
    {
        parents[i] = i;
        friendAmount[i] = 1;
    }
    while (T--)
    {
        stringMap.clear();
        cin >> F;
        for (int i = 0; i <= groupIdx; ++i)
        {
            parents[i] = i;
            friendAmount[i] = 1;
        }
                groupIdx = 0;
        while (F--)
        {
            cin >> f1 >> f2;
            n1 = stringToInt(f1);
            n2 = stringToInt(f2);
            merge(n1, n2);
            cout << friendAmount[find(n1)] << "\n";
        }
    }
    return 0;
}