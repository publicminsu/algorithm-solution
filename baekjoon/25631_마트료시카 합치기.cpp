#include <iostream>
#include <unordered_map>
using namespace std;

int N;
unordered_map<int, int> cnts;
int maxCnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        ++cnts[a];

        maxCnt = max(maxCnt, cnts[a]);
    }

    cout << maxCnt;
    return 0;
}