#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
string word;
map<string, pair<string, vector<string>>> m;
set<string> isVisited;

const bool compare(const pair<string, pair<string, vector<string>>> &a, const pair<string, pair<string, vector<string>>> &b)
{
    if (a.second.second.size() == b.second.second.size())
    {
        return a.second.first < b.second.first;
    }

    return a.second.second.size() > b.second.second.size();
}

int main()
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

    vector<pair<string, pair<string, vector<string>>>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < min(5, static_cast<int>(v.size())); ++i)
    {
        auto p = v[i];

        sort(p.second.second.begin(), p.second.second.end());

        cout << "Group of size " << p.second.second.size() << ": ";

        for (auto s : p.second.second)
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
    return 0;
}