#include <iostream>
#include <stack>
using namespace std;
int N, answer;
string word;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> word;
        if (word.size() % 2)
        {
            continue;
        }

        stack<char> s;

        for (char c : word)
        {
            if (!s.empty() && s.top() == c) // 남은 값이 같으면 곡선을 긋는다.
            {
                s.pop();
                continue;
            }
            s.push(c);
        }

        answer += s.empty(); // 비어있는 경우 1을 더한다
    }

    cout << answer;
    return 0;
}