#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int X, Y, M, curHp, i = 1, j;
    vector<pii> damage, heal;
    vector<int> ret;
    cin >> X >> Y >> M;
    int startD = 0, endD = X - 1, startH = 0, endH = Y - 1;
    curHp = M;
    while (X--)
    {
        cin >> j;
        damage.push_back({j, i++});
    }
    sort(damage.begin(), damage.end());
    i = 1;
    while (Y--)
    {
        cin >> j;
        heal.push_back({j, i++});
    }
    sort(heal.begin(), heal.end());
    while (startD <= endD)
    {
        pii curNode = damage[endD];
        if (curNode.first < curHp)
        {
            ret.push_back(-curNode.second);
            curHp -= curNode.first;
            --endD;
            continue;
        }
        curNode = damage[startD];
        if (curNode.first < curHp)
        {
            ret.push_back(-curNode.second);
            curHp -= curNode.first;
            ++startD;
            continue;
        }
        if (startH > endH)
        {
            cout << 0;
            return 0;
        }
        curNode = heal[endH];
        if (curNode.first + curHp <= M)
        {
            ret.push_back(curNode.second);
            curHp += curNode.first;
            --endH;
            continue;
        }
        curNode = heal[startH];
        ret.push_back(curNode.second);
        curHp += curNode.first;
        ++startH;
    }
    for (int r : ret)
        cout << r << "\n";
    while (startH <= endH)
        cout << heal[startH++].second << "\n";
    return 0;
}