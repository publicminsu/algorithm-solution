#include <iostream>
#include <vector>
using namespace std;
vector<int> A;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, answer = 1, i = 0, j = 1;
    cin >> N;
    A = vector<int>(N);
    for (int &a : A)
    {
        cin >> a;
    }
    while (j < N)
    {
        if (A[i] <= A[j]) // 감소하지 않는다면 범위를 좁힌다.
        {
            ++i;
        }
        else
        {
            ++j;
        }
        answer = max(answer, j - i);
        if (i == j)
        {
            ++j;
        }
    }
    cout << answer;
    return 0;
}