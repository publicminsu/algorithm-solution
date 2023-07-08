#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map;
vector<int> v;
int dir[] = {7, 3, 1, 5};
int N, M, ret[3];
// 2차원 배열을 1차원 배열로 옮겨주는 것
void mapToV()
{
    int first = N / 2 - 1;
    for (int i = first, len = 2; i >= 0; --i, len += 2)
    {
        for (int j = 1; j <= len; ++j)
        {
            if (!map[i + j][i])
                return;
            v.push_back(map[i + j][i]);
        }
        for (int j = 1; j <= len; ++j)
        {
            if (!map[i + len][i + j])
                return;
            v.push_back(map[i + len][i + j]);
        }
        for (int j = 1; j <= len; ++j)
        {
            if (!map[i + len - j][i + len])
                return;
            v.push_back(map[i + len - j][i + len]);
        }
        for (int j = 1; j <= len; ++j)
        {
            if (!map[i][i + len - j])
                return;
            v.push_back(map[i][i + len - j]);
        }
    }
}
// 블리자드 마법 1차원 배열에서 구슬을 지워준다.
void skill(int d, int s)
{
    int i = dir[d], gap = dir[d];
    if (i > v.size())
        return;
    vector<int> target{i};
    while (true)
    {
        gap += 8;
        i += gap;
        if (i > v.size() || target.size() == s)
            break;
        target.push_back(i);
    }
    for (int i = target.size() - 1; i >= 0; --i)
        v.erase(v.begin() + target[i] - 1);
}
// 4개 이상 연속하는 구슬을 지워준다.
void explosion()
{
    vector<int> target;
    while (true)
    {
        if (v.empty())
            return;
        int cnt = 1, num = v[0];
        target.push_back(0);
        bool isFind = false;
        for (int i = 1; i < v.size(); ++i)
        {
            int curNum = v[i];
            if (num == curNum)
            {
                target.push_back(i);
                ++cnt;
            }
            else
            {
                if (cnt >= 4)
                {
                    ret[num - 1] += cnt;
                    isFind = true;
                }
                else
                    while (cnt--)
                        target.pop_back();
                target.push_back(i);
                num = curNum;
                cnt = 1;
            }
        }
        if (cnt >= 4)
        {
            ret[num - 1] += cnt;
            isFind = true;
        }
        else
            while (cnt--)
                target.pop_back();
        if (!isFind)
            break;
        for (int i = target.size() - 1; i >= 0; --i)
            v.erase(v.begin() + target[i]);
        target.clear();
    }
}
// 그룹을 변화시킨다.
void change()
{
    vector<int> target;
    if (v.empty())
        return;
    int cnt = 1, num = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        int curNum = v[i];
        if (num == curNum)
            ++cnt;
        else
        {
            target.push_back(cnt);
            target.push_back(num);
            num = curNum;
            cnt = 1;
        }
    }
    if (num)
    {
        target.push_back(cnt);
        target.push_back(num);
    }
    if (target.size() > N * N - 1)
        target.resize(N * N - 1);
    v = target;
}
// 2차원 배열을 입력받는다.
void mapInput()
{
    cin >> N >> M;
    map = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];
}
// 블리자드에 대한 입력을 받으며 블리자드, 폭발, 변화를 행한다.
void skillInput()
{
    mapToV();
    while (M--)
    {
        int d, s;
        cin >> d >> s;
        skill(--d, s);
        explosion();
        change();
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    mapInput();
    skillInput();
    cout << ret[0] + ret[1] * 2 + ret[2] * 3;
    return 0;
}