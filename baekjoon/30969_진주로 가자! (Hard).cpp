#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, jinjuCost, outLen;
long long C;
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
        if (C > 1000)
        {
            ++outLen;
        }
        else
        {
            costs.push_back(C);
        }
    }

    sort(costs.begin(), costs.end());

    cout << jinjuCost << "\n";
    cout << (costs.size() - (upper_bound(costs.begin(), costs.end(), jinjuCost) - costs.begin())) + outLen; // 진주보다 큰 값의 범위
    return 0;
}