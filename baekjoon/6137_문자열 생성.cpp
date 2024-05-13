#include <iostream>
#include <deque>
using namespace std;
int N;
deque<char> dq, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    while (N--)
    {
        char c;

        cin >> c;
        dq.push_back(c);
    }

    while (!dq.empty())
    {
        char c;

        int idx = 0;
        while (true)
        {
            if (dq[idx] < dq[dq.size() - 1 - idx])
            {
                c = dq.front();
                dq.pop_front();
            }
            else if (dq[idx] > dq[dq.size() - 1 - idx] || idx * 2 >= dq.size())
            {
                c = dq.back();
                dq.pop_back();
            }
            else
            {
                ++idx;
                continue;
            }
            break;
        }
        answer.push_back(c);
    }

    for (int i = 0; i < answer.size(); ++i)
    {
        if (i % 80 == 0 && i > 0)
        {
            cout << "\n";
        }
        cout << answer[i];
    }
    return 0;
}