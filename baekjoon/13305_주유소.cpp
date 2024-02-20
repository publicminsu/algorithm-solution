#include <iostream>
#include <vector>
using namespace std;
vector<int> dist;
int N, curPrice, nextPrice;
long long answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    dist = vector<int>(N - 1);
    for (int &i : dist)
    {
        cin >> i;
    }

    cin >> curPrice;
    for (int i = 0; i < N - 1; ++i)
    {
        answer += static_cast<long long>(curPrice) * dist[i];
        cin >> nextPrice;
        curPrice = min(curPrice, nextPrice); // 최소 비용을 기록
    }
    cout << answer;
    return 0;
}