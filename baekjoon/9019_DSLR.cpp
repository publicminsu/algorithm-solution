#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using psi = pair<string, int>;

bool isVisited[10000];
int T, A, B;
queue<psi> q;

void push(string nextCommand, const int &nextValue)
{
    if (!isVisited[nextValue])
    {
        q.push({nextCommand, nextValue});
        isVisited[nextValue] = true;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        memset(isVisited, false, sizeof(isVisited));

        q = queue<psi>();

        cin >> A >> B;

        q.push({"", A});

        while (true)
        {
            psi cur = q.front();
            q.pop();

            const string &curCommand = cur.first;
            const int &curValue = cur.second;

            if (curValue == B)
            {
                cout << curCommand << "\n";
                break;
            }

            int nextDValue = (curValue * 2) % 10000;
            push(curCommand + "D", nextDValue);

            int nextSValue = curValue - 1;
            if (nextSValue == -1)
            {
                nextSValue = 9999;
            }
            push(curCommand + "S", nextSValue);

            int nextLValue = curValue / 1000 + (curValue % 1000) * 10;
            push(curCommand + "L", nextLValue);

            int nextRValue = (curValue % 10) * 1000 + curValue / 10;
            push(curCommand + "R", nextRValue);
        }
    }
    return 0;
}