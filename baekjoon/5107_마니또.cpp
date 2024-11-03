#include <iostream>
#include <map>
using namespace std;
int N, answer, i;
map<string, string> m;
map<string, bool> isVisited;

void dfs(string name)
{
    if (isVisited[m[name]])
    {
        ++answer;
    }
    else
    {
        isVisited[m[name]] = true;
        dfs(m[name]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> N)
    {
        if (N == 0)
        {
            break;
        }

        answer = 0;

        isVisited.clear();
        m.clear();

        while (N--)
        {
            string name1, name2;
            cin >> name1 >> name2;
            m[name1] = name2;
        }

        for (auto p : m)
        {
            if (isVisited[p.first])
            {
                continue;
            }

            dfs(p.first);
        }

        cout << ++i << " " << answer << "\n";
    }

    return 0;
}