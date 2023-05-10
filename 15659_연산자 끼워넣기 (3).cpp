#include <iostream>
#include <vector>
using namespace std;
vector<int> A, op;
int opAmount[4], N, retMin = 1000000001, retMax = -1000000001;
void dfs(int idx, vector<int> v)
{
    if (idx == N)
    {
        int sum = v[0];
        for (int i = 1; i < v.size(); ++i)
        {
            int o = op[i - 1];
            if (o == 0)
                sum += v[i];
            else
                sum -= v[i];
        }
        retMin = retMin > sum ? sum : retMin;
        retMax = retMax < sum ? sum : retMax;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (!opAmount[i])
            continue;
        vector<int> nv(v);
        --opAmount[i];
        if (i >= 2) // 2이상이면 바로 계산
        {
            if (i == 2)
            {
                nv[nv.size() - 1] *= A[idx];
            }
            else
            {
                nv[nv.size() - 1] /= A[idx];
            }
            dfs(idx + 1, nv);
        }
        else
        {
            nv.push_back(A[idx]);
            op.push_back(i);
            dfs(idx + 1, nv);
            op.pop_back();
        }
        ++opAmount[i];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    A = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < 4; ++i)
        cin >> opAmount[i];
    dfs(1, {A[0]});
    cout << retMax << "\n"
         << retMin;
    return 0;
}