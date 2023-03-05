#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, sum = 0, totalSum = 0;
    cin >> N;
    vector<int> time(N);

    for (int i = 0; i < N; ++i)
        cin >> time[i];

    sort(time.begin(), time.end());

    for (int i = 0; i < N; ++i)
    {
        sum += time[i];
        totalSum += sum;
    }
    cout << totalSum;
}