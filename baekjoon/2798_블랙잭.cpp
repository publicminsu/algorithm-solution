#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int N, M, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    v = vector<int>(N);
    for (int &i : v)
    {
        cin >> i;
    }

    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = i + 1; j < N - 1; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                int sum = v[i] + v[j] + v[k];

                if (sum > M)
                {
                    continue;
                }

                answer = max(sum, answer);
            }
        }
    }

    cout << answer;
    return 0;
}