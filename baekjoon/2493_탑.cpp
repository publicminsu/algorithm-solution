#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int index, height;
};
vector<int> heights, answers;
vector<node> towers;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    heights = answers = vector<int>(N);

    for (int &height : heights)
    {
        cin >> height;
    }

    for (int cur = N - 1; cur >= 0; --cur)
    {
        int &curHeight = heights[cur];

        // 기록된 높이가 현재 높이 미만일 경우
        while (!towers.empty() && towers.back().height < curHeight)
        {
            answers[towers.back().index] = cur + 1;

            towers.pop_back();
        }

        towers.push_back({cur, curHeight});
    }

    for (const int &answer : answers)
    {
        cout << answer << " ";
    }
    return 0;
}