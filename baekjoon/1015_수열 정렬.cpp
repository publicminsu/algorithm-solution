#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
vector<pii> A;
vector<int> P;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    P = vector<int>(N);
    A = vector<pii>(N);

    for (int i = 0, a; i < N; ++i)
    {
        cin >> a;
        A[i].first = a;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; ++i)
    {
        P[A[i].second] = i;
    }

    for (const int &i : P)
    {
        cout << i << " ";
    }
    return 0;
}