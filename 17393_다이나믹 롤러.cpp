#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<ull> A(N), B(N);
    vector<int> ret(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> B[i];
    for (int i = N - 2; i >= 0; --i)
    {
        int cnt = 0;
        for (int j = i + 1; j < N; ++j)
        {
            if (A[i] < B[j]) // 점도 지수는 오름차순이기에 뒤엣것을 더 볼 필요 없다.
                break;
            if (A[i] >= A[j] && ret[j]) // 잉크 지수가 같거나 크다면 넘어갈 수 있다.
            {
                cnt += ret[j];
                j += ret[j] - 1;
                continue;
            }
            ++cnt;
        }
        ret[i] = cnt;
    }
    for (int i : ret)
        cout << i << " ";
    return 0;
}