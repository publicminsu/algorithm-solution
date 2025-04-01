#include <iostream>
using namespace std;

int answer = 100;

void dfs(int K, string S)
{
    int size = S.size();
    answer = min(answer, size);

    if (K == 0)
    {
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (S[i] != S[j] || S[i] == 'X')
            {
                continue;
            }

            string nextS = S;

            nextS.erase(nextS.begin() + i, nextS.begin() + j + 1);

            dfs(K - 1, nextS);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K;
    string S;
    cin >> N >> K >> S;
    dfs(K, S);
    cout << answer;
    return 0;
}