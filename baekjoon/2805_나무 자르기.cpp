#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, ret = 0;
    ll low = 0, high = 0, mid;
    cin >> N >> M;
    vector<int> trees(N);
    for (int i = 0; i < N; ++i)
    {
        int tree;
        cin >> tree;
        trees.push_back(tree);
        if (high < tree)
            high = tree;
    }
    while (low <= high)
    {
        ll sum = 0;
        mid = (low + high) / 2;
        for (int tree : trees)
        {
            sum += ((tree - mid) > 0 ? (tree - mid) : 0);
        }
        if (sum >= M)
        {
            low = mid + 1;
            if (ret < mid)
                ret = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ret;
    return 0;
}