#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, answer = 0;
    string problem;
    cin >> N >> M;
    while (N--)
    {
        cin >> problem;
        int cnt = 0;
        for (char c : problem)
        {
            if (c == 'O')
            {
                ++cnt;
            }
        }
        if (cnt * 2 > M) // 과반수 확인
        {
            ++answer;
        }
    }
    cout << answer;
}