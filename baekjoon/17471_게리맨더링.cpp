#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector<int> popul;
queue<int> q;
vector<vector<int>> map;
int N, ret = 1001, total = 0;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    popul = vector<int>(N);
    map = vector<vector<int>>(N, vector<int>());

    for (int i = 0; i < N; ++i)
    {
        cin >> popul[i];
        total += popul[i];
    }
    for (int i = 0; i < N; ++i)
    {
        int near;
        cin >> near;
        while (near--)
        {
            int nearNum;
            cin >> nearNum;
            --nearNum;
            map[i].push_back(nearNum);
        }
    }
    for (int i = 1; i < (1 << N); ++i)
    {
        int part = 0, visted = 0, my = 0;
        for (int j = 0; j < N; ++j)
        {
            if (visted & (1 << j)) // 이미 방문한 경우
                continue;
            visted = (visted | (1 << j));
            ++part;
            if (part > 2) // 구역이 2개 이상인 경우 넘어간다
            {
                q = queue<int>();
                break;
            }
            bool isSelected = (i & (1 << j)); // 누구의 선거구인지 확인
            if (isSelected)
                my += popul[j];
            q.push(j);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int k : map[cur])
                {
                    if ((visted & (1 << k)) || (isSelected != bool(i & (1 << k)))) // 방문했거나 나와 다른 경우 넘어간다
                        continue;
                    visted = (visted | (1 << k)); // 방문 표시
                    if (isSelected)               // 내 선거구면 횟수를 더 해준다.
                        my += popul[k];
                    q.push(k);
                }
            }
        }
        if (part != 2)
            continue;
        int gap = total - (my << 1); // 상대 선거구 - 내 선거구 => 전체 선거구 - 내 선거구 *2
        if (gap < 0)
            gap *= -1;
        ret = ret > gap ? gap : ret;
    }
    if (ret == 1001)
        cout << -1;
    else
        cout << ret;
}