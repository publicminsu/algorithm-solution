#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<vector<ll>> defaultBaseMat = {{1, 1}, {1, 0}};                        // 밑
vector<vector<ll>> multi(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2) // 행렬 곱
{
    vector<vector<ll>> retMat = vector<vector<ll>>(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                retMat[i][j] += mat1[i][k] * mat2[k][j];
                retMat[i][j] %= 1000000;
            }
        }
    }
    return retMat;
}
vector<vector<ll>> recur(vector<vector<ll>> &mat, ll n) // 재귀
{
    if (n == 1)
    {
        return mat;
    }

    if (n & 1)
    {
        vector<vector<ll>> retMat = recur(mat, n - 1);
        return multi(retMat, defaultBaseMat);
    }
    else
    {
        vector<vector<ll>> retMat = recur(mat, (n >> 1));
        return multi(retMat, retMat);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> retMat = vector<vector<ll>>(defaultBaseMat);
    retMat = recur(retMat, n);
    cout << retMat[0][1];
    return 0;
}