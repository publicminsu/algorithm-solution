#include <iostream>
#include <deque>
using namespace std;
int N, M, answer, num;
deque<int> a;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        a.push_back(i);
    }

    while (M--)
    {
        cin >> num;

        int op2 = 0;

        while (a.front() != num)
        {
            a.push_back(a.front());
            a.pop_front();
            ++op2;
        }

        int op3 = a.size() - op2;

        a.pop_front();

        answer += min(op2, op3);
    }

    cout << answer;
    return 0;
}