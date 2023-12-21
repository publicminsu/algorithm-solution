#include <iostream>
#include <vector>
using namespace std;
vector<int> prefix;
int N, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    prefix = vector<int>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> prefix[i];
    }

    for (int i = 2; i < N; ++i) // 누적 합
    {
        prefix[i] += prefix[i - 2];
    }

    answer = max(prefix[N - 1], prefix[N - 2]);
    if (N >= 4) // 처음 상대에게 주는 것을 밑장
    {
        answer = max(answer, prefix[0] + prefix[N - 3]);
    }

    for (int i = 2; i < N; ++i)
    {
        if (i % 2) // 상대에게 밑장
        {
            answer = max(answer, prefix[i - 1] + prefix[N - 3] - prefix[i - 2]); // 현재까지의 값+순서 반전으로 얻을 수 있는 값
        }
        else // 나에게 밑장
        {
            answer = max(answer, prefix[i - 2] + prefix[N - 1] - prefix[i - 1]); // 현재까지의 값+순서 반전으로 얻을 수 있는 값
        }
    }
    cout << answer;
    return 0;
}