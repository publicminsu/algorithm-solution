#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;
struct info
{
    string name;
    bool isFolder;
};
unordered_map<string, vector<info>> dir;
unordered_set<string> us;
int ret;
void dfs(string cur)
{
    for (auto d : dir[cur])
    {
        if (d.isFolder)
            dfs(d.name);
        else
        {
            ++ret;
            us.insert(d.name);
        }
    }
}
vector<string> sub(string query)
{
    stringstream ss(query);
    string temp;
    vector<string> v;
    while (getline(ss, temp, '/'))
    {
        v.push_back(temp);
    }
    return v;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M, i = 0, Q;
    string P, F, query;
    bool C;
    cin >> N >> M;
    for (; i < N + M; ++i)
    {
        cin >> P >> F >> C;
        if (F == "main")
        {
            dir[P].push_back({F, C});
            ++i;
            break;
        }
        if (P == "main")
            dir["."].push_back({F, C});
        else
            dir[P].push_back({F, C});
    }
    for (; i < N + M; ++i)
    {
        cin >> P >> F >> C;
        dir[P].push_back({F, C});
    }
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        cin >> query;
        vector<string> v = sub(query);
        ret = 0;
        us.clear();
        if (v.size() == 1)
            dfs(".");
        else
            dfs(v.back());
        cout << us.size() << " " << ret << "\n";
    }
    return 0;
}