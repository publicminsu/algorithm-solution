#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, ret = 0;
    vector<pair<int, int>> v;
    cin >> N;
    while (N--)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int left = v[0].first, right = v[0].second;
    for (auto i : v)
    {
        if (right < i.first) // 겹치지 않는 경우 (새로운 선의 시작점이 기존 선의 끝점보다 클 경우)
        {
            ret += right - left; // 기존 선의 길이를 답에 추가해준다.
            left = i.first;      // 새로운 선의 시작과 끝으로 바꾸어준다.
            right = i.second;
        }
        else // 겹치는 선일 경우 (새로운 선의 시작점이 기존 선의 끝점보다 작거나 같을 경우)
        {
            if (right < i.second) // 새로운 선의 끝점이 더 클 시 끝점만 늘려준다.
                right = i.second;
        }
    }
    ret += right - left; // 모든 선을 소비했을 때 마지막 남은 선의 길이
    cout << ret;
    return 0;
}