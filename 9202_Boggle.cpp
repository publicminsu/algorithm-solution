#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cstring>
using namespace std;
struct trie
{
    unordered_map<char, trie *> um;
    bool isEnd;
};
trie *root;
int w, b, maxScore;
unordered_set<string> isUsed;
string temp, ret;
char grid[4][4];
bool isVisited[4][4];
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx[] = {1, -1, 0, 0, 1, -1, -1, 1}, score[] = {0, 0, 1, 1, 2, 3, 5, 11};
void dfs(int y, int x, trie *cur)
{
    if (cur->isEnd)
        if (isUsed.find(temp) == isUsed.end())
        {
            isUsed.insert(temp);
            maxScore += score[temp.length() - 1];
            if (ret.length() < temp.length())
                ret = temp;
            else if (ret.length() == temp.length() && ret > temp)
                ret = temp;
        }
    for (int i = 0; i < 8; ++i)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || isVisited[ny][nx])
            continue;
        char c = grid[ny][nx];
        if (cur->um.find(c) == cur->um.end())
            continue;
        isVisited[ny][nx] = true;
        temp.push_back(c);
        dfs(ny, nx, cur->um[c]);
        temp.pop_back();
        isVisited[ny][nx] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    root = new trie();
    cin >> w;
    for (int i = 0; i < w; ++i)
    {
        trie *cur = root;
        cin >> temp;
        for (char c : temp)
        {
            if (cur->um.find(c) == cur->um.end())
                cur->um[c] = new trie();
            cur = cur->um[c];
        }
        cur->isEnd = true;
    }
    cin >> b;
    while (b--)
    {
        isUsed.clear();
        memset(isVisited, false, sizeof(isVisited));
        ret = "";
        maxScore = 0;
        for (int i = 0; i < 4; ++i)
        {
            cin >> temp;
            for (int j = 0; j < 4; ++j)
                grid[i][j] = temp[j];
        }
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                char c = grid[i][j];
                if (root->um.find(c) == root->um.end())
                    continue;
                isVisited[i][j] = true;
                temp = c;
                dfs(i, j, root->um[c]);
                isVisited[i][j] = false;
            }
        }
        cout << maxScore << " " << ret << " " << isUsed.size() << "\n";
    }
    return 0;
}