#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int prevTime, answer;

vector<int> v;

void calc(int size, int coolTime)
{
    v.clear();

    answer = 1;

    while (size--)
    {
        cin >> prevTime;
        v.push_back(prevTime);
    }

    sort(v.begin(), v.end());

    prevTime = v.front();

    for (const int &curTime : v)
    {
        if (curTime - prevTime < coolTime)
        {
            continue;
        }

        prevTime = curTime;
        ++answer;
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    v.reserve(max(N, M));

    calc(N, 100);
    cout << " ";
    calc(M, 360);

    return 0;
}