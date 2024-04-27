#include <iostream>
using namespace std;
int ret;
int answers[10];
void dfs(int idx, int score, int choice, int cnt)
{
    if (idx == 10)
    {
        if (score >= 5)
        {
            ++ret;
        }
        return;
    }

    for (int i = 1; i <= 5; ++i)
    {
        int nextCnt = choice == i ? cnt + 1 : 1;

        if (nextCnt == 3)
        {
            continue;
        }

        int nextScore = score + (answers[idx] == i);

        dfs(idx + 1, nextScore, i, nextCnt);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int &answer : answers)
    {
        cin >> answer;
    }

    dfs(0, 0, -1, 0);

    cout << ret;
    return 0;
}