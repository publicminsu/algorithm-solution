#include <iostream>
#include <unordered_map>
using namespace std;
int N;
float ret;
string word;
struct trie
{
    unordered_map<char, trie *> um;
    bool isEnd;
};
trie *root;
void dfs(trie *cur, int cnt)
{
    int isNotSolo = cur->um.size() > 1 ? 1 : 0;
    if ((cur->um.size() == 1) && (cur->isEnd))
        isNotSolo = 1;
    if (cur->isEnd)
        ret += cnt;
    for (auto next : cur->um)
        dfs(next.second, cnt + isNotSolo);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cout << fixed;
    cout.precision(2);
    root = new trie();
    while (cin >> N)
    {
        root->um.clear();
        root->isEnd = false;
        ret = 0;
        for (int i = 0; i < N; i++)
        {
            trie *cur = root;
            cin >> word;
            for (char c : word)
            {
                if (cur->um.find(c) == cur->um.end())
                    cur->um[c] = new trie();
                cur = cur->um[c];
            }
            cur->isEnd = true;
        }
        for (auto next : root->um)
            dfs(next.second, 1);
        ret /= N;
        cout << ret << "\n";
    }
    return 0;
}