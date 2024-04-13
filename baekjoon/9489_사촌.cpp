#include <iostream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;
int n, k, parent, prevNum, num;
int parents[1000001];
map<int, vector<int>> childs;
queue<int> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        cin >> n >> k;
        if (!n)
        {
            break;
        }
        memset(parents, 0, sizeof(parents));
        childs.clear();
        q = queue<int>();

        cin >> prevNum;
        q.push(prevNum);

        for (int i = 1; i < n; ++i)
        {
            cin >> num;

            if (prevNum + 1 != num)
            {
                parent = q.front();
                q.pop();
            }

            parents[num] = parent;
            childs[parent].push_back(num);

            q.push(num);

            prevNum = num;
        }
        q = queue<int>();
        int p = parents[k];
        int pp = parents[p];

        if (!pp) // 부모의 부모가 없는 경우
        {
            cout << 0 << "\n";
            continue;
        }

        int sum = -childs[p].size();

        for (const int &i : childs[pp]) // 사촌을 모두 더한다.
        {
            sum += childs[i].size();
        }
        cout << sum << "\n";
    }
}