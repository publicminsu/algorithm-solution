#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
unordered_set<string> us;
queue<string> q;
string car;
int N, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> car;
        q.push(car);
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> car;

        us.insert(car);

        if (q.front() != car)
        {
            ++answer;
        }
        else
        {
            q.pop();

            while (us.find(q.front()) != us.end())
            {
                q.pop();
            }
        }
    }

    cout << answer;
    return 0;
}