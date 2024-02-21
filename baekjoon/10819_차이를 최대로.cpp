#include <iostream>
#include <vector>
using namespace std;
vector<int> A;
int N, answer;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    A = vector<int>(N);
    for (int &i : A)
    {
        cin >> i;
    }
}
int calc()
{
    int sum = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        sum += abs(A[i] - A[i + 1]);
    }
    return sum;
}
void recur(int idx)
{
    if (idx == N)
    {
        answer = max(answer, calc());
        return;
    }
    for (int i = idx; i < N; ++i)
    {
        swap(A[i], A[idx]);
        recur(idx + 1);
        swap(A[i], A[idx]);
    }
}
int main()
{
    input();
    recur(0);
    cout << answer;
    return 0;
}