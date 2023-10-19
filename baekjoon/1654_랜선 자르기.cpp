#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K, N, ret = 0;
    long long start, end = 0, mid;
    cin >> K >> N;
    vector<int> lines;
    for (int i = 0; i < K; ++i)
    {
        int line;
        cin >> line;
        lines.push_back(line);
        if (end < line)
            end = line;
    }
    start = 1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int sum = 0;
        for (int line : lines)
        {
            sum += (line / mid);
        }
        if (sum >= N)
        {
            start = mid + 1;
            if (ret < mid)
                ret = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << ret;
    return 0;
}