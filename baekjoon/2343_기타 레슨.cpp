#include <iostream>
#include <vector>
using namespace std;
int N, M, low, high;
vector<int> videos;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    videos = vector<int>(N);
    for (int &video : videos)
    {
        cin >> video;
        low = max(low, video);
    }
}
int solve()
{
    int mid, size, cnt, answer;
    answer = 0;
    high = 1000000000;

    while (low <= high)
    {
        mid = (low + high) >> 1;
        size = 0;
        cnt = 1;

        for (const int &video : videos)
        {
            size += video;
            if (size > mid) // 크기를 넘어가면
            {
                ++cnt;
                size = video;
            }
        }

        if (cnt <= M) // 해당 값만큼 크기를 설정해도 개수가 많거나 같다면
        {
            high = mid - 1;
            answer = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return answer;
}
int main()
{
    input();
    cout << solve();
    return 0;
}