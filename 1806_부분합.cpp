#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, S, sum = 0, ret = 100001, bot = 0;
    cin >> N >> S;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
        sum += v[i];
        while (sum >= S)
        {
            if (sum - v[bot] >= S)
            {
                sum -= v[bot++];
            }
            else
            {
                int dis = i - bot + 1;
                ret = ret > dis ? dis : ret;
                break;
            }
        }
    }
    cout << (ret == 100001 ? 0 : ret);
}