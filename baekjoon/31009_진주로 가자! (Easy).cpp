#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, jinjuCost, answer, C;
vector<short> costs;
string D;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    costs.reserve(N);
    while (N--)
    {
        cin >> D >> C;

        if (D == "jinju")
        {
            jinjuCost = C;
        }
        else
        {
            costs.push_back(C);
        }
    }

    for (short cost : costs)
    {
        if (cost > jinjuCost) // 진주의 비용보다 높은 곳
        {
            ++answer;
        }
    }

    cout << jinjuCost << "\n";
    cout << answer;
    return 0;
}