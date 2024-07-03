#include <iostream>
#include <queue>
using namespace std;
string N;
queue<string> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    q.push(N);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        bool isFind = true;
        for (int i = N.size(); i > 0; --i)
        {
            int j = (N[i - 1] - '0');

            if (j && (stoll(cur) % j))
            {
                isFind = false;
            }
        }

        if (isFind)
        {
            cout << cur;
            break;
        }

        for (char i = '0'; i <= '9'; ++i)
        {
            q.push(cur + i);
        }
    }
    return 0;
}