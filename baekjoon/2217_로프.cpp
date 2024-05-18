#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, answer;
vector<int> ropes;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    ropes = vector<int>(N);
    for (int &rope : ropes)
    {
        cin >> rope;
    }

    sort(ropes.begin(), ropes.end());

    for (const int &rope : ropes)
    {
        answer = max(answer, rope * N);
        --N;
    }

    cout << answer;
    return 0;
}