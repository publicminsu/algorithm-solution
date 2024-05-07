#include <iostream>
#include <set>
using namespace std;
int N;
set<int> prevSet, curSet;
int nums[] = {1, 5, 10, 50};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (const int &num : nums)
    {
        curSet.insert(num);
    }

    while (--N)
    {
        prevSet = curSet;
        curSet.clear();

        for (const int &i : prevSet)
        {
            for (const int &num : nums)
            {
                curSet.insert(i + num);
            }
        }
    }

    cout << curSet.size();
    return 0;
}