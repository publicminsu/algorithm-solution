#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<vector<int>> A;
int N;
ll B;
vector<vector<int>> multi(vector<vector<int>> &mat1, vector<vector<int>> &mat2) // 행렬의 곱셈
{
    vector<vector<int>> ret = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                ret[i][j] += (mat1[i][k] * mat2[k][j]);
                ret[i][j] %= 1000;
            }
        }
    }
    return ret;
}
vector<vector<int>> recur(vector<vector<int>> &cur, ll num)
{
    if (num == 1) // 기본값 반환
    {
        return cur;
    }

    if (num % 2) // 홀수인지
    {
        vector<vector<int>> recurMat = recur(cur, num - 1);
        return multi(recurMat, A);
    }
    else
    {
        vector<vector<int>> recurMat = recur(cur, num / 2);
        return multi(recurMat, recurMat); // 제곱
    }
}
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> B;

    A = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
    }
}
int main()
{
    input();
    vector<vector<int>> ret = recur(A, B);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << ret[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
    return 0;
}