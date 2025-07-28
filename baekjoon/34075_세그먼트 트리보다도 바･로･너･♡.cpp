#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int N, M, Q;
map<string, int> diffs;
unordered_map<string, int> tiers;
string cmd[3], curName;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string algo;
        cin >> algo;
        cin >> diffs[algo];
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        string name;
        cin >> name;
        cin >> tiers[name];
    }
}

void query()
{
    cin >> Q;
    while (Q--)
    {
        for (int i = 0; i < 3; ++i)
        {
            cin >> cmd[i];
        }

        if (cmd[1] == "-")
        {
            curName = cmd[0];
            cout << "hai!\n";
        }
        else
        {
            string algo1, algo2;
            int tier = tiers[curName];
            int gap = 31;

            for (auto p : diffs)
            {
                int value = abs(tier - p.second);

                if (value < gap)
                {
                    gap = value;
                    algo1 = p.first;
                }
            }

            gap = 31;
            for (auto p : diffs)
            {
                if (p.first == algo1)
                {
                    continue;
                }

                int value = abs(tier - p.second);

                if (value < gap)
                {
                    gap = value;
                    algo2 = p.first;
                }
            }

            cout << algo2 << " yori mo " << algo1 << "\n";
        }
    }
}

int main()
{
    input();
    query();
    return 0;
}