#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using pis = pair<int, string>;
using pii = pair<int, int>;

int t, l;
string userWord, suggestWord;
unordered_map<char, pii> m;
vector<pis> v;

void cacheLine(string line, int height)
{
    for (int i = 0; i < line.size(); ++i)
    {
        m[line[i]] = {height, i};
    }
}

void cache()
{
    cacheLine("qwertyuiop", 0);
    cacheLine("asdfghjkl", 1);
    cacheLine("zxcvbnm", 2);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    v.reserve(10);
    cache();

    cin >> t;

    while (t--)
    {
        cin >> userWord >> l;

        while (l--)
        {
            int dist = 0;

            cin >> suggestWord;

            for (int i = 0; i < userWord.length(); ++i)
            {
                const pii &j = m[userWord[i]];
                const pii &k = m[suggestWord[i]];

                dist += abs(j.first - k.first) + abs(j.second - k.second);
            }

            v.push_back({dist, suggestWord});
        }

        sort(v.begin(), v.end());

        for (const pis &p : v)
        {
            cout << p.second << " " << p.first << "\n";
        }

        v.clear();
    }
    return 0;
}