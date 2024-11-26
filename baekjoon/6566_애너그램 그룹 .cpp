#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
string word;
map<string, pair<string, vector<string>>> m;
set<string> isVisited;
vector<pair<string, vector<string>>> v;

const bool compare(const pair<string, vector<string>> &a, const pair<string, vector<string>> &b)
{
    if (a.second.size() == b.second.size())
    {
        return a.second[0] < b.second[0];
    }

    return a.second.size() > b.second.size();
}

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (cin >> word)
    {
        string w = word;

        sort(word.begin(), word.end());

        if (m[word].first == "")
        {
            m[word].first = w;
        }
        else
        {
            m[word].first = min(m[word].first, w);
        }

        m[word].second.push_back(w);
    }
}

void solve()
{
    v.reserve(m.size());

    for (auto &p : m)
    {
        sort(p.second.second.begin(), p.second.second.end());
        v.push_back({p.first, p.second.second});
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < min(5, static_cast<int>(v.size())); ++i)
    {
        const auto &p = v[i];

        cout << "Group of size " << p.second.size() << ": ";

        for (const auto &s : p.second)
        {
            if (isVisited.find(s) != isVisited.end())
            {
                continue;
            }

            isVisited.insert(s);
            cout << s << " ";
        }
        cout << ".\n";
    }
}

int main()
{
    input();
    solve();
    return 0;
}